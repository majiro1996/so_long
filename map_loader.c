/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:56:24 by manujime          #+#    #+#             */
/*   Updated: 2023/04/12 12:26:15 by manujime         ###   ########.fr       */
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
