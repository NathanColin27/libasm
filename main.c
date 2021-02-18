#include <stdio.h>
#include <string.h>
#include "libasm.h"

void test_strlen(void)
{
	printf("TESTING FT_STRLEN\n");

	printf("[SYSTEM]: [%ld]\n", strlen(""));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen(""));

	printf("[SYSTEM]: [%ld]\n", strlen("Il était une fois"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("Il était une fois"));

	printf("[SYSTEM]: [%ld]\n", strlen("Une petite mandarine"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("Une petite mandarine"));

	printf("[SYSTEM]: [%ld]\n", strlen("42"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("42"));

	printf("[SYSTEM]: [%ld]\n", strlen("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee"));

	printf("[SYSTEM]: [%ld]\n", strlen("Lourd, léger, professionnel"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("Lourd, léger, professionnel"));

	printf("[SYSTEM]: [%ld]\n", strlen("Parce que tuuuunnel"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("Parce que tuuuunnel"));
}

void test_strcpy(void)
{
	printf("TESTING FT_STRCPY\n");
}

void test_write(void)
{
	printf("TESTING FT_WRITE\n");
}

void test_read(void)
{
	printf("TESTING FT_READ\n");
}

void test_strcmp(void)
{
	printf("TESTING FT_STRCMP\n");

	printf("ft_strcmp: %i\n", ft_strcmp("hvtuklshriehnslkerjhntkrujbnjtvntrjbslnt.lnbejrtbnrt.ktjnl","hvtuklshriehnslkerjhntkrujbnjtvntrjbslnt.lnbejrtbnrt.ktjnj"));
	printf("strcmp   : %i\n", strcmp("hvtuklshriehnslkerjhntkrujbnjtvntrjbslnt.lnbejrtbnrt.ktjnl", "hvtuklshriehnslkerjhntkrujbnjtvntrjbslnt.lnbejrtbnrt.ktjnj"));
}

void test_strdup(void)
{
	printf("TESTING FT_STRDUP\n");
}



int	main(void)
{
	test_strlen();
	test_strcpy();
	test_write();
	test_read();
	test_strcmp();
	test_strdup();

	
}