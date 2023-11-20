NAME = libft.a

LIB = libft.a

HEADER = libft.h

SRC_FILES = \
 ft_bzero.c  ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_memset.c  ft_strlen.c  \
 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c\
 ft_memchr.c ft_memcmp.c ft_strnstr.c  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
 ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c\

SRC_BONUS = \
 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = $(SRC_FILES:.c=.o)

OBJS_BONUS = $(SRC_BONUS:.c=.o)

FLAGS = -Wall -Werror -Wextra

.PHONY: all
all: $(OBJS) $(HEADER)
	@ ar rcs $(LIB) $^
	@ echo $(LIB) "successfully generated"

$(NAME) : all

.PHONY: bonus
bonus: $(OBJS) $(OBJS_BONUS) $(HEADER)
	@ ar rcs $(LIB) $^
	@ echo $(LIB) "successfully generated including bonus functions"

%.o: %.c
	@ echo "$< -> $@"
	@ cc -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	@ rm -f *.o
	@ echo "cleaned"

.PHONY: fclean
fclean: clean
	@ rm -f $(LIB)

.PHONY: re
re: fclean all
