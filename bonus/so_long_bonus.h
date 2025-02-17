/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:17 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/17 20:00:56 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "/usr/include/minilibx-linux/mlx.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42
# define PICTURE_WALL "./picture/wall.xpm"
# define PICTURE_GROUND "./picture/ground.xpm"
# define PICTURE_PLAYER_R "./picture/right.xpm"
# define PICTURE_PLAYER_L "./picture/left.xpm"
# define PICTURE_COIN "./picture/coin.xpm"
# define PICTURE_EXIT "./picture/exit.xpm"
# define PICTURE_ENEMY_R "./picture/enemy_right.xpm"

# define PICTURE_F1 "./picture/1.xpm"
# define PICTURE_F2 "./picture/2.xpm"
# define PICTURE_F3 "./picture/3.xpm"
# define PICTURE_F4 "./picture/4.xpm"
# define PICTURE_F5 "./picture/5.xpm"
# define PICTURE_F6 "./picture/6.xpm"

typedef struct s_so_long
{
	int		wals;
	int		fd;
	int		eat;
	int		door;
	int		pos;
	int		pist;
	int		rectangular;
	int		x;
	int		y;
	int		tol;
	int		l3rd;
	int		find_c;
	int		find_e;
	int		pos_e_x;
	int		pos_e_y;
	int		pos_ex;
	int		pos_ey;
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*ground;
	void	*player;
	void	*player_left;
	void	*coin;
	void	*exit;
	void	*enemy;
	void	*enemy_l;
	char	**str;
	char	**str_copy;
	int		move;
	int		i;
	int		a;

	void	*f1;
	void	*f2;
	void	*f3;
	void	*f4;
	void	*f5;
	void	*f6;

	int		width;
	int		height;

	int		width_g;
	int		height_g;

	int		width_p;
	int		height_p;

	int		width_l;
	int		height_l;

	int		width_c;
	int		height_c;

	int		width_e;
	int		height_e;

	int		width_ene;
	int		height_ene;

	int		width_ene_l;
	int		height_ene_l;

	int		width_f;
	int		height_f;

	int		c;
	int		d;

	int		z;
	int		w;

	int		map_inv;
}			t_so_long_check;

char		*get(int fd);
char		*ft_strjoin(const char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
int			main(int argc, char **argv);
int			check_map(char *argv, t_so_long_check *map);
int			check_walls(char *wals);
int			ft_strlen_map(char *str);
int			flood_file(char *argv, t_so_long_check *map);
int			check_rectangular(char *argv, t_so_long_check *map);
int			check_wals(char *argv, t_so_long_check *map);
int			check_path(char **tri9, int x, int y, t_so_long_check *map);
void		set_window(t_so_long_check *map);
void		ft_putnbr(int nb);
void		up(t_so_long_check *data);
void		right(t_so_long_check *data);
void		left(t_so_long_check *data);
void		down(t_so_long_check *data);
int			close_map(t_so_long_check *close);
void		*free_free(t_so_long_check *map);
void		set_pic(char c, t_so_long_check *map, int x, int y);
void		free_free_map(t_so_long_check *map, int i);
void		display_move(t_so_long_check *data);
int			close_x(t_so_long_check *map);
void		enemy_left(t_so_long_check *data);
void		enemy_right(t_so_long_check *data);
void		enemy_up(t_so_long_check *data);
void		enemy_down(t_so_long_check *data);
void		set_image_frame(t_so_long_check *map);
int			animate_frames(t_so_long_check *map);
void		close_frame(t_so_long_check *close);
void		print_error(t_so_long_check *map);

#endif