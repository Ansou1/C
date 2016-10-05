#include "conf.h"

const t_config_parsing g_parse_config[NUMBER_CONFIG]=
{
	{"error_log", configure_error_log},
	{"zappy_log", configure_zappy_log},
	{"team", configure_team},
	{"min_ressource", configure_min_ressource},
	{"percent_ressource", configure_percent_ressource},
	{"player_by_team", configure_player_by_team},
	{"map_width", configure_width},
	{"map_height", configure_height},
	{"port", configure_port},
	{"time_unit", configure_time}
};

const char *g_ressources[RESSOURCE_TYPE] = 
{
	"linemate",
	"deraumere",
	"sibur",
	"mendiane",
	"phiras",
	"thystame",
	"food"
};

void 			free_variable(void *data)
{
	t_variable 	*a;

	a = (t_variable *)data;
	if (a->name)
		free(a->name);
	if (a->value)
		free(a->value);
	free(data);
}

t_variable 		*new_variable(char *line)
{
	t_variable 	*new;

	if ((new = malloc(sizeof (t_variable))) == NULL)
		return (NULL);
	while (*line && (*line == '\t' || *line == ' '))
		++line;
	if ((new->name = strdup(line)) == NULL)
		return (NULL);
	new->name[strcspn(new->name, " =")] = 0;
	while (*line && *line != '=')
		++line;
	if (*line == 0 || *(++line) == 0)
	{
		new->value = NULL;
	}
	else if ((new->value = strdup(line)) == NULL)
		return (NULL);
	return (new);
}

list 			*get_variable(unsigned int *number)
{
	list 		*variable;
	char 		*line;
	size_t 		s;
	t_variable 	*a;

	if ((variable = malloc(sizeof(list))) == NULL)
		return (NULL);
	init_list(variable);
	variable->free = free_variable;
	while ((line = strtok(NULL, "\n"))
	 && (s = strcspn(line, "}")) == strlen(line))
	{
		++(*number);
		if ((a = new_variable(line)) == NULL)
			errx(2, "malloc fail line : %d", *number);
		variable->push_back(variable ,a);
	}
	return (variable);
}

void 	interpret_line_config(t_zappy *z, char *line, unsigned int *num)
{
	int i;

	i = -1;
	while (++i < NUMBER_CONFIG)
		if (strncmp(line, g_parse_config[i].str, strlen(g_parse_config[i].str)) == 0)
			(g_parse_config[i].fct)(z, line, num);
}

void 				read_config_lines(t_zappy *z, char *data)
{
	char 			*line;
	unsigned int 	num;

	num = 1;
	line = strtok(data, "\n");
	interpret_line_config(z, line, &num);
	while ((line = strtok(NULL, "\n")))
	{
		++num;
		interpret_line_config(z, line, &num);
	}
}

void 		read_config(t_zappy *z)
{
	int 	fd;
	off_t 	size;
	void 	*data;
	char 	*file;

	if ((fd = open("zappy.conf", O_RDONLY)) == -1)
		return ;
	if ((size = lseek(fd, 0, SEEK_END)) == (off_t)-1)
    	errx(2, "invalide conf file \"zappy.conf\"\n");
    if ((data = mmap(NULL, size, PROT_READ, MAP_SHARED, fd, 0)) == NULL)
    	return ;
    file = strdup(data);
    close(fd);
    munmap(data, size);
    read_config_lines(z, file);
    free(file);
}