/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:53:00 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/09 10:31:53 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	counter(t_animate **move)
{
	(*(*move)->g)->counter++;
	write(1, "Moves = ", 9);
	ft_putnbr((*(*move)->g)->counter);
	write(1, "\n", 1);
	return (0);
}

int	quit(t_animate **move)
{
	mlx_destroy_window((*(*move)->g)->mlx, (*(*move)->g)->win);
	exit (1);
	return (0);
}

int	gamecomplete(t_animate **move, int i, int j)
{
	int		mwidth;
	int		mheight;
	t_game	**g;

	g = (*move)->g;
	(*g)->finish = 0;
	(*(*move)->g)->success = 1;
	mwidth = (*g)->wwidth / 2;
	mheight = (*g)->wheight / 2;
	mlx_put_image_to_window((*g)->mlx, (*g)->win,
		(*g)->bg, j * 50, i * 50);
	mlx_put_image_to_window((*g)->mlx, (*g)->win,
		(*g)->blk, mwidth - 20, mheight - 25);
	mlx_string_put((*g)->mlx, (*g)->win, mwidth - 10,
		mheight, 0x0000FF00, "Well");
	mlx_string_put((*g)->mlx, (*g)->win, mwidth - 10,
		mheight + 10, 0x0000FF00, "Done!");
	return (0);
}

int	hooks(int keycode, t_animate **move)
{
	if (keycode == 53)
		quit(move);
	else if (keycode == 0 && (*(*move)->g)->finish)
		move_hero('l', move);
	else if (keycode == 2 && (*(*move)->g)->finish)
		move_hero('r', move);
	else if (keycode == 1 && (*(*move)->g)->finish)
		move_hero('d', move);
	else if (keycode == 13 && (*(*move)->g)->finish)
		move_hero('u', move);
	return (0);
}
