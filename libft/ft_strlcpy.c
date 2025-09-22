/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:20:05 by almejia-          #+#    #+#             */
/*   Updated: 2024/04/01 18:22:14 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	c;

	c = ft_strlen(src);
	if (dstsize == 0)
		return (c);
	while (dstsize-- > 1 && *src)
		*(dst++) = *(src++);
	*dst = '\0';
	return (c);
}
