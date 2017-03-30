/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_step.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:32:55 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/29 19:32:56 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

short 			insert_token(t_block *block, int y, int x)
{
	int			j;
	int			i;
	int			match;

	match = 0;
	j = -1;
	while (++j < block->ty)
	{
		i = -1;
		while (++i < block->tx)
		{
			if (block->token[j][i] == '*')
			{
				if (block->map[j + y][i + x] == (block->player))
				{
					if (++match > 1)
						return (0);
				}
				else if (block->map[y + j][x + i] == (block->ai))
					return (0);
			}
		}
	}
	return (match == 1 ? 1 : 0);
}

void			player_step(t_block *block)
{
	int			j;
	int			i;

	j = 0;
	while (j + (block->ty - 1) < block->max_y)
	{
		while (i + (block->tx - 1) < block->max_x) 
		{
			if (insert_token(block, i, j))
				;// calc;// recalc_priority();
		}
		j++;

	}


	ft_printf("%d %d\n", block->step_y, block->step_x);
}
