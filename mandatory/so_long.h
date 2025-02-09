/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:17 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/09 20:21:46 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "/home/adzahrao/Desktop/so_long/printf/ft_printf.h"
# include "/usr/include/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

typedef struct so_long
{
	int		wals;
	int		fd;
	int		makla;
	int		lbab;
	int		pos;
	int		pist;
	int		mostatil;
	int		x;
	int		y;
	int		tol;
	int		l3rd;
	int		find_C;
	int		find_E;
	int		pos_E_x;
	int		pos_E_y;
	int		pos_EX;
	int		pos_EY;
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

	int z;
	int w;
}			so_long_check;

char		*get_next_line(int fd);
char		*ft_strjoin(const char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *str);
int			main(int argc, char **argv);
int			check_map(char *argv, so_long_check *map);
int			check_l7it(char *wals);
int			ft_strlen_map(char *str);
int			flood_file(char *argv, so_long_check *map);
int			check_mostatil(char *argv, so_long_check *map);
int			check_wals(char *argv, so_long_check *map);
int			check_tri9(char **tri9, int x, int y, so_long_check *map);
void		set_window(so_long_check *map);
void		ft_putnbr(int nb);
void		up(so_long_check *data);
void		right(so_long_check *data);
void		left(so_long_check *data);
void		down(so_long_check *data);
int			close_map(so_long_check *close);
void		*free_free(so_long_check *map);
void		set_pic(char c, so_long_check *map, int x, int y);

#endif