/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:56:24 by manujime          #+#    #+#             */
/*   Updated: 2023/04/13 15:42:44 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_y(char *mapfile)
{
	int		len;
	int		fd;
	char	*line;

	len = 0;
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	free (line);
	close(fd);
	return (len);
}

/*saves the content of the map into a char ** and returns it*/
char	**ft_charge_map(char *mapfile)
{
	int		c;
	int		fd;
	char	*line;
	char	**map;

	c = 0;
	map = malloc(sizeof(char *) * (ft_count_y(mapfile) + 1));
	if (!map)
		return (NULL);
	fd = open(mapfile, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map[c] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		c++;
	}
	free(line);
	close(fd);
	map[c] = NULL;
	return (map);
}

void	ft_data_init(t_game *game, char **map)
{
	game->mlx = 0;
	game->man = 0;
	game->map = map;
	game->move_count = 0;
	game->total_collect = ft_el_count(map, 'C');
	game->current_collect = 0;
	game->current_y = 0;
	game->current_x = 0;
	game->size_y = 10;
	game->size_x = 10;
	game->exit = 0;
	game->key_pressed = 0;
}
