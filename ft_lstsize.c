/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:38:01 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:38:03 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
/*
#include <stdio.h>

int main()
{
	t_list *head = NULL;
	printf("Initial size: %d\n", ft_lstsize(head));

	t_list *node1 = ft_lstnew("maga");
	ft_lstadd_front(&head, node1);
	printf("After adding maga: %d\n", ft_lstsize(head));	

	t_list *node2 = ft_lstnew("dudu");
	ft_lstadd_front(&head, node2);
	printf("After adding dudu: %d\n", ft_lstsize(head));
}
*/
