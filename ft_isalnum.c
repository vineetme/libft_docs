/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 13:53:01 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/16 11:41:05 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	1. checks if input isalpha || is digit
	2. isalpha checks if input isupper || islower
	3. isupper checks if input is  upper case letter
	4. islower checks if input is lowercase character
	5. is digit checks if input is digit 0 through 9
	6. all isfunctions return 1 if input is in tested class, 0 if not.
*/

#include "libft.h"

int	ft_isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c >= 'a' && c <= 'z')
		return (0);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%d\n", !!isalnum('6'));
	printf("%d\n", ft_isalnum('6'));
}
*/
