/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 20:25:45 by omartyno          #+#    #+#             */
/*   Updated: 2016/09/11 14:01:43 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"

int		*make_line(char *code)
{
	int j;
	int *line;

	j = 0;
	line = (int *)malloc(sizeof(*line) * 9);
	while (j < 9)
	{
		if ((code[j] > '9' || code[j] < '0') && code[j] != '.')
			break;
		if (code[j] == '.')
			line[j] = 0;
		else
			line[j] = code[j] - '0';
		j++;
	}
	if (j < 9)
		return (0);
	return (line);
}

int		**make_field(char **c)
{
	int i;
	int *line;
	int **to_ret;

	i = 0;
	to_ret = (int **)malloc(sizeof(*to_ret) * 10);
	while (i < 9)
	{
		line = make_line(c[i + 1]);
		if (line)
			to_ret[i] = line;
		else
			break;
		i++;
	}
	if (i < 9)
		return (0);
	to_ret[i] = 0;
	return(to_ret);
}

void	show_sudoku(int **ans)
{
	int i;
	int j;

	i = 0;
	while (ans[i] != 0)
	{
		j = 0;
		while (j < 9)
		{
			if (ans[i][j] != 0)
			{
				if (ans[i][j] == -1)
					ft_putchar('M');
				else
					ft_putnbr(ans[i][j]);
			}
			else
				ft_putchar('*');
			if ((j + 1) % 3)
				ft_putchar(' ');
			else
				ft_putchar('|');
			j++;
		}
		ft_putchar('\n');
		if (!((i + 1) % 3))
		{
			ft_putstr("------------------");
			ft_putchar('\n');
		}
		i++;
	}
}

