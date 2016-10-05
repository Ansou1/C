#ifndef CONF_H
#define CONF_H

#include <sys/mman.h>
#include "zappy.h"

typedef struct 	s_config_parsing
{
	const char 	*str;
	void 		(*fct)(t_zappy *, char *, unsigned int *);
}				t_config_parsing;

typedef struct 	s_accolade
{
	char 		*name;
	char 		*value;
}				t_variable;

#define NUMBER_CONFIG (10)

extern const t_config_parsing 	parse_config[];
extern const char 				*g_ressources[];

void 		free_variable(void *data);
t_variable 	*new_variable(char *line);
list 		*get_variable(unsigned int *number);
void 		interpret_line_config(t_zappy *z, char *line, unsigned int *num);
void 		read_config_lines(t_zappy *z, char *data);
void 		read_config(t_zappy *z);
void 		configure_error_log(t_zappy *z, char *line, unsigned int *num);
void 		configure_zappy_log(t_zappy *z, char *line, unsigned int *num);
void 		configure_team(t_zappy *z, __attribute__((unused))char *line, unsigned int *num);
e_ressource get_ressource_type(const char *str);
void 		configure_limit_ressource(t_zappy *z, unsigned int *num, int min);
void 		configure_min_ressource(t_zappy *z, __attribute__((unused))char *line, unsigned int *num);
void 		configure_max_ressource(t_zappy *z, __attribute__((unused))char *line, unsigned int *num);
void 		configure_percent_ressource(t_zappy *z, __attribute__((unused))char *line, unsigned int *num);
void 		configure_player_by_team(t_zappy *z, char *line, unsigned int *num);
void 		configure_width(t_zappy *z, char *line, unsigned int *num);
void 		configure_height(t_zappy *z, char *line, unsigned int *num);
void 		configure_port(t_zappy *z, char *line, unsigned int *num);
void 		configure_time(t_zappy *z, char *line, unsigned int *num);

#endif

//strdup et free dasn la liste des team