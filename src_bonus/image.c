/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:56:56 by iragusa           #+#    #+#             */
/*   Updated: 2023/02/22 21:57:07 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_collect(t_all *p)
{
	p->cont.coll = ft_itoa(p->cont.collect);
	p->matrix[p->pos.luy][p->pos.lux] = '0';
	mlx_string_put(p->mlx, p->win.win, 120, 20, 0x006400,
		p->cont.coll);
	free(p->cont.coll);
	p->cont.collect--;
	ft_string_to_win(p);
}

void	ft_string_to_win(t_all *p)
{
	p->cont.mov = ft_itoa(p->cont.moves);
	mlx_string_put(p->mlx, p->win.win, 60, 55, 0xFFFFFF, p->cont.mov);
	p->cont.moves++;
	free(p->cont.mov);
	p->cont.mov = ft_itoa(p->cont.moves);
	p->cont.coll = ft_itoa(p->cont.collect);
	mlx_string_put(p->mlx, p->win.win, 60, 55, 0xFF00FF, p->cont.mov);
	mlx_string_put(p->mlx, p->win.win, 120, 20, 0xFF0000, p->cont.coll);
	if (p->cont.collect == 0)
	{
		mlx_string_put(p->mlx, p->win.win, 120, 20, 0x006400, p->cont.coll);
		mlx_string_put(p->mlx, p->win.win, 120, 20, 0xFFFF00,
			"reach the broom!!");
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.bro,
			p->pos.ex * SIZE, p->pos.ey * SIZE);
	}
	free(p->cont.mov);
	free (p->cont.coll);
}

void	ft_images2(t_all *p)
{
	static int	hw = 5;

	p->sprite.l_r = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/l_r.xpm", &hw, &hw);
	p->sprite.l_l = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/l_l.xpm", &hw, &hw);
	p->sprite.l_up = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/l_up.xpm", &hw, &hw);
	p->sprite.lwin = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/lwin.xpm", &hw, &hw);
	p->sprite.bella = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/be.xpm", &hw, &hw);
	p->sprite.be_l = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/be_l.xpm", &hw, &hw);
	p->sprite.bro = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/bro.xpm", &hw, &hw);
	p->sprite.lose = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/l_lose.xpm", &hw, &hw);
	ft_charcheck(p);
}

void	ft_images(t_all *p)
{
	static int	hw = 5;

	p->img.floor = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/floor.xpm", &hw, &hw);
	p->img.wall = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/wall.xpm", &hw, &hw);
	p->img.shoe = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/shoe.xpm", &hw, &hw);
	p->img.quadro = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/exit.xpm", &hw, &hw);
	p->sprite.luna = mlx_xpm_file_to_image(p->mlx,
			"src_bonus/Hw/l_do.xpm", &hw, &hw);
	ft_images2(p);
}

void	ft_put_img(t_all *p, char c)
{
	if (c == '0')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == '1')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.wall,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'P')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.luna,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'C')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.shoe,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'E')
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.quadro,
			p->mat.x * SIZE, p->mat.y * SIZE);
	else if (c == 'B')
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.bella,
			p->mat.x * SIZE, p->mat.y * SIZE);
}
