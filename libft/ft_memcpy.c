/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 06:19:46 by almejia-          #+#    #+#             */
/*   Updated: 2024/05/05 06:53:28 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*p1;
	const unsigned char	*p2;

	if (!dst && !src)
		return (NULL);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (n-- > 0)
		*(p1++) = *(p2++);
	return (dst);
}

/*
#include <stdio.h>
int main()
{
	char src[] = "a,bcdefghijklmnopqrstuvwxyz";
	char dst[27];

	ft_memcpy(dst, src, sizeof(char) * 27);
	printf("dst1: %s\n", dst);

	char dst2 [10];

	ft_memcpy(dst2, src+8, sizeof(char) * 9);
	dst2  [9] = '\0';

	printf("dst2: %s\n", dst2);

	char src1[] = "a,bcdefghijklmnopqrstuvwxyz";
//superposicion
	ft_memcpy(src1+5, src1, sizeof(char) * 10);
	src1[15] = '\0';

	printf("src1: %s\n", src1);

	return 0;
}
*/
