/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_priority.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 15:01:09 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/30 15:01:10 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void	update(t_block *block, int y, int x)
{
	int			j;
	int			i;
	int			tmp;

	block->priority[y][x] = MIN_INT; // del??
	j = -1;
	while (++j < block->max_y)
	{
		i = -1;
		while (++i < block->max_x)
		{
			// if (block->map[j][i] != block->ai)
			// {	
				tmp = ABS(j - y) + ABS(i - x);
				block->priority[j][i] = ft_min(tmp, block->priority[j][i]);
			// }
		}
	}
}

void			update_priority(t_block *block)
{
	int			j;
	int			i;

	j = 0;
	while (j < block->max_y)
	{
		i = 0;
		while (i < block->max_x)
		{
			if (block->map[j][i] == block->ai)
				update(block, j, i);
			i++;
		}
		j++;
	}
	block->priority_dot = MAX_INT;
	block->step_y = 0;
	block->step_x = 0;
}

void			create_priority(t_block *block, int max_y, int max_x)
{
	int			j;

	j = 0;
	if (!(block->priority = (int **)malloc(sizeof(int *) * (max_y))))
		perror("allocation error");
	while (j < max_y)
	{
		if (!(block->priority[j] = (int *)malloc(sizeof(int) * (max_x))))
			perror("allocation error");
		j++;
	}
}
