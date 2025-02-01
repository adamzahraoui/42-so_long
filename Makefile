CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= so_long
RM= rm -f
SRC= mandatory/main.c \
	mandatory/get_next_line_utils.c \
	mandatory/get_next_line.c \
	mandatory/so_long_check_map.c \
	mandatory/so_long_tri9.c \
	mandatory/so_long_utils.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c mandatory/so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re all

