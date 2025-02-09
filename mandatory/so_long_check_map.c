/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:42:44 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/09 14:10:30 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_l7it(char *wals)
{
	int	i;

	i = 0;
	while (wals[i] != '\0' && wals[i] != '\n')
		i++;
	if (wals[0] != '1' || wals[i - 1] != '1')
		return (0);
	return (1);
}

int	check_wals(char *argv, so_long_check *map)
{
	char	*str;
	int		i;

	(1) && (i = 0, map->fd = open(argv, O_RDONLY),
		str = get_next_line(map->fd));
	if (!str)
		return (close(map->fd), 0);
	while (str[i] != '\0' && str[i] != '\n')
		if (str[i++] != '1')
			return (free(str), close(map->fd), 0);
	free(str);
	str = get_next_line(map->fd);
	while (str != NULL)
	{
		i = 0;
		if (check_l7it(str) == 0)
			return (free(str), close(map->fd), 0);
		while (str[i] == '1' && str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\0')
			i = -1;
		free(str);
		str = get_next_line(map->fd);
	}
	if (i == -1)
		return (free(str), close(map->fd), 1);
	return (free(str), close(map->fd), 0);
}

int	check_other(char *argv, so_long_check *map)
{
	char	*str;
	int		i;

	(1) && (i = 0, map->fd = open(argv, O_RDONLY),
		str = get_next_line(map->fd));
	if (!str)
		return (close(map->fd), 0);
	while (str)
	{
		i = 0;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] == 'C')
				map->makla++;
			if (str[i] == 'E')
				map->lbab++;
			if (str[i] == 'P')
				map->pos++;
			i++;
		}
		free(str);
		str = get_next_line(map->fd);
	}
	if (map->lbab == 1 && map->makla != 0 && map->pos == 1)
		return (close(map->fd), 1);
	return (close(map->fd), 0);
}

int	check_mostatil(char *argv, so_long_check *map)
{
	char	*str;

	map->fd = open(argv, O_RDONLY);
	str = get_next_line(map->fd);
	if (!str)
		return (0);
	map->l3rd++;
	map->tol = ft_strlen_map(str);
	free(str);
	str = get_next_line(map->fd);
	map->l3rd++;
	while (str)
	{
		if (map->tol != ft_strlen_map(str))
			return (close(map->fd), free(str), 0);
		free(str);
		str = get_next_line(map->fd);
		map->l3rd++;
	}
	if (map->l3rd >= 3 && map->tol >= 3)
		return (close(map->fd), free(str), 1);
	return (ft_printf("Error :The map must be rectangular\n"), close(map->fd),
		free(str), 0);
}

int	check_map(char *argv, so_long_check *map)
{
	if (check_wals(argv, map) == 1 && check_other(argv, map) == 1
		&& check_mostatil(argv, map) == 1)
	{
		if (flood_file(argv, map) == 1)
			return (1);
		free_free(map);
		return (0);
	}
	return (0);
}
