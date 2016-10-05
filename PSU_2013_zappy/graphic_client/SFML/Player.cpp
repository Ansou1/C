#include "Player.hh"

player::player()
{
	int		i = 0;

	this->level = 0;
	while (i < 7)
	{
		this->inventaire[i] = 0;
		i++;
	}
	this->team = "";
	this->x = 0;
	this->y = 0;
}

player::~player()
{
}

player::player(__attribute__((unused))const player &src) {}

player		player::operator=(__attribute__((unused))const player &src) { return (*this); }

int 		player::getX() const { return this->x; }

int 		player::getY() const { return this->y; }

int 		player::getLevel() const { return this->level; }

void 		player::setX(int src) { this->x = src; }

void 		player::setY(int src) { this->y = src; }

void 		player::setLevel(int src) { this->level = src; }
