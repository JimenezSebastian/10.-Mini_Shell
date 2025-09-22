/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 05:40:26 by almejia-          #+#    #+#             */
/*   Updated: 2024/05/08 14:30:58 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*s;

	s = b;
	while (len-- > 0)
		*(s++) = (unsigned char)c;
	return (b);
}

/*
#include <stdio.h>
int	main(void)
{
	int arr [5];

	ft_memset(arr, 0 , sizeof(arr));

	int i = 0;

	while (i < 5)
	{
		printf("[%d]=%d\n", i, arr[i]);
		i++;
	}

	return (0);
}
*/
