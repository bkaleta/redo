/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:11:33 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/22 17:06:35 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	unsigned char *tmpPtr;
	unsigned char tmp;

	tmpPtr = (unsigned char *) s;
	tmp = (unsigned char) c;

	i = -1;
	while (++i < n)
		if (tmpPtr[i] == tmp)
			return ((void *) &tmpPtr[i]);
	return (NULL);
}
