/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 18:20:04 by omartyno          #+#    #+#             */
/*   Updated: 2016/09/11 17:44:10 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"
#include "s1_lib.h"
#include "s_mask.h"
#include <stdio.h> // Watch out!

char	**sudoku(int ac, char **av)
{
	int ***cube;
	int i;
	int size = 9;
	int *c_s; //Wo!

	cube = (int ***)malloc(sizeof(*cube) * 10);
	cube[0] = make_field(av);
	i = 0;
	while (++i < 10)
		cube[i] = make_mask(*cube, i, 9);
	i = 0;
	while (++i < 10)
	{
		show_sudoku(cube[i]);
		ft_putchar('\n');
	}
	show_sudoku(cube[0]);
	return (0);
}

int		main(int argc, char **argv)
{
	if (argc < 10)
		return 0;
	sudoku(argc, argv);
}
