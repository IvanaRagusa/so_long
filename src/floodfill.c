/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flodfill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:53:36 by iragusa           #+#    #+#             */
/*   Updated: 2023/03/02 17:53:39 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_find_pos(t_all *p, char c)
{
	if (c == 'P')
	{
		p->pos.lux = p->mat.x;
		p->pos.luy = p->mat.y;
	}
	else if (c == 'E')
	{
		p->pos.ex = p->mat.x;
		p->pos.ey = p->mat.y;
	}
	else if (c == 'B')
	{
		p->pos.bex = p->mat.x;
		p->pos.bey = p->mat.y;
	}
}

void	ft_pos(t_all *p)
{
	p->mat.y = 0;
	while (p->mat.y < p->win.y)
	{
		p->mat.x = 0;
		while (p->matrix[p->mat.y][p->mat.x] != '\0')
		{
			ft_find_pos(p, p->matrix[p->mat.y][p->mat.x]);
			p->mat.x++;
		}
		p->mat.y++;
	}
}

void	ft_find(char **temp, t_window size, t_vector pos)
{
	if (pos.x < 0 || pos.x > size.x || pos.y < 0 || pos.y >= size.y
		|| temp[pos.y][pos.x] == '1')
		return ;
	if (temp[pos.y][pos.x] == 'E')
	{
		temp[pos.y][pos.x] = '1';
		return ;
	}
	temp[pos.y][pos.x] = '1';
	ft_find(temp, size, (t_vector){pos.x + 1, pos.y});
	ft_find(temp, size, (t_vector){pos.x - 1, pos.y});
	ft_find(temp, size, (t_vector){pos.x, pos.y + 1});
	ft_find(temp, size, (t_vector){pos.x, pos.y - 1});
}

int	ft_flood_fill(char **tab, t_window size, t_vector begin)
{
	int	y;
	int	x;

	y = 0;
	ft_find(tab, size, begin);
	while (tab[y] != 0)
	{
		x = 0;
		while (tab[y][x] != '\0')
		{
			if (tab[y][x] != '0' && tab[y][x] != '1')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
