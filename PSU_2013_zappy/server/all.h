/**
 * \file all.h
 * \brief Every data usefull.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * Every data usefull.
 *
 */

#ifndef ALL_H
#define ALL_H

/**
 * \enum bool
 * \brief boolean
 *
 * Use for condition
 */

typedef enum {false, true} bool;

/**
 * \enum e_direction
 * \brief Direction
 *
 * Use for direction
 */

typedef enum {UP = 0, RIGHT, DOWN, LEFT} e_direction;

/**
 * \enum e_action
 * \brief Action
 *
 * Use for action
 */

typedef enum {AVANCE = 0, DROITE, GAUCHE, VOIR, INVENTAIRE, PREND, POSE, EXPULSE, BROADCAST, INCANTATION, FORK, CONNECT_NBR, ECLOSION = 22} e_action;

/**
 * \enum e_ressource
 * \brief Ressource
 *
 * Use for ressource
 */
typedef enum {LINEMATE = 0, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME, FOOD, UNKNOW} e_ressource;


#define DIRECTIONS (4)
#define RESSOURCE_TYPE (7)

#endif
