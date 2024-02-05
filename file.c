/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:41:02 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 11:54:15 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_check_ext(t_data *d, char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'b' \
	|| file[i - 2] != 'e' || file[i - 1] != 'r')
	{
		write(1, "ERROR\n -> Incorrect extension\n", 31);
		ft_free(d);
	}
}

char	*ft_read_file(int fd, char *line)
{
	int		readed;
	char	*buffer;

	buffer = ft_calloc(sizeof(char), 2);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read (fd, buffer, 1);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(t_data *d, int fd)
{
	char	*line;

	line = ft_calloc(sizeof(char), 1);
	if (!line)
		ft_error (d);
	line = ft_read_file(fd, line);
	return (line);
}

void	ft_check_file(t_data *d, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(1, "ERROR\n -> Problems with file\n", 30);
		ft_free(d);
	}
	d->map = get_next_line(d, fd);
	close(fd);
}
