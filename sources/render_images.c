/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:58:00 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/10 17:10:31 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill_background(t_game **g)
{
	int	mw;
	int	mh;
	int	i;
	int	j;

	i = 0;
	j = 0;
	mw = (*g)->wwidth / 50;
	mh = (*g)->wheight / 50;
	while (j < mh)
	{
		while (i < mw)
		{
			mlx_put_image_to_window((*g)->mlx,
				(*g)->win, (*g)->bg, 50 * i, 50 * j);
			i++;
		}
		j++;
		i = 0;
	}
}

void	fill_walls(t_animate **move)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*(*move)->g)->lines)
	{
		while (j < (*(*move)->g)->linelen)
		{
			if (((*move)->map)[i][j] == '1')
			{
				mlx_put_image_to_window((*(*move)->g)->mlx,
					(*(*move)->g)->win, (*(*move)->g)->bg, j * 50, i * 50);
				mlx_put_image_to_window((*(*move)->g)->mlx,
					(*(*move)->g)->win, (*(*move)->g)->wall, j * 50, i * 50);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	render_collectables(char **mp, t_game **g, void *gem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*g)->lines)
	{
		while (j < (*g)->linelen)
		{
			if (mp[i][j] == 'C')
			{
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, (*g)->bg, j * 50, i * 50);
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, gem, j * 50, i * 50);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	render_enemy(char **mp, t_game **g, void *x)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*g)->lines)
	{
		while (j < (*g)->linelen)
		{
			if (mp[i][j] == 'X')
			{
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, (*g)->bg, j * 50, i * 50);
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, x, j * 50, i * 50);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void	render_exit(char **mp, t_game **g, void *exit)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*g)->lines)
	{
		while (j < (*g)->linelen)
		{
			if (mp[i][j] == 'E')
			{
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, (*g)->bg, j * 50, i * 50);
				mlx_put_image_to_window((*g)->mlx,
					(*g)->win, exit, j * 50, i * 50);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
