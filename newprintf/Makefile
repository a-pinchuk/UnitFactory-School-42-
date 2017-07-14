NAME = libftprintf.a


SRC = ft_printf.c ft_itoa_base.c typecast.c types.c useful_funcs.c ft_flags.c \
	ft_atoi.c ft_isdigit.c ft_putchar.c ft_putstr.c ft_strchr.c ft_strlen.c ft_strstr.c ft_strsub.c print_characters.c\

OBJ = $(SRC:.c=.o)

CFLAGS = -c 
HEADER = ft_printf.h

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -I $(HEADER)
	ar	rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $<

clean:
	rm	-rf $(OBJ)

fclean: clean
	rm	-rf $(NAME)

re: fclean all