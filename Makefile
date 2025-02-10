RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m
RESET = \033[0m

define SO_LONG
$(CYAN)
█████████████████████████████████████████████████████████████████████████████████
█                                                                               █
█                              Enjoy the game!                                  █
█                                                                               █
█                         ✦ WASD or Arrows to move                              █
█                         ✦ ESC or X to exit                                    █
█                         ✦ Collect all coins!                                  █
█                                                                               █
█████████████████████████████████████████████████████████████████████████████████

   ▄████████  ▄██████▄           ▄█          ▄██████▄  ███▄▄▄▄      ▄██████▄  
  ███    ███ ███    ███         ███         ███    ███ ███▀▀▀██▄   ███    ███ 
  ███    █▀  ███    ███         ███         ███    ███ ███   ███   ███    █▀  
  ███        ███    ███         ███         ███    ███ ███   ███  ▄███        
▀███████████ ███    ███         ███         ███    ███ ███   ███ ▀▀███ ████▄  
         ███ ███    ███         ███         ███    ███ ███   ███   ███    ███ 
   ▄█    ███ ███    ███         ███▌     ▄ ███    ███ ███   ███   ███    ███ 
 ▄████████▀   ▀██████▀  █████   ███████▄▄██  ▀██████▀   ▀█   █▀   ████████▀  

█████████████████████████████████████████████████████████████████████████████████

$(RESET)
endef
export SO_LONG

CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= so_long
RM= rm -f
MFLAGS= -lmlx -L/usr/include/minilibx-linux/ -lXext -lX11
SRC= mandatory/main.c \
	mandatory/get_next_line_utils.c \
	mandatory/get_next_line.c \
	mandatory/so_long_check_map.c \
	mandatory/so_long_path.c \
	mandatory/so_long_utils.c \
	mandatory/set_window.c \
	mandatory/click_move.c \
	printf/ft_printf.c \
	printf/ft_printf_ft.c

OBJ= $(SRC:.c=.o)

all: $(NAME)
	@echo "$$SO_LONG"

%.o: %.c mandatory/so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re : fclean all

.PHONY: clean fclean re all

