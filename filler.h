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
	char 				player;
	char				ai;

	int					max_y;
	int					max_x;
	char				**map;



	int 				ty;
	int					tx;
	char				**token;


	int					y;
	int					x;


	char				*line;


}						t_block;




// void			error_filler(char *str);
void					read_token_size(t_block *block);










#endif