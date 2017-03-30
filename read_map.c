/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:37:02 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/29 19:37:02 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		skip_line_plateau(char **line)
{
	if (!ft_strncmp(*line, "Plateau", 7))
	{
		ft_strdel(line);
		get_next_line(STDIN, line);
	}
	ft_strdel(line);
}

void		read_map(t_block *block, int max_y, int max_x)
{
	int		j;
	int		i;
	int		k;
	char	*line;

	j = 0;
	while (j < block->max_y)
	{
		k = 0;
		get_next_line(STDIN, &line);
		while (!strchr(".OXox", line[k]))
			k++;
		i = 0;
		while (i < block->max_x)
		{
			(block->map)[j][i] = line[k];
			(block->priority)[j][i] = MAX_INT;
			i++;
			k++;
		}
		j++;
		ft_strdel(&line);
	}
}
