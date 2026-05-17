/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:37:42 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:37:45 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The Problem with Arrays:
An array requires contiguous memory. If you want an array of 1000 integers,
you must find a single unbroken block of memory large enough to hold all 1000.

If you want to add 1 more item (make it 1001), you cannot just tack it on the
end if another variable is blocking it. You have to malloc a brand new array 
of 1001, copy everything over, and free the old one.

The Solution: What if, instead of a rigid block, every integer was just 
floating randomly out in the massive ocean of the Heap? How would you keep 
track of them?

We need a container that holds two things:
1. The Data (The integer/any other data).
2. The pointer to the next memory address containing the next data.

But Standard C variables (int, char) only hold one thing. In C, when you want 
to build a custom container that holds multiple different variables, you build 
a struct (short for structure).

This is what your libft.h contains

typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;

Let's break this down:

void *content: This is where you store your data. Why is it a generic 
void * instead of a char *? Because we want this list to be universal. 
A void * means this box can hold anything. It can hold a string, a 
pointer to an integer, or even a pointer to another struct.

struct s_list *next: This is a pointer variable. Its only job is to hold 
the memory address of the next struct in the chain.

typedef and t_list (The Nickname): Writing struct s_list every single time 
you want to make a node is annoying. typedef tells the compiler: "Whenever 
I type t_list, just pretend I typed struct s_list."

Now let's come to the actual function:

Function Signature: t_list *ft_lstnew(void *content)

Intended Mechanics: It asks the Operating System for enough memory to hold 
exactly one t_list structure. It then packs the user's data (content) into 
the node and explicitly caps off the end by setting the next pointer to NULL.

Returns: A pointer to the newly minted node on the Heap. If malloc fails, 
it returns NULL.

The Traps & Fatal Bugs
The Wild Pointer Trap: In C, malloc provides raw, uninitialized memory. 
If you forget the line new_node->next = NULL;, that pointer will hold 
whatever garbage address was previously in that memory slot. Later, when 
you try to loop through your linked list, your program will try to jump to 
that garbage address and instantly Segfault.

The Shallow Payload: Notice that new_node->content = content; does not use 
malloc or ft_strdup. It is a simple assignment. It only copies the pointer, 
not the physical data. If the programmer passes a local Stack variable as 
the content, and that variable gets destroyed later, your linked list will 
be pointing to dead memory. The caller is responsible for ensuring the 
contentstays alive.

The . vs -> Crash: Because new_node is a pointer to a struct, you must use 
thearrow operator (->) to reach inside it. If you wrote new_node.content, the 
compiler would throw a fatal error because you are trying to access a pointer 
as if it were a physical object.

The Logic (Pseudo-code)
1. Declare a pointer capable of holding a t_list struct.
2. ALLOCATE: Ask the Heap for exactly the size of one t_list.
3. GUARD: If the Heap refuses (returns NULL), return NULL.
4. Reach into the new node and set 'content' variable to the provided data.
5. Reach into the new node and set 'next' pointer to NULL ("end of line").
6. Return the memory address of the finished node.

Line-by-Line Breakdown
t_list *new_node;

Creates a local variable that will store the memory address of our 
new structure.

new_node = (t_list *)malloc(sizeof(t_list));

The system call. sizeof(t_list) tells the compiler to calculate exactly 
how many bytes the struct requires(usually 16 bytes on a 64-bit system:
8 bytes for the void * and 8 bytes for the t_list *. It safely casts the 
returned generic void * into a t_list *.

if (!new_node) return (NULL);

The standard crash shield against a failed memory allocation.

new_node->content = content;

The arrow operator (->) dereferences the new_node pointer and accesses 
the content field inside the struct. It drops the user's payload (which
is a generic void *, meaning it can be a string, an int array, or even 
another struct) into the box.

new_node->next = NULL;

Crucial step. This defines this node as an isolated island. It explicitly
states that there is no subsequent node attached to it yet.

return (new_node);

Hands the pointer to this newly created structure back to the user.*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void    *str;
    t_list  *my_node;
	t_list	*my_nodeor;

    str = "magadudu";
    my_node = ft_lstnew(str);
    if (my_node == NULL)
        return (1);

    // 4. REACH INSIDE THE BOX to print the content.
    // We cast it to (char *) so printf knows it's reading text.
    printf("%s\n", (char *)my_node->content);

    // 5. Clean up the Heap memory that ft_lstnew created
    free(my_node);

    return (0);
}
*/
