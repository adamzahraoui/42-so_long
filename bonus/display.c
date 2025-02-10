/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adzahrao <adzahrao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:13:37 by adzahrao          #+#    #+#             */
/*   Updated: 2025/02/10 12:38:24 by adzahrao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	size;
	size_t	i;

	size = ft_strlen(s) + 1;
	p = (char *)malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

int	size_nb(long a)
{
	int	size;

	size = 0;
	if (a < 0)
	{
		a = -a;
		size++;
	}
	while (a > 0)
	{
		a /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		size;
	char	*itoa;
	int		c;

	nb = n;
	c = 0;
	size = size_nb(nb);
	if (n == 0)
		return (ft_strdup("0"));
	itoa = malloc((size + 1) * sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[size] = '\0';
	if (nb < 0)
	{
		nb = -nb;
		itoa[c++] = '-';
	}
	while (size > c)
	{
		itoa[(size--) - 1] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoa);
}

void	display_move(t_so_long_check *data)
{
	char	*nb;

	nb = ft_itoa(data->move);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 0, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 32, 0);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->wall, 64, 0);
	mlx_string_put(data->mlx, data->mlx_win, 13, 20, 0x00FF00, nb);
	data->move++;
	free(nb);
}
