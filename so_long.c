/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:41:13 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 13:14:05 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"
#include <unistd.h>

void	ft_init_all(t_data *d, char *file)
{
	ft_check_ext(d, file);
	ft_check_file(d, file);
	ft_check_map(d);
	ft_init_img(d);
	d->win = mlx_new_window(d->mlx, d->x, d->y, "so_long");
	ft_init_map(d);
	d->num_mov = 0;
}

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc != 2)
	{
		write(1, "ERROR\n -> Incorrect number of arguments.\n", 42);
		return (0);
	}
	d = ft_calloc(1, sizeof(t_data));
	if (!d)
		return (0);
	d->mlx = mlx_init();
	ft_init_all(d, argv[1]);
	mlx_key_hook(d->win, ft_read_mov, d);
	mlx_hook(d->win, 17, 0, ft_free, d);
	mlx_loop(d->mlx);
	ft_free(d);
	return (0);
}
