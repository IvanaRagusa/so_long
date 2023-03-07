/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 17:17:15 by iragusa           #+#    #+#             */
/*   Updated: 2023/02/11 18:29:51 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <time.h>
# include <stddef.h>

# ifndef SIZE
#  define SIZE 50
# endif

/*struct*/

typedef struct s_counter
{
	int		pos;
	int		exit;
	int		collect;
	char	*coll;
	char	*mov;
	int		moves;
	int		check_loop;
	int		flag;
	int		wait;

}	t_counter;

typedef struct s_window
{
	void	*win;
	int		x;
	int		y;
}	t_window;

typedef struct s_vector
{
	int		x;
	int		y;
}	t_vector;

typedef struct s_img {
	void		*floor;
	void		*wall;
	void		*shoe;
	void		*quadro;
}	t_img;

typedef struct s_sprite
{
	void	*luna;
	void	*l_r;
	void	*l_l;
	void	*l_up;
	void	*lwin;
	void	*bella;
	void	*be_l;
	void	*bro;
	void	*lose;
}	t_sprite;

typedef struct s_mat
{
	int	x;
	int	y;
}	t_mat;

typedef struct s_pos
{
	int	lux;
	int	luy;
	int	bex;
	int	bey;
	int	ex;
	int	ey;
}	t_pos;

typedef struct s_all
{
	void		*mlx;
	char		**matrix;
	char		**temp;
	char		*map;
	t_window	win;
	t_vector	lu;
	t_counter	cont;
	t_img		img;
	t_sprite	sprite;
	t_mat		mat;
	t_pos		pos;
}	t_all;

/*error*/
int		map_error(char *msg, t_all *p, int check);

/*window*/

void	get_window(t_all *p);
int		my_key_hook(int keycode, t_all *p);
int		ft_close(t_all *p);
void	ft_string_to_win(t_all *p);

/*map*/

void	read_map(char *path, t_all *p);
void	check_map(t_all *p);
int		contchar(t_all *p);
void	check_rows(t_all *p);
void	ft_find(char **temp, t_window size, t_vector pos);
void	ft_find_pos(t_all *p, char c);
void	ft_pos(t_all *p);
int		ft_flood_fill(char **tab, t_window size, t_vector pos);

/*img*/
void	ft_images(t_all *p);
void	ft_put_img(t_all *p, char c);
void	ft_charcheck(t_all *p);

/*free*/
int		free_mat(char **matrix);

/*moves*/
int		move_right(t_all *p);
int		move_left(t_all *p);
int		move_down(t_all *p);

/*game*/
void	ft_win(t_all *p);
void	ft_collect(t_all *p);
void	ft_lose(t_all *p);
int		ft_enemy(void *param);
#endif
