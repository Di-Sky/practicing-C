/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 12:35:46 by omartyno          #+#    #+#             */
/*   Updated: 2016/09/11 13:44:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_mask.h"

int		**null_msk(int size)
{
	int i;
	int j;
	int **mask;

	i = -1;
	mask = (int **)malloc(sizeof(*mask) * (size + 1));
	while (++i < size)
		*(mask + i) = (int *)malloc(sizeof(**(mask + i)) * size);
	mask[i] = 0;
	i = 0;
	while (i < size)
	{
		j = -1;
		while (++j < size)
			mask[i][j] = 0;
		i++;
	}
	return (mask);
}

void	min_line(int *line, int size)
{
	int i;

	i = -1;
	while (++i < size)
		line[i] = (!line[i]) ? -1 : line[i];
}

void	min_col(int **msk, int j, int size)
{
	int i;

	i = -1;
	while (++i < size)
		msk[i][j] = (!msk[i][j]) ? -1 : msk[i][j];
}

void	min_block(int **mask, int line, int col)
{
	int i;
	int j;
	int w_block;
	int h_block;

	h_block = 0;
	w_block = 0;
	h_block = (line < 3) ? 3 : h_block;
	h_block = (line >= 6) ? 9 : h_block;
	if (!h_block)
		h_block = 6;
	w_block = (col < 3) ? 3 : w_block;
	w_block = (col >= 6) ? 9 : w_block;
	if (!w_block)
		w_block = 6;
	i = h_block - 3;
	while (i < h_block)
	{
		j = w_block - 3;
		while (j < w_block)
		{
			if (!mask[i][j])
				mask[i][j] = -1;
			j++;
		}
		i++;
	}
}

int		**make_mask(int **g_f, int num, int size)
{
	int **mask;
	int i;
	int j;

	mask = null_msk(size);
	i = 0;
	while (g_f[i])
	{
		j = 0;
		while (j < size)
		{
			if (g_f[i][j] != num)
			{
				if (g_f[i][j])
					mask[i][j] = -1; 
			}
			else
			{
				mask[i][j] = num;
				min_line(mask[i], size);
				min_col(mask, j, size);
				min_block(mask, i, j);
			}
			j++;
		}
		i++;
	}
	return (mask);
}
