/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:26:42 by manujime          #+#    #+#             */
/*   Updated: 2023/04/14 21:10:26 by manujime         ###   ########.fr       */
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

void	ft_take_potion(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	game->current_collect++;
	game->map[y][x] = '0';
	ft_printf("Potions collected: %d\n", game->current_collect);
	while (i < game->total_collect)
	{
		if (game->potion->instances[i].y == y * 32
			&& game->potion->instances[i].x == x * 32)
		{
			game->potion->instances[i].y += 4000;
			break ;
		}
		i++;
	}
}
