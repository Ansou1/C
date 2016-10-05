#include <cstdlib>
#include <sstream>
#include "Zappy.hh"

int			main(int ac, char **av)
{
  int                   port;
  std::string           ip;
  std::istringstream    ss;
  zappy			my_zappy;

  if (ac == 3)
    {
      ip.assign(av[1]);
      ss.str(av[2]);
      ss >> port;
      try
	{
	  //if (my_zappy.connecting(ip.c_str(), port) != -1)
	  //{
	  //my_zappy.getData();
	      my_zappy.run();
	      //}
	}
      catch (std::exception &e)
	{
	  std::cerr << e.what() << std::endl;
	}
    }
  else
    std::cout << "Usage: ./client_graphic IP PORT" << std::endl;
  return (EXIT_SUCCESS);
}
