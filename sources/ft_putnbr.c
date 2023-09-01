/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 18:48:32 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/08 17:30:46 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	put_char(char nb)
{
	write(1, &nb, 1);
}

void	ft_putnbr(int nb)
{
	int	max;

	max = 2147483647;
	if (nb == max)
	{
		put_char('-');
		put_char('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		put_char('-');
		nb = nb * -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	if (nb < 10)
	{
		put_char(nb + 48);
	}
}
