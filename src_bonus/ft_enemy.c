/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:41:29 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/06 18:41:34 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	bella_right(t_all *p)
{
	int	step;

	step = p->pos.bex;
	if (p->matrix[p->pos.bey][++step] == 'P')
		ft_lose(p);
	else if (p->matrix[p->pos.bey][step] != '1' &&
			p->matrix[p->pos.bey][step] != 'C' &&
			p->matrix[p->pos.bey][step] != 'P' &&
			p->matrix[p->pos.bey][step] != 'E')
	{
		p->pos.bex++;
		step -= 1;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			(p->pos.bex - 1) * SIZE, p->pos.bey * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.bella,
			p->pos.bex * SIZE, p->pos.bey * SIZE);
		p->matrix[p->pos.bey][p->pos.bex] = 'B';
		p->matrix[p->pos.bey][step] = '0';
	}
	return (0);
}

int	bella_left(t_all *p)
{
	int	step;

	step = p->pos.bex;
	if (p->matrix[p->pos.bey][--step] == 'P')
		ft_lose(p);
	else if (p->matrix[p->pos.bey][step] != '1' &&
			p->matrix[p->pos.bey][step] != 'C' &&
			p->matrix[p->pos.bey][step] != 'P' &&
			p->matrix[p->pos.bey][step] != 'E')
	{
		p->pos.bex--;
		step += 1;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			(p->pos.bex + 1) * SIZE, p->pos.bey * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.be_l,
			p->pos.bex * SIZE, p->pos.bey * SIZE);
		p->matrix[p->pos.bey][p->pos.bex] = 'B';
		p->matrix[p->pos.bey][step] = '0';
	}
	return (0);
}

int	bella_up(t_all *p)
{
	int	step;

	step = p->pos.bey;
	if (p->matrix[--step][p->pos.bex] == 'P')
		ft_lose(p);
	else if (p->matrix[step][p->pos.bex] != '1' &&
			p->matrix[step][p->pos.bex] != 'C' &&
			p->matrix[step][p->pos.bex] != 'P' &&
			p->matrix[step][p->pos.bex] != 'E')
	{
		p->pos.bey--;
		step += 1;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->pos.bex * SIZE, (p->pos.bey + 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.bella,
			p->pos.bex * SIZE, p->pos.bey * SIZE);
		p->matrix[p->pos.bey][p->pos.bex] = 'B';
		p->matrix[step][p->pos.bex] = '0';
	}
	return (0);
}

int	bella_down(t_all *p)
{
	int	step;

	step = p->pos.bey;
	if (p->matrix[++step][p->pos.bex] == 'P')
		ft_lose(p);
	else if (p->matrix[step][p->pos.bex] != '1' &&
		p->matrix[step][p->pos.bex] != 'P' &&
		p->matrix[step][p->pos.bex] != 'C' &&
		p->matrix[step][p->pos.bex] != 'E')
	{
		p->pos.bey++;
		step -= 1;
		mlx_put_image_to_window(p->mlx, p->win.win, p->img.floor,
			p->pos.bex * SIZE, (p->pos.bey - 1) * SIZE);
		mlx_put_image_to_window(p->mlx, p->win.win, p->sprite.be_l,
			p->pos.bex * SIZE, p->pos.bey * SIZE);
		if (p->matrix[p->pos.bey][p->pos.bex] == 'C')
			ft_collect(p);
		p->matrix[p->pos.bey][p->pos.bex] = 'B';
		p->matrix[step][p->pos.bex] = '0';
	}
	return (0);
}

int	ft_enemy(void *param)
{
	t_all		*p;
	int			move;

	p = (t_all *)param;
	move = 0;
	if (p->cont.flag == 0)
	{
		srand(time(NULL));
		p->cont.flag = 1;
	}
	move = rand() % (4 + 1);
	if (p->cont.wait % 50000 == 0)
	{
		if (move == 1)
			bella_up(p);
		else if (move == 2)
			bella_down(p);
		else if (move == 3)
			bella_left(p);
		else if (move == 4)
			bella_right(p);
	}
	p->cont.wait++;
	return (0);
}
