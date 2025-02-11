/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:17 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/11 20:32:30 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "/usr/include/minilibx-linux/mlx.h"
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
	char	**str;
	char	**str_copy;
	int		move;
	int		i;
	int		a;

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

	int		z;
	int		w;
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

#endif