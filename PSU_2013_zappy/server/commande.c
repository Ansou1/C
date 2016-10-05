/**
 * \file commande.c
 * \brief all the commande.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * All the commande.
 *
 */

#include "zappy.h"
#include "time.h"

/*
** Premier paramêtre la commande en char *
** Deuxième le temps que cela consome a effectuer l'action
** Troisième le pointeur sur fonction qui doit être appelé
**
** en commentaire ce que doit renvoyer la commande en réponse
*/

const t_command liste_cmd[23]=
  {
    {"avance", 7, false, move, cmd_score}, // ok
    {"droite", 7, false, right, cmd_score}, // ok
    {"gauche", 7, false, left, cmd_score}, // ok
    {"voir", 7, false, voir, cmd_score}, //case1, case2, case3, ...
    {"inventaire", 1, false, inventory, cmd_score},//linemate n, sibur n,... ou n correspond au nombre que poséde le client
    {"prend", 7, true, take, cmd_score}, // ok / ko
    {"pose", 7, true, put, cmd_score},// ok / ko
    {"expulse", 7, false, deport, cmd_score},// ok / ko
    {"broadcast", 7, true, broadcast, cmd_score}, // ok
    {"incantation", 300, false, incantation, command_incantation}, //elevation en cour
    {"fork", 42, false, forkk, cmd_fork},//ok
    {"connect_nbr", 0, false, connect_nbr, cmd_score}, //renvoie le nombre de slots non utilisé par l'équipe
    {"GRAPHIC", 0, false, NULL, cmd_graphic},
    {"msz", 0, false, NULL, cmd_msz},
    {"bct", 0, true, NULL, cmd_bct},
    {"mct", 0, false, NULL, cmd_mct},
    {"tna", 0, false, NULL, cmd_tna},
    {"ppo", 0, true, NULL, cmd_ppo},
    {"plv", 0, true, NULL, cmd_plv},
    {"pin", 0, true, NULL, cmd_pin},
    {"sgt", 0, false, NULL, cmd_sgt},
    {"sst", 0, true, NULL, cmd_sst},

    {"eclosion", 0, false, eclosion, NULL}
  };

/**
 * \fn void handling(t_zappy *z)
 * \brief lauch everything.
 *
 * \param t_zappy *z
 * \return none.
 */

//on boucle sur le buffer
//si match on recupere l'id du joueur puis on envoie l'iterator buf
void    handling(t_zappy *z)
{
  stock_commande(z);
  execute_commande(z);
  gravedigger(z);
}

/**
 * \fn void stock_commande(t_zappy *z)
 * \brief stock commande.
 *
 * \param t_zappy *z
 * \return none.
 */

void                stock_commande(t_zappy *z)
{
    t_list_iterator *buf;
    char            *str;
    char            *tmp;
    int             i;

    buf = z->buffer.begin(&z->buffer);
    while (buf)
    {
        i = ((t_buffer *)(buf->data))->size;
        if ((str = malloc(i + 1)) == NULL)
            return ;
        str = memset(str, 0, i + 1);
        str = memcpy(str, (char *)(((t_buffer *)(buf->data))->msg), i);
        tmp = strtok(str, "\n");
        while (tmp)
        {
          cut_request(z, buf, tmp);
          tmp = strtok(NULL, "\n");
        }
        buf = buf->next;
        free(str);
    }
    z->buffer.clear(&z->buffer);
}

/**
 * \fn void cut_request(t_zappy *z, t_list_iterator *buf, char *cmd)
 * \brief cut the commande.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd
 * \return none.
 */

void      cut_request(t_zappy *z, t_list_iterator *buf, char *cmd)
{
    int   i;
    bool  pass;

    pass = false;
    i = 0;
    while (i < 22)
    {
        if (strncmp(liste_cmd[i].cmd, cmd, strlen(liste_cmd[i].cmd)) == 0)
        {
          if (liste_cmd[i].parse)
            (liste_cmd[i].parse)(z, buf, cmd, i);
            pass = true;
        }
        ++i;
    }
    if (!pass && z->team_name.find(&z->team_name, z->team_name.begin(&z->team_name), match_team, cmd) != NULL)
        cmd_team_name(z, buf, cmd);
}

