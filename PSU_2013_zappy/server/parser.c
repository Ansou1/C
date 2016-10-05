/**
 * \file parser.c
 * \brief parser.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * parser.
 *
 */
#include "zappy.h"
/**
 * \fn int get_name_team(int ac, char **av, t_param *this)
 * \brief get name team from param
 *
 * \param int ac, char **av, t_param *this
 * \return 0 if success otherwise -1
 */

int			get_name_team(int ac, char **av, t_zappy *this)
{
  int			i;

  i = optind;
  if (i == ac)
    {
      fprintf(stderr, "\033[31mERROR in get_name_team\n\033[0m");
      return (-1);
    }
  while (i  < ac && av[i][0] != '-')
    {
      this->team_name.push_back(&this->team_name, strdup(av[i]));
      i++;
    }
  return (0);
}

/**
 * \fn unsigned long int get_value_from_arg(char *value)
 * \brief get value from argument.
 *
 * \param char *value
 * \return unsigned long int from strtoul param
 */

unsigned long int	get_value_from_arg(char *value)
{
  unsigned long int	result;
  int			errno;

  errno = 0;
  result = strtoul(value, NULL, 10);
  if (errno != 0 || errno == ERANGE)
    errx(EXIT_FAILURE, "\033[31mERROR: %s\033[0m", strerror(errno));
  return (result);
}

/**
 * \fn int check_value_in_struct(t_param *this)
 * \brief check value in struct.
 *
 * \param t_param *this
 * \return 0 if success otherwise -1
 */

int			check_value_in_struct(t_zappy *this)
{
  if (this->port < 1)
    {
      fprintf(stderr, "\033[31mERROR: port must be between [0-65535]\n\033[0m");
      return (-1);
    }
  if (this->width == 0 || this->width > 100 || this->height == 0 || this->height > 100)
    {
      fprintf(stderr, "\033[31mERROR: x and y must be set and lower than 100\n\033[0m");
      return (-1);
    }
  if (this->players_by_team == 0)
    {
      fprintf(stderr, "\033[31mERROR: nbr of client per team must be set.\n\033[0m");
      return (-1);
    }
  if (this->t == 0)
    {
      fprintf(stderr, "\033[31mERROR: time action must be set\n\033[0m");
      return (-1);
    }
  return (0);
}

/**
 * \fn void init_struct(t_param *this)
 * \brief initialisation of t_param.
 *
 * \param t_param *this
 * \return none.
 */

/*
void			init_struct(t_param *this)
{
  this->_port = 0;
  this->_width = 0;
  this->_height = 0;
  init_list(&this->_team_name);
  this->_nbr_max_client = 0;
  this->_time_action = 0;
}*/

/**
 * \fn int get_argument(int ac, char **av, t_param *this)
 * \brief get argument from line command.
 *
 * \param int ac, char **av, t_param *this
 * \return 0 if success otherwise -1
 */

int			get_argument(int ac, char **av, t_zappy *this)
{
  int			c;

  while ((c = getopt(ac, av, "p:x:y:t:c:n")) != -1)
    {
      if (c == 'p')
	this->port = get_value_from_arg(optarg);
      else if (c == 'x')
	this->width = get_value_from_arg(optarg);
      else if (c == 'y')
	this->height = get_value_from_arg(optarg);
      else if (c == 't')
	this->t = get_value_from_arg(optarg);
      else if (c == 'c')
	this->players_by_team = get_value_from_arg(optarg);
      else if (c == 'n')
	{
	  if (get_name_team(ac, av, this) == -1)
	    return (-1);
	}
      else
	return (-1);
    }
  return (check_value_in_struct(this));
}
