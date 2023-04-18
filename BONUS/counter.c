/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:59:57 by manujime          #+#    #+#             */
/*   Updated: 2023/04/18 16:28:11 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_counter(t_game *game)
{
	char	*counter;

	counter = ft_itoa(game->move_count);
	mlx_delete_image(game->mlx, game->text);
	game->text = mlx_put_string(game->mlx, counter, 8, 4);
	free(counter);
}
