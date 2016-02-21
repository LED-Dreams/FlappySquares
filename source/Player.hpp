#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player
{
public:
	Player(int height, int pos);

	int GetPos() const;
	void SetPos(int pos);

	void Thrust(float thrust);

	void Update();

private:
	int height;
	float accel, vel, pos;
	float gravity, maxSpeed;

};


#endif
