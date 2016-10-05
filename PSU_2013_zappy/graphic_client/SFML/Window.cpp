#include "Window.hh"
#include "Exception.hpp"

window::window()
{
	if (!this->ground.LoadFromFile("./img/grass1.png"))
		throw my_exception("ERROR in LoadFromFile.");
	if (!this->food.LoadFromFile("./img/Steak.PNG"))
		throw my_exception("ERROR in LoadFromFile.");
	if (!this->ogres.LoadFromFile("./img/ogre.png"))
		throw my_exception("ERROR in LoadFromFile.");
	if (!this->eggs.LoadFromFile("./img/all_eggs.png"))
		throw my_exception("ERROR in LoadFromFile.");
	//this->view = new sf::View(sf::Vector2f(400, 300), sf::Vector2f(800, 600));
}

window::~window(void) {}

window::window(__attribute__((unused))const window &src) {}

window window::operator=(__attribute__((unused))const window &src) { return (*this); }

void		window::createWindow(int x, int y)
{
  this->fenetre.Create(sf::VideoMode(x, y, 32), "Graphic client");
}
void		window::update()
{
}

void		window::draw_case(int x, int y, int ressources[7])
{
	int i = 0;

	this->sp_ground.SetPosition(x, y); //multiplier par la taiile de l'image
	this->sp_ground.SetImage(this->ground);
	while (i < 7)
	{
		if (ressources[i] > 0)
		{
			;
		}
		i++;
	}
}