/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:30:08 by manujime          #+#    #+#             */
/*   Updated: 2023/04/11 17:44:35 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checks that all rows are the same length 
and that x and y size is bigger than 3*/
int	ft_shape(char **map, char *mapfile)
{
	int					c;
	unsigned int		x_len;
	unsigned int		y_len;

	c = 0;
	x_len = ft_strlen(map[0]);
	y_len = ft_count_y(mapfile);
	if (x_len < 4 || y_len < 4)
		return (0);
	while (map[c])
	{
		if ((unsigned int)c == y_len - 1)
			x_len--;
		if (ft_strlen(map[c]) != x_len)
		{
			ft_printf("Error, wrong map shape\n");
			return (0);
		}
		c++;
	}
	return (1);
}

/*checks if all the characters of the map are suported characters*/
int	ft_elements(char **map)
{
	int		c;
	int		k;

	c = 0;
	while (map[c])
	{
		k = 0;
		while (map[c][k])
		{
			if (ft_strchr("01CEP\n", map[c][k]) == NULL)
			{
				ft_printf("Error, non suported elements in the map\n");
				return (0);
			}
			k++;
		}
		c++;
	}
	return (1);
}

int	ft_el_count(char **map, char el)
{
	int		el_count;
	int		c;
	int		k;

	el_count = 0;
	c = 0;
	while (map[c])
	{
		k = 0;
		while (map[c][k])
		{
			if (map[c][k] == el)
			{
				el_count++;
			}
			k++;
		}
		c++;
	}
	return (el_count);
}

int	ft_walls(char **map, char *mapfile)
{
	int		c;
	int		k;

	c = 0;
	while (map[c])
	{
		k = 0;
		while (map[c][k])
		{
			if (map[c][k] != '1')
			{
				ft_printf("Error, not surrounded by walls\n");
				return (0);
			}
			k++;
		}
		c++;
	}
	return (1);
}

int	ft_map_check(char *mapfile)
{
	int		clear;
	char	**map;

	clear = 0;
	map = ft_charge_map(mapfile);
	ft_print_char_matrix(map);
	clear += ft_shape(map, mapfile);
	clear += ft_elements(map);
	if (ft_el_count(map, 'P') == 1 && ft_el_count(map, 'C') >= 1
		&& ft_el_count(map, 'E') == 1)
		clear += 1;
	clear += ft_walls(map, mapfile);
	if (clear == 3)
	{
		ft_printf("^-^ working");
		return (1);
	}
	else
		return (0);
}
