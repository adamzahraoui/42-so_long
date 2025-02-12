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
BNAME= so_long_v2
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
	mandatory/ft_printf.c \
	mandatory/ft_printf_ft.c

BSRC = bonus/main.c \
	bonus/get_next_line_utils.c \
	bonus/get_next_line.c \
	bonus/so_long_check_map.c \
	bonus/so_long_path.c \
	bonus/so_long_utils.c \
	bonus/set_window.c \
	bonus/click_move.c \
	bonus/ft_printf.c \
	bonus/ft_printf_ft.c \
	bonus/display.c \
	bonus/enemy.c

OBJ= $(SRC:.c=.o)
BOBJ= $(BSRC:.c=.o)

all: $(NAME)
	@echo "$$SO_LONG"

%.o: %.c mandatory/so_long.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(MFLAGS) -o $(NAME)

%.o: %.c bonus/so_long_bonus.h
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus : $(BOBJ)
	@$(CC) $(CFLAGS) $(BOBJ) $(MFLAGS) -o $(BNAME)
	@touch bonus

clean:
	@$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME) $(BNAME)

re : fclean all

.PHONY: clean fclean re all