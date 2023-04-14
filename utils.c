/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:26:42 by manujime          #+#    #+#             */
/*   Updated: 2023/04/14 20:26:53 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_finish(t_game *game)
{
	if (game->current_collect == game->total_collect)
	{
		mlx_close_window(game->mlx);
		ft_printf("Give me those potions you twat\n");
	}
	else
		ft_printf("Don't you dare to come down here without my potions!!!\n");
}

void	ft_the_end(t_game *game)
{
	if (game->map[game->current_y][game->current_x] == 'E')
		ft_finish(game);
	game->key_pressed = 0;
}

void	ft_take_potion(t_game *game)
{
	game->current_collect++;
	game->map[game->current_y][game->current_x] = '0';
	//mlx_image_to_window(game->mlx, game->floor, x * 32, y * 32);
}
