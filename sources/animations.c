/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:53:28 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/11 12:09:57 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	animate_heroimages(t_game **g)
{
	if ((*g)->dead == 1)
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->bg,
			(*g)->pposj * 50, (*g)->pposi * 50);
	else if ((time(NULL) % 2) == 0)
	{
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->bg,
			(*g)->pposj * 50, (*g)->pposi * 50);
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->hero1,
			(*g)->pposj * 50, (*g)->pposi * 50);
	}
	else
	{
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->bg,
			(*g)->pposj * 50, (*g)->pposi * 50);
		mlx_put_image_to_window((*g)->mlx, (*g)->win, (*g)->hero2,
			(*g)->pposj * 50, (*g)->pposi * 50);
	}
	return (0);
}

int	animate_gemimages(t_animate **move)
{
	t_game			**g;
	static int		i;

	if (!i)
		i = 0;
	g = (*move)->g;
	animate_gemimages_helper(move, g, &i);
	if (i == 200000000)
		i = 0;
	return (0);
}

int	animate_exitimages(t_animate **move)
{
	t_game			**g;
	static int		i;

	if (!i)
		i = 0;
	g = (*move)->g;
	animate_exitimages_helper(move, g, &i);
	if (i == 10000000)
		i = 0;
	return (0);
}

int	animate_enemy(t_animate **move)
{
	t_game			**g;
	static int		i;

	if (!i)
		i = 0;
	g = (*move)->g;
	if (i == 0)
	{
		render_enemy((*move)->map, g, (*g)->x1);
		while (i < 1000000)
			i++;
	}
	else if (i == 1000000)
	{
		render_enemy((*move)->map, g, (*g)->x2);
		while (i < 2000000)
			i++;
		i = 0;
	}
	return (0);
}

int	animations(t_animate **move, t_game **g)
{
	fill_background(g);
	animate_gemimages(move);
	animate_exitimages(move);
	animate_enemy(move);
	fill_walls(move);
	put_steps(move);
	if ((*g)->dead != 1 && (*g)->success != 1)
		animate_heroimages(g);
	if ((*g)->dead)
		you_died(move, (*g)->pposi, (*g)->pposj);
	return (0);
}
