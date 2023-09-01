/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:22:01 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/09 10:49:00 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	leftmove(t_animate **move, int i, int j, char **map)
{
	if (map[i][j - 1] == '1')
		return (0);
	leftmove_helper(move, i, j, map);
	if (map[i][j - 1] == 'E')
	{
		if ((*(*move)->g)->colls > 0)
		{
			map[i][j] = '0';
			leftmove(move, i, j - 1, map);
		}
		else
			gamecomplete(move, i, j);
	}
	counter(move);
	return (1);
}

int	rightmove(t_animate **move, int i, int j, char **map)
{
	if (map[i][j + 1] == '1')
		return (0);
	rightmove_helper(move, i, j, map);
	if (map[i][j + 1] == 'E')
	{
		if ((*(*move)->g)->colls > 0)
		{
			map[i][j] = '0';
			rightmove(move, i, j + 1, map);
		}
		else
			gamecomplete(move, i, j);
	}
	counter(move);
	return (1);
}

int	upmove(t_animate **move, int i, int j, char **map)
{
	if (map[i - 1][j] == '1')
		return (0);
	upmove_helper(move, i, j, map);
	if (map[i - 1][j] == 'E')
	{
		if ((*(*move)->g)->colls > 0)
		{
			map[i][j] = '0';
			upmove(move, i - 1, j, map);
		}
		else
			gamecomplete(move, i, j);
	}
	counter(move);
	return (1);
}

int	downmove(t_animate **move, int i, int j, char **map)
{
	if (map[i + 1][j] == '1')
		return (0);
	downmove_helper(move, i, j, map);
	if (map[i + 1][j] == 'E')
	{
		if ((*(*move)->g)->colls > 0)
		{
			map[i][j] = '0';
			downmove(move, i + 1, j, map);
		}
		else
			gamecomplete(move, i, j);
	}
	counter(move);
	return (1);
}

int	move_hero(char c, t_animate **move)
{
	int		i;
	int		j;
	char	**map;

	i = (*(*move)->g)->pposi;
	j = (*(*move)->g)->pposj;
	map = (*move)->map;
	if (c == 'l' && (*(*move)->g)->dead == 0)
		leftmove(move, i, j, map);
	else if (c == 'r' && (*(*move)->g)->dead == 0)
		rightmove(move, i, j, map);
	else if (c == 'u' && (*(*move)->g)->dead == 0)
		upmove(move, i, j, map);
	else if (c == 'd' && (*(*move)->g)->dead == 0)
		downmove(move, i, j, map);
	return (0);
}
