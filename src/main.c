/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:29:08 by iragusa           #+#    #+#             */
/*   Updated: 2023/02/09 20:07:59 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_win(t_all *p)
{
	int	x;
	int	y;

	x = p->win.x / 2;
	y = p->win.y / 2;
	mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
		p->pos.lux * SIZE, p->pos.luy * SIZE);
	mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.lwin,
		p->pos.ex * SIZE, p->pos.ey * SIZE);
	mlx_string_put(p->mlx, p->win.win, x * SIZE,
		y * SIZE, 0x000000, "YOU WON!!!");
	p->cont.check_loop = 1;
	ft_printf("\033[32m wa! hai vinto, che fatica questa vita!\n");
	ft_printf("\033[34m mosse:%d\n", p->cont.moves);
}

void	get_window(t_all *p)
{
	p->cont.check_loop = 0;
	p->mlx = mlx_init();
	mlx_do_key_autorepeaton(p->mlx);
	p->win.win = mlx_new_window (p->mlx, p->win.x * SIZE,
			p->win.y * SIZE, "comm_so_long");
	ft_images(p);
	p->cont.moves = 0;
	ft_printf("\033[33m GAME START!\n Raccogli tutte le scarpe!\n");
	ft_printf("\033[36m raggiungi la signora grassa senza toccare Bellatrix\n");
	mlx_hook(p->win.win, 2, 1L << 0, &my_key_hook, p);
	mlx_hook(p->win.win, 17, 0, ft_close, p);
	mlx_string_put(p->mlx, p->win.win, 20, 55, 0x0000FF, "MOVES:");
	mlx_string_put(p->mlx, p->win.win, 20, 20, 0xFF0000, "shoes to grab:");
	mlx_loop(p->mlx);
}

int	main(int ac, char **av)
{
	char	*path;
	t_all	p;

	path = av[1];
	if (ac == 2)
	{
		read_map(path, &p);
		get_window(&p);
	}
	else if (ac > 2)
		map_error("Error\n Dude, too many arguments, less is more!", &p, 0);
	else
		map_error("Error\n eeehy dude, do not be lazy, choose a map!", &p, 0);
	return (0);
}
