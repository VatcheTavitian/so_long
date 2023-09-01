/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:48:07 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/10 17:18:53 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_end_path(char **mp, int si, int sj, t_game **game)
{
	if (mp[si][sj] == '1' || mp[si][sj] == 'X' || mp[si][sj] == '2'
		|| mp[si][sj] == '3' || mp[si][sj] == '5')
		return (0);
	if (mp[si][sj] == 'E')
		(*game)->exit_check = 1;
	else if (mp[si][sj] == '0')
		mp[si][sj] = '2';
	else if (mp[si][sj] == 'C')
	{
		(*game)->colls--;
		mp[si][sj] = '3';
	}
	else if (mp[si][sj] == 'P')
		mp[si][sj] = '5';
	check_end_path(mp, si - 1, sj, game);
	check_end_path(mp, si + 1, sj, game);
	check_end_path(mp, si, sj - 1, game);
	check_end_path(mp, si, sj + 1, game);
	if ((*game)->colls == 0 && (*game)->exit_check == 1)
		return (1);
	else
		return (0);
}

void	copy_map(char **mp, t_game **game, char **mpcopy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (*game)->lines)
	{
		mpcopy[i] = (char *)malloc(sizeof(char) * ((*game)->linelen + 1));
		while (j < (*game)->linelen)
		{
			mpcopy[i][j] = mp[i][j];
			j++;
		}
		mpcopy[i][j] = '\0';
		j = 0;
		i++;
	}
}

void	free_all(char **mpcopy, int lines)
{
	int	i;

	i = 0;
	while (i < lines)
	{
		free(mpcopy[i]);
		i++;
	}
}

void	check_key_paths(char **mp, t_game **game)
{
	t_points	start;
	char		**mpcopy;
	int			colls;

	mpcopy = (char **)malloc(sizeof(char **) * (*game)->lines);
	copy_map(mp, game, mpcopy);
	colls = (*game)->colls;
	start.i = (*game)->pposi;
	start.j = (*game)->pposj;
	if (check_end_path(mpcopy, start.i, start.j, game) == 0)
		error_msg("Error\nPath is unreachable");
	free_all(mpcopy, (*game)->lines);
	free(mpcopy);
	(*game)->colls = colls;
}
