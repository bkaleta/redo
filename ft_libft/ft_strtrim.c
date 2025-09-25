/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:19:26 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/26 01:03:31 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	check_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_end(char const *s1, char const *set)
{
	size_t	end;

	end = ft_strlen(s1);
	while (end > 0 && check_set(s1[end - 1], set))
		end--;
	return (end);
}

static size_t	trim_start(char const *s1, char const *set)
{
	size_t	start;

	start = 0;
	while (s1[start] && check_set(s1[start], set))
		start++;
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	i;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = trim_start(s1, set);
	end = trim_end(s1, set);
	if (end < start)
		end = start;
	len = end - start;
	trimed = (char *)malloc(sizeof(char) * (len + 1));
	if (!trimed)
		return (NULL);
	while (start < end)
	{
		trimed[i] = s1[start];
		start++;
		i++;
	}
	trimed[i] = '\0';
	return (trimed);
}
