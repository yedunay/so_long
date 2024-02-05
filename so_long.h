/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydunay <ydunay@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 11:39:54 by ydunay            #+#    #+#             */
/*   Updated: 2024/02/05 12:17:26 by ydunay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*main;
	void	*exit;
	void	*coin;
	void	*pexit;
	void	*floor;
	void	*wall;
	int		w;
	int		h;
	int		x;
	int		y;
	int		letter_c;
	int		letter_p;
	int		letter_e;
	int		num_c;
	int		num_l;
	int		num_mov;
	int		main_init;
	int		path;
	char	*map;
}	t_data;

int		ft_free(t_data *d);
int		ft_strlen(char *str);
int		ft_read_mov(int key, t_data *d);
char	*ft_itoa(int n);
char	*ft_strjoin(char *stash, char *buff);
void	*ft_calloc(size_t count, size_t size);
void	ft_error(t_data *d);
void	ft_check_ext(t_data *d, char *file);
void	ft_check_file(t_data *d, char *file);
void	ft_check_map(t_data *d);
void	ft_init_map(t_data *d);
void	ft_init_img(t_data *d);

#endif