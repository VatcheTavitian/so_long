/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:10:10 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/08 17:31:42 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_key_chars(char **mp, int lines, int j)
{
	int		c;
	int		e;
	int		p;

	c = 0;
	e = 0;
	p = 0;
	while (lines--)
	{
		while (mp[lines][j])
		{
			if (mp[lines][j] == 'C')
				c++;
			else if (mp[lines][j] == 'E')
				e++;
			else if (mp[lines][j] == 'P')
				p++;
			j++;
		}
		j = 0;
	}
	if (c <= 0 || e != 1 || p != 1)
		error_msg("Error\nInsufficient number of key characters");
}

void	check_illegal_chars(char **mp, int lines, int i)
{
	int		j;
	char	x;

	j = 0;
	while (i < lines)
	{
		while (mp[i][j])
		{
			x = mp[i][j];
			if (x == '1' || x == '0' || x == 'C'
				|| x == 'E' || x == 'P' || x == 'X')
				j++;
			else
				error_msg("Error\nForbidden character found in map!");
		}
		j = 0;
		i++;
	}
}

void	check_walls(char **maparray, int lines, int i, int linelen)
{
	int	j;

	j = 0;
	while (maparray[0][j])
	{
		if (maparray[0][j] != '1' || maparray[lines - 1][j] != '1')
			error_msg("Error\nWalls Top or Bottom Incomplete");
		j++;
	}
	i = 1;
	while (i < lines)
	{
		if (maparray[i][0] != '1' || maparray[i][linelen - 1] != '1')
			error_msg("Error\nWalls Incomplete Sides");
		i++;
	}
}

int	check_line_len(char **maparray, int lines, int i)
{
	int	expectedlen;
	int	j;

	j = 0;
	expectedlen = 0;
	while (maparray[i][j++] != '\0')
		expectedlen = j;
	j = 0;
	while (i < lines)
	{
		while (maparray[i][j] != '\0')
			j++;
		if (j != expectedlen)
			error_msg("Error\nMap is not a rectangle");
		j = 0;
		i++;
	}
	return (expectedlen);
}
