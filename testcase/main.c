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
	test_strcmp(g_buf, g_buf);
}

static void	testcase_write()
{
	printf("\n--- test write ---\n");

	test_write(1, "aiueo", 5);
	test_write(1, 0, 5);
	test_write(-1, "aiueo", 5);
	test_write(-1, 0, 5);
	test_write(1, "aiueo", -1);
	// test_write(1, g_buf, (size_t)BUFFER_SIZE);
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
	
	testcase_strlen();
	testcase_strcpy();
	testcase_strcmp();
	testcase_write();
	testcase_read();
	testcase_strdup();

	return (0);
}
