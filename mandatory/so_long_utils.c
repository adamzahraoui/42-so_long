/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:27 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/05 10:56:00 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_strlen_map(char *str)
{
    int i;

    i = 0;
    while(str[i] && str[i] != '\n')
        i++;
    return (i);
}

int position(char **str, so_long_check *map)
{
    map->y = 0;
    while(str[map->y])
    {
        map->x = 0;
        while(str[map->y][map->x++])
            if(str[map->y][map->x] == 'P')
                return (1);
        map->y++;    
    }
    return (0);
}

int    free_map(char **str, so_long_check *map)
{
    while(map->y--)
        free(str[map->y]);
    free(str);
    return (0);
}

void    copy_map(so_long_check *map)
{
    int y;
    int i;

    y = 0;
    i = 0;
    map->str_copy = malloc((map->l3rd + 1) * sizeof(char *));
    while(map->str[y])
    {
        i = 0;
        map->str_copy[y] = malloc(map->tol + 1);
        while(map->str[y][i])
        {
            map->str_copy[y][i] = map->str[y][i];
            i++;
        }
        y++;
    }
}

int flood_file(char *argv, so_long_check *map)
{
    int i;
    char *str;

    (1)&&(map->fd = open(argv, O_RDONLY), map->y = 0);
    if(!(map->str = malloc((map->l3rd + 1) * sizeof(char *))))
        return (0);
    if(!(str = get_next_line(map->fd)))
        return (close(map->fd), 0);
    while(str)
    {
        (1)&&(i = 0, map->x = 0);
        if(!(map->str[map->y] = malloc(map->tol)))
            return(free_map(map->str,map));
        while(str[i] && str[i] != '\n')
            map->str[map->y][map->x++] = str[i++];
        map->str[map->y][map->x] = '\0';
        free(str);
        map->y++;
        str = get_next_line(map->fd);
    }
    map->str[map->y] = NULL;
    copy_map(map);
    if(position(map->str, map) == 1 && check_tri9(map->str_copy, map->x, map->y, map) == 1)
        return (1);
    return (0);
}
