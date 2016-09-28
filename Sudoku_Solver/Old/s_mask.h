/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mask.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 13:44:46 by omartyno          #+#    #+#             */
/*   Updated: 2016/09/11 13:47:19 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MASK_H
# define S_MASK_H

#include <stdlib.h>

int		**null_msk(int size);
void	min_line(int *line, int size);
void	min_col(int **msk, int j, int size);
void	min_block(int **mask, int line, int col);
int		**make_mask(int **g_f, int num, int size);

#endif
