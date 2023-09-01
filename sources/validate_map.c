/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:43:43 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/11 12:34:28 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*allocate_toarray(int fd, int filesize, char *map)
{
	char	*maparray;

	maparray = (char *)malloc(sizeof(char) * (filesize + 1));
	if (!maparray)
		error_msg("Error\nFailed to malloc and allocate");
	fd = open(map, O_RDONLY);
	if (fd == -1)
		error_msg("Error\nFailed to open file");
	read(fd, maparray, filesize);
	maparray[filesize] = '\0';
	return (maparray);
}

static int	get_filesize(int fd)
{
	char	buffer;
	int		filesize;

	filesize = 0;
	while (read(fd, &buffer, 1))
		filesize++;
	if (filesize == 0)
		error_msg("Error\nMap file is empty");
	return (filesize);
}

void	check_empty_lines(char *map)
{
	int	i;

	i = 0;
	if (map[i] == '\n')
		error_msg("Error\nEmpty line in beginning of map");
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
			error_msg("Error\nEmpty or incomplete line in map");
		i++;
	}
	if (map[i - 1] == '\n')
		error_msg("Error\nEmpty line end of map");
}

void	check_map_chars(char **maparray, int lines)
{
	int	linelen;

	linelen = check_line_len(maparray, lines, 0);
	check_walls(maparray, lines, 0, linelen);
	check_illegal_chars(maparray, lines, 0);
	check_key_chars(maparray, lines, 0);
}

void	validate_map(int fd, char *map, t_game **gameinfo)
{
	int		filesize;
	int		lines;
	char	**maparray;
	char	*readmap;

	filesize = get_filesize(fd);
	readmap = allocate_toarray(fd, filesize, map);
	maparray = ft_split(readmap, '\n');
	lines = ft_countlines(readmap, '\n');
	check_empty_lines(readmap);
	check_map_chars(maparray, lines);
	initialise_struct(maparray, lines, gameinfo);
	free(readmap);
	free(maparray);
}
