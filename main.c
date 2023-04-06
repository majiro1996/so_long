/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:33:15 by manujime          #+#    #+#             */
/*   Updated: 2023/04/06 19:04:31 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checks if the map extension is correct*/
int	ft_extension_check(char *str)
{
	int		len;
	char	*aux;

	len = ft_strlen(str);
	if (len < 4)
		return (0);
	aux = str + (len - 4);
	if (ft_strcmp(aux, ".ber") == 0)
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error, too many arguments\n");
		else
			ft_printf("Error, no mapfile found\n");
		exit(1);
	}
	if (ft_extension_check(argv[1]))
	{
		ft_printf("this working mate\n");
	}
}
