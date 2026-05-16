/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:42:43 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:42:47 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function Signature: char *ft_strdup(const char *s)

Intended Mechanics: It measures the exact length of a given string s, asks the
Operating System for a brand new, perfectly sized block of memory on the Heap,
and then copies the entire string (including the invisible Null Terminator)
into that new space.

Returns: A pointer to the newly created clone of the string. If the 
OS runs out of memory & refuses the allocation, it returns NULL.

Traps & Bugs
The + 1 Trap: If you request malloc(count * sizeof(char)), you allocate 
exactly enough space for the visible characters, but zero space for the \0. 
When you run result[i] = '\0' at the end, you write outside the bounds of your 
malloc'd box, corrupting the Heap.

The Unprotected malloc: If the OS refuses to give you memory, malloc returns
NULL. If you don't use if (!result) to catch this, the very next line 
(result[i] = ...) will attempt to write data to address 0x0, causing an 
immediate Segmentation Fault.

The Deep Theory: Shallow Copy vs. Deep Copy
Why does ft_strdup even exist? If you want to copy a string, why can't you 
just write this?  char *new_str = s;

This is called a Shallow Copy. You did not copy the data; you only copied 
the address. You now have two pointers pointing to the exact same physical 
box in memory.

If s was a read-only literal (.rodata), new_str cannot modify it without 
crashing. If you modify new_str, you accidentally overwrite the original
s as well.

ft_strdup performs a Deep Copy. It completely divorces the new string from 
the old one. By generating fresh memory on the Heap and moving the data over
byte-by-byte, it creates a completely independent clone. You can modify,
pass around, or destroy the cloned string without ever affecting the original.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	ptr = malloc (len + 1);
	if (ptr == NULL)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%s\n", ft_strdup("magadudu"));
	printf("%s\n", strdup("magadudu"));
	return(0);
}
*/
