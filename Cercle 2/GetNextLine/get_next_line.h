#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

#if BUFFER_SIZE < 0
#undef BUFFER_SIZE
#define BUFFER_SIZE 0
#endif

# include <unistd.h> //pour les fonctions open et read
# include <string.h> // pour la fonction strchr


# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

size_t  ft_strlen(char const *str);
size_t	ft_strlcpy(char *dst, const char *src, unsigned int size);
char	*ft_strchr(const char *s, int c);
size_t	get_min(size_t a, size_t b);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     check(char const *set, const char curr_c);
char	*ft_strtrim(char const *s, char const *set);
char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);


#endif
