/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:31:57 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/21 01:22:13 by bkaleta          ###   ########.fr       */
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
	int_checker("Test #1 ft_isalpha", ft_isalpha, ('a' -1), 0);
	int_checker("Test #2 ft_isalpha", ft_isalpha, 'a', 1);
	int_checker("Test #3 ft_isalpha", ft_isalpha, ('z' + 1), 0);
	int_checker("Test #4 ft_isalpha", ft_isalpha, 'z', 1);
	int_checker("Test #5 ft_isalpha", ft_isalpha, ('A' - 1), 0);
	int_checker("Test #6 ft_isalpha", ft_isalpha, 'A', 1);
	int_checker("Test #7 ft_isalpha", ft_isalpha, ('Z' + 1), 0);
	int_checker("Test #8 ft_isalpha", ft_isalpha, 'Z', 1);

	printf("\nFUNCTION #2 Tests for: ft_isdigit...\n");
	int_checker("Test #1 ft_isdigit", ft_isdigit, -1, 0);
	int_checker("Test #2 ft_isdigit", ft_isdigit, 0, 0);
	int_checker("Test #3 ft_isdigit", ft_isdigit, '0', 1);
	int_checker("Test #4 ft_isdigit", ft_isdigit, '0' - 1, 0);
	int_checker("Test #4 ft_isdigit", ft_isdigit, '0' + 5, 1);

	printf("\nFUNCTION #3 Tests for: ft_isalnum...\n");
	int_checker("Test #1 ft_isalnum", ft_isalnum, -1, 0);
	int_checker("Test #2 ft_isalnum", ft_isalnum, 0, 0);
	int_checker("Test #3 ft_isalnum", ft_isalnum, '0', 1);
	int_checker("Test #4 ft_isalnum", ft_isalnum, 'z', 1);
	int_checker("Test #5 ft_isalnum", ft_isalnum, 'z' + 1, 0);


	printf("\nFUNCTION #4 Tests for: ft_isascii...\n");
	int_checker("Test #1 ft_isascii", ft_isascii, -1, 0);
	int_checker("Test #2 ft_isascii", ft_isascii, 0, 1);
	int_checker("Test #3 ft_isascii", ft_isascii, 128, 0);
	int_checker("Test #4 ft_isascii", ft_isascii, 127, 1);

	printf("\nFUNCTION #5 Tests for: ft_isprint...\n");
	int_checker("Test #1 ft_isprint", ft_isprint, -1, 0);
	int_checker("Test #2 ft_isprint", ft_isprint, ' ', 1);
	int_checker("Test #3 ft_isprint", ft_isprint, ' ' -1, 0);
	int_checker("Test #4 ft_isprint", ft_isprint, 'z', 1);
	int_checker("Test #5 ft_isprint", ft_isprint, 'z' +1, 1);
	int_checker("Test #6 ft_isprint", ft_isprint, 126, 1);
	int_checker("Test #7 ft_isprint", ft_isprint, 127, 0);
	
	// printf("%d\n", isdigit(-1));

	return (0);
}
