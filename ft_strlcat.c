/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:50:10 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/15 19:50:58 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strlcat function takes a source string and attaches it to the end of a 
destination string. Just like strlcpy, it forces you to provide the total size 
of the destination buffer (dstsize). It finds the end of the dst string, starts 
pasting src right there, and guarantees it will stop before overflowing the 
buffer, leaving exactly one byte free to cap it with a '\0'.

The Traps & Edge Cases
The "Un-terminated Destination" Trap: What if the dst buffer is filled with 
garbage memory and doesn't actually have a '\0' in it? Standard strcat would 
run infinitely and crash. Your code safely stops looking for the end of dst 
once it hits dstsize.

The dstsize == 0 Gotcha: If dstsize is 0, the function cannot modify dst at 
all. It must instantly return src_len (because 0 + src_len = src_len).

The Return Value: "If my dstsize is 5, my dst length is 10, and my 
src is 3, what does it return?" "It returns 8 (dstsize + src_len). If dstsize 
is smaller than or equal to the length of dst, the function considers the 
destination 'full' and physically unreachable. It returns the size of the 
buffer it was allowed to look at plus the length of the source."

The Logic (Pseudo-code)
1. Calculate the full length of the source string.
2. Find the end of the destination string (count its length). 
   - BUT do not count past 'dstsize'. If you hit 'dstsize', stop counting.
3. Is the destination already completely full (dst_len == dstsize)?
   - YES: Abort concatenation. Return (dstsize + src_len).
   - NO: Continue to step 4.
4. Copy characters from 'src' to the end of 'dst'. Keep copying AS LONG AS:
   - We haven't hit the end of 'src'.
   - We still have room in 'dst' (saving 1 spot for the stop sign).
5. Add the final stop sign ('\0') to the newly glued string.
6. Return the length of string we TRIED to create (original dst_len + src_len).

Line-by-Line Breakdown
size_t dst_len = 0; size_t src_len = ft_strlen(src); size_t i = 0;

We set up our variables. We calculate src_len immediately because we need it 
for the final return value no matter what happens.

while (dst[dst_len] != '\0' && dst_len < dstsize)

dst_len++

We walk down the dst string to find its end. The && dst_len < dstsize is the 
safety net: if the string is missing a null-terminator, we stop searching 
once we hit the border of the buffer.

if (dst_len == dstsize)

return (dstsize + src_len);

The abort switch. If we hit the boundary before finding a '\0', it means there 
is physically no room to glue anything. We return the size we were given plus 
the length of src.

while ((dst_len + i) < (dstsize - 1) && src[i] != '\0')

The Glue Loop.

dst_len + i is the exact current position in the destination buffer.

< (dstsize - 1) ensures we don't write out of bounds and we leave one byte for 
the null-terminator.

dst[dst_len + i] = src[i]; i++;

Drop the character from src into the correct index of dst.

dst[dst_len + i] = '\0';

Cap the newly extended string with a null-terminator.

return (dst_len + src_len);

We return the theoretical total length of the glued string (the original length 
of dst plus the full length of src).*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	src_len = strlen(src);
	j = 0;
	dst_len = 0;
	while (dst_len < dstsize && dst[dst_len] != '\0')
		dst_len++;
	if (dstsize == 0)
		return (src_len);
	if (dstsize == dst_len)
		return (dstsize + src_len);
	else
	{
		while ((dstsize - 1) > (dst_len + j) && src[j] != '\0')
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
		return (dst_len + src_len);
	}
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int   main()
{
   char dst[8] = "GMBH";
   printf("%zu\n", ft_strlcat(dst, "berlin", 8));
   return (0);
}
*/
