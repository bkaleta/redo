/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 20:11:02 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/28 01:42:53 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

unsigned int	count_len(int n);
char			*fill_array(char *out, unsigned int num, unsigned int num_len);

char	*ft_itoa(int n)
{
	char			*out;
	unsigned int	num;
	unsigned int	num_len;

	num = n;
	num_len = count_len(n);
	out = malloc(num_len + 1);
	out[num_len--] = '\0';
	if (!out)
		return (NULL);
	out = fill_array(out, num, num_len);
	return (out);
}

unsigned int	count_len(int n)
{
	unsigned int	num_len;
	unsigned int	num;

	num_len = 0;
	num = n;
	if (n <= 0)
	{
		num_len = 1;
		num *= -1;
	}
	while (num > 0)
	{
		num /= 10;
		num_len++;
	}
	return (num_len);
}

char	*fill_array(char *out, unsigned int num, unsigned int num_len)
{
	int	n;

	n = num;
	if (num == 0)
	{
		out[0] = '0';
		return (out);
	}
	else if (n < 0)
	{
		out[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		out[num_len] = num % 10 + '0';
		num /= 10;
		num_len--;
	}
	return (out);
}
