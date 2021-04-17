#include "testcase.h"

static void test_write2(char *s, ssize_t (*func)(int, const void *, size_t), int fildes, const void *buf, size_t nbyte)
{
	ssize_t rc = 0;
	errno = 0;

	if(PRINT)
	{
		printf(BLUE"%s"RESET, s);
		printf(" : \n");
		fflush(stdout);
	}
	rc = (* func)(fildes, buf, nbyte);
	printf("\n");
	printf("ret = %zu, errno = %d\n", rc, errno);
	if (errno)
		printf(RED"%s\n"RESET, strerror(errno));
}

void	test_write(int fildes, const void *buf, size_t nbyte)
{
	printf(MAGENTA"--- write(%d, %s, %zu); ---\n"RESET, fildes, buf, nbyte);
	test_write2("libc", write, fildes, buf, nbyte);
	lseek(fildes, 0, SEEK_SET);
	test_write2("libasm", ft_write, fildes, buf, nbyte);
}

static void	test_read2(char *s, ssize_t (*func)(int, void *, size_t), int fildes, char *buf, size_t nbyte)
{
	ssize_t rc = 0;
	errno = 0;
	lseek(fildes, 0, SEEK_SET);

	rc = (* func)(fildes, (void *)buf, nbyte);
	if (rc != -1)
		buf[rc] = 0;

	if (PRINT)
	{
		printf(BLUE"%s"RESET, s);
		fflush(stdout);
		printf(" : %s\n", buf);
	}
	printf("ft_strlen(buf) : %zu\n", ft_strlen(buf));
	printf("ret = %zu, errno = %d\n", rc, errno);
	if (errno)
		printf(RED"%s\n"RESET, strerror(errno));
}

void	test_read(int fildes, char *buf, size_t nbyte)
{
	printf(MAGENTA"--- read(%d, buf, %zu); ---\n"RESET, fildes, nbyte);
	test_read2("libc", read, fildes, buf, nbyte);
	test_read2("libasm", ft_read, fildes, buf, nbyte);
}
