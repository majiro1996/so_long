/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 23:30:08 by manujime          #+#    #+#             */
/*   Updated: 2023/04/11 00:35:12 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_flood_fill(void)
{
	//code
}

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

	while (map[c])
	{
		k = 0;
		while (map[c][k])
		{
			ft_printf("pls work");//
			if (ft_strchr("01CEP", map[c][k]) == NULL)
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

int	ft_map_check(char *mapfile)
{
	int		clear;
	char	**map;

	clear = 0;
	map = ft_charge_map(mapfile);
	ft_print_char_matrix(map);
	clear += ft_shape(map, mapfile);
	clear += ft_elements(map);
	//clear += ft_walls(map);
	if (clear == 2)
	{
		ft_printf("^-^ working");
		return (1);
	}
	else
		return(0);
}