/**
 * \fn void cmd_team_name(t_zappy *z, t_list_iterator *buf, char *cmd)
 * \brief cut the team name.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd
 * \return none.
 */

void          cmd_team_name(t_zappy *z, t_list_iterator *buf, char *cmd)
{
    int       teamate;
    int       fd;
    char      *s1;
    t_player  *p;

    fd = ((t_buffer *)buf->data)->fd;
    cmd = replace_str(cmd, '\n', 0);
    //check si le fd n'est pas deja utilisé
    if (z->player.find(&z->player, z->player.begin(&z->player),
     match_player_fd, &fd) != NULL)
      return ;
    //on cherche si un joueur vivant est libre
    if ((p = z->player.get(&z->player, match_player_free, cmd)) != NULL)
    {
      p->fd = fd;
      if (p->status == EGG)
        send_player_connect_for_egg(z, p);
      if ((s1 = malloc(100)) == NULL)
          return ;
      memset(s1, 0, 100);
      sprintf(s1, "%d\n%d %d\n", p->number, z->width, z->height);
      z->send.push_back(&z->send, new_buffer(s1, strlen(s1), fd));
      free(s1);
      send_player_connect(z, p);
      return ;
    }
    //on creer un nouveau joueur
    teamate = get_number_of_players(cmd, z->player.begin(&z->player));
    if (z->players_by_team - teamate > 0)
    {
        if ((s1 = malloc(100)) == NULL)
            return ;
        memset(s1, 0, 100);
        sprintf(s1, "%d\n%d %d\n", z->num, z->width, z->height);
        z->send.push_back(&z->send, new_buffer(s1, strlen(s1), fd));
        free(s1);
        z->player.push_back(&z->player, new_player(&z->num, cmd, rand() % z->width, rand() % z->height, fd));
        send_player_connect(z, (z->player.find(&z->player,
         z->player.begin(&z->player), match_player_fd, &fd))->data);
    }
    else
    {
      z->send.push_back(&z->send, new_buffer("ko", 2, fd));
    }
}

/**
 * \fn void cmd_score(t_zappy *z, t_list_iterator *buf, char *arg, const int i)
 * \brief commande score.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *arg, const int i
 * \return none.
 */

void              cmd_score(t_zappy *z, t_list_iterator *buf, char *arg,
                    const int i)
{
  int             fd;
  t_player        *p;

  fd = ((t_buffer *)buf->data)->fd;
  p = z->player.get(&z->player, match_player_fd, &fd);
  if (p == NULL || p->status == EGG)
    return ;
  if (p->action.size(&p->action) > 9)
    return ;
  log_player_request(&z->log, p, arg);
  if (liste_cmd[i].take_arg)
  {
    if (arg == NULL || strcspn(arg, " ") >= strlen(arg))
      return ;
    p->action.push_back(&p->action, new_action(&arg[strcspn(arg, " ") + 1], i,
      liste_cmd[i].time));
  }
  else
    p->action.push_back(&p->action, new_action(&arg[strcspn(arg, " ") + 1], i,
      liste_cmd[i].time));
}

/**
 * \fn void cmd_fork(t_zappy *z, t_list_iterator *buf, char *arg, const int i)
 * \brief commande fork.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *arg, const int i
 * \return none.
 */

void              cmd_fork(t_zappy *z, t_list_iterator *buf, char *arg,
                    const int i)
{
  int             fd;
  t_player        *p;

  fd = ((t_buffer *)buf->data)->fd;
  p = z->player.get(&z->player, match_player_fd, &fd);
  if (p == NULL || p->status == EGG)
    return ;
   if (p->action.size(&p->action) > 9)
    return ;
   p->action.push_back(&p->action, new_action(&arg[strcspn(arg, " ") + 1], i,
      liste_cmd[i].time));
   send_player_pond(z, p);
}

