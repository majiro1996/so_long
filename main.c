/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manujime <manujime@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:33:15 by manujime          #+#    #+#             */
/*   Updated: 2023/04/07 12:31:21 by manujime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*checks if the map extension is correct*/
int	ft_extension_check(char *str, char *ex)
{
	int		len;
	int		ex_len;
	char	*aux;

	len = ft_strlen(str);
	ex_len = ft_strlen(ex);
	if (len < ex_len)
		return (0);
	aux = str + (len - ex_len);
	if (ft_strcmp(aux, ex) == 0)
		return (1);
	else
		return (0);
}

/*initialices the game*/
void	ft_so_long(char *mapfile)
{
	if (mapfile)
		ft_printf("ok\n");
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		if (argc > 2)
			ft_printf("Error, too many arguments\n");
		if (argc < 2)
			ft_printf("Error, no mapfile found\n");
		exit (1);
	}
	if (ft_extension_check(argv[1], ".ber"))
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_printf("Error, no mapfile found\n");
			exit (1);
		}
		close(fd);
		ft_so_long(argv[1]);
		return (0);
	}
	else
		ft_printf("Error, not a .ber file\n");
	exit (1);
}
