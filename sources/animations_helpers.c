/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:07:43 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/11 12:10:48 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	animate_gemimages_helper(t_animate **move, t_game **g, int *i)
{
	if (*i == 0)
	{
		render_collectables((*move)->map, g, (*g)->gem1);
		while (*i < 100000000)
			(*i)++;
	}
	else if (*i == 100000000)
	{
		render_collectables((*move)->map, g, (*g)->gem3);
		while (*i < 200000000)
			(*i)++;
	}
	return (*i);
}

void	animate_exitimages_helper(t_animate **move, t_game **g, int *i)
{
	if (*i == 0)
	{
		render_exit((*move)->map, g, (*g)->exit1);
		while (*i < 10000000)
			(*i)++;
	}
	else if (*i == 10000000)
	{
		render_exit((*move)->map, g, (*g)->exit2);
		while (*i < 20000000)
			(*i)++;
	}
}
