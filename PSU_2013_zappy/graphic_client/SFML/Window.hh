#ifndef _WINDOW_H_
# define _WINDOW_H_

#include <iostream>
#include <string>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class window
{
public:
  sf::RenderWindow	fenetre;
  sf::Image			ground;
  sf::Sprite		sp_ground;
  sf::Image			food;
  sf::Sprite		sp_food;
  sf::Image			ogres;
  sf::Sprite		sp_ogres;
  sf::Image			eggs;
  sf::Sprite		sp_eggs;
  sf::View			*view;

private:
  window(const window &);
  window operator=(const window &);

public:
  window();
  virtual ~window(void);

  void				createWindow(int, int);
  void				update();
  void				draw_case(int, int, int ressources[7]);
};

#endif /* _WINDOW_H_ */
