/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaleta <bkaleta@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 21:31:57 by bkaleta           #+#    #+#             */
/*   Updated: 2025/09/21 21:07:05 by bkaleta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

static void	int_checker(const char *name, int (*fn)(int), int x, int expec);
static void str_checker(const char *name, size_t (*fn)(const char*), char* str, size_t len);

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

	printf("\nFUNCTION #6 Tests for: ft_strlen...\n");
	str_checker("Test #1 strlen", strlen, "123", 3);
	str_checker("Test #2 strlen", strlen, "12\0", 2);
	str_checker("Test #3 strlen", strlen, "", 0);
	str_checker("Test #1 ft_strlen", strlen, "123", 3);
	str_checker("Test #2 ft_strlen", strlen, "12\0", 2);
	str_checker("Test #2 ft_strlen", strlen, "", 0);

	printf("\nFUNCTION #7 Tests for: ft_memset...\n");
	printf("Tests #1 memset...\n");
	char test_memset[42];
	memset(test_memset, 'X', 42);
	printf("%s\n", test_memset);
	printf("Tests #2 ft_memset...\n");
	ft_memset(test_memset, 'D', 42);
	printf("%s\n", test_memset);

	printf("\nFUNCTION #8 Tests for: ft_bzero...\n");
	printf("Tests #1 ft_bzero...\n");
	ft_bzero(test_memset, 42);
	printf("%s\n", test_memset);
	// printf("%d\n", isdigit(-1));
	
	printf("\nFUNCTION #9 Tests for: ft_memcpy...\n");
	printf("Test #1 memcepy\n");
	char dest[7];
	char *src = "12345";
	//printf("SRC: %s\nDEST: %s\n", src, dest);
	memcpy(dest, src, 5);
	printf("SRC: %s\nDEST: %s\n", src, dest);
	printf("Test #1 ft_memcepy\n");
	char desttest[7];
	ft_memcpy(desttest, src, 5);
	printf("SRC: %s\nDEST: %s\n", src, dest);
	
	printf("\nFUNCTION #10 Tests for: ft_memmove...\n");
	
	printf("\nFUNCTION #11 Tests for: ft_strlcpy...\n");
	char	*teststrlcpysrc = "123";
	char	testdst[10];
	ft_strlcpy(testdst, teststrlcpysrc, 10);
	printf("SRC: %s\nDEST: %s\n", teststrlcpysrc, testdst);


	return (0);
}

static void	int_checker(const char *name, int (*fn)(int), int x, int expec)
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

static void	str_checker(const char *name, size_t (*fn)(const char*), char* str, size_t len)
{
	size_t got;

	got = fn(str);
	if (got == len) 
		printf("%s(\"%s\"): OK (len=%zu)\n", name, str ? str : "(null)", got);
    else 
	{
        printf("%s(\"%s\"): FAIL (got=%zu expected=%zu)\n",
			name, str ? str : "(null)", got, len);
    }
}
