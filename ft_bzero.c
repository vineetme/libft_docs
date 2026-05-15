/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 19:50:38 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/14 19:59:53 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Notes:	1. ft_bzero returns NOTHING. VOID.
		2. While testing, use a '0' instead of 0, so printf works!

#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
*/
#include <libft.h>

void	ft_bzero(void *s, size_t len)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	unsigned char ptr1[] = "abcd";
	unsigned char ptr2[] = "abcd";
	size_t len = 4;

	ft_bzero(ptr1, len);
	printf("%s\n", ptr1);
	bzero(ptr2, len);
	printf("%s\n", ptr2);
}
*/
