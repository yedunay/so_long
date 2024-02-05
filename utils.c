/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:40:19 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 11:53:57 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	int		i;
	int		j;

	if (!stash || !buff)
		return (NULL);
	str = ft_calloc(sizeof(char), ft_strlen(stash) + ft_strlen(buff) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	j = 0;
	while (buff[j])
	{
		str[i + j] = buff[j];
		j++;
	}
	free(stash);
	return (str);
}

size_t	ft_size_malloc(int n)
{
	long int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n != 0)
	{
		n = (n / 10);
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	size;
	long int	ncpy;
	char		*dst;

	size = ft_size_malloc(n);
	ncpy = n;
	dst = ft_calloc(sizeof(char), size + 1);
	if (!dst)
		return (0);
	if (ncpy < 0)
	{
		ncpy = (ncpy * (-1));
		dst[0] = '-';
	}
	dst[size] = '\0';
	while (size > 0)
	{
		if (dst[0] == '-' && size == 1)
			return (dst);
		dst[size - 1] = ((ncpy % 10) + 48);
		ncpy = (ncpy / 10);
		size--;
	}
	return (dst);
}
