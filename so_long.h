/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larobbie <larobbie@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:39:13 by sergejleski       #+#    #+#             */
/*   Updated: 2022/04/28 22:43:48 by larobbie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx/mlx.h"

typedef struct s_surface {
	void	*surface;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*img_usr;
	void	*img_bomb;
	void	*img_wall;
	void	*mlx_win;
	void	*mlx;
}				t_surface;

typedef struct	s_pos {
	int	i;
	int	j;
}				t_pos;


typedef struct	s_pic {
	int		weight;
	int		height;
	char	*name;
	void	*img;
}		t_pic;

typedef struct	s_player {
	t_pos	pos;
	t_pic	pic;
	int		moves;
	int		count;
}				t_player;

typedef struct	s_collect {
	t_pos	pos;
	int		collected;
	t_pic	pic;
	int		count;
}				t_collect;

typedef struct	s_exit {
	t_pos	pos;
	int		reached;
	t_pic	pic;
	int		count;
}				t_exit;

typedef struct	s_map {
	int			n;
	int			m;
	char		**map;
}				t_map;

typedef struct	s_game {
	t_surface	surface;
	t_map		*map;
	t_player	player;
	t_collect	collect;
	t_exit		exit;
}				t_game;


# define BUFFER_SIZE 21

char	*parse(char *buffer);
char	*get_new(char *buffer);
char	*read_line(int fd, char *buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *c);
char	*ft_strjoin(char *s1, char *s2);
int		n_not_in(char *s);
int		dist(char *s);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	*ft_memset(void *b, int c, size_t len);
void	check_map(t_game *g, char *argv);
void	check_map_1(t_game *g);
void	check_map_2(t_game *g);
void	check_map_3(t_game *g);
void	check_map_4(t_game *g);
int		find_s_y(char *a);
void	so_long(t_game *g);
void	draw_images(t_game *g);
int		rewrite_map(t_game *g);
int		key_event(int code, t_game *g);
void	win(t_game *g);
int		free_all(t_game *g);
void	error_exit();
#endif
