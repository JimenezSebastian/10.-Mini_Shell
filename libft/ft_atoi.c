/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:28:54 by almejia-          #+#    #+#             */
/*   Updated: 2024/03/29 05:00:13 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*isspaces(const char *str)
{
	int	p;

	p = 0;
	while (str[p] == ' ' || (str[p] >= '\t' && str[p] <= '\r'))
		++p;
	return (str + p);
}

int	signos(const char *str)
{
	int	minus;
	int	plus;
	int	sign;

	minus = 0;
	plus = 0;
	sign = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			++minus;
		if (*str == '+')
			++plus;
		++str;
	}
	if ((minus > 1 || plus > 1) || (minus == 1 && plus == 1))
		return (0);
	if (minus == 1)
		sign = -1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	str = isspaces(str);
	sign = signos(str);
	while (*str == '+' || *str == '-')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		++str;
	}
	result *= sign;
	return (result);
}

/*
#include<stdlib.h>
#include<stdio.h>
int main()
{
	printf("%d", ft_atoi("    -123abc123"));
	printf("%d", atoi("    -123abc123"));
	return (0);
}
*/
