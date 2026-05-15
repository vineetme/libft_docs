/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:00:53 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/14 22:04:41 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
Notes:	1.  Calloc returns a void *; That mean it returns a memory address.
	2.  Memory address means 2 things need to b specified:
		- How many steps from the memory to "count"?
		- What is the "size" (number of bytes: where 1 byte = 8 bits) 
		  of each step?
	3.  So it takes as input parameter these two things - size and count.
	4.  Since size and count cant be negative and they need to be able to
	    handle very large data, their type is size_t;
	5.  size * count could be so huge that its not possible to allocate so
            much memory. This is INTEGER OVERFLOW. 
        6.  Whats the absolute maximum number that can be represented without
	    any issue on any computer ? Ans: (size_t-1).
        7.  What exactly, and how big, is size_t? size_t is a data type. Like 
	    int long etc. It is unsigned. Its exact size is 32 / 64 bits, i.e 4 
	    bytes or 8 bytes, depending on compiler. And it can represent upto 
	    2 raised to power of 32 / 64 unique values.
	8.  So first step is to check whether count * size < (size_t-1) and if 
	    not, return error.
	9.  Finally - It sets the memory block to zero! 	
*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	if (count != 0 && size > ((size_t)-1) / count)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/*
int main(void)
{
    // 1. Ask for 3 integers (each int is 4 bytes, so 12 bytes total)
    int *ptr = (int *)ft_calloc(3, sizeof(int));

    // 2. Check if the "construction crew" failed
    if (ptr == NULL)
    {
        printf("Error: Could not allocate memory!\n");
        return (1);
    }

    // 3. Print the values to see if they are actually 0
    printf("Value 1: %d\n", ptr[0]);
    printf("Value 2: %d\n", ptr[1]);
    printf("Value 3: %d\n", ptr[2]);

    // 4. Give the memory back when finished
    free(ptr);

    return (0);
}
*/
