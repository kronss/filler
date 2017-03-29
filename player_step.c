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
	int j;
	int i;
	int match;

	match = 0;
	j = 0;
	while (j < block->ty)
	{
		i = 0;
		while (i < block->tx)
		{
			if (block->token[y][x] == '*')
			{
				if (block->map[j + y][i + x] == (block->player))// || block->player1))
					if (++match > 1)
						return (0);
				else if (block->map[j + y][i + x] == (block->ai))// || block->ai1))
					return (0);
			}
			i++;
		}
		j++;
	}
	return ((match == 1) ? (1) : (0));
}

void			recalc_priority(t_block *block, int j, int i)
{

}

void	find_way(t_block *block)
{
	int j;
	int i;

	j = 0;
	while (j < block->max_y)
	{
		i = 0;
		while (i < block->max_x)
		{
			if (block->map[j][i] == block->ai)
				recalc_priority(block, j, i);
			i++;
		}
		j++;
	}
}

void			player_step(t_block *block)
{
	int			j;
	int			i;

	find_way(block);
	j = 0;
	while (j + (block->ty - 1) < block->max_y)
	{
		while (i + (block->tx - 1) < block->max_x) 
		{
			if (insert_token(block, i, j))
			{
				recalc_priority();
			}
		}
		j++;

	}
	ft_printf("%d %d\n", block->step_y, block->step_x);
}
