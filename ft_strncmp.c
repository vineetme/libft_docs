/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vineet <vineet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 13:22:02 by vineet            #+#    #+#             */
/*   Updated: 2026/05/13 14:28:53 by vineet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The ft_strncmp function compares two strings, s1 and s2, character by character. 
However, it comes with a strict leash: it will only compare up to a maximum of n 
characters.

If the strings are completely identical up to that point, it returns 0. If it 
finds a difference, it stops instantly and returns the mathematical difference 
between the first two characters that failed to match.

The Traps & Edge Cases
The Extended ASCII Trap: Standard ASCII characters (like 'A' or 'a') go from 0 to 
127. But memory can hold values up to 255 (like special accents é, ñ). If you use 
a normal signed char, anything above 127 overflows into negative numbers. If you 
subtract a negative number from a positive number, your math breaks entirely and 
you return the wrong result.

The n == 0 Gotcha: If the user passes 0 for n, it means "Compare zero bytes." The 
correct answer is always 0 (they match). If your function tries to check index 0 
first, it will fail.

The Double \0 Illusion: What if s1 is "cat" and s2 is "catastrophe", and n is 10?
When i hits 3, s1[3] is \0 but s2[3] is 'a'. 

The Logic (Pseudo-code)
1. Did the user ask to compare 0 characters? 
   - YES: Return 0 immediately.
2. Start at the first character of both strings.
3. Keep walking forward AS LONG AS all three conditions are met:
   - We haven't hit the limit 'n'.
   - The characters in both strings are identical.
   - We haven't hit the end of string 1 ('\0').
4. The loop stopped. Why did it stop?
   - Did we hit the limit 'n'? 
     - YES: The strings are identical up to the allowed limit. Return 0.
   - NO: We stopped because we found a difference (or hit the end).
5. Grab the two mismatched characters, convert them to strictly positive numbers, 
and subtract them. Return the result.

Line-by-Line Breakdown
int ft_strncmp(const char *s1, const char *s2, size_t n)

Takes two read-only strings and an unsigned limit n. Returns an int (can be 
negative, positive, or zero).

if (n == 0) return (0);

The immediate bail-out. We do absolutely nothing if n is 0.

while (i < n && s1[i] == s2[i] && s1[i] != '\0')

The triple-lock loop.

i < n: Keeps us inside the boundary.

s1[i] == s2[i]: Ensures we only move forward if the characters match.

s1[i] != '\0': Prevents us from walking off the edge of s1. (Note: We don't 
need s2[i] != '\0' because if s2 ends first, the s1[i] == s2[i] check will 
automatically fail anyway!)

i++;

Step forward to the next index.

if (i == n) return (0);

If the loop broke because our counter i reached the limit n, it means we 
successfully verified every byte up to the limit without finding a mismatch.

return ((unsigned char)s1[i] - (unsigned char)s2[i]);

The core calculation. We grab the specific memory boxes that failed to match. 
We forcefully cast them to unsigned char (so they are strictly positive numbers 
between 0 and 255), and subtract them.

The Theory
The Implicit int Promotion
An evaluator might look at your last line and ask: "Wait. You are subtracting an 
unsigned char from an unsigned char. In C, an unsigned number cannot be negative. 
So if s1 is 'A' (65) and s2 is 'Z' (90), wouldn't 65 - 90 cause an underflow and 
return a massive positive number?"

Your Defense: "No, because of C's implicit integer promotion. Before the compiler 
actually does the mathematical subtraction, it sees that the return type of the 
function is a standard int. It takes those two unsigned char values (which are 
1-byte numbers) and automatically promotes them into standard 4-byte signed int 
registers inside the CPU. So the math happens as normal integers (65 - 90), safely 
resulting in -25.*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t  i;

    i = 0;
    if (n == 0)
        return (0);
    while (i < n && s1[i] != '\0' && s1[i] == s2[i])
        i++;
    if (i == n)
        return (0);
    else
        return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main()
{
    printf ("%d\n", strncmp("bob", "bobby", 4));
    printf ("%d\n", ft_strncmp("bob", "bobby", 4));
}
*/
