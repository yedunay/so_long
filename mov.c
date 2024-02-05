/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:40:42 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 12:48:49 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include "minilibx/mlx.h"

void	ft_write_mov(t_data *d)
{
	char	*aux_num;

	aux_num = ft_itoa(d->num_mov);
	write(1, "-> Number of movements: ", 25);
	write(1, aux_num, ft_strlen(aux_num));
	write(1, "\n", 1);
	if (aux_num)
		free(aux_num);
}

int	ft_check_step(t_data *d, int i)
{
	if (d->map[i] == '1')
		return (0);
	else if (d->map[i] == 'C')
	{
		d->letter_c--;
		if (d -> map[d -> main_init] != 'X')
			d->map[d->main_init] = '0';
		d->map[i] = 'P';
	}
	else if (d -> map[d -> main_init] == 'X')
	{
		d -> map[d -> main_init] = 'E';
		d -> map[i] = 'P';
	}
	else if ((d->map[i] == 'E' || d ->map[i] == 'X') && d->letter_c == 0)
	{
		write(1, "-----------------------------\n", 30);
		write(1, "-> You made it, my friend!\n", 28);
		write(1, "-----------------------------\n", 30);
		ft_free(d);
	}
	else if ((d->map[i] == 'E' || d -> map[i] == 'X')  && d->letter_c != 0)
	{
		d->map[d->main_init] = '0';
		d->map[i] = 'X';
	}
	else if (d->map[i] == '0')
	{
		d->map[d->main_init] = '0';
		d->map[i] = 'P';
	}
	return (1);
}

int	ft_read_mov(int key, t_data *d)
{
	int		i;

	i = 0;
	if (key == 53)
	{
		mlx_destroy_window(d->mlx, d->win);
		ft_free(d);
	}
	else if (key == 13)
		i = d->main_init - d->num_c - 1;
	else if (key == 1)
		i = d->main_init + d->num_c + 1;
	else if (key == 0)
		i = d->main_init - 1;
	else if (key == 2)
		i = d->main_init + 1;
	if (ft_check_step(d, i))
	{
		d->num_mov++;
		mlx_clear_window(d -> mlx, d -> win);
		ft_init_map(d);
		ft_write_mov(d);
	}
	return (0);
}
