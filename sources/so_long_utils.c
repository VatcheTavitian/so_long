/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:11:37 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/10 17:12:47 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	set_win_height(int lines)
{
	if (lines * 50 > 1152)
		error_msg("Error\nMap height beyond resolution limits");
	return (lines * 50);
}

int	set_win_width(int linelen)
{
	if (linelen * 50 > 2050)
		error_msg("Error\nMap width beyond resolution limits");
	return (linelen * 50);
}

int	put_steps(t_animate **move)
{
	t_game	**g;
	char	*num;

	g = (*move)->g;
	num = ft_itoa((*g)->counter);
	mlx_string_put((*g)->mlx, (*g)->win, 15, 10, 0x000000FF, "Steps Taken : ");
	mlx_string_put((*g)->mlx, (*g)->win, 110, 10, 0x000000FF, num);
	free(num);
	return (0);
}

void	error_msg(char *msg)
{
	errno = 1;
	perror(msg);
	exit (-1);
}

int	ft_strlen(const char *str)
{
	int		i;
	char	*str1;

	if (!str)
		return (0);
	str1 = (char *)str;
	i = 0;
	while (str1[i] != '\0')
		i++;
	return (i);
}
