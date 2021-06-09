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

sani: CFLAGS += -g -fsanitize=address -D WRITE
sani: run

strlen: CFLAGS += -D STRLEN
strlen: run

strcpy: CFLAGS += -D STRCPY
strcpy: run

strcmp: CFLAGS += -D STRCMP
strcmp: run

strdup: CFLAGS += -D STRDUP
strdup: run

write: CFLAGS += -D WRITE
write: run

read: CFLAGS += -D READ
read: run

run: all
	@$(CC) $(CFLAGS) ./testcase/*.c libasm.a
	@./a.out
	@$(RM) -rf a.out a.out.dSYM

do:
	$(CC) $(CFLAGS) -D STRLEN -D STRCPY -D STRCMP -D STRDUP -D WRITE -D READ ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(NAME) ./output.txt ./testcase/long.txt

re: fclean all
