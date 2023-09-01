/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:22:32 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:17 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	you_died(t_animate **move, int i, int j)
{
	int		mwidth;
	int		mheight;
	t_game	**g;

	g = (*move)->g;
	(*g)->finish = 0;
	mwidth = (*g)->wwidth / 2;
	mheight = (*g)->wheight / 2;
	mlx_put_image_to_window((*g)->mlx, (*g)->win,
		(*g)->blk, mwidth - 20, mheight - 25);
	mlx_put_image_to_window((*g)->mlx, (*g)->win,
		(*g)->bg, j * 50, i * 50);
	mlx_put_image_to_window((*g)->mlx, (*g)->win,
		(*g)->x3, j * 50, i * 50);
	mlx_string_put((*g)->mlx, (*g)->win, mwidth - 10,
		mheight, 0x00FF0000, "YOU");
	mlx_string_put((*g)->mlx, (*g)->win, mwidth - 10,
		mheight + 10, 0x00FF0000, "DIED");
}

void	leftmove_helper(t_animate **move, int i, int j, char **map)
{
	if (map[i][j - 1] == '0')
	{
		map[i][j - 1] = 'P';
		(*(*move)->g)->pposj = j - 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
	}
	else if (map[i][j - 1] == 'C')
	{
		map[i][j - 1] = 'P';
		(*(*move)->g)->pposj = j - 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
		(*(*move)->g)->colls--;
	}
	else if (map[i][j - 1] == 'X')
	{
		(*(*move)->g)->pposj = j - 1;
		(*(*move)->g)->dead = 1;
	}
}

void	rightmove_helper(t_animate **move, int i, int j, char **map)
{
	if (map[i][j + 1] == '0')
	{
		map[i][j + 1] = 'P';
		(*(*move)->g)->pposj = j + 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
	}
	else if (map[i][j + 1] == 'C')
	{
		map[i][j + 1] = 'P';
		(*(*move)->g)->pposj = j + 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
		(*(*move)->g)->colls--;
	}
	else if (map[i][j + 1] == 'X')
	{
		(*(*move)->g)->pposj = j + 1;
		(*(*move)->g)->dead = 1;
	}
}

void	upmove_helper(t_animate **move, int i, int j, char **map)
{
	if (map[i - 1][j] == '0')
	{
		map[i - 1][j] = 'P';
		(*(*move)->g)->pposi = i - 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
	}
	else if (map[i - 1][j] == 'C')
	{
		map[i - 1][j] = 'P';
		(*(*move)->g)->pposi = i - 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
		(*(*move)->g)->colls--;
	}
	else if (map[i - 1][j] == 'X')
	{
		(*(*move)->g)->pposi = i - 1;
		(*(*move)->g)->dead = 1;
	}
}

void	downmove_helper(t_animate **move, int i, int j, char **map)
{
	if (map[i + 1][j] == '0')
	{
		map[i + 1][j] = 'P';
		(*(*move)->g)->pposi = i + 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
	}
	else if (map[i + 1][j] == 'C')
	{
		map[i + 1][j] = 'P';
		(*(*move)->g)->pposi = i + 1;
		if (map[i][j] != 'E')
			map[i][j] = '0';
		(*(*move)->g)->update = 0;
		(*(*move)->g)->colls--;
	}
	else if (map[i + 1][j] == 'X')
	{
		(*(*move)->g)->pposi = i + 1;
		(*(*move)->g)->dead = 1;
	}
}
