
#ifndef TESTCASE_H
#define TESTCASE_H

#include <libc.h>
#include <errno.h>

#ifndef LOGGING_H
#define LOGGING_H
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"
#endif

#define BUFFER_SIZE 2147483646
#define PRINT 0

size_t	ft_strlen(char *s);
char	*ft_strcpy(char *d, const char *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
void	test_strlen(char *s);
void	test_strcpy(const char *s);
void	test_strcmp(const char *d, const char *s);
void	test_strdup(char *d);
void	test_write(int fildes, const void *buf, size_t nbyte);
void	test_read(int fildes, char *buf, size_t nbyte);

#endif
