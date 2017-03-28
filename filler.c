/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/28 20:52:49 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/28 20:52:49 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void					choose_player(t_block *block)
{
	char *line;

	get_next_line(STDIN, &line);
	if (!ft_strncmp("$$$ exec p1 :", line, 13))
	{
		block->player = 'O';
		block->ai = 'X';
	}
	else
	{
		block->player = 'X';
		block->ai = 'O';
	}
	ft_strdel(&line);
}

void						in_block(t_block *block)
{
	


}

int							main(void)
{
	t_block block;

	// in_block(&block);
	choose_player(&block);
	return (0);
}