/**
 * \fn void command_incantation(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande incantation.
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              command_incantation(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_player        *p;
  unsigned int    nb_players_on;

  fd = ((t_buffer *)buf->data)->fd;
  p = z->player.get(&z->player, match_player_fd, &fd);
  if (p == NULL || p->status == EGG)
    return ;
   if (p->action.size(&p->action) > 9)
    return ;
  nb_players_on = get_number_of_player_on(z, p->x, p->y);
  if (check_ressource(nb_players_on, &p->stuf, p->level))
  {
    p->action.push_back(&p->action, new_action(NULL, 9,
      liste_cmd[9].time));
    z->send.push_back(&z->send, new_buffer("ok\n", 3, p->fd));
    send_player_incant(z, p, p->x, p->y);
  }
  else
    z->send.push_back(&z->send, new_buffer("ko\n", 3, p->fd));
}

/**
 * \fn void cmd_graphic(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande graphic
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_graphic(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_fd            *f;
  t_list_iterator *it;
  t_player        *p;
  char            *s;

  fd = ((t_buffer *)buf->data)->fd;
  if ((f = z->fd.get(&z->fd, match_fd_fd, &fd)) == NULL)
    return ;
  f->is_monitor = true;
  cmd_msz(z, buf, NULL, 0);
  cmd_sgt(z, buf, NULL, 0);
  cmd_mct(z, buf, NULL, 0);
  cmd_tna(z, buf, NULL, 0);
  it = z->player.begin(&z->player);
  while (it)
  {
    if ((s = malloc(100)) == NULL)
      return ;
    memset(s, 0, 100);
    p = (t_player *)it->data;
    if (p->status == EGG)
    {
      sprintf(s, "enw %d %d %d %d\n", p->number, p->number, p->x, p->y);
      z->send.push_back(&z->send, new_buffer(s, strlen(s), fd));
    }
    else
    {
      sprintf(s, "pnw %d %d %d %d %d %s\n", p->number, p->x, p->y, p->dir + 1, p->level, p->team);
      z->send.push_back(&z->send, new_buffer(s, strlen(s), fd));
    }
    it = it->next;
  }
}

/**
 * \fn void cmd_msz(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande msz.
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void    cmd_msz(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int   fd;
  char  *str;

  if ((str = malloc(30)) == NULL)
    return ;
  memset(str, 0, 30);
  fd = ((t_buffer *)buf->data)->fd;
  sprintf(str, "msz %d %d\n", z->width, z->height);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn char *get_map_content_graphic(const unsigned int x, const unsigned int y, t_map** map)
 * \brief get the content of map.
 *
 * \param const unsigned int x, const unsigned int y, t_map** map
 * \return char * de la valeur de la map.
 */

//graphic.c
char    *get_map_content_graphic(const unsigned int x, const unsigned int y, t_map** map)
{
  t_map tmp;
  char  *ret;

  if ((ret = malloc(100)) == NULL)
    return (NULL);
  memset(ret, 0, 100);
  tmp = map[y][x];
  sprintf(ret, "bct %d %d %d %d %d %d %d %d %d\n", x, y, tmp.linemate,
   tmp.deraumere, tmp.sibur, tmp.mendiane, tmp.phiras, tmp.thystame, tmp.food);
  return (ret);
}

