/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vineet <vineet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 18:43:12 by vineet            #+#    #+#             */
/*   Updated: 2026/05/14 09:50:16 by vineet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The ft_memset function takes a block of memory and completely overwrites a 
specified number of bytes (len) with a single, repeating value (c). It doesn't 
care if the memory holds text, numbers, or complex structures; it acts like a 
steamroller, flattening everything in its path with the exact same byte.

The Traps & Edge Cases
The void * Arithmetic Trap: A void * is an "unknown" pointer. The compiler knows 
it points to memory, but it doesn't know how big the boxes are (are they 1-byte 
chars, 4-byte ints, or 8-byte longs?). Because it doesn't know the size, you 
cannot do pointer arithmetic or array indexing (b[i]) on a void *. If you try, 
the compiler will throw a fatal error. 

The "Giant Integer" Trap: The function accepts the value to write as an int c 
(which is 4 bytes). But memory is written byte-by-byte (1 byte). If a user 
passes a massive number like 258, C standards require that the (unsigned char) 
cast truncates the 4-byte integer into a single byte, leaving only the lowest 
8 bits. (258 becomes 2).

The \0 Oblivion: Because this is a memory function, not a string function, it 
does not stop at null-terminators. If you memset a string, you will overwrite 
the \0 and potentially destroy the string's termination entirely. That is the 
programmer's responsibility, not yours.

The Logic (Pseudo-code)
1. Receive a raw memory address (b), a value to write (c), & a limit (len).
2. Create a "temporary" pointer that steps forward exactly 1 byte at a time.
3. Point this temporary pointer at the start of the unknown memory address.
4. Start walking forward:
   - Keep walking as long as we haven't hit the 'len' limit.
   - Take the integer 'c', crush it down to exactly 1 byte, and shove it into 
   the current memory box.
   - Step forward to the next box.
5. The filling is complete. Return the ORIGINAL, starting address 'b'.

Line-by-Line Breakdown
void *ft_memset(void *b, int c, size_t len)

Takes a universal pointer (void *), an integer value, and a limit. Returns a 
universal pointer.

unsigned char *s;

You declare a pointer specifically typed to unsigned char. Why char? Why 
unsigned ? char - because char is guaranteed to be exactly 1 byte in size on all 
systems. And unsigned because we want to use numbers greater than 127. 

s = (unsigned char *)b;

The crucial cast. You take the universal, size-less pointer b and tell the 
compiler: "From now on, treat this memory as an array of 1-byte boxes." * while 
(i < len)

The standard boundary loop.

s[i] = (unsigned char)c;

The engine. Because s is an unsigned char *, writing to s[i] specifically writes 
exactly 1 byte of memory. You forcefully cast c down to an unsigned char to fit 
it into that single byte box.

i++;

Moves to the next byte.

return (b);

Notice you return b, NOT s. The official standard requires you to return the 
original pointer. b is already a void *, so it returns cleanly without needing 
to cast s back to void *.

5. The Theory
Why does C use void * here?

Imagine you wanted to reset an array of ints to 0. Then later, you wanted to 
reset a massive custom struct to 0. If memset only accepted char *, the compiler 
would scream at you every time you tried to pass an int * or a struct * into it.
A void * can accept any pointer type without complaining. */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void    *ft_memset(void *b, int c, size_t len)
{
    unsigned char *ptr;
    size_t  i;

    ptr = (unsigned char *)b;
    i = 0;
    while (i < len)
    {
        ptr[i] = (unsigned char)c;
        i++;
    }
    return (b);
}
/*
int main()
{
    char ptr1[] = "abcd";
    char ptr2[] = "abcd";

    memset(ptr1, '2', 3);
    ft_memset(ptr2, '2', 3);
    
    printf("%s\n", ptr1);
    printf("%s\n", ptr2);
}

Note: 
Must declare strings with char ptr[] = "abcd" syntax, i.e as an array, for it 
to work, as it is in the stack which is readable and writable. 

If declared with char *ptr = "abcd" syntax, i.e as string literal, it goes in
the read/execute only ROsegment of the RAM, giving a seg fault.

Try with n = 0 to 31 for some interesting results! Hint: Code is OK !
*/
