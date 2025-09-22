/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:19:04 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/22 18:24:39 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i <= len)
	{
		j = 0;
		while (haystack[i+j] == needle[j] && needle[j] != '\0' && i + j < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *) &haystack[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
