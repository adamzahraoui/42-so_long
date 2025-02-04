/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:24:27 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/02 10:43:05 by adzahrao         ###   ########.fr       */
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

int flood_file(char *argv, so_long_check *map)
{
    int i;
    char *str;
    char **tri9;

    (1)&&(map->fd = open(argv, O_RDONLY), map->y = -1);
    if(!(tri9 = malloc((map->l3rd + 1) * sizeof(char *))))
        return (0);
    if(!(str = get_next_line(map->fd)))
        return (close(map->fd), 0);
    while(str)
    {
        (1)&&(i = 0, map->x = 0);
        map->y++;
        if(!(tri9[map->y] = malloc(map->tol)))
            return(free_map(tri9,map));
        while(str[i] && str[i] != '\n')
            tri9[map->y][map->x++] = str[i++];
        tri9[map->y][map->x] = '\0';
        free(str);
        str = get_next_line(map->fd);
    }
    tri9[map->y] = NULL;
    if(position(tri9, map) == 1 && check_tri9(tri9, map->x, map->y, map) == 1)
        return (1);
    return (0);
}
