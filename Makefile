NAME = libasm.a
srcs = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_strdup.s \
		ft_write.s \
		ft_read.s
objs = $(srcs:%.s=%.o)

.PHONY = all clean fclean re test do sani

all: $(NAME)

%.o: %.s
	nasm -f macho64 -o $@ $<

$(NAME): $(objs)
	ar rcs $(NAME) $^

lldb: re
	gcc -g ./testcase/*.c libasm.a
	lldb ./a.out
	$(RM) -rf a.out.dSYM

sani: re
	gcc -g -fsanitize=address ./testcase/*.c libasm.a
	./a.out
	$(RM) -rf a.out.dSYM

do: re
	gcc ./testcase/*.c libasm.a
	./a.out
	$(RM) a.out

test:
	printf %.1000000000d 9 > ./testcase/long.txt
	printf %.1000000000d 9 >> ./testcase/long.txt
	printf %.200000000d 9 >> ./testcase/long.txt

clean:
	$(RM) $(objs)

fclean: clean
	$(RM) $(NAME)

re: fclean all
