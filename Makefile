# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/09 10:25:34 by vtavitia          #+#    #+#              #
#    Updated: 2023/06/09 10:53:04 by vtavitia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = animations.c\
		initialise_struct.c\
		so_long_utils.c\
		animations_helpers.c\
		key_hooks.c\
		validate_map.c\
		assign_values.c\
		main.c\
		validate_map_helpers.c\
		ft_itoa.c\
		move_hero.c\
		validate_paths.c\
		ft_putnbr.c\
		move_hero_helpers.c\
		ft_split.c\
		render_images.c

SRCPATH = sources/
OBJPATH = objects/

SOURCES = $(addprefix $(SRCPATH), $(SRCS))
OBJECTS = $(addprefix $(OBJPATH), $(SRCS:.c=.o))

CC = cc

FLAGS = -Wall -Werror -Wextra 

all: $(OBJPATH) $(NAME)

$(OBJPATH)%.o: $(SRCPATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJPATH):
	mkdir $(OBJPATH)
	
$(NAME):  $(OBJECTS) 
	$(CC) $(FLAGS) $^ -LminiLibX -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
