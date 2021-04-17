NAME = libasm.a
srcs =  ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_write.s \
		ft_read.s
objs = $(srcs:%.s=%.o)
CC = gcc
CFLAGS = -D PRINT=1 -D BUFFER_SIZE=2147483646

.PHONY = all clean fclean re do sani strlen strcpy strcmp strdup write read clean_all

all: $(NAME)

%.o: %.s
	nasm -f macho64 -o $@ $<

$(NAME): $(objs)
	ar rcs $(NAME) $^
ifeq (, $(wildcard ./testcase/long.txt))
	printf %.1000000000d 9 > ./testcase/long.txt
	printf %.1000000000d 9 >> ./testcase/long.txt
	printf %.200000000d 9 >> ./testcase/long.txt
endif

lldb:
	$(CC) $(CFLAGS) -g ./testcase/*.c libasm.a
	lldb ./a.out
	$(RM) -rf a.out.dSYM

sani:
	$(CC) $(CFLAGS) -g -fsanitize=address ./testcase/*.c libasm.a
	./a.out
	$(RM) -rf a.out.dSYM

strlen: all
	$(CC) $(CFLAGS) -D STRLEN ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

strcpy: all
	$(CC) $(CFLAGS) -D STRCPY ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

strcmp: all
	$(CC) $(CFLAGS) -D STRCMP ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

strdup: all
	$(CC) $(CFLAGS) -D STRDUP ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

write: all
	$(CC) $(CFLAGS) -D WRITE ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

read: all
	$(CC) $(CFLAGS) -D READ ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

do:
	$(CC) $(CFLAGS) -D STRLEN -D STRCPY -D STRCMP -D STRDUP -D WRITE -D READ ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(NAME) ./output.txt ./testcase/long.txt

re: fclean all
