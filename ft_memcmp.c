/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:38:37 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/16 16:31:58 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function Signature: int ft_memcmp(const void *s1, const void *s2, size_t n)

Intended Mechanics: It takes two raw memory addresses and scans them left-
to-right, byte by byte. It stops either when it hits the n byte limit, or 
when it finds two bytes that do not match.

Returns: 0 if the memory blocks are identical up to n bytes. If different, it 
returns the mathematical difference of the first mismatched byte pair.

The Traps & Fatal Bugs
The unsigned mandate: Memory must be interpreted as unsigned char. If you cast 
the pointers to a standard signed char, values greater than 127 will be 
interpreted as negative numbers. This completely breaks the subtraction logic 
at the end and returns the wrong mathematical difference.

The Null Pointer Crash: memcmp does not protect against invalid memory. If s1 
or s2 are NULL and n is greater than 0, the function will attempt to read from 
a non-existent address and trigger a Segmentation Fault.

The Sequence Trap: If you flip the conditions in your while loop to 
ptr1[i] == ptr2[i] && i < n, the program will read the memory array before 
checking if it crossed the boundary limit n, resulting in Out-of-Bounds read.

The Logic (Pseudo-code)
1. Declare an index counter (i) and two 1-byte read-only pointers.
2. Cast the generic void pointers s1 and s2 into const unsigned char pointers.
3. Initialize i to 0.
4. SCAN LOOP: While i is less than n AND the byte at ptr1[i] matches ptr2[i]:
   a. Increment i by 1.
5. If the loop broke because i reached n:
   - Return 0 (The blocks are identical).
6. Otherwise (the loop broke early due to a mismatch):
   - Return the mathematical difference: (ptr1[i] - ptr2[i]).

Line-by-Line Breakdown
const unsigned char *ptr1; / const unsigned char *ptr2;

Sets up 1-byte pointers to traverse the memory safely. Using unsigned ensures 
we are comparing pure magnitude values (0 to 255).

ptr1 = s1; / ptr2 = s2;

Assigns the incoming generic memory addresses to local traversable pointers.

while (i < n && ptr1[i] == ptr2[i])

Checks the array boundary (i < n) first. If safe, it accesses the arrays and 
compares the data.

i++;

Advances the index to the next byte in both arrays.

if (i == n)

Evaluates why the loop stopped. If i reached n, the scan completed without 
finding any mismatched data.

return (0);

Returns 0, confirming a perfect match.

return (ptr1[i] - ptr2[i]);

If i is less than n, a mismatch triggered the loop exit. Calculates and 
returns the exact integer difference between the two differing bytes.

The Theory: Short-Circuit Evaluation
Why doesn't ptr1[i] == ptr2[i] cause a memory crash when i reaches exactly n?

C utilizes a concept called Short-Circuit Evaluation. When the compiler 
evaluates a logical && (AND) statement, it reads strictly from left to right.

If the left side of the equation (i < n) evaluates to False, the program 
logically knows that the entire combined statement can never be True. Because 
it already knows the final answer, it immediately stops evaluating and skips 
the right side entirely. It never executes the memory read at ptr1[i], which 
acts as a built-in safety mechanism against out-of-bounds array access.*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	i = 0;
	while (i < n && ptr1[i] == ptr2[i])
		i++;
	if (i == n)
		return (0);
	else
		return (ptr1[i] - ptr2[i]);
}

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", ft_memcmp("abcd", "ab", 3));
	printf("%d\n", memcmp("abcd", "ab", 3));
}
