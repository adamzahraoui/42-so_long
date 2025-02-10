/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:46:11 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/10 10:39:01 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (map->lbab != 1)
		ft_printf("Error : There is no exit on the map\n");
	if (map->makla == 0)
		ft_printf("Error : There is no collectible on the map\n");
	if (map->pos != 1)
		ft_printf("Error : There is no player on the map\n");
}

int	main(int argc, char **argv)
{
	t_so_long_check	map;

	map.wals = 0;
	map.lbab = 0;
	map.makla = 0;
	map.pos = 0;
	map.pist = 0;
	map.mostatil = 0;
	map.find_c = 0;
	map.find_e = 0;
	map.l3rd = 0;
	map.tol = 0;
	if (argc == 2)
	{
		if (check_map(argv[1], &map) == 0 || check_extention(argv[1]) == 0)
			return (print_error(&map), 1);
		else
			return (set_window(&map), free_free(&map), 1);
	}
	else
		printf("Error: select one map\n");
	return (1);
}
