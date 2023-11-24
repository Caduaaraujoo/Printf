NAME = program
HEADERS = ./includes/ft_printf.h
SRC_FILES = ./srcs/ft_printf.c ./srcs/ft_putnbr_unsigned.c 
OBJS = $(SRC_FILES:.c=.o)
FLAGS = -Wall -Wextra -Werror -g3 -I./includes

$(NAME): $(OBJS) libft.a libftprintf.a
	@ cc $(FLAGS) -o $(NAME) $^
	@ echo $(NAME) "successfully generated"

libft.a:
	@ $(MAKE) -C ./libft
	@ cp ./libft/libft.a ./

libftprintf.a: $(OBJS)
	@ ar rcs libftprintf.a $^
	@ echo "libftprintf.a successfully generated"

%.o: %.c $(HEADERS)
	@ echo "$< -> $@"
	@ cc -c $< -o $@ $(FLAGS)

.PHONY: all
all : $(NAME)

.PHONY: clean
clean:
	@ rm -f ./srcs/*.o
	@ rm -f libft.a libftprintf.a
	@ echo "cleaned"

.PHONY: fclean
fclean: clean
	@ $(MAKE) -C ./libft fclean
	@ rm -f $(NAME)

.PHONY: re
re: fclean all
