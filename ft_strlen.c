/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vineet <vineet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 09:06:01 by vineet            #+#    #+#             */
/*   Updated: 2026/05/12 10:13:17 by vineet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strlen (string length) function counts how many "characters" are in a 
"string" and "returns" that "number". 
It starts at the beginning of the string and counts one by one until it hits the 
hidden "stop sign" at the end of the string. 
Importantly, it does not count the stop sign itself.

The Traps & Edge Cases
The NULL Pointer Trap: What happens if you call ft_strlen(NULL)? Your program 
will instantly Segfault (crash).

Then why didn't we add if (!s) return (0); to protect against NULL?

Because the standard C library strlen does not protect against NULL. If you pass 
NULL to the real strlen, it segfaults. The goal of Libft is to mimic the original 
functions exactly, bug-for-bug, crash-for-crash.

The Missing Null-Terminator: If the string you pass to ft_strlen is missing its 
final stop sign (meaning it's just a raw array of characters), this function 
will blindly keep reading memory out of bounds until it randomly hits a 0 
somewhere else in your RAM, or crashes.

The Logic (Pseudo-code)
Plaintext
1. Create a counter and set it to 0.
2. Look at the character at the current counter's position.
3. Is it the stop sign ('\0')?
   - NO: Add 1 to the counter. Go back to step 2.
   - YES: Stop the loop.
4. Return the counter.

Line-by-Line Breakdown
size_t ft_strlen(const char *s)

size_t: The return type. It is an unsigned integer used specifically for 
representing sizes of things in memory.

const: A strict promise to the compiler to onl read the string, not alter or 
delete any characters inside it.

char *s: The pointer to the first character of the string we want to measure.

size_t i;

Declares our index/counter variable. We use size_t here instead of int so it 
matches the function's return type perfectly.

i = 0;

Sets our starting position to the very first character of the string (index 0).

while (s[i] != '\0')

s[i] accesses the character at position i.

'\0' is the null-terminator.

This translates to: "As long as the current character is NOT the null-terminator, 
keep doing the code inside the block."

i++;

Moves our counter up by 1. We now look at the next character.

return (i);

Once the loop breaks, i holds the exact number of characters we walked past. 
We return that number.

The Theory
What actually is a string in C?
In languages like Python or Java, a string is an object that knows its own 
length. In C, a string is literally just a line of consecutive bytes in memory. 
The computer has absolutely no idea how long the string is.

The Null Terminator ('\0')
Because the computer doesn't know the length, the creators of C decided on a 
universal rule: Every string must end with a byte composed entirely of zeros. 
In the ASCII table, the character value of 0 is represented as '\0' (the Null 
character). Without this, ft_strlen would be impossible to write.

Why size_t instead of int?
An int can be negative. Can a string have a length of -5? No.
Also, a standard int usually maxes out at around 2.1 billion. On a modern 64-bit 
machine, size_t can hold a number up to 18 quintillion. If you have a massive 
text file loaded into memory, int might overflow, but size_t is guaranteed by the 
compiler to be large enough to measure any object your system's memory can hold.*/

#include <stddef.h>
#include <stdio.h>

size_t   ft_strlen(const char *str)
{
   size_t   i;

   i = 0;
   while (str[i] != '\0')
   {
      i++;
   } 
   return (i);
}

int   main()
{
    printf("%zu\n", ft_strlen("a"));
    printf("%zu\n", ft_strlen("abc"));
    printf("%zu\n", ft_strlen("42 toscana"));
    printf("%zu\n", ft_strlen(" "));
    printf("%zu\n", ft_strlen("\n"));
    printf("%zu\n", ft_strlen("\0"));
    printf("%zu\n", ft_strlen("0123456789"));
    printf("%zu\n", ft_strlen(": !@#$%^&*()"));
    printf("%zu\n", ft_strlen("Long string test for buffer check............................"));
    return (0);
}
