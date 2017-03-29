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

static void					init_player(t_block *block)
{
	char 	*line;

	get_next_line(STDIN, &line);
	if (!ft_strncmp("$$$ exec p1 :", line, 13))
	{
		// printf("123\n");
		block->player = 'O';
		block->ai = 'X';
	}
	else
	{
		// printf("321\n");
		block->player = 'X';
		block->ai = 'O';
	}
	ft_strdel(&line);
	get_next_line(STDIN, &line);
	ft_strdel(&line);
}

static void					read_map_max_size(t_block *block)
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

static void					create_map(t_block *block, int max_y, int max_x)
{
	int			j;

	j = 0;
	if (!(block->map = (char **)malloc(sizeof(char *) * (max_y + 1))))
		perror("allocation error");
	while (j < max_y)
	{
		if (!(block->map[j] = ft_strnew(max_x + 1)))
			perror("allocation error");
		block->map[j][max_x] = '\0';
		j++;
	}
	(block->map)[j] = NULL;
	//printf("y%d * x%d\n", max_y, max_x);
}

static void					create_map_priority(t_block *block, int max_y, int max_x)
{
	int 		j;

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

int							main(void)
{
	perror("allocation error");
	t_block		block;

	int x;
	int y = 0;

	init_player(&block);
	read_map_max_size(&block);
	create_map(&block, block.max_y, block.max_x);
	create_map_priority(&block, block.max_y, block.max_x);
	while ((get_next_line(STDIN, &block.line) > 0))
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

		player_step(&block);

	}







	return (0);
}
