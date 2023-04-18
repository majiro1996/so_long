/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:59:07 by manujime          #+#    #+#             */
/*   Updated: 2023/04/18 18:44:05 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_list(t_game *game, mlx_image_t *image)
{
	if (game->enemy_c == 0)
	{
		game->enemy = malloc(sizeof(mlx_image_t *)
				* (ft_el_count(game->map, 'A') + 1));
		if (!game->enemy)
			exit(1);
		game->enemy[0] = image;
		game->current_collect++;
	}
	else
	{
		game->enemy[game->enemy_c] = image;
		game->enemy_c++;
	}
}

void	ft_render_enemy(t_game *game)
{
	mlx_image_t	*aux;
	int			y;
	int			x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'A')
			{
				aux = mlx_texture_to_image(game->mlx, game->textures->enemy_1);
				if (mlx_image_to_window(game->mlx, aux, x * 32,
						y * 32) < 0)
					exit(1);
				ft_enemy_list(game, aux);
			}
			x++;
		}
		y++;
	}
}
