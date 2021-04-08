
#include "testcase.h"

void	test_strlen(char *s)
{
	size_t lenlibasm = ft_strlen(s);
	size_t lenlibc = strlen(s);
	if (PRINT)
	{
		printf(MAGENTA"--- \"%s\" ---\n"RESET, s);
		printf(BLUE"libc  "RESET);
		printf(" : %lu\n", lenlibc);
		printf(BLUE"libasm"RESET);
		printf(" : %lu\n", lenlibasm);
	}
	if (lenlibc == lenlibasm)
		printf(GREEN"OK\n"RESET);
	else
		printf(RED"NG\n"RESET);
}

void	test_strcpy(const char *s)
{
	char *dst_libc = calloc(1, (size_t)BUFFER_SIZE + 100 + 1);
	char *dst_libasm = calloc(1, (size_t)BUFFER_SIZE + 100 + 1);
	char *libasm = ft_strcpy(dst_libasm, s);
	char *libc = strcpy(dst_libc, s);

	if (PRINT)
	{
		printf(MAGENTA"--- \"%s\" ---\n"RESET, s);
		printf(BLUE"libc\n"RESET);
		printf("ret = %s\n", libc);
		printf("dst = %s\n", dst_libc);
		printf("  s = %s\n", s);

		printf(BLUE"libasm\n"RESET);
		printf("ret = %s\n", libasm);
		printf("dst = %s\n", dst_libasm);
		printf("  s = %s\n", s);
	}
	if (!strcmp(libc, libasm) && !strcmp(libasm, dst_libasm) && !strcmp(dst_libasm, s))
		printf(GREEN"OK\n"RESET);
	else
		printf(RED"NG\n"RESET);
}

void	test_strcmp(const char *d, const char *s)
{
	int libasm = ft_strcmp(d, s);
	int libc = strcmp(d, s);
	if (PRINT)
	{
		printf(MAGENTA"--- %s : %s ---\n"RESET, d, s);
		printf(BLUE"libc"RESET);
		printf(" : %d\n", libc);
		printf(BLUE"libasm"RESET);
		printf(" : %d\n", libasm);
	}
	if (libc == libasm)
		printf(GREEN"OK\n"RESET);
	else
		printf(RED"NG\n"RESET);
}

void	test_strdup(char *s)
{
	char *dst_libasm = ft_strdup(s);
	char *dst_libc = strdup(s);
	if (PRINT)
	{
		printf(MAGENTA"--- \"%s\" ---\n"RESET, s);

		printf(BLUE"libc\n"RESET);
		printf("ret = %s\n", dst_libc);
		printf("  s = %s\n", s);

		printf(BLUE"libasm\n"RESET);
		printf("ret = %s\n", dst_libasm);
		printf("  s = %s\n", s);
	}
	if (!strcmp(dst_libasm, dst_libc) && !strcmp(s, dst_libasm))
		printf(GREEN"OK\n"RESET);
	else
		printf(RED"NG\n"RESET);

	free(dst_libasm);
	free(dst_libc);
}
