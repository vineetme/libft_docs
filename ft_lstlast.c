/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:36:55 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:37:00 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Signature: t_list *ft_lstlast(t_list *lst)

Purpose: Traverse the linked list & return the memory address of the last node.

Input: A single pointer (lst) holding the starting address of the list.

Output: A single pointer holding the address of the final node (or NULL if
the list is empty).

The Mechanics (Step-by-Step)
The Safety Check:If the list is empty, starting address is 0x0 (NULL), 
it aborts and returns NULL.

The Look-Ahead Radar: while (lst->next != NULL) checks the arrow inside
the box before taking a step. It asks, "Does the next box exist?"

The Step: lst = lst->next; updates your local photocopy of the pointer
to hold the address of the next node.

The Landing: The loop terminates exactly when you are standing on the
final node, allowing you to return its address.

Traps & Gotchas
The Segfault Trap: If you forget if (!lst) and main passes an empty list,
the while condition attempts to read lst->next. Accessing ->next on a NULL
pointer causes an instant segmentation fault.

The Overshoot Error: Writing while (lst != NULL) instead of while 
(lst->next != NULL). If you do this, the loop takes one step too many,
and returns NULL instead of the actual last node.

The Infinite Loop: Forgetting to write lst = lst->next; inside the while loop.
The pointer stays on first node forever, checking same next arrow infinitely.

4. Memory Reality 
You are physically overwriting the lst variable inside your loop.

Because the function takes a single pointer (t_list *lst), C only gave you a
photocopy of the starting address from main.

Walking this photocopy down to the end of the chain has zero effect on the 
head pointer back in main. The scope wall protects the original variable.*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
#include <stdio.h>
#include <string.h>

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("[%s] --> ", (char *)head->content);
		head = head->next;
	}
	printf("NULL\n\n");
}

int	main(void)
{
	t_list	*head =	NULL;
	printf("The initial state of head:\n");
	print_list(head);
	
	t_list *node1 = ft_lstnew("dudu");
	ft_lstadd_front(&head, node1);
	printf("After ading dudu:\n");
	print_list(head);

	t_list *node2 = ft_lstnew("maga");
	ft_lstadd_front(&head, node2);
	printf("After adding maga:\n");
	print_list(head);

	printf("Last node: [%s]\n", (char *)(ft_lstlast(head)->content));
}
*/
