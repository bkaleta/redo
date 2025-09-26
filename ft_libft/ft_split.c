/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:15:35 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/26 12:34:54 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	count_words(char const *s, char c);
static char		*fill_arr(char *word, char const *s, size_t start, size_t end);
static char		**split_words(char const *s, char c, char **out, size_t len);
static char		**free_split(char **out, size_t word);

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	len;

	len = count_words(s, c);
	out = (char **)malloc(sizeof(char *) * (len + 1));
	if (!out)
		return (NULL);
	out = split_words(s, c, out, len);
	printf("%ld\n", len);
	return (out);
}

static size_t	count_words(char const *s, char c)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (len);
}

static char	*fill_arr(char *word, char const *s, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (i < end)
	{
		word[i] = s[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static char	**split_words(char const *s, char c, char **out, size_t len)
{
	size_t	i;
	size_t	word;
	size_t	letters_in_word;

	i = 0;
	word = 0;
	while (word < len)
	{
		letters_in_word = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			letters_in_word++;
			i++;
		}
		out[word] = malloc(letters_in_word + 1);
		if (!out)
			return (free_split(out, word));
		fill_arr(out[word], s, i - letters_in_word, letters_in_word);
		word++;
	}
	out[word] = 0;
	return (out);
}

static char		**free_split(char **out, size_t word)
{
	while (word > 0)
	{
		free(out[word]);
		word--;
	}
	free(out);
	return (NULL);
}
