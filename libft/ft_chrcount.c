/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 23:16:44 by ochayche          #+#    #+#             */
/*   Updated: 2016/12/05 23:16:45 by ochayche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrcount(char *str, char c)
{
	int counter;

	counter = 0;
	if (str != '\0')
	{
		while (*str != '\0')
		{
			if (*str == c)
				counter++;
			str++;
		}
	}
	return (counter);
}
