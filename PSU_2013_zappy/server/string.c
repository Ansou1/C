/**
 * \file string.c
 * \brief usefull function on string.
 * \author corrad_f / daguen_s
 * \version 0.1
 * \date 10 mai 2014
 *
 * string function.
 *
 */

#include <string.h>
#include <stdlib.h>

/**
 * \fn char *concat_str(char *s1, char *s2)
 * \brief concat deux string.
 *
 * \param char *s1, char *s2
 * \return char *
 */

char *concat_str(char *s1, char *s2)
{
	char *ret;

	if (s1 == NULL)
		return (strdup(s2));
	if ((ret = malloc(strlen(s1) + strlen(s2) + 1)) == NULL)
		return (NULL);
	memset(ret, 0, strlen(s1) + strlen(s2) + 1);
	ret = strcat(ret, s1);
	ret = strcat(ret, s2);
	return (ret);
}

/**
 * \fn char *realloc_str(char *s1, char *s2)
 * \brief realloc d'une chaine.
 *
 * \param char *s1, char *s2
 * \return char *
 */

char *realloc_str(char *s1, char *s2)
{
	char *ret;

	ret = concat_str(s1, s2);
	if (s1)
		free(s1);
	return (ret);
}

/**
 * \fn char *replace_str(const char *s1, int find, int replace)
 * \brief replace str
 *
 * \param const char *s1, int find, int replace
 * \return char *
 */

char *replace_str(const char *s1, int find, int replace)
{
	char *tmp;

	tmp = (char *)s1;
	while (*tmp)
	{
		if (*tmp == find)
			*tmp = replace;
		++tmp;
	}
	return ((char *)s1);
}
