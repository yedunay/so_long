/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:40:49 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 13:04:16 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_paint(int last, char *map, t_data *d)
{
	if (map[last] == 'P')
	{
		d->path = 1;
		return ;
	}
	map[last] = 'A';
	if (map[last - 1] != '1' && map[last - 1] != 'A')
		ft_paint((last - 1), map, d);
	if (map[last + 1] != '1' && map[last + 1] != 'A')
		ft_paint((last + 1), map, d);
	if (map[last - d->num_c - 1] != '1' && map[last - d->num_c - 1] != 'A')
		ft_paint((last - d->num_c - 1), map, d);
	if (map[last + d->num_c + 1] != '1' && map[last + d->num_c + 1] != 'A')
		ft_paint((last + d->num_c + 1), map, d);
}

void	ft_check_path(int i, t_data *d)
{
	char	*aux_map;

	d->path = 0;
	aux_map = ft_calloc(sizeof(char), 1);
	if (!aux_map)
		ft_error(d);
	aux_map = ft_strjoin(aux_map, d->map);
	ft_paint(i, aux_map, d);
	free (aux_map);
	if (d->path == 0)
		ft_error(d);
}

void	ft_check_min(t_data *d)
{
	int	i;

	i = 0;
	while (d->map[i])
	{
		if (d->map[i] != 'E' && d->map[i] != 'P' && d->map[i] != 'C' && \
		d->map[i] != '1' && d->map[i] != '0' && d->map[i] != '\n' && d->map[i])
			ft_error(d);
		else if (d->map[i] == 'E' || d->map[i] == 'C')
		{
			if (d->map[i] == 'C')
				d->letter_c++;
			if (d->map[i] == 'E')
				d->letter_e--;
			ft_check_path(i, d);
		}
		else if (d->map[i] == 'P')
			d->letter_p--;
		i++;
	}
	if (d->letter_e != 0 || d->letter_p != 0 || d->letter_c == 0)
		ft_error(d);
}

int	ft_check_edg(t_data *d)
{
	int	i;
	int	x;
	int	len;

	i = 0;
	x = ft_strlen(d->map) - 1;
	while ((d->map[i] != '\n') && (d->map[i]))
	{
		if ((d->map[i] != '1') || (d->map[x] != '1'))
			ft_error(d);
		i++;
		x--;
	}
	len = i;
	while (d->map[len])
	{
		if ((d->map[len] != '\n') && (d->map[len] != '\0'))
			ft_error(d);
		if ((d->map[len] == '\n' && d->map[len + 1] != '1') \
		|| (d->map[len] == '\n' && d->map[len - 1] != '1'))
			ft_error(d);
		len = len + i + 1;
	}
	d->num_c = i;
	return (len);
}

void	ft_check_map(t_data *d)
{
	int	len;

	if (!d->map[0])
		ft_error(d);
	len = ft_check_edg(d);
	if (!d->map[d->num_c])
		ft_error(d);
	d->num_l = (len + 1) / (d->num_c + 1);
	d->letter_c = 0;
	d->letter_p = 1;
	d->letter_e = 1;
	ft_check_min(d);
}
