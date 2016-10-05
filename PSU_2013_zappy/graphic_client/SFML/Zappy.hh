#ifndef _ZAPPY_H_
# define _ZAPPY_H_

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <cstdio>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Window.hh"
#include "Map.hh"

class				 zappy
{
private:
  int				 _map_x;
  int				 _map_y;
  int				 _fd;
  int				 _time;
  int				 _nbr_player;
  std::list<std::string>	_team_name;
  bool			 (zappy::*command[23])(std::string const &);
  window		 graph;
  map        zappy_map;

private:
  zappy(const zappy &);
  zappy				operator=(const zappy &);

public:
  zappy();
  virtual     ~zappy(void);

  int				 getFd() const;
  int				 getTime() const;
  int				 getNbrPlayer() const;
  int				 str_to_int(std::string const &);

  void				run();
  void        draw();
  bool				connecting(const char *, const int);
  void				getData();

  bool				msz(std::string const &);
  bool				bct(std::string const &);
  bool				tna(std::string const &);
  bool				pnw(std::string const &);
  bool				ppo(std::string const &);
  bool				plv(std::string const &);
  bool				pin(std::string const &);
  bool				pex(std::string const &);
  bool				pbc(std::string const &);
  bool				pic(std::string const &);
  bool				pie(std::string const &);
  bool				pfk(std::string const &);
  bool				pdr(std::string const &);
  bool				pgt(std::string const &);
  bool				pdi(std::string const &);
  bool				enw(std::string const &);
  bool				eht(std::string const &);
  bool				ebo(std::string const &);
  bool				edi(std::string const &);
  bool				sgt(std::string const &);
  bool				seg(std::string const &);
  bool				smg(std::string const &);
  bool				suc(std::string const &);
  bool				sbp(std::string const &);
};

#endif /* _ZAPPY_H_ */
