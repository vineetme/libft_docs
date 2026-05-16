/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:38:21 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:38:24 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function Signature: void *ft_memchr(const void *s, int c, size_t n)

Intended Mechanics: It takes a starting memory address and scans forward, byte 
by byte, searching for a specific target value (c). It stops either when it 
finds the first instance of that value or when it hits the strict n byte limit.

Returns: A pointer to the memory address where the matching byte was found.
If the byte is never found within the n byte limit, it returns NULL.

The Traps & Fatal Bugs
The int c Comparison Trap: The target character is passed into the function as
a 32-bit int, but memory is scanned as 8-bit unsigned char boxes. If you compare
them directly without casting c to (unsigned char), a negative number passed as
c could result in a false negative during comparison due to how C handles sign
extension.

The String Illusion: memchr is entirely blind to text. Unlike strchr, which 
stops the moment it hits a \0 (Null Terminator), memchr ignores it entirely.
If n is 50, and the string is only 5 characters long, it will march right past
the \0 and read 44 bytes of adjacent memory.

The Missing Address-Of Operator: If you wrote return ((void *)ptr[i]); instead
of return ((void *)&ptr[i]);, the compiler would take the actual character data
(like 97 for 'a') and try to return it as a memory address (0x00000061). When 
the calling program tries to use that fake address, it will instantly crash.

The Logic (Pseudo-code)
1. Declare an index counter (i) and a 1-byte read-only pointer.
2. Cast the generic void pointer s into our const unsigned char pointer.
3. Initialize i to 0.
4. SCAN LOOP: While i is less than n:
   a. Check if the byte at ptr[i] matches the target c (cast to unsigned char).
   b. If it matches, get the memory address of that index and return it.
   c. If it does not match, increment i by 1.
5. If the loop finishes exhausting all n bytes without returning:
   - Return NULL (The target does not exist in this block).

Line-by-Line Breakdown
const unsigned char *ptr;

Sets up a 1-byte pointer to safely traverse the memory block.

ptr = s;

Assigns the generic starting address to our traversable pointer.

while (i < n)

The loop is only allowed to run n times.

if (ptr[i] == (unsigned char)c)

Accesses the raw byte in the memory array. It forcefully downcasts the int c
into an unsigned char to ensure a perfect 8-bit to 8-bit comparison.

return ((void *)&ptr[i]);

The target is found. The & operator gets the physical memory address of that
specific box. It is then cast back to a (void *) to cleanly match the 
function signature's return type.

i++;

Advances the search head to the next byte.

return (NULL);

The loop hit the n limit. It returns the standard C null pointer to 
communicate absolute failure to the calling program.

The Deep Theory: Integer Promotion
Looking at the signature void *ft_memchr(const void *s, int c, size_t n), 
a question arises: If we are searching for a 1-byte character, why is the
parameter int c a 4-byte integer?

This is due to a historic C rule called Integer Promotion.

When C was designed, computer hardware (CPU registers) operated most 
efficiently on whole "word" sizes (like 32-bit or 64-bit blocks). 
Working with tiny 8-bit chunks of memory was actually more computationally
expensive for the processor.

Therefore, the C standard dictates that whenever you pass a small data type 
(like a char or a short) as an argument to a function, the compiler will 
automatically pad it out and "promote" it to a full int for the journey 
into the function.

The function receives the bulky int, but to do the byte-by-byte memory 
scanning, it is up to the programmer to slice it back down to an 8-bit size
using (unsigned char)c before comparing it against the memory array.*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	ptr = s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char s[] = "magadudu";
	char *result = ft_memchr(s, 'u', 8);
	if (result != NULL)
		printf("%s\n", result);
	else
		printf("Not found.\n");
	
	const char s1[] = "magadudu";
    char *result1 = ft_memchr(s1, 'u', 8);
    if (result != NULL)
        printf("%s\n", result1);
    else
        printf("Not found.\n");
    return (0);
}
*/
/*printf %s starts to print	from the given address but doesnt stop after
printing just that, it keeps printing till it finds '\0'.*/	
