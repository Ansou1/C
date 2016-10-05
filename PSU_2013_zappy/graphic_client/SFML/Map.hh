#ifndef _MAP_H_
# define _MAP_H_

#include <iostream>
#include <string>

typedef struct 		s_map
{
	unsigned int	linemate;
	unsigned int	deraumere;
	unsigned int	sibur;
	unsigned int	mendiane;
	unsigned int	phiras;
	unsigned int	thystame;
	unsigned int	food;
}			   		t_map;

class map
{
private:
	t_map			**zappy_map;
	unsigned int	_width;
	unsigned int	_height;

private:
	map(const map &);
  	map				operator=(const map &);

public:
	map();
	~map(void);

	void			create(int, int);
	void 			fill_case(int, int, int, int, int, int, int, int, int);

	unsigned int	getWidth();
	unsigned int 	getHeight();

	void 			setWidth(unsigned int);
	void 			setHeight(unsigned int);
};

#endif