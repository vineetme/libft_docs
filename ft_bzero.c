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

*/
void	ft_bzero(void *s, size_t len)
{
	unsigned char *ptr;
	size_t	i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < len)
	{
		ptr[i] = 0;
		i++;
	}
}
