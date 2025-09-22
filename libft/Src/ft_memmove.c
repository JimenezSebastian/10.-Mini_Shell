/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:32:35 by almejia-          #+#    #+#             */
/*   Updated: 2024/03/30 20:54:46 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (d == s)
		return (dst);
	if (d > s)
		while (len-- > 0)
			d[len] = s[len];
	else
		ft_memcpy(d, s, len);
	return (dst);
}

/*
#include <string.h>
int main()
{

	d < s + len
    char src[] = "ABC";
    char dest[3];
 //   printf("%s", memmove(dest, src, 14));
//	printf("%s", memmove(src +2, src, 3));
	printf("%s", memmove(dest +3, src, 3));
	printf("%c", '\n');
	printf("%s", memcpy(dest +3, src, 3));
    return (0);
}
*/
