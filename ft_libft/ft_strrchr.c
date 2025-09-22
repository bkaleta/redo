/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:19:14 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/22 17:48:09 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) + 1;
	while (--i > 0)
		if (s[i] == (char)c)
			return ((char *) &s[i]);
	if (s[i] == (char)c)
		return ((char *) &s[i]);
	return (NULL);
}
