/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 08:02:05 by almejia-          #+#    #+#             */
/*   Updated: 2024/03/29 04:52:06 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;

	str = s;
	while (n-- > 0)
	{
		if (*str == (unsigned char)c)
		{
			return ((void *)(str));
		}
		++str;
	}
	return (NULL);
}

/*
int main()
{
	printf("%s", memchr("Hello Patt", 'e', 10));
	printf("%s", ft_memchr("Hello Patt", 'e', 10));
}
*/
