/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almejia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 07:39:16 by almejia-          #+#    #+#             */
/*   Updated: 2024/05/17 18:05:30 by almejia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int main ()
{
	t_list *new_list = ft_lstnew("Hello, World!");
	t_list *empty_element = ft_lstnew(NULL);

	printf("Contenido de la new_list: %s\n", (char *)new_list->content);
	if (empty_element->content)
		printf("empty_content: %s\n", (char *)empty_element->content);
	else
		printf("empty_element está vacío.\n");

	free(new_list);
	free(empty_element);

	return 0;
}
*/
