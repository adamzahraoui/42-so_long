/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:42:44 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/17 20:03:14 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_walls(char *wals)
{
	int	i;

	i = 0;
	while (wals[i] != '\0' && wals[i] != '\n')
		i++;
	if (i > 1)
	{
		if (wals[0] == '1' && wals[i - 1] == '1')
			return (1);
	}
	return (0);
}

int	check_wals(char *argv, t_so_long_check *map)
{
	char	*str;

	(1) && (map->i = 0, map->fd = open(argv, O_RDONLY), str = get(map->fd));
	if (!str || map->fd < 0)
		return (close(map->fd), 0);
	while (str[map->i] != '\0' && str[map->i] != '\n')
		if (str[map->i++] != '1')
			map->map_inv--;
	free(str);
	str = get(map->fd);
	while (str)
	{
		map->i = 0;
		if (check_walls(str) == 0)
			map->map_inv--;
		while (str[map->i] == '1' && str[map->i] != '\n' && str[map->i])
			map->i++;
		if (str[map->i] == '\0')
			map->i = -1;
		free(str);
		str = get(map->fd);
	}
	if (map->i == -1 && map->map_inv == 0)
		return (close(map->fd), 1);
	return (close(map->fd), 0);
}

int	check_other(char *argv, t_so_long_check *map)
{
	char	*str;
	int		i;

	(1) && (i = 0, map->fd = open(argv, O_RDONLY), str = get(map->fd));
	if (!str)
		return (close(map->fd), 0);
	while (str)
	{
		i = 0;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] == 'C')
				map->eat++;
			if (str[i] == 'E')
				map->door++;
			if (str[i++] == 'P')
				map->pos++;
		}
		free(str);
		str = get(map->fd);
	}
	if (map->door == 1 && map->eat != 0 && map->pos == 1)
		return (close(map->fd), 1);
	return (close(map->fd), 0);
}

int	check_rectangular(char *argv, t_so_long_check *map)
{
	char	*str;
	int		x;

	(1) && (map->fd = open(argv, O_RDONLY), str = get(map->fd), x = 1);
	if (!str)
		return (close(map->fd), 0);
	map->l3rd++;
	map->tol = ft_strlen_map(str);
	free(str);
	str = get(map->fd);
	map->l3rd++;
	while (str)
	{
		if (map->tol != ft_strlen_map(str))
			x = 0;
		free(str);
		str = get(map->fd);
		map->l3rd++;
	}
	if (map->l3rd >= 3 && map->tol >= 3 && x == 1)
		return (close(map->fd), free(str), 1);
	return (ft_printf("Error :The map must be rectangular\n"), close(map->fd),
		free(str), 0);
}

int	check_map(char *argv, t_so_long_check *map)
{
	if (check_wals(argv, map) == 1)
	{
		if (check_other(argv, map) == 1
			&& check_rectangular(argv, map) == 1)
		{
			if (flood_file(argv, map) == 1)
				return (1);
			return (ft_printf("Error : no path\n"), print_error(map), 0);
		}
		else
			return (print_error(map), 0);
	}
	return (ft_printf("Error\n"), 0);
}
