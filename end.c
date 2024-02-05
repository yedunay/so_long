/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:41:07 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 12:53:07 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

int	ft_free(t_data *d)
{
	if (d->map)
		free(d->map);
	if (d)
		free(d);
	exit(0);
}

void	ft_error(t_data *d)
{
	write(1, "ERROR\n-> Sorry bro, the game had ", 34);
	write(1, "problems to start. :(\n", 23);
	ft_free(d);
}
