/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:59:07 by manujime          #+#    #+#             */
/*   Updated: 2023/04/19 17:16:49 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_animation(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->enemy_c)
	{
		if (game->move_count % 3 == 0 || game->move_count % 5 == 0)
			break ;
		ft_printf("moving this thing !!!!???\n");
		if (game->enemy_2[i]->enabled)
		{
			game->enemy_2[i]->enabled = 0;
			game->danger = 0;
		}
		else
		{
			game->enemy_2[i]->enabled = 1;
			game->danger = 1;
		}
		i++;
	}
}

void	ft_enemy_list(t_game *game, mlx_image_t *image)
{
	if (game->enemy_c == 0)
	{
		game->enemy_2 = malloc(sizeof(mlx_image_t *)
				* (game->total_enemy + 1));
		if (!game->enemy_2)
			exit(1);
		game->enemy_2[0] = image;
		game->enemy_c++;
		game->enemy_2[game->total_collect] = 0;
	}
	else
	{
		game->enemy_2[game->enemy_c] = image;
		game->enemy_c++;
	}
}

void	ft_render_hole(t_game *game, int y, int x)
{
	mlx_image_t	*aux;

	if (game->map[y][x] == 'A')
	{
		aux = mlx_texture_to_image(game->mlx, game->textures->enemy_1);
		if (mlx_image_to_window(game->mlx, aux, x * 32,
				y * 32) < 0)
			exit(1);
	}
}

void	ft_render_tentacles(t_game *game, int y, int x)
{
	mlx_image_t	*aux;

	if (game->map[y][x] == 'A')
	{
		aux = mlx_texture_to_image(game->mlx, game->textures->enemy_2);
		if (mlx_image_to_window(game->mlx, aux, x * 32,
				y * 32) < 0)
			exit(1);
		ft_enemy_list(game, aux);
	}
}
