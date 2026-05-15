/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 19:55:08 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/15 19:55:10 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strrchr function stands for "String Reverse Character". It searches a 
string s to find the last occurrence of a specific character c. Instead of 
starting at the beginning and reading left-to-right, it jumps to the end of the
string and scans right-to-left.

If it finds the character, it doesn't return the index (like 4 or 10); it 
returns a pointer directly to that specific character's memory address inside 
the string. If it doesn't find the character, it returns NULL.

The Traps & Edge Cases
The "Find Stop Sign" Trap: What if the user calls ft_strrchr("Hello", '\0')? 
The null-terminator is technically part of the string's memory allocation. If 
the user asks to find '\0', the function MUST return a pointer to the 
invisible '\0' at the very end. If you cannot just return NULL.

The Unsigned Underflow: size_t is an unsigned integer. It cannot be negative. 
If we write a loop like while (len >= 0) and subtract 1 from 0, the number 
doesn't become -1. It wraps around to 18,446,744,073,709,551,615. The loop 
becomes infinite, and the program Segfaults. 

Why must we use size_t and not simply int ? Because a string's length cannot 
physically be negative, but it can be massively huge. size_t on a 64-bit 
Mac is a 64-bit unsigned integer. It doesn't waste a bit on negative numbers. 
Its maximum value is 18.4 Quintillion. It guarantees that no matter 
how much RAM your computer has, size_t can count every byte of it safely.

Also ft_strlen returns a size_t. If you write int len = ft_strlen(s);, the 
compiler sees you taking a massive 64-bit unsigned number and trying to cram 
it into a smaller 32-bit signed box and gives mplicit conversion loses 
integer precision and changes signedness error.

String in NULL (that does not mean its "empty", it means it doesn't exist): 
The function must crash with a seg fault as thats the original behaviour. 

Also, important note: If you pass a string to strrchr that is missing its 
null-terminator, you trigger a Buffer Over-read.

The three common ways one can accidentally create and pass a "string" without 
a null-terminator.

1. The Manual Array Trap
When you create a string using double quotes, the compiler adds the \0. But 
if you build an array character by character, the compiler assumes you know 
exactly what you are doing and does not help you.

2. If you declare an array with a specific size, and you fill it with a double-
quote string of that exact same size, the C compiler will drop the null- 
terminator to make it fit.

3. When you ask the OS for memory using malloc, it does not clean the memory 
first. It just hands you a chunk of RAM that is filled with leftover garbage 
from other programs.

The Logic (Pseudo-code)
1. Find the total length of the string (this tells us where the end is).
2. Is the character we are looking for the stop sign ('\0')?
   - YES: Return a pointer to the exact memory address of the stop sign.
   - NO: Proceed to step 4.
3. While we haven't reached the beginning of the string:
   - Take one step backwards.
   - Is the character at this step the one we are looking for?
     - YES: Return a pointer to this character.
4. If we check every single box and find nothing, return NULL.

Line-by-Line Breakdown
char *ft_strrchr(const char *s, int c)

Takes a read-only string (const char *s) and the character to find (int c).

len = ft_strlen(s);

We calculate the length. If the string is "42", len is 2.

if ((char)c == '\0') return ((char *)&s[len]);

The edge case. If they want the '\0', we find it at exactly s[len].

&s[len] gets the memory address of that box.

(char *) is a "typecast". We are forcefully ripping the const lock off the 
pointer so we can return it as a normal, writable char *.

while (len > 0)

We start our reverse engine. We only run this if we are strictly greater 
than 0.

len--;

Crucial step. We step backward before we check. If the length is 2, the 
last readable character is at index 1. So we immediately drop len from 2 
to 1.

if (s[len] == (char)c)

We cast c to a char (to make sure the memory comparison is exact) and check 
if the current box holds our target.

return ((char *)&s[len]);

If we found it, we grab the memory address of this exact box (&), rip off 
the const lock ((char *)), and hand it back to the user.

return (NULL);

The loop finished, we hit index 0, and we never found the character. 
Return NULL.

5. The Theory
Why does it take an int c instead of a char c? Why would a function looking 
for a character ask for an integer?

Before the modern ANSI C standard was written, When you passed a char into
a function, the compiler automatically 'promoted' it to an int because older 
computer processors were faster at pushing word-sized integers into memory 
registers. The standard library kept int c so they wouldn't break millions 
of lines of code written in the 1970s.

The const Cast-Away
Notice how the function takes a const char *s (promising not to change the 
string), but it returns a regular char * (a pointer that can change the string). 
Isn't returning a non-const pointer a security flaw?"

"Yes, technically it is a flaw in the C standard library design. strrchr 
assumes that the programmer who called the function originally owned the 
string and has the right to modify it. We are forced to cast it to (char *) 
to respect the official standard prototype, even though it strips away the const 
protection."*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;

	len = strlen(str);
	if ((char)c == '\0')
		return ((char *)&str[len]);
	while (len > 0)
	{
		len--;
		if (str[len] == (char)c)
			return ((char *)&str[len]);
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>
#inclide <strings.h>

int   main()
{
   printf("%s\n", strrchr("ozne", 'o' ));
   printf("%s\n", ft_strrchr("ozne", 'o' ));
}
*/
