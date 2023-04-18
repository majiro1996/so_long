/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:56:24 by manujime          #+#    #+#             */
/*   Updated: 2023/04/17 15:05:06 by manujime         ###   ########.fr       */
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

void	ft_data_init(t_game *game, char **map, char *mapfile)
{
	t_point	pos;

	pos = ft_get_player_yx(map);
	game->textures = NULL;
	game->mlx = NULL;
	game->player = NULL;
	game->map = map;
	game->move_count = 0;
	game->total_collect = ft_el_count(map, 'C');
	game->current_collect = 0;
	game->current_y = pos.y;
	game->current_x = pos.x;
	game->size_y = ft_count_y(mapfile);
	game->size_x = ft_strlen(map[0]) - 1;
	game->exit = 0;
	game->key_pressed = 0;
}
