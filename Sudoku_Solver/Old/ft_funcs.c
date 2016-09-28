/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 10:47:32 by omartyno          #+#    #+#             */
/*   Updated: 2016/09/11 11:40:14 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
		ft_putchar(str[i]);
}

void	ft_putnbr(int nb)
{
	int ch_nb;
	int d_r;
	int lowest_int;

	lowest_int = (nb == -2147483648) ? 1 : 0;
	nb /= (nb == -2147483648) ? 10 : 1;
	if (nb < 0)
		ft_putchar('-');
	nb *= (nb < 0) ? -1 : 1;
	ch_nb = nb;
	d_r = 1;
	while (ch_nb > 9)
	{
		ch_nb /= 10;
		d_r *= 10;
	}
	while (d_r > 0)
	{
		ch_nb = (nb / d_r) % 10;
		ft_putchar('0' + ch_nb);
		d_r /= 10;
	}
	if (lowest_int)
		ft_putchar('8');
}
