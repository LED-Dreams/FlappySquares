#include "Player.hpp"

Player::Player(int height, int pos) {
	this->height = height;
	this->pos = pos;

	accel = 0;
	vel = 0;
	gravity = 0.05;
	maxSpeed = 0.5;
}

int Player::GetPos() const {
	return pos;
}

void Player::SetPos(int pos) {
	this->pos = pos;
}

void Player::Thrust(float thrust) {
	this->vel += thrust;
}

void Player::Update() {
	vel += accel + gravity;

	if(vel > maxSpeed)
		vel = maxSpeed;
	else if(vel < -maxSpeed)
		vel = -maxSpeed;

	pos += vel;

	if(pos >= height)
		pos = height - 1;
	else if(pos < 0)
		pos = 0;
}
