/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 07:05:57 by almejia-          #+#    #+#             */
/*   Updated: 2024/03/29 05:37:32 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;

	while (n-- > 0)
	{
		if (*p1 != *p2)
			return ((int)(*p1 - *p2));
		++p1;
		++p2;
	}
	return (0);
}

/*
int main()
{
	printf("%d", ft_memcmp("hola", "", 1));
    printf("%d", memcmp("hola", "", 1));
}
*/
