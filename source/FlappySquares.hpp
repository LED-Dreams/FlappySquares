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
#define HEIGHT	24

class FlappySquares
{
public:
	FlappySquares(int width, int height);

	int Update();

private:
	void StartGame();
	void RenderDisplay();
	void DrawObstacle(const Obstacle &o);

	int GetKey();

	enum {
		STATE_MAINMENU,
		STATE_PLAY,
		STATE_GAMEOVER
	} gameState;

	std::unique_ptr<LEDMatrix> display;
	std::unique_ptr<Player> player;
	std::vector<Obstacle> obstacles;

	Color bgColor;

	int width, height, score;
	float speed;
};

#endif
