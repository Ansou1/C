#ifndef HEADER_H_
# define HEADER_H_

/* get_next_line.c */
char	*my_strcpy(char *dest, char *src);
char	*my_strcat(char *dest, char *src);
int	my_buf(char *buffer, char *buffer_s, int ret);
char	*my_realloc(char *buffer, int size);
char	*get_next_line(const int fd);

/* main.c */
int	write_in_file(int fd_header, char *line);
int	fill_header(int fd, int fd_header);

/* match.c */
int	match(char *s1, char *s2);


#endif /* !HEADER_H_ */
