#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "libasm.h"
#include <error.h>

void test_strlen(void)
{
	printf("\n\n*********************\n");
	printf("* TESTING FT_STRLEN *\n");
	printf("*********************\n\n");
	printf("[SYSTEM]: [%ld]\n", strlen(""));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen(""));
	
	printf("[SYSTEM]: [%ld]\n", strlen("\\"));
	printf("[LIBASM]: [%ld]\n\n", ft_strlen("\\"));
	
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
	printf("\n\n*********************\n");
	printf("* TESTING FT_STRCPY *\n");
	printf("*********************\n\n");
	
	char *str_libasm = malloc(15);
	char *str_system = malloc(15);
	
	printf("[SYSTEM]: [%s]\n", strcpy(str_libasm, "test"));
	printf("[LIBASM]: [%s]\n\n", ft_strcpy(str_system, "test"));
	
	printf("[SYSTEM]: [%s]\n", strcpy(str_libasm, ""));
	printf("[LIBASM]: [%s]\n\n", ft_strcpy(str_system, ""));
	
	printf("[SYSTEM]: [%s]\n", strcpy(str_libasm, "42"));
	printf("[LIBASM]: [%s]\n\n", ft_strcpy(str_system, "42"));
	
	printf("[SYSTEM]: [%s]\n", strcpy(str_libasm, "\0"));
	printf("[LIBASM]: [%s]\n\n", ft_strcpy(str_system, "\0"));
	
	printf("[SYSTEM]: [%s]\n", strcpy(str_libasm, "( ͡° ͜ʖ ͡°)"));
	printf("[LIBASM]: [%s]\n\n", ft_strcpy(str_system, "( ͡° ͜ʖ ͡°)"));
	
	free(str_libasm);
	free(str_system);

	
	// printf("%s\n ", str_libasm);
	// printf("%s\n ", str_system);

	// printf("[SYSTEM]: [%s]\n", ft_strcpy(str_libasm, NULL));
	// printf("[LIBASM]: [%s]\n\n", strcpy(str_system, NULL));

}

void test_write(void)
{
	printf("\n\n********************\n");
	printf("* TESTING FT_WRITE *\n");
	printf("********************\n\n");

	printf("Trying different fds\n");

	char *sys = "hello world!\n";
	char *asem = "hello world!\n";
	int fd;
	fd = 0;
	printf("[SYSTEM] && fd = 0: [%zi]\n", write(fd, sys , 14));
	printf("[LIBASM] && fd = 0: [%zi]\n\n", ft_write(fd, asem , 14));
	fd = 1;
	printf("[SYSTEM] && fd = 1: [%zi]\n", write(fd, sys , 14));
	printf("[LIBASM] && fd = 1: [%zi]\n\n", ft_write(fd, asem , 14));
	fd = 2;
	printf("[SYSTEM] && fd = 2: [%zi]\n", write(fd, sys , 14));
	printf("[LIBASM] && fd = 2: [%zi]\n\n", ft_write(fd, asem , 14));
	printf("Maintenant, on fout le zbeul\n\n" );
	fd = -1;
	printf("[SYSTEM] && fd = -1: [%zi]\n", write(fd, sys , 14));
	perror("[SYSTEM]: errno");
	printf("[LIBASM] && fd = -1: [%zi]\n", ft_write(fd, asem , 14));
	perror("[LIBASM]: errno");
	fd = 1;
	printf("\n[SYSTEM] && nbyte = -1: [%zi]\n", write(fd, sys ,-1));
	perror("[SYSTEM]: errno");
	printf("[LIBASM] && nbyte = -1: [%zi]\n", ft_write(fd, asem ,-1));
	perror("[LIBASM]: errno");

	printf("\n[SYSTEM] && buff = NULL: [%zi]\n", write(fd, NULL ,14));
	perror("[SYSTEM]: errno");
	printf("[LIBASM] && buff = NULL: [%zi]\n", ft_write(fd, NULL ,14));
	perror("[LIBASM]: errno");

}

void test_read(void)
{
	printf("\n\n*******************\n");
	printf("* TESTING FT_READ *\n");
	printf("*******************\n\n");
}

void test_strcmp(void)
{
	printf("\n\n*********************\n");
	printf("* TESTING FT_STRCMP *\n");
	printf("*********************\n\n");
	
	printf("[SYSTEM]: %i\n", strcmp("", ""));
	printf("[LIBASM]: %i\n\n", ft_strcmp("",""));
	
	printf("[SYSTEM]: %i\n", strcmp("a", "b"));
	printf("[LIBASM]: %i\n\n", ft_strcmp("a","b"));
	
	printf("[SYSTEM]: %i\n", strcmp("a", "z"));
	printf("[LIBASM]: %i\n\n", ft_strcmp("a","z"));
	
	printf("[SYSTEM]: %i\n", strcmp("\0", "\0"));
	printf("[LIBASM]: %i\n\n", ft_strcmp("\0","\0"));
	
	printf("[SYSTEM]: %i\n", strcmp("aaaaaaaaaa", "aaaaaaaaaa"));
	printf("[LIBASM]: %i\n\n", ft_strcmp("aaaaaaaaaa","aaaaaaaaaa"));
	
	printf("[SYSTEM]: %i\n", strcmp("wqerr  024lw,'>H;[qewr", "wqerr  024lw,'>H;[qewr"));
	printf("[LIBASM]: %i\n\n", ft_strcmp("wqerr  024lw,'>H;[qewr","wqerr  024lw,'>H;[qewr"));
}

void test_strdup(void)
{
	printf("\n\n*********************\n");
	printf("* TESTING FT_STRDUP *\n");
	printf("*********************\n\n");

	char *str_system;
	char *str_libasm;

	str_system = strdup("HELLO");
	str_libasm = ft_strdup("HELLO");
	printf("[SYSTEM] : %s\n",str_system);
	printf("[LIBASM] : %s\n\n",str_libasm);
	free(str_system);
	free(str_libasm);

	str_system = strdup("");
	str_libasm = ft_strdup("");
	printf("[SYSTEM] : %s\n",str_system);
	printf("[LIBASM] : %s\n\n",str_libasm);
	free(str_system);
	free(str_libasm);

	str_system = strdup("\0");
	str_libasm = ft_strdup("\0");
	printf("[SYSTEM] : %s\n",str_system);
	printf("[LIBASM] : %s\n\n",str_libasm);
	free(str_system);
	free(str_libasm);

	str_system = strdup("Let's go les gars");
	str_libasm = ft_strdup("Let's go les gars");
	printf("[SYSTEM] : %s\n",str_system);
	printf("[LIBASM] : %s\n\n",str_libasm);
	free(str_system);
	free(str_libasm);

	// str_system = strdup(NULL);
	// str_libasm = ft_strdup(NULL);
	// printf("[SYSTEM] : %s\n",str_system);
	// printf("[LIBASM] : %s\n\n",str_libasm);
	// free(str_system);
	// free(str_libasm);

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