/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:40:16 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/09 10:59:06 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	assign_locations(t_game **g, char **mp, int i)
{
	int		j;

	j = 0;
	while (i < (*g)->lines)
	{
		while (mp[i][j])
		{
			if (mp[i][j] == 'P')
			{
				(*g)->pposi = i;
				(*g)->pposj = j;
			}
			else if (mp[i][j] == 'E')
			{
				(*g)->eposi = i;
				(*g)->eposj = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	number_of_colls(char **mp, int lines)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (i < lines)
	{
		while (mp[i][j])
		{
			if (mp[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	animate_images(t_animate **move)
{
	t_game	**g;

	g = (*move)->g;
	if ((*g)->update == 1 && (*g)->finish == 1 && (*g)->success == 0)
		animations(move, g);
	else if ((*g)->finish == 1 && (*g)->success == 0)
	{
		animations(move, g);
		(*g)->update = 1;
	}
	else if ((*g)->finish == 0 && (*g)->success == 1)
	{
		fill_background(g);
		put_steps(move);
		mlx_put_image_to_window((*g)->mlx, (*g)->win,
			(*g)->bg, (*g)->pposj * 50, (*g)->pposi * 50);
		mlx_put_image_to_window((*g)->mlx, (*g)->win,
			(*g)->blk, (*g)->wwidth / 2 - 20, (*g)->wheight / 2 - 25);
		mlx_string_put((*g)->mlx, (*g)->win, (*g)->wwidth / 2 - 10,
			(*g)->wheight / 2, 0x0000FF00, "Well");
		mlx_string_put((*g)->mlx, (*g)->win, (*g)->wwidth / 2 - 10,
			(*g)->wheight / 2 + 10, 0x0000FF00, "Done!");
	}
	return (0);
}

void	initialise_struct(char **maparray, int lines, t_game **g)
{
	t_animate	*move;

	*g = malloc(sizeof(t_game));
	move = malloc(sizeof(t_animate));
	if (!g || !move)
		error_msg("Error\nCreating structure for game failed...");
	assign_values(g, &move, maparray, lines);
	assign_locations(g, maparray, 0);
	check_key_paths(maparray, g);
	mlx_loop_hook((*g)->mlx, animate_images, &move);
	mlx_key_hook((*g)->win, hooks, &move);
	mlx_hook((*g)->win, 17, 0L, quit, &move);
	mlx_loop((*g)->mlx);
	free(g);
	free(move);
}
