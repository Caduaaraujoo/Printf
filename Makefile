HEADERS_PATH = ./includes/
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
LIBS_PATH = ./libs/

CC = gcc
FLAGS = -Wall -Wextra -Werror

RM = rm -f
MKDIR = mkdir -p

NAME = libftprintf.a
SRC_FILES = ft_printf.c \
			ft_convert_dec_hex.c \
			ft_itoa_unsigned.c \
			ft_prefix_hex.c \
			ft_putnbr_unsigned.c
SOURCES = $(addprefix $(SRCS_PATH), $(SRC_FILES))
OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))
EXECUTABLE = ft_printf_test


all: $(NAME)

$(NAME): $(OBJECTS)
	@cd $(LIBS_PATH)libft && $(MAKE)
	@cp $(LIBS_PATH)libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJECTS)


$(OBJS_PATH)%.o : $(SRCS_PATH)%.c $(HEADERS_PATH)*.h
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(FLAGS) -c $< -I $(HEADERS_PATH) -o $@

clean:
	@$(RM) $(OBJECTS)
	@cd $(LIBS_PATH)libft && $(MAKE) $@


fclean: clean
	@$(RM) $(NAME)
	@cd $(LIBS_PATH)libft && $(MAKE) $@


re: fclean all

.PHONY: all run clean fclean re