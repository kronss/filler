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
	char				player1;
	char				ai;
	char				ai1;

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









#endif