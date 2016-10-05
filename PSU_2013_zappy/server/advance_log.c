#include "player.h"
#include "log.h"

void 		log_player(t_log *l, t_player *p, const char *str)
{
  char 	*s;

  if ((s = malloc(300)) == NULL)
    return ;
  sprintf(s, "joueur %d de l'équipe %s %s le ", p->number, p->team, str);
  l->write_log(l, s);
  free(s);
}

void 		log_player_request(t_log *l, t_player *p, const char *str)
{
  char 	*s;

  if ((s = malloc(300)) == NULL)
    return ;
  sprintf(s, "joueur %d de l'équipe %s demande \"%s\" le ", p->number,
	  p->team, str);
  l->write_log(l, s);
  free(s);
}
