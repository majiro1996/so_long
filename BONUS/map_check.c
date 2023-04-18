/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:30:08 by manujime          #+#    #+#             */
/*   Updated: 2023/04/17 14:57:59 by manujime         ###   ########.fr       */
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

/*counts how many elements of one type are in the map*/
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

/*checks if all borders of the map are '1'*/
int	ft_walls(char **map, char *mapfile)
{
	int		c;
	int		x_len;
	int		y_len;

	x_len = ft_strlen(map[0]);
	y_len = ft_count_y(mapfile);
	c = 0;
	while (map[0][c] == '1')
		c++;
	if (c != x_len - 1)
		return (0);
	c = 1;
	while (c < (y_len - 1))
	{
		if (map[c][0] != '1' || map[c][x_len - 2] != '1')
			return (0);
		c++;
	}
	c = 0;
	while (map[y_len - 1][c] == '1')
		c++;
	if (c != x_len - 1)
		return (0);
	return (1);
}

/*checks if the map is valid and returns it, if it's not it prints
an Error message*/
int	ft_map_check(char *mapfile)
{
	int		clear;
	char	**map;

	clear = 0;
	map = ft_charge_map(mapfile);
	clear += ft_shape(map, mapfile);
	clear += ft_elements(map);
	if (!(ft_el_count(map, 'P') == 1 && ft_el_count(map, 'C') >= 1
			&& ft_el_count(map, 'E') == 1))
	{
		clear --;
		ft_printf("Error, wrong number of some elements in the map\n");
	}
	if (ft_walls(map, mapfile) != 1)
	{
		clear --;
		ft_printf("Error, map not surrounded by walls\n");
	}
	ft_free_char_matrix(map);
	if (clear == 2)
		return (1);
	return (0);
}
