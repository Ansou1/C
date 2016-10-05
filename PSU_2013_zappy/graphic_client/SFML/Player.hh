#ifndef _PLAYER_H_
# define _PLAYER_H_

#include <iostream>
#include <string>

class player
{
private:
	int 		x;
	int 		y;
	int 		level;
	int 		inventaire[7];
	std::string	team;

private:
	player(const player &);
	player 				operator=(const player &);

public:
	player();
	~player(void);

	int 		getX() const;
	int 		getY() const;
	int			getLevel() const;

	void 		setX(int);
	void 		setY(int);
	void 		setLevel(int);
};

#endif