/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_token_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 11:48:57 by ochayche          #+#    #+#             */
/*   Updated: 2017/03/29 11:48:58 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	void				create_token(char ***token, int max_y, int max_x)
{
	char *line;
	int j;
	int i;

	j = 0;
	if (!(*token = (char **)malloc(sizeof(char *) * (max_y + 1))))
		perror("allocation error");
	while (j < max_y)
	{
		get_next_line(STDIN, &line);
		(*token)[j] = ft_strdup(line);
		j++;
		ft_strdel(&line);
	}
	(*token)[j] = NULL;
}

void						read_token_size(t_block *block)
{
	int			i;
	char		*line;

	i = 0;
	get_next_line(STDIN, &line);
	while (!ft_isdigit(line[i]))
		i++;
	block->ty = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	block->tx = ft_atoi(&line[i]);
	while (!ft_isdigit(line[i]))
		i++;
	// printf("y% d * x% d\n", y, x);
	ft_strdel(&line);
	create_token(&block->token, block->ty, block->tx);
}
