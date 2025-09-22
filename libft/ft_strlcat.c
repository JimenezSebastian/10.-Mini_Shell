/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:16:59 by almejia-          #+#    #+#             */
/*   Updated: 2024/03/29 06:12:27 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	while (dst[i] && i < dstsize)
		++i;
	while (*src && (i + i2 +1) < dstsize)
	{
		dst[i] = *src;
		++i;
		++src;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (i + ft_strlen(src));
}
