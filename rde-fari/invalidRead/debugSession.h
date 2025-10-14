#ifndef DEBUGSESSION_H
# define DEBUGSESSION_H


//*=============== Library ===============
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
//*=======================================




//*===============  Utils  ===============
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(const char *string);
char	*ft_substr(char const *s,int start, size_t len);
char	**ft_split(char const *s, char c);
void	ft_print_array_n_size(char **array);
//*=======================================


#endif