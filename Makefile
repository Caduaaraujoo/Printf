NAME = libftprintf.a

HEADERS = ft_printf.h

SRC_FILES = ft_printf.c

OBJS = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	@ ar rcs $(NAME) $^
	@ echo $(NAME) "successfully generated"

.PHONY: all
all : $(NAME)

%.o: %.c $(HEADERS)
	@ echo "$< -> $@"
	@ cc -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	@ rm -f *.o
	@ echo "cleaned"

.PHONY: fclean
fclean: clean
	@ rm -f $(NAME)

.PHONY: re
re: fclean all