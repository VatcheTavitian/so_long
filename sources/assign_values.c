/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_values.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:38:56 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:38 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	assign_files(t_game **g, void *(*fun)(), int w, int h)
{
	(*g)->bg = fun((*g)->mlx, "./images/bg.xpm", &w, &h);
	(*g)->hero1 = fun((*g)->mlx, "./images/hero1.xpm", &w, &h);
	(*g)->hero2 = fun((*g)->mlx, "./images/hero2.xpm", &w, &h);
	(*g)->gem1 = fun((*g)->mlx, "./images/gem1.xpm", &w, &h);
	(*g)->gem2 = fun((*g)->mlx, "./images/gem2.xpm", &w, &h);
	(*g)->gem3 = fun((*g)->mlx, "./images/gem3.xpm", &w, &h);
	(*g)->gem4 = fun((*g)->mlx, "./images/gem4.xpm", &w, &h);
	(*g)->exit1 = fun((*g)->mlx, "./images/exit1.xpm", &w, &h);
	(*g)->exit2 = fun((*g)->mlx, "./images/exit2.xpm", &w, &h);
	(*g)->exit3 = fun((*g)->mlx, "./images/exit3.xpm", &w, &h);
	(*g)->wall = fun((*g)->mlx, "./images/wall.xpm", &w, &h);
	(*g)->x1 = fun((*g)->mlx, "./images/x1.xpm", &w, &h);
	(*g)->x2 = fun((*g)->mlx, "./images/x2.xpm", &w, &h);
	(*g)->x3 = fun((*g)->mlx, "./images/x3.xpm", &w, &h);
	(*g)->blk = fun((*g)->mlx, "./images/blk.xpm", &w, &h);
}

void	assign_values(t_game **g, t_animate **move, char **maparray, int lines)
{
	int		h;
	int		w;
	char	*t;
	void	*(*fun)();

	fun = mlx_xpm_file_to_image;
	t = "so_long";
	h = 50;
	w = 50;
	(*g)->linelen = check_line_len(maparray, lines, 0);
	(*g)->lines = lines;
	(*g)->update = 1;
	(*g)->finish = 1;
	(*g)->counter = 0;
	(*g)->dead = 0;
	(*g)->success = 0;
	(*g)->iter = (*g)->linelen * (*g)->lines;
	(*g)->colls = number_of_colls(maparray, lines);
	(*g)->wwidth = set_win_width((*g)->linelen);
	(*g)->wheight = set_win_height((*g)->lines);
	(*g)->mlx = mlx_init();
	(*g)->win = mlx_new_window((*g)->mlx, (*g)->wwidth, (*g)->wheight, t);
	assign_files(g, fun, w, h);
	(*move)->map = maparray;
	(*move)->g = g;
}
