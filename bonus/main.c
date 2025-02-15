/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:11 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/15 12:30:21 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*free_free(t_so_long_check *map)
{
	int	i;

	i = map->l3rd;
	while (i--)
	{
		free(map->str[i]);
		free(map->str_copy[i]);
	}
	free(map->str_copy);
	free(map->str);
	return (NULL);
}

int	check_extention(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
		i++;
	if (argv[i - 1] == 'r' && argv[i - 2] == 'e' && argv[i - 3] == 'b' && argv[i
			- 4] == '.' && argv[i - 5] != '/' && i > 4)
		return (1);
	return (ft_printf("The map name must end in .ber"), 0);
}

void	print_error(t_so_long_check *map)
{
	if (map->door != 1)
		ft_printf("Error : There should be one exit on the map\n");
	if (map->eat == 0)
		ft_printf("Error : There is no collectible on the map\n");
	if (map->pos != 1)
		ft_printf("Error : There must be one player on the map\n");
}

int	check_map_numeric(t_so_long_check *map)
{
	int	i;
	int	y;

	y = 0;
	while (map->str[y])
	{
		i = 0;
		while (map->str[y][i])
		{
			if (map->str[y][i] != '1' && map->str[y][i] != '0'
				&& map->str[y][i] != 'P' && map->str[y][i] != 'C'
				&& map->str[y][i] != 'E' && map->str[y][i] != 'L')
			{
				ft_printf("Error :The map contains an unknown item\n");
				return (0);
			}
			i++;
		}
		y++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_so_long_check	map;

	map.wals = 0;
	map.door = 0;
	map.eat = 0;
	map.pos = 0;
	map.pist = 0;
	map.rectangular = 0;
	map.find_c = 0;
	map.find_e = 0;
	map.l3rd = 0;
	map.tol = 0;
	map.map_inv = 0;
	if (argc == 2)
	{
		if (check_map(argv[1], &map) == 0 )
			return (ft_printf("Error: The map contains a newline\n"), 1);
		if(check_extention(argv[1]) == 0 || check_map_numeric(&map) == 0)
			return (free_free(&map), print_error(&map), 1);
		else
			return (set_window(&map), free_free(&map), 1);
	}
	else
		printf("Error: select one map\n");
	return (1);
}
