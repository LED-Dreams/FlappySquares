#ifndef FLAPPYSQUARES_HPP
#define FLAPPYSQUARES_HPP

#include "../../OutSystem/source/LEDMatrix.hpp"
#include <stdint.h>
#include <memory>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <curses.h>
#include <iostream>
#include "Obstacle.hpp"
#include "Player.hpp"

#define WIDTH	32
#define HEIGHT	16

class FlappySquares
{
public:
	FlappySquares(int width, int height, int obstacleCount, float speed);

	int Update();

private:
	void RenderDisplay();
	void DrawObstacle(const Obstacle &o);

	int GetKey();

	enum {
		STATE_MAINMENU,
		STATE_GETREADY,
		STATE_PLAY,
		STATE_GAMEOVER
	} gameState;
	uint64_t stateTime;

	std::unique_ptr<LEDMatrix> display;
	std::unique_ptr<Player> player;
	std::vector<Obstacle> obstacles;

	Color bgColor;

	int width, height;
	float speed;
};

#endif
