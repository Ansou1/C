#include "Map.hh"
#include "Exception.hpp"

map::map()
{
	this->_width = 0;
	this->_height = 0;
}

map::~map()
{
}

map::map(__attribute__((unused))const map &src) {}

map			map::operator=(__attribute__((unused))const map &src) { return (*this); }

void		map::create(int width, int height)
{
  int   y;

	this->_width = width;
	this->_height = height;
	this->zappy_map = new t_map*[height];
  y = -1;
  while (++y < height)
  {
    this->zappy_map[y] = new t_map[width];
  }
}

void    map::fill_case(int x, int y, int linemate, int deraumere, int sibur, int mendiane, int phiras, int thystame, int food)
{
  this->zappy_map[x][y].linemate = linemate;
  this->zappy_map[x][y].deraumere = deraumere;
  this->zappy_map[x][y].sibur = sibur;
  this->zappy_map[x][y].mendiane = mendiane;
  this->zappy_map[x][y].phiras = phiras;
  this->zappy_map[x][y].thystame = thystame;
  this->zappy_map[x][y].food = food;
}

unsigned int  map::getWidth() { return this->_width; }

unsigned int  map::getHeight() { return this->_height; }

void      map::setWidth(unsigned int src) { this->_width = src; }

void      map::setHeight(unsigned int src) { this->_height = src; }
