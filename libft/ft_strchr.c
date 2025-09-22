/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:28:12 by almejia-          #+#    #+#             */
/*   Updated: 2024/04/29 05:01:33 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)(s));
		++s;
	}
	if ((char)c == '\0')
		return ((char *)(s));
	return (NULL);
}

/*
int main()
{
	printf("%s", ft_strchr("Hola loca", 'a'));
	printf("%s", strchr("Hola loca", 'a'));
}
*/
