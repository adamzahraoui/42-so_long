/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:17 by adzahrao          #+#    #+#             */
/*   Updated: 2025/01/28 18:14:16 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#  define BUFFER_SIZE 42


typedef struct so_long
{
    int wals;
    int fd;
    int makla;
    int lbab;
    int pos;
    int pist;
    int mostatil;
    int x;
    int y;
    int tol;
    int l3rd;
}so_long_check;


char	*get_next_line(int fd);
char	*ft_strjoin(const char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
int     main(int argc, char **argv);
int     check_map(char *argv);
int     check_l7it(char *wals);
int     check_map(char *argv);
int     ft_strlen_map(char *str);
int     flood_file(char *argv, so_long_check *map);
int     check_mostatil(char *argv, so_long_check *map);
int     check_wals(char *argv, so_long_check *map);


#endif