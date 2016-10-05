#include "conf.h"

void 			configure_error_log(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	free(z->error_log);
	z->error_log = strdup(a->value);
	free_variable(a);
}

void 			configure_zappy_log(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	free(z->log_file);
	z->log_file = strdup(a->value);
	free_variable(a);
}

void 			configure_team(t_zappy *z, __attribute__((unused))char *line, unsigned int *num)
{
	list 		*l;
	t_variable 	*a;

	//on passe l'accolade
	strtok(NULL, "\n");
	l = get_variable(num);

	//transfert d'une liste dans une autre
	while ((a = l->pop_front(l)))
	{
		z->team_name.push_back(&z->team_name, a->name);
	}
	free(l);
}

e_ressource get_ressource_type(const char *str)
{
	int i;

	i =  -1;
	while (++i < RESSOURCE_TYPE && strcmp(str, g_ressources[i]) != 0);
	return (i);
}

void configure_limit_ressource(t_zappy *z, unsigned int *num, int min)
{
	list 		*l;
	t_variable 	*a;
	e_ressource r;

	//on passe l'accolade
	strtok(NULL, "\n");
	l = get_variable(num);
	//transfert d'une liste dans une autre
	while ((a = l->pop_front(l)))
	{
		if ((r = get_ressource_type(a->name)) == UNKNOW)
			errx(2, "Unknow ressource type line : %d", *num);
		if (min == 1)
		{
			z->min_ressource[r] = atoi(a->value);
		}
		else
			z->percent[r] = atoi(a->value);
		free(a);
	}
	free(l);
}

void 			configure_min_ressource(t_zappy *z, __attribute__((unused))char *line, unsigned int *num)
{
	configure_limit_ressource(z, num, 1);
}

void 			configure_percent_ressource(t_zappy *z, __attribute__((unused))char *line, unsigned int *num)
{
	configure_limit_ressource(z, num, 2);
}

void 			configure_player_by_team(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	z->players_by_team = atoi(a->value);
	free_variable(a);
}

void 			configure_width(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	z->width = atoi(a->value);
	free_variable(a);
}

void 			configure_height(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	z->height = atoi(a->value);
	free_variable(a);
}

void 			configure_port(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	z->port = atoi(a->value);
	free_variable(a);
}

void 			configure_time(t_zappy *z, char *line, unsigned int *num)
{
	t_variable 	*a;

	if ((a = new_variable(line)) == NULL)
		errx(2, "missing argument line %d", *num);
	z->t = atoi(a->value);
	free_variable(a);
}