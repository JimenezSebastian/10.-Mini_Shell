#include "libft.h"

int ft_strcmp(const char *s1, const char *s2)
{
    int n;

    n = 0;
    while(s1[n])
    {
        if (s1[n] == s2[n])
            ++n;
        else 
            return(1);
    }
    return (0);
}