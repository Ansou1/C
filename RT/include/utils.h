#ifndef UTILS_H_
# define UTILS_H_

# include <unistd.h>

void	*w_malloc(unsigned int);
void	w_free(void **);
void	w_memset(void *, int, int);
void	w_error(char *);
void	w_warning(char *);
char	**str_to_wt(char *str);
char	*x_strdup(const char *str_to_copy);
size_t	my_strlen(const char *s);
void	print_error(const char *str);
int	my_atoi(const char *str);
void	my_putstr(const char *str);

#endif/* !UTILS_H_ */
