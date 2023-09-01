/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:59 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/11 12:11:01 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <sys/errno.h>
# include "./miniLibX/mlx.h"

typedef struct s_game
{
	int		linelen;
	int		lines;
	int		pposi;
	int		pposj;
	int		eposi;
	int		eposj;
	int		colls;
	int		exit_check;
	int		iter;
	int		wwidth;
	int		wheight;
	int		update;
	int		finish;
	int		success;
	int		dead;
	int		counter;
	void	*mlx;
	void	*win;
	void	*bg;
	void	*hero1;
	void	*hero2;
	void	*gem1;
	void	*gem2;
	void	*gem3;
	void	*gem4;
	void	*exit1;
	void	*exit2;
	void	*exit3;
	void	*wall;
	void	*blk;
	void	*x1;
	void	*x2;
	void	*x3;
}	t_game;

typedef struct s_points
{
	int	i;
	int	j;
}	t_points;

typedef struct t_animate
{
	char	**map;
	t_game	**g;
}	t_animate;

void	validate_map(int fd, char *map, t_game **gameinfo);
char	**ft_split(char const *s, char c);
int		ft_countlines(char const *s, char c);
void	check_walls(char **maparray, int lines, int i, int linelen);
int		check_line_len(char **maparray, int lines, int i);
void	check_illegal_chars(char **mp, int lines, int i);
void	check_key_chars(char **mp, int lines, int i);
void	error_msg(char *msg);
void	initialise_struct(char **maparray, int lines, t_game **gameinfo);
int		ft_strlen(const char *str);
void	check_key_paths(char **mp, t_game **game);
int		animate_images(t_animate **move);
void	fill_background(t_game **g);
void	fill_walls(t_animate **move);
void	render_collectables(char **mp, t_game **g, void *gem);
void	render_enemy(char **mp, t_game **g, void *x);
void	render_exit(char **mp, t_game **g, void *exit);
int		animate_gemimages_helper(t_animate **move, t_game **g, int *i);
void	animate_exitimages_helper(t_animate **move, t_game **g, int *i);
int		set_win_width(int linelen);
int		set_win_height(int lines);
int		number_of_colls(char **mp, int lines);
void	assign_locations(t_game **g, char **mp, int i);
void	assign_values(t_game **g, t_animate **move, char **maparray, int lines);
void	ft_putnbr(int nb);
int		hooks(int keycode, t_animate **move);
int		counter(t_animate **move);
void	you_died(t_animate **move, int i, int j);
int		move_hero(char c, t_animate **move);
void	leftmove_helper(t_animate **move, int i, int j, char **map);
void	rightmove_helper(t_animate **move, int i, int j, char **map);
void	upmove_helper(t_animate **move, int i, int j, char **map);
void	downmove_helper(t_animate **move, int i, int j, char **map);
char	*ft_itoa(int n);
int		quit(t_animate **move);
int		animate_heroimages(t_game **g);
int		animations(t_animate **move, t_game **g);
int		put_steps(t_animate **move);
int		gamecomplete(t_animate **move, int i, int j);
int		animate_enemy(t_animate **move);
int		animate_exitimages(t_animate **move);
int		animate_gemimages(t_animate **move);

#endif