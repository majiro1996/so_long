/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:00:30 by manujime          #+#    #+#             */
/*   Updated: 2023/04/14 17:20:49 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	mlx_t	*mlx;
	t_game	*game;

	game = param;
	mlx = game->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (!game->key_pressed)
	{
		if (mlx_is_key_down(mlx, MLX_KEY_UP))
			game->player->instances[0].y -= 32;
		if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
			game->player->instances[0].y += 32;
		if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
			game->player->instances[0].x -= 32;
		if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
			game->player->instances[0].x += 32;
		game->key_pressed = 1;
	}
	else
		game->key_pressed = 0;
}
