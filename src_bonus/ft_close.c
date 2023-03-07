/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iragusa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:47:12 by iragusa           #+#    #+#             */
/*   Updated: 2023/02/11 22:47:50 by iragusa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	free_mat(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	return (0);
}

int	map_error(char *msg, t_all *p, int check)
{
	if (check == 1)
		free(p->map);
	if (check == 2)
		free_mat(p->matrix);
	if (check == 3)
	{
		free_mat(p->matrix);
		free_mat(p->temp);
	}	
	perror(msg);
	exit (0);
}

int	ft_close(t_all *p)
{
	mlx_destroy_image(p->mlx, p->img.floor);
	mlx_destroy_image(p->mlx, p->img.wall);
	mlx_destroy_image(p->mlx, p->sprite.luna);
	mlx_destroy_image(p->mlx, p->sprite.l_r);
	mlx_destroy_image(p->mlx, p->sprite.l_l);
	mlx_destroy_image(p->mlx, p->sprite.lwin);
	mlx_destroy_image(p->mlx, p->sprite.l_up);
	mlx_destroy_image(p->mlx, p->sprite.bro);
	mlx_destroy_image(p->mlx, p->img.shoe);
	mlx_destroy_image(p->mlx, p->img.quadro);
	mlx_destroy_image(p->mlx, p->sprite.bella);
	mlx_destroy_image(p->mlx, p->sprite.be_l);
	mlx_destroy_image(p->mlx, p->sprite.lose);
	mlx_clear_window(p->mlx, p->win.win);
	mlx_destroy_window(p->mlx, p->win.win);
	mlx_destroy_display(p->mlx);
	free_mat(p->matrix);
	free(p->mlx);
	exit(0);
}
