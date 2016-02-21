#ifndef OBSTACLE_HPP
#define OBSTACLE_HPP

#include <stdint.h>
#include <cstdlib>

class Obstacle
{
public:
	Obstacle(int height, int pos, int gap);

	void Reset(int pos);

	int GetPos() const;
	void SetPos(int pos);

	void Move(float i);

	uint64_t GetShape() const;
private:
	void GenerateShape();

	int height, gap;
	float pos;
	uint64_t shape;
};

#endif
