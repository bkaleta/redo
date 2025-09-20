/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:31:57 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/21 00:50:52 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdbool.h>

static void	int_checker(char *name, int (*fn)(int), int x, int expec)
{
	int	func_out;
	int	res_bool;

	func_out = fn((unsigned char)x);
	res_bool = (func_out != 0);

	if (res_bool == expec)
		printf("%s('%c'): OK!\n", name, x);
	else
		printf("%s(%d): FAIL (got=%d expected=%d)\n", name, x, res_bool, expec);
}

int	main(void)
{
	printf("\nFUNCTION #1 Tests for: ft_isalpha...\n");
	int_checker("Test #1 ft_isalpha", ft_isalpha, 'X', 1);
	int_checker("Test #2 ft_isalpha", ft_isalpha, '1', 0);
	int_checker("Test #3 ft_isalpha", ft_isalpha, 1, 0);
	int_checker("Test #4 ft_isalpha", ft_isalpha, 127, 0);

	printf("\nFUNCTION #2 Tests for: ft_isascii...\n");
	int_checker("Test #1 ft_isascii", ft_isascii, 67, 1);
	int_checker("Test #1 ft_isascii", ft_isascii, 129, 0);

	return (0);
}
