/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:02:25 by manujime          #+#    #+#             */
/*   Updated: 2023/04/17 14:59:10 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_get_player_yx(char **map)
{
	t_point	begin;
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				begin.x = x;
				begin.y = y;
			}
			x++;
		}
		y++;
	}
	return (begin);
}

void	ft_flood_fill(char **map, t_point begin, int *valid)
{
	if (map[begin.y][begin.x] == 'P' || map[begin.y][begin.x] == 'C')
		map[begin.y][begin.x] = '0';
	if (map[begin.y][begin.x] == 'E')
		*valid = 1;
	if (map[begin.y][begin.x] != '0')
		return ;
	map[begin.y][begin.x] = 'F';
	ft_flood_fill(map, (t_point){begin.y - 1, begin.x}, valid);
	ft_flood_fill(map, (t_point){begin.y + 1, begin.x}, valid);
	ft_flood_fill(map, (t_point){begin.y, begin.x - 1}, valid);
	ft_flood_fill(map, (t_point){begin.y, begin.x + 1}, valid);
}

int	ft_path(char **map)
{
	t_point	begin;
	int		valid;

	valid = 0;
	begin = ft_get_player_yx(map);
	ft_flood_fill(map, begin, &valid);
	if (valid == 0)
		ft_printf("Error, no valid path in the map\n");
	return (valid);
}
