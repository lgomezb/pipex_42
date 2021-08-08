#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

/* Used functions libft */
void		ft_putendl_fd(char *s, int fd);
char		**ft_split(const char *s, char c);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void		getPath(char *cmd, char *envp[], char **f_path);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
void		ft_putstr_fd(char *s, int fd);
void		freeArray(char **array);

#endif
