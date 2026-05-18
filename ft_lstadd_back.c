/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:32:37 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:32:39 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
1. The Blueprint
Function Signature: void ft_lstadd_back(t_list **lst, t_list *new)
Intended Mechanics: Takes address of pointer to master list head, and address
of a new node. It traverses to the end of the chain and attaches the new node.
If the master list is empty, it assigns the new node as the very first element.
Returns: void (Nothing).

The Traps & Fatal Bugs
The Empty List Segfault: If the master list head is empty (*lst == NULL), 
there are no physical nodes in the Heap. Attempting to run ft_lstlast
would return NULL, and subsequently calling last_node->next would attempt to
write to memory address 0x0, causing a Segmentation Fault.

The Invalid Address Dereference: If the lst double pointer itself is NULL 
(meaning main did not even provide the address of its pointer), executing
*lst == NULL would crash the program.

The Logic (Pseudo-code)
1.Verify that the incoming double pointer (lst) and the new node (new) are
physically valid addresses.

2.Check if the master list is completely empty (*lst holds NULL).
If true, overwrite the master pointer in main to hold the address of the
new node. Return.

If the list is not empty, pass the starting address to ft_lstlast to locate
the final node in the chain.

Overwrite the next arrow of that final node to point to the new node.

Line-by-Line Breakdown

t_list *last_node;

Declares a local, single pointer that will eventually hold the memory
address of the final node.

if (!lst || !new)
The primary safety check. Ensures main actually passed a valid address for
the pointer itself, and a valid address for the new node. Aborts if either
is missing.

if (*lst == NULL)
Dereferences the double pointer to look directly at the value held inside
main's master pointer. Evaluates if the list has zero nodes.

*lst = new;

Executes only if the list is empty. Reaches across the scope wall using
the double pointer and permanently overwrites main's master pointer to
hold the address of the new node.

return ;

Stops function execution as the node is already successfully added.

last_node = ft_lstlast(*lst);

Executes only if the list has at least one node. Dereferences the double
pointer to pass the starting address (a single pointer) into the helper
function. Stores the returned address of the final node into the local
last_node variable.

last_node->next = new;

Jumps to the physical final node out in the Heap and overwrites its next
variable (which was previously NULL) with the 8-byte memory address of the
new node, linking the chain.

The Deep Theory: Conditional Double Dereferencing
This function illustrates exactly why we need to pass a double pointer 
even when you only want to modify the back of the list.

99% of the time, this function only modifies a node out in the Heap 
(last_node->next = new;), which strictly only requires a single pointer. 
However, because C demands that you handle the 1% edge case where the list is
empty, you must possess the architectural capability to overwrite the master
head variable sitting on the Stack in main. The double pointer is the mandatory
physical bridge required to access and overwrite that Stack memory location.*/

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}
/*
#include <stdio.h>

void	print_list(t_list *head)
{
	while (head != NULL)
	{
		printf("[%s] --> ", (char *)head->content);
		head = head->next;
	}
	printf("NULL\n\n");
}

int	main()
{
	t_list *head = NULL;
	printf("The initial state of master list:\n");
	print_list(head);

	t_list *node1 = ft_lstnew("maga");
	ft_lstadd_back(&head, node1);
	printf("After adding maga:\n");
	print_list(head);
	
	t_list *node2 = ft_lstnew("dudu");
	ft_lstadd_back(&head, node2);
	printf("After adding dudu:\n");
	print_list(head);
}
*/
