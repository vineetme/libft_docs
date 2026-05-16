/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:03:23 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/16 11:33:34 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strlcpy (string length copy) function copies a string from a source 
into a destination buffer. It forces you to specify the exact maximum size of 
the destination (destsize). It guarantees two things: it will never write past 
that size, and it will always put a null - terminator '\0' at the end (unless 
the size is 0). Finally, it returns the total length of the original source 
string, regardless of how much was actually copied.

The Traps & Edge Cases
The destsize == 0 Trap: If the programmer says the destination has a size 
of 0, the function must do absolutely nothing. It cannot even write a null-
terminator, because there is no room. Therefore it needs the if 
(destsize != 0) check.

The Return Value Gotcha: The most common mistake is returning the number of 
characters they copied. Wrong. strlcpy always returns the length of src. Why? 
So the programmer calling the function can check: "Did the return value end 
up being larger than my buffer size? If yes, my string got truncated!"

The Overlap Crash: If the src and dst memory addresses overlap, strlcpy will 
exhibit undefined behavior.

The Logic (Pseudo-code)
1. Set a counter to 0.
2. Did the user give us a destination size greater than 0?
   - NO: Skip to step 5.
   - YES: Continue to step 3.
3. Look at the src string. Keep copying characters to the des AS LONG AS:
   - We haven't hit the source's stop sign ('\0').
   - AND we still have at least 1 empty space left for our final stop sign.
4. Put the final stop sign ('\0') at the end of the newly copied string.
5. Count the length of the ENTIRE original src string and return that number.

Line-by-Line Breakdown
size_t ft_strlcpy(char *dst, const char *src, size_t destsize)

char *dst: The empty box where we are pasting the string.

const char *src: The original string we are copying (locked as const so we 
don't accidentally change it).

size_t destsize: The absolute maximum capacity of dst.

if (destsize != 0)

If the capacity is 0, we bypass the writing process entirely to avoid 
corrupting memory.

while (i < (destsize - 1) && src[i] != '\0')

The dual-engine of the function.

i < (destsize - 1): We keep copying only if we have room. We subtract 1 
from the total size to reserve a mandatory parking spot for the '\0'.

src[i] != '\0': We also stop if we just naturally reach the end of the 
source string before filling the buffer.

dst[i] = src[i]; i++;

Take the character from the source, paste it into the destination, and 
move to the next slot.

dst[i] = '\0';

The safety seal. No matter how the while loop ended (whether it ran out 
of room or ran out of characters), we forcefully cap the string with a 
null-terminator.

return (ft_strlen(src));

We calculate the true length of src and hand it back to the user.

5. The Theory
First came strcpy doesn't ask for size. If you try to copy a 100-character 
string into a 10-character box, strcpy will blindly keep writing the 
remaining 90 characters into adjacent memory. This is a Buffer Overflow. 

Then came strncpy, which asked for a size, but it had a fatal flaw: if 
the source string was longer than the buffer, strncpy wouldn't add a null-
terminator at the end. The string would just bleed into random memory.

strlcpy was invented by OpenBSD developers to be the ultimate, foolproof 
solution. It forces a size limit (preventing buffer overflows) AND it forces 
a null-terminator (preventing runaway strings).*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen (src));
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main()
{
    char dst[15] = "baby";
    printf("%zu\n", ft_strlcpy(dst, "ergo", 3));
    return (0);
}
*/
