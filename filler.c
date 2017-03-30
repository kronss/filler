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

static	void	init_player(t_block *block)
{
	char		*line;

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

static	void	read_map_max_size(t_block *block)
{
	int			i;
	char		*line;

	i = 0;
	get_next_line(STDIN, &line);
	while (!ft_isdigit(line[i]))
		i++;
	block->max_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	while (!ft_isdigit(line[i]))
		i++;
	block->max_x = ft_atoi(&line[i]);
	ft_strdel(&line);
}


static	void	create_map(t_block *block, int max_y, int max_x)
{
	int			j;

	j = 0;
	if (!(block->map = (char **)malloc(sizeof(char *) * (max_y + 1))))
		perror("allocation error");
	while (j < max_y)
	{
		if (!(block->map[j] = ft_strnew(max_x + 1)))
			perror("allocation error");
		j++;
	}
	(block->map)[j] = NULL;
}

int				main(void)
{
	t_block		block;
	int			res;

															// int x;
															// int y;

	init_player(&block);
	read_map_max_size(&block);
	create_map(&block, block.max_y, block.max_x);
	create_priority(&block, block.max_y, block.max_x);
	while (get_next_line(STDIN, &block.line) > 0)
	{
		skip_line_plateau(&block.line);
		read_map(&block, block.max_y, block.max_x);
		read_token_size(&block);
		

															// y = 0;
															// while (y < block.max_y)
															// {
															// 	printf("%s\n", block.map[y]);
															// 	y++;
															// }
															// y = 0;
															// while (y < block.ty)
															// {
															// 	printf("%s\n", block.token[y]);
															// 	y++;
															// }
		update_priority(&block);
		



		player_step(&block);
	}
	// if (res == -1)
		// perror("error");
		// sleep(100);
	return (0);
}
