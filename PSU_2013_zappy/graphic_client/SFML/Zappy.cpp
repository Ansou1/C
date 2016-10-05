#include <cerrno>
#include <cstring>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "Exception.hpp"
#include "Zappy.hh"

//constructeur
zappy::zappy()
{
  this->_fd = -1;
  this->_time = 0;
  this->_nbr_player = 0;
}

zappy::~zappy(void) {}

zappy::zappy(__attribute__((unused))const zappy &src) {}

zappy			zappy::operator=(__attribute__((unused))const zappy &src) { return (*this);}

int			zappy::getFd() const { return this->_fd; }

int			zappy::getTime() const { return this->_time; }

int			zappy::getNbrPlayer() const { return this->_nbr_player; }

bool			zappy::connecting(const char *ip_machine, const int port)
{
  struct protoent       *protocole;
  struct sockaddr_in    sin;

  if ((protocole = getprotobyname("TCP")) == NULL)
      throw my_exception("Error cannot determine the protocole\n");
  if ((this->_fd = socket(AF_INET, SOCK_STREAM, protocole->p_proto)) == -1)
      throw my_exception(strerror(errno));
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  sin.sin_addr.s_addr = inet_addr(ip_machine);
  if ((connect(this->_fd, (const struct sockaddr *)&sin, sizeof(sin))) == -1)
    {
      close(this->_fd);
      throw my_exception(strerror(errno));
    }
  std::cout << "Connexion établie sur " << ip_machine << ":" << port << std::endl;
  return true;
}

//obtenir toutes les valeurs
void			zappy::getData()
{
  char                  b[11];

  if (memset(b, 0, 11) == NULL)
    throw my_exception(strerror(errno));
  if (recv(this->_fd, b, 10, 0) == -1)
    throw my_exception(strerror(errno));
  std::cout << b;
  if (send(this->_fd, "GRAPHIC\n", 8, 0) == -1)
    throw my_exception(strerror(errno));
}

//boucle total
void			zappy::run(void)
{
  this->graph.createWindow(1920, 1080);
  while (this->graph.fenetre.IsOpened())
    {
      sf::Event event;
      while (this->graph.fenetre.GetEvent(event))
	{
	  if (event.Type == sf::Event::Closed)
	    this->graph.fenetre.Close();
	}
      this->graph.fenetre.Clear();
      this->draw();
      this->graph.fenetre.Display();
    }
}

bool			zappy::msz(std::string const &src)
{
  sscanf(src.c_str(), "msz %d %d\n", &(this->_map_x), &(this->_map_y));
  if (this->_map_x == 0 || this->_map_y == 0 || this->_map_x > 100 || this->_map_y > 100)
    throw my_exception("ERROR in map size");
  this->zappy_map.create(this->_map_x, this->_map_y);
  return true;
}

bool			zappy::bct(std::string const &src)
{
  int     x;
  int     y;
  int     ressource[7];

  sscanf(src.c_str(), "bct %d %d %d %d %d %d %d %d %d\n", &x, &y, &ressource[0], &ressource[1], &ressource[2], &ressource[3], &ressource[4], &ressource[5], &ressource[6]);
  this->zappy_map.fill_case(x, y, ressource[0], ressource[1], ressource[2], ressource[3], ressource[4], ressource[5], ressource[6]);
  this->graph.draw_case(x, y, ressource);
  return true;
}

bool			zappy::tna(std::string const &src)
{
  std::string team_name;

  team_name.assign(src, 4, src.size());
  this->_team_name.push_back(team_name);
  return true;
}

bool			zappy::pnw(std::string const &src)
{
  int     num_player;
  int     x;
  int     y;
  int     orientation;
  int     level;
  char    name[1024];

  sscanf(src.c_str(), "pnw %d %d %d %d %d %s\n", &num_player, &x, &y, &orientation, &level, name); 
  //faire une liste de player et ajouter un et créer une classe player
  return true;
}

bool			zappy::ppo(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::plv(std::string const &src)
{
  int     num_player;
  int     level;

  sscanf(src.c_str(), "plv %d %d\n", &num_player, &level);
  //set level to num_player
  return true;
}

bool			zappy::pin(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pex(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pbc(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pic(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pie(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pfk(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pdr(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pgt(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::pdi(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::enw(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::eht(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::ebo(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::edi(__attribute__((unused))std::string const &src)
{
  return true;
}

bool			zappy::sgt(std::string const &src)
{
  std::cout << "Time unit : " << src << std::endl;
  this->_time = str_to_int(src);
  return true;
}

bool			zappy::seg(std::string const &src)
{
  std::cout << "Team " << src << "win the game." << std::endl;
  //ici pense a free tout est sortir
  return true;
}

//pour toute aide pour executé qqch
bool			zappy::smg(std::string const &src)
{
  std::cout << "Message from server : " << src << std::endl;
  return true;
}

bool			zappy::suc(__attribute__((unused))std::string const &src)
{
  std::cout << "Unknown command." << std::endl;
  return true;
}

bool			zappy::sbp(__attribute__((unused))std::string const &src)
{
  std::cout << "Bad parameter." << std::endl;
  return true;
}

int			zappy::str_to_int(std::string const &str)
{
  std::istringstream	buffer(str);
  int			stock;

  buffer >> stock;
  return stock;
}

void    zappy::draw()
{
  this->graph.fenetre.Draw(this->graph.sp_ground);
}