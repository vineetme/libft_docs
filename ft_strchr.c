#include <stdlib.h>

char    *ft_strchr(const char *str, int c)
{
    size_t  i;

    i = 0;
    while (str[i] != (char)c)
    {
        if (str[i] == '\0')
            return (NULL);
        i++;
    }
    return ((char *)&str[i]);
}
