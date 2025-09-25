/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:19:40 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/25 19:55:44 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	copy_len;
	size_t	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((size_t)start >= slen)
	{
		out = malloc(1);
		if (!out)
			return (NULL);
		out[0] = '\0';
		return (out);
	}
	copy_len = slen - (size_t)start;
	if (copy_len > len)
		copy_len = len;
	out = malloc(copy_len + 1);
	if (!out)
		return (NULL);
	ft_memcpy(out, s + start, copy_len);
	out[copy_len] = '\0';
	return (out);
}
