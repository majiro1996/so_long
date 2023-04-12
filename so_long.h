/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:47:35 by manujime          #+#    #+#             */
/*   Updated: 2023/04/12 10:48:45 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"

typedef struct s_point
{
	int	x;
	int	y;
}		t_point;

//map_check
char	**ft_map_check(char *mapfile);
//map_loader
int		ft_count_y(char *mapfile);
char	**ft_charge_map(char *mapfile);

#endif