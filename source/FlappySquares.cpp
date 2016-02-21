#include "FlappySquares.hpp"


int main() {
	FlappySquares game(WIDTH, HEIGHT, 3, 0.25);
	timespec req, rem;
	req.tv_sec = 0;
	req.tv_nsec = 30000000L;

	while(game.Update() == 0) {
		nanosleep(&req, &rem);
	}

	return 0;
}


FlappySquares::FlappySquares(int width, int height, int obstacleCount, float speed) {
	this->width = width;
	this->height = height;
	this->speed = speed;

	srand(time(NULL));

	initscr();

	cbreak();
	noecho();
	nodelay(stdscr, TRUE);

	display.reset(new LEDMatrix(width, height));

	player.reset(new Player(height, height/2));

	for(int i = 0; i < obstacleCount; i++) {
		obstacles.push_back(Obstacle(height, width + i*width/obstacleCount, 6));
	}

	bgColor = Color(0, 0, 0);

	gameState = STATE_PLAY;
	stateTime = bcm2835_st_read();
}

int FlappySquares::Update() {
	switch(gameState) {
		case STATE_PLAY: {
			int key = GetKey();

			//Spacebar
			if(key == 32)
				player->Thrust(-1);

			player->Update();

			for(auto &o : obstacles) {
				o.Move(-speed);
				if(o.GetPos() < 0)
					o.Reset(width-1);
			}
		}
		break;

		default:
			break;
	}

	RenderDisplay();

	return 0;
}

void FlappySquares::RenderDisplay() {
	display->Fill(bgColor);

	switch(gameState) {
	case STATE_PLAY: {
		for(auto &o : obstacles) {
			if(o.GetPos() < width)
				DrawObstacle(o);
		}
		display->SetPixel(0, player->GetPos(), Color(0, 255, 0));
	}
	break;

	default:
		break;
	}

	display->Display();
}

void FlappySquares::DrawObstacle(const Obstacle &o) {
	uint64_t shape = o.GetShape();

	for(int i = 0; i < height; i++) {
		if(shape & (1 << i))
			display->SetPixel(o.GetPos(), i, Color(255, 0, 0));
	}
}


int FlappySquares::GetKey() {
	int ch = getch();

	if(ch == ERR)
		return -1;
	else
		return ch;
}
