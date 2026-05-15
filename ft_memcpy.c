/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vineet <vineet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 09:53:06 by vineet            #+#    #+#             */
/*   Updated: 2026/05/14 12:49:23 by vineet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function Signature: void *ft_memcpy(void *dst, const void *src, size_t n)

Parameters:

dst (void *): A generic pointer to the starting memory address where the data 
will be written. This memory block must be pre-allocated and large enough to 
safely hold at least n bytes.

src (const void *): A read-only generic pointer to the starting memory address 
containing the raw data to be copied. The const qualifier guarantees the source 
data will not be mutated.

n (size_t): An unsigned integer representing the exact, absolute number of bytes 
to transfer from src to dst.

Mechanics:
The function strips the generic void * typing by casting both pointers to 
unsigned char * (and const unsigned char *). This forces the compiler to 
treat both memory blocks as arrays of 1-byte containers. It then executes 
a strict left-to-right linear loop, reading the raw byte at src[i] and 
overwriting the byte at dst[i], repeating exactly n times. It assumes the 
memory blocks are entirely isolated from one another.

Returns: * Returns the original dst pointer (void *).

If both dst and src are passed as NULL, it immediately returns dst (which 
evaluates to NULL) to prevent a segmentation fault.

2. The Traps & Edge Cases
The NULL Trap: The standard C library memcpy is legally allowed to 
crash if you pass it NULL pointers. However, the 42 grading bot intentionally 
passes two NULL pointers to test your defensive programming.

The const Promise: Because src is const void *, casting it directly to unsigned 
char * would trigger a compiler warning for discarding the read-only qualifier. 
It needs to be cast to a const unsigned char *l, preserving the hardware-level 
promise not to alter the source memory.

The Overlap Vulnerability (Undefined Behavior): memcpy reads and writes strictly 
from index 0 up to n-1. If the src and dst arrays physically overlap in RAM, 
and dst starts slightly ahead of src, the left-to-right copying process will 
overwrite the end of the src data before the loop has a chance to read it. This 
permanently corrupts the data.

The Logic (Pseudo-code)
1. Receive parameters: dst (writable memory), src (read-only memory), and n 
(byte limit).
2. Security Check: If dst is NULL AND src is NULL, immediately return dst.
3. Cast dst to a 1-byte writable pointer (unsigned char *).
4. Cast src to a 1-byte read-only pointer (const unsigned char *).
5. Initialize an iterator (i) to 0.
6. Loop while i is strictly less than n:
   a. Read the 1-byte value located at src[i].
   b. Write that exact 1-byte value into dst[i].
   c. Increment i by 1.
7. Return the original, unmodified dst address.

Line-by-Line Breakdown
void *ft_memcpy(void *dst, const void *src, size_t n)

unsigned char *s; / const unsigned char *l;

Declaring local 1-byte pointers. unsigned is required to prevent the CPU's 
sign-extension logic from corrupting raw binary data.

if (!dst && !src) return (dst);

The 42-specific edge-case shield against double-NULL pointer evaluation.

s = (unsigned char *)dst; / l = (const unsigned char *)src;

The actual typecasting. This defines the step size for pointer arithmetic.
The compiler now knows that s[1] means "move exactly 1 physical byte forward 
in RAM."

while (i < n)

The boundary loop ensuring exactly n bytes are processed.

s[i] = l[i];

The core engine. It physically reads the raw byte from the source memory box 
and overwrites whatever currently exists in the destination memory box.

i++;

Advances the iterator to the next byte block.

return (dst);

The ISO C Standard requires returning the pointer to the start of the 
destination block. You return the original void *dst, not the locally 
incremented unsigned char *s.

5. The Deep Theory
Why doesn't memcpy handle overlapping memory?
In standard C, memcpy is optimized purely for raw speed. Modern compilers 
detect memcpy calls and replace them with highly aggressive Assembly 
instructions (like SIMD vectors) that grab massive chunks of memory at 
once—moving 64, 128, or even 256 bits in a single microscopic CPU cycle—rather 
than actually executing a slow byte-by-byte while loop.

Checking if memory addresses mathematically overlap requires extra CPU cycles 
and branching logic. The creators of C decided memcpy should be the "fast and 
dangerous" option. It blindly assumes the programmer has already verified the 
memory blocks are isolated. If the programmer suspects the memory might overlap, 
they are legally required by the C standard to use memmove instead, which is 
slightly slower but mathematically calculates a safe copy direction to prevent
corruption.*/
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*
int	main(void)
{
	unsigned char dst[6] ={0};
	const char src[] = {48,48,48};
	printf("%s\n", (char *)ft_memcpy(dst, src, 2));
	return (0);
}
*/
