/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:33:10 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:33:14 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function Signature: void ft_lstadd_front(t_list **lst, t_list *new)

Intended Mechanics: It takes a new, isolated node and inserts it at 
the very beginning of an existing linked list. It rewires the new node to 
point to the old "first" node, and then updates the master list pointer so it 
knows the new node is now the front of the line.

To understand it better lets assume you are running a main function.

You have an existing node on the Heap. Let's say the Operating System put it 
at memory address 0x800.

You now create a new node. Let's say the OS put it at memory address 0x900.

In your main function, you have a pointer variable keeping track of the 
start of your list. We will call it head. Because head is a local variable, 
it lives on the Stack. Let's say it lives at memory address 0x50.

Here is what your RAM looks like right before you call the function:

--------------- IN MAIN (The Stack) ---------------
Address: 0x50
Name:    head
Value:   0x800        <-- It stores the address of the first node.

--------------- ON THE HEAP -----------------------
Address: 0x800 (The Old First Node)
content: "Apple"
next:    NULL

Address: 0x900 (The Brand New Node)
content: "Banana"
next:    NULL

Passing the Variables

Now, you call your function from main: ft_lstadd_front(&head, new_node);

Look at what you just passed to the function parameters:

lst gets the address of head = 0x50

new gets the address of the new node = 0x900

3. Executing the Two Lines of Code
Now we just run your code, substituting the variables for the literal
hex addresses.

Line 1: new->next = *lst;

*lst means: "Go to address 0x50 and read the value inside it."
The value inside is 0x800.

The code becomes: new->next = 0x800;

What happens: You go to your new node at 0x900, and you write 0x800 into
its next variable. The new node now successfully points to the old node.

Line 2: *lst = new;

new is 0x900.

*lst means: "Go to address 0x50, and overwrite the value inside it."

The code becomes: *lst = 0x900;

What happens: You physically overwrite the variable in main. It used to
say 0x800. Now it says 0x900.

4. The Result
The function ends.
Back in main, you tell printf to print the first item in the head list.
The computer looks at head (at 0x50). It reads the value: 0x900. It goes 
to 0x900, and it prints "Banana".

Returns: Nothing (void). It alters the memory connections directly.

The Logic (Pseudo-code)
1. If eithr the master pointer address or the new node doesn't exist, abort.
2. Hook the new node's 'next' to what the current first node of the list is.
3. Update the master pointer (*lst) to point to the new node.

Important Theory
Why is head a pointer in the first place?
This is the real question. Why don't we just put the actual struct in main? 
Why is head a pointer (t_list *) instead of just a regular struct (t_list)?

If you wrote t_list head; in main, the 16-byte box would be built permanently 
on the Stack.

The Stack is rigid. It is very hard to resize or shift things around.

If you wanted to add a new node to the front, you would have to physically 
copy 16 bytes of data from the Heap, overwrite the 16 bytes on the Stack, and
shuffle everything else down. It would be incredibly slow.

Instead, we put all the 16-byte boxes out on the Heap (where there is infinite
space),and we only keep a tiny, lightweight 8-byte arrow (the pointer head) on 
the Stack to point to whichever box is currently first.

Because the variable we are keeping in our head is a pointer, 
we must use a pointer to a pointer to change where it points! 
Why must we use pointer to pointer ? Because C is a "Pass-By-Value" language. 
Whenever you pass a variable into a function, C refuses to give the function 
the original item. It makes a photocopy of it and hands the photocopy to the 
function. Thus, to change a variable, you must pass a pointer to that variable.

Note on syntax:
Our head here is only an 8-byte memory address (like 0x800). It does not 
physically contain content or next. So how are we doing head->content and 
head->next ?

The secret lies in what -> actually does under the hood. It is a built-in 
shortcut that performs two separate actions at the same time:
a jump and a grab.

The Long Way: (*head).content
If the arrow operator did not exist, you would have to write this syntax 
every single time:(*head).content

Here is the mechanical breakdown of those two steps:

The Jump (*head): The asterisk tells the compiler to dereference the pointer. 
It reads the address 0x800, travels across the RAM to the Heap, and physically 
stands in front of the massive 16-byte t_list box.

The Grab (.content): The dot operator is used on physical structs. Now that you 
are standing in front of the physical box, the dot tells the compiler to reach 
inside and grab the specific content variable.

The Shortcut: head->content
Because C programmers have to interact with pointers to structs constantly, 
writing (*pointer).member over and over gets tedious. Furthermore, 
because of C's strict mathematical order of operations, if you forget the 
parentheses and write *head.content, the compiler crashes.

To fix this, the creators of C invented the -> operator.

When you write head->content, the compiler instantly translates it into 
(*head).content.
*/

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <stdlib.h>

void print_list(t_list *head)
{   
    // We loop through the list until we hit the NULL pointer at the end
    while (head != NULL)
    {
        printf("[%s] -> ", (char *)head->content);
        head = head->next;
    }
    printf("NULL\n\n");
}

int main(void)
{
    // Step A: Create our master pointer. We start with an empty list.
    t_list *head = NULL;

    printf("Starting state (Empty List):\n");
    print_list(head);

    // Step B: Build the first car and add it.
    t_list *node1 = ft_lstnew("Apple");
    ft_lstadd_front(&head, node1);

    printf("After adding Apple:\n");
    print_list(head);

    // Step C: Build a second car and push it to the front.
    t_list *node2 = ft_lstnew("Banana");
    ft_lstadd_front(&head, node2);

    printf("After adding Banana to the front:\n");
    print_list(head);

    // Step D: Build a third car and push it to the front.
    t_list *node3 = ft_lstnew("Cherry");
    ft_lstadd_front(&head, node3);

    printf("After adding Cherry to the front:\n");
    print_list(head);

    return (0);
}
*/
