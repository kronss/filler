/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 21:12:25 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/28 21:12:26 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**			explain the struct t_block
**
**	player		- my player (X or O)
**	ai			- my oponent
**	max_y		- max y map size
**	max_x		- max x map size
**	map 		- game map     (max_y * max_x)
**	priority	- priority map (max_y * max_x)
**  ty			- max token y size
**  tx			- max token x size
**	token		- token (ty * tx) wich contain piece (random_size *)
**	step_y		- y cord wich be will print to filler_vm
**	step_x		- x cord wich be will print to filler_vm
**	line		- tmp line for save extra lines in function

**	write
**	read
**	malloc
**	free
**	perror
**	strerror
*/

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef	struct			s_block
{
	char				player;
	char				ai;
	int					max_y;
	int					max_x;
	char				**map;
	int 				**priority;
	int 				ty;
	int					tx;
	char				**token;

	int					step_y;
	int					step_x;
	char				*line;
}						t_block;




// void			error_filler(char *str);
void					skip_line_plateau(char **line);
void					read_map(t_block *block, int max_y, int max_x);
void					read_token_size(t_block *block);
void					player_step(t_block *block);

void					create_priority(t_block *block, int max_y, int max_x);
void					update_priority(t_block *block);







#endif