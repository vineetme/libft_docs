/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:39:42 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/16 18:22:33 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Function Signature: void *ft_memmove(void *dst, const void *src, size_t len)

Intended Mechanics: It copies len bytes from the src memory address to the 
dst memory address. Crucially, it calculates the relative positions of src and 
dst in memory before copying. Based on this calculation, it decides whether to 
copy the data front-to-back (left-to-right) or back-to-front (right-to-left) to 
prevent overwriting data before it can be copied.

Returns: The original starting address of dst.

The Traps & Fatal Bugs
The Destructive Overlap: If dst sits slightly after src in memory, and you copy 
front-to-back, you will overwrite the end of your src string with the beginning 
of your src string before the end can be copied. This results in repeating 
gibberish (e.g., "ABABCD" instead of "ABAB").

The Moulinette NULL Trap: The condition if (!dst && !src) is a specific defense 
against 42's Moulinette. Standard memmove expects valid pointers, but the 
testing server will intentionally pass two NULL pointers to see if your code 
crashes. Returning NULL (or dst) immediately passes this edge case.

The Reverse Index Off-by-One: When copying backward, the last byte of an array 
of size len is located at index len - 1. If you start copying at index len, you 
will read/write out of bounds. while (len--) is needed to handle this.

The Logic (Pseudo-code)

1. Guard Clause: If both dst and src are NULL, return dst immediately.
2. Cast dst and src to 1-byte unsigned char pointers for safe traversal.
3. DIRECTION CHECK: Compare the memory addresses of dst and src.
4. If dst is physically BEFORE src in memory (dst < src):
   a. NO OVERLAP DANGER. Copy front-to-back (index 0 up to len - 1).
5. If dst is physically AFTER src in memory (dst > src):
   a. OVERLAP DANGER. Copy back-to-front. 
   b. Start at the very last byte (len - 1) and copy downwards to index 0.
6. Return the original dst pointer.

Line-by-Line Breakdown
if (!dst && !src)

The edge-case shield. If both pointers point to 0x0, there is nothing to move 
and nowhere to put it. It exits safely.

s = (unsigned char *)dst; / l = (const unsigned char *)src;

Casts the generic pointers into 1-byte arrays to allow byte-by-byte copying.

if (s < l)

If dst starts at a lower memory address than src, the front of dst will 
never collide with the uncopied back of src.

while (i < len) { s[i] = l[i]; i++; }

Standard front-to-back copy. (Exactly identical to the logic in ft_memcpy).

else

If dst >= src, there is a high risk that copying left-to-right will overwrite 
the end of the src string.

while (len--)

It checks if len is greater than 0, then immediately subtracts 1 before entering 
the loop body. If len was 5, it enters the loop with len set to 4 (the exact 
correct index for the last element in a 5-byte array).

s[len] = l[len];

It copies the last byte, then the second-to-last byte, marching backward until 
len hits 0.

return (dst);

Returns the generic void pointer to the start of the destination memory.*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s;
	const unsigned char	*l;
	size_t				i;

	if (!dst && !src)
		return (dst);
	s = (unsigned char *)dst;
	l = (const unsigned char *)src;
	i = 0;
	if (s < l)
	{
		while (i < len)
		{
			s[i] = l[i];
			i++;
		}
	}
	else
	{
		while (len--)
		{
			s[len] = l[len];
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char dst[] = "maga";
	printf("%s\n", dst);
	char src[] = "dudu";
	ft_memmove(dst, src, 4);
	printf("%s\n", dst);

	char dst1[] = "maga";
    printf("%s\n", dst1);
    char src1[] = "dudu";
    memmove(dst1, src1, 4);
    printf("%s\n", dst1);

	return (0); 
}
*/
/*Testing this requires declaring dst and src as array in the stack,
not string literal, which is in the .rodata.
*/
