/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:59:57 by manujime          #+#    #+#             */
/*   Updated: 2023/04/17 18:02:24 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->move_count);
	mlx_delete_image(game->mlx, game->text);
	game->text = mlx_put_string(game->mlx, moves, 8, 4);
	free(moves);
}
