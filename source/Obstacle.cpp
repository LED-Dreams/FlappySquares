#include "Obstacle.hpp"

Obstacle::Obstacle(int height, int pos, int gap) {
	this->height = height;
	this->pos = pos;
	this->gap = gap;

	GenerateShape();
}

void Obstacle::Reset(int pos) {
	this->pos = pos;

	GenerateShape();
}

int Obstacle::GetPos() const {
	return pos;
}

void Obstacle::SetPos(int pos) {
	this->pos = pos;
}

void Obstacle::Move(float i) {
	pos += i;
}

uint64_t Obstacle::GetShape() const {
	return shape;
}

void Obstacle::GenerateShape() {
	int gapPos = rand() % (height - gap);

	shape = (1 << height) - 1;

	for(int i = 0; i < gap; i++) {
		shape &= ~(1 << (gapPos + i));
	}
}
