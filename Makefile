NAME = libftprintf.a

HEADERS = ./includes/ft_printf.h

SRC_FILES = ./srcs/ft_printf.c

OBJS = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	@ ar rcs $(NAME) $^
	@ echo $(NAME) "successfully generated"

.PHONY: all
all : $(NAME)

%.o: %.c $(HEADERS)
	@ echo "$< -> $@"
	@ cc -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	$(MAKE) -C ./libft clean
	@ rm -f ./srcs/*.o
	@ echo "cleaned"

.PHONY: fclean
fclean: clean
	$(MAKE) -C ./libft fclean
	@ rm -f $(NAME)

.PHONY: re
re: fclean all