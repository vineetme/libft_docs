/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmeharia <vmeharia@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 19:47:04 by vmeharia          #+#    #+#             */
/*   Updated: 2026/05/11 19:47:08 by vmeharia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]) != NULL)
		begin++;
	end = ft_strlen(s1);
	while (end > begin && ft_strchr(set, s1[end - 1]) != NULL)
		end--;
	return (ft_substr(s1, begin, end - begin));
}
