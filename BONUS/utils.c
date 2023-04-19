/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:26:42 by manujime          #+#    #+#             */
/*   Updated: 2023/04/19 17:27:30 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_finish(t_game *game)
{
	if (game->total_collect == 0)
	{
		mlx_close_window(game->mlx);
		ft_printf("Bring those potions down here, FAST!!\n");
		free(game->potion);
	}
	else
		ft_printf("Don't you dare to come down here without my potions!!!\n");
}

void	ft_the_end(t_game *game)
{
	if (game->map[game->current_y][game->current_x] == 'E')
		ft_finish(game);
	if (game->map[game->current_y][game->current_x] == 'A' && game->danger == 1)
	{
		mlx_close_window(game->mlx);
		ft_printf("Nooooo, hhelpp...arhdfdhj...\n");
		free(game->potion);
	}
	game->key_pressed = 0;
}

void	ft_collectible_list(t_game *game, mlx_image_t *image)
{
	if (game->current_collect == 0)
	{
		game->potion = malloc(sizeof(mlx_image_t *)
				* (game->total_collect + 1));
		if (!game->potion)
			exit(1);
		game->potion[0] = image;
		game->current_collect++;
		game->potion[game->total_collect] = 0;
	}
	else
	{
		game->potion[game->current_collect] = image;
		game->current_collect++;
	}
}

void	ft_take_potion(t_game *game, int y, int x)
{
	int	i;

	i = 0;
	game->total_collect--;
	game->map[y][x] = '0';
	ft_printf("Potions collected: %d\n", game->current_collect
		- game->total_collect);
	while (game->potion[i])
	{
		if (game->potion[i]->instances[0].y == y * 32
			&& game->potion[i]->instances[0].x == x * 32)
		{
			ft_printf("And I take this potion\n");
			game->potion[i]->enabled = 0;
			break ;
		}
		i++;
	}
}
