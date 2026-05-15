/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 21:17:09 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/15 21:24:50 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
ft_strchr locates the first occurrence of a char c in the string str.
It returns a pointer to first occurrence of the char c in the str or NULL
if char c is not in string
*/

#include <stdlib.h>

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i] != (char)c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&str[i]);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int	main(void)
{
	char str[] = "magadudu";
	char c = 'a';
	printf("%s\n", strchr(str, c));
	printf("%s\n", strchr(str, c));
}
*/
