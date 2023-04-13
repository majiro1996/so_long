/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 20:52:23 by manujime          #+#    #+#             */
/*   Updated: 2023/04/13 16:10:56 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_window(t_game *game)
{
	game->mlx = mlx_init(game->size_x * 32, game->size_y * 32,
			"so_long", false);
	if (!game->mlx)
	{
		ft_printf("Graphic error\n");
		exit(1);
	}
	mlx_loop_hook(game->mlx, &ft_hook, game->mlx);
	mlx_loop(game->mlx);
	exit(0);
}
