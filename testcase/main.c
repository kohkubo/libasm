#include "testcase.h"

char g_buf[(size_t)BUFFER_SIZE + 100];
int g_fd;

static void	testcase_strlen()
{
	printf("\n--- test strlen ---\n");
	test_strlen("aiueo");
	test_strlen("0123456789ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	test_strlen("");
	test_strlen(g_buf); // long.txt
}

static void	testcase_strcpy()
{
	printf("\n--- test strcpy ---\n");
	test_strcpy("aioue");
	test_strcpy("0123456789ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	test_strcpy("");
	test_strcpy(g_buf); // long
}

static void	testcase_strcmp()
{
	printf("\n--- test strcmp ---\n");
	const char *d = "01234";
	test_strcmp(d, "01234");
	test_strcmp(d, "012341");
	test_strcmp(d, " 01234");
	test_strcmp("0", d);
	test_strcmp("01", d);
	test_strcmp("012", d);
	test_strcmp("0123", d);
	test_strcmp("01234", d);
	test_strcmp("", d);
	test_strcmp(d, "");
	test_strcmp("", "");
	test_strcmp("あいうえお", "あいうえな");
	test_strcmp("茜  穐  悪  握  渥  旭  葦", "茜  穐  悪  握  渥  廨  葦");
	test_strcmp(g_buf, g_buf);
}

static void	testcase_write()
{
	printf("\n--- test write ---\n");

	int rc = ft_write(1, "aiueo", -1);
	printf("ret = %d, errno = %d\n", rc, errno);
	if (errno)
		printf(RED"%s\n"RESET, strerror(errno));
	// test_write(1, "aiueo", 5);
	// test_write(1, 0, 5);
	// test_write(-1, "aiueo", 5);
	// test_write(-1, 0, 5);
	// test_write(1, "aiueo", -1);
	// int fd = open("./output.txt", O_WRONLY | O_CREAT | O_TRUNC | S_IRUSR | S_IWUSR);
	// test_write(fd, g_buf, (size_t)BUFFER_SIZE);
}

static void	testcase_read()
{
	printf("\n--- test read ---\n");
	char buf[10000] = {0};
	int fd = open("./testcase/test.txt", O_RDONLY);

	test_read(fd, buf, 5);
	test_read(fd, buf, 100);
	test_read(fd, buf, 0);
	test_read(fd, buf, -1);
	// test_read(fd, 0, 5); // crash
	test_read(-1, buf, 5);
	test_read(g_fd, g_buf, (size_t)BUFFER_SIZE);
}

static void	testcase_strdup()
{
	printf("\n--- test strdup ---\n");

	test_strdup("aiueo");
	test_strdup("0123456789ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
	test_strdup("");
	test_strdup(g_buf);
}

int main()
{
	g_fd = open("./testcase/long.txt", O_RDONLY);
	printf("g_fd : %d\n", g_fd);
	ft_read(g_fd, g_buf, (size_t)BUFFER_SIZE);

	strcat(g_buf, "tsettest");

#ifdef STRLEN
	testcase_strlen();
#endif
#ifdef STRCPY
	testcase_strcpy();
#endif
#ifdef STRCMP
	testcase_strcmp();
#endif
#ifdef WRITE
	testcase_write();
#endif
#ifdef READ
	testcase_read();
#endif
#ifdef STRDUP
	testcase_strdup();
#endif
	return (0);
}