/**
 * \fn void cmd_bct(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
 * \brief commande bct.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void            cmd_bct(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
{
  int           fd;
  char          *str;
  unsigned int  x;
  unsigned int  y;

  fd = ((t_buffer *)buf->data)->fd;
  if (!cmd)
    {
      z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
      return ;
    }
  x = atoi(cmd);
  while (*cmd && *cmd != ' ')
    ++cmd;
  y = atoi(cmd);
  str = get_map_content_graphic(x, y, z->map);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn void cmd_mct(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande mct.
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void            cmd_mct(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int           fd;
  char          *str;
  unsigned int  x;
  unsigned int  y;

  fd = ((t_buffer *)buf->data)->fd;
  y = -1;
  while (++y < z->height)
  {
    x = -1;
    while (++x < z->width)
    {
      str = get_map_content_graphic(x, y, z->map);
      z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
      free(str);
    }
  }
}

/**
 * \fn void cmd_tna(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande tna.
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_tna(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_list_iterator *team;
  char            *str;
  char            *team_name;

  fd = ((t_buffer *)buf->data)->fd;
  team = z->team_name.begin(&z->team_name);
  while (team)
  {
    team_name = (char *)team->data;
    if ((str = malloc(strlen(team_name) + 6)) == NULL)
      return ;
    memset(str, 0, strlen(team_name) + 6);
    sprintf(str, "tna %s\n", team_name);
    z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
    free(str);
    team = team->next;
  }
}

/**
 * \fn void cmd_ppo(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
 * \brief commande ppo.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_ppo(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_player        *p;
  int             num;
  char            *str;

 fd = ((t_buffer *)buf->data)->fd;
  if (cmd == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  num = atoi(cmd);
  if ((p = z->player.get(&z->player, match_player_num, &num)) == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  if ((str = malloc(50)) == NULL)
    return ;
  memset(str, 0, 50);
  sprintf(str, "ppo %d %d %d %d\n", num, p->x, p->y, p->dir + 1);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn void cmd_plv(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
 * \brief commande plv.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_plv(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_player        *p;
  int             num;
  char            *str;

 fd = ((t_buffer *)buf->data)->fd;
  if (cmd == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  num = atoi(cmd);
  if ((p = z->player.get(&z->player, match_player_num, &num)) == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  if ((str = malloc(50)) == NULL)
    return ;
  memset(str, 0, 50);
  sprintf(str, "plv %d %d\n", num, p->level);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn void cmd_pin(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
 * \brief commande pin.
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_pin(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  t_player        *p;
  int             num;
  char            *str;

 fd = ((t_buffer *)buf->data)->fd;
  if (cmd == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  num = atoi(cmd);
  if ((p = z->player.get(&z->player, match_player_num, &num)) == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  if ((str = malloc(100)) == NULL)
    return ;
  memset(str, 0, 100);
  sprintf(str, "pin %d %d %d %d %d %d %d %d %d %d\n", num, p->x, p->y,
   p->stuf.linemate, p->stuf.deraumere, p->stuf.sibur, p->stuf.mendiane,
    p->stuf.phiras, p->stuf.thystame, p->stuf.food);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn void cmd_sgt(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
 * \brief commande sgt
 *
 * \param t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_sgt(t_zappy *z, t_list_iterator *buf, __attribute__((unused))char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  char            *str;

  fd = ((t_buffer *)buf->data)->fd;
  if ((str = malloc(20)) == NULL)
    return ;
  memset(str, 0, 20);
  sprintf(str, "sgt %d\n", z->t);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}

/**
 * \fn void cmd_sst(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
 * \brief commande sst
 *
 * \param t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i
 * \return none.
 */

void              cmd_sst(t_zappy *z, t_list_iterator *buf, char *cmd, __attribute__((unused))const int i)
{
  int             fd;
  unsigned int    t;
  char            *str;

 fd = ((t_buffer *)buf->data)->fd;
  if (cmd == NULL)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  t = atoi(cmd);
  if (t == 0)
  {
    z->send.push_back(&z->send, new_buffer("sbp\n", 4, fd));
    return ;
  }
  z->t = t;
  if ((str = malloc(20)) == NULL)
    return ;
  memset(str, 0, 20);
  sprintf(str, "sst %d\n", z->t);
  z->send.push_back(&z->send, new_buffer(str, strlen(str), fd));
  free(str);
}
