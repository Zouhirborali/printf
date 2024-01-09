#include "ft_printf.h"

char *ft_substr(const char *s, unsigned int start, size_t len)
{
    size_t i = 0;
	char buffer[len+1];
	char * re;
    if (!s)
        return NULL;

    while (s[start] && i < len)
        buffer[i++] = s[start++];

    buffer[i] = '\0';
	re = buffer;
    return re;
}
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	char	*substr =NULL;
// 	//char *re;
// 	size_t	i;
// 	if(substr)
// 		free(substr);
// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return ((char *) malloc(1));
// 	if (ft_strlen(s) <= start + len)
// 		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
// 	else
// 		substr = malloc(sizeof(char) * (len + 1));
// 	if (!substr)
// 		return (NULL);
// 	while (s[start] && i < len)
// 		substr[i++] = s[start++];
// 	substr[i] = '\0';

// 	//re= substr;
// 	//free(substr);
// 	return (substr);
// }
