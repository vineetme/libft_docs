/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2026/05/15 19:29:28 by vmeharia	       #+#    #+#	      */
/*   Updated: 2026/05/15 19:43:44 by vmeharia         ###   ########.fr       */
/*									      */
/* ************************************************************************** */
/*The ft_strnstr function searches for the first complete occurrence of the 
needle string inside the haystack string. However, it will only search up to 
len characters of the haystack.

If it finds the needle, it returns a pointer to the very first character of 
the needle inside the haystack. If the needle is completely empty, it returns 
the haystack. If the needle isn't found within the limit, it returns NULL.

The Traps & Edge Cases
The Empty Needle Trap: What if the user searches for ""? The C standard 
dictates that searching for nothing should instantly return the entire 
haystack. 

The "Cut-Off" Trap: Imagine haystack is "42School", needle is "School", and 
len is 7. The word "School" exists, but the 'l' is at index 7. Because len 
is 7, we are only allowed to look at indices 0 through 6 ("42Schoo"). The 
needle shouldn't match! The entire needle should fit inside the allowed 
boundary.

The Partial Match Illusion: What if the haystack is "mississippi" and the 
needle is "issip"? The code will find "iss" and fail on the first try. It 
needs to cleanly reset and try again from the next letter. 

The Logic (Pseudo-code)
1. Is the needle completely empty?
   - YES: Return a pointer to the start of the haystack.
2. Start walking through the haystack one step at a time (Index 'i').
   - Keep walking AS LONG AS we haven't hit the 'len' limit AND haven't hit 
   the end of the haystack.
3. At the current step 'i', look ahead to see if the needle starts here:
   - Create a second counter 'j' to look at the needle.
   - Keep looking ahead AS LONG AS:
     - The needle hasn't ended.
     - The letter in the haystack matches the letter in the needle.
     - Our look-ahead distance (i + j) hasn't crossed the 'len' limit.
4. Did our look-ahead successfully reach the end of the needle?
   - YES: We found it! Return a pointer to haystack[i].
   - NO: The match failed. Step forward in the haystack and try again.
5. We searched everything within the limit and found nothing. Return NULL.

Line-by-Line Breakdown
char *ft_strnstr(const char *haystack, const char *needle, size_t len)

Takes two strings and our absolute search limit len.

if (needle[0] == '\0') return ((char *)haystack);

The instant bail-out for an empty needle. Notice the (char *) cast—we have to 
rip off the const lock from the haystack before returning it.

while (i < len && haystack[i] != '\0')

The Anchor Loop. This controls where we start looking. i is our anchor point 
in the haystack. We only drop an anchor if we are within the limit and haven't 
hit the \0.

j = 0;

Reset the needle index. Every time we move the anchor i, we must start checking 
the needle from the beginning again.

while (needle[j] != '\0' && haystack[i + j] == needle[j] && (i + j) < len)
j++;

The Look-Ahead Engine.

haystack[i + j]: This is the magic. i is where we are anchored. j is how far we 
are looking ahead.

(i + j) < len: This strictly prevents us from finding a needle that starts 
inside the boundary but bleeds out past the limit.

j++ : Jump to the next character of the needle.

if (needle[j] == '\0') return ((char *)&haystack[i]);

If the inner loop broke because needle[j] hit \0, it means every single 
character of the needle matched. We found it.

&haystack[i] grabs the memory address of our anchor point, we cast away 
the const, and return it.

i++;

The look-ahead failed. Move the anchor forward one byte and restart the 
process.*/

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && needle[j] != '\0' && 
			haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main()
{
    printf("%s\n", strnstr("magadudu", "dudu", 8));
    printf("%s\n", ft_strnstr("magadudu", "dudu", 8));
}
*/
