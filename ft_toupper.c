/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:48:00 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/16 13:33:08 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("%c\n", ft_toupper('b'));
	printf("%c\n", toupper('b'));
}
*/
