/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:11:33 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/25 18:42:46 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp_ptr;
	unsigned char	tmp;

	tmp_ptr = (unsigned char *) s;
	tmp = (unsigned char) c;

	i = -1;
	while (++i < n)
		if (tmp_ptr[i] == tmp)
			return ((void *) &tmp_ptr[i]);
	return (NULL);
}
