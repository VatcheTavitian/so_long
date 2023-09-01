/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:36:49 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/08 17:33:20 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_ber_file(char *file)
{
	int	idx;

	if (ft_strlen(file) < 5)
		error_msg("Error\nNot valid ber file");
	idx = ft_strlen(file) - 1;
	if (file[idx] != 'r' || file[idx - 1] != 'e'
		|| file[idx - 2] != 'b' || file[idx - 3] != '.')
		error_msg("Error\nfile must have .ber extension");
}

int	main(int argc, char **argv)
{
	int		fd;
	t_game	*gameinfo;

	if (argc == 2)
		check_ber_file(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1)
		error_msg("Error\nLaunch with 1 valid map path");
	validate_map(fd, argv[1], &gameinfo);
}
