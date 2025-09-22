/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:08:10 by almejia-          #+#    #+#             */
/*   Updated: 2024/04/05 17:11:18 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	j;
	size_t	i;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j] && (i + j) < len)
		{
			++j;
			if (needle[j] == '\0')
				return ((char *)(haystack + i));
		}
		++i;
	}
	return (NULL);
}

/*
int main()
{

	printf("%s" ,ft_strnstr("hola caracola","",7));
	printf("%s" ,strnstr("hola caracola","", 7));
}
*/
