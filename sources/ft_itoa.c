/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtavitia <vtavitia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 13:02:49 by vtavitia          #+#    #+#             */
/*   Updated: 2023/06/10 17:09:27 by vtavitia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_allocspace(int digits)
{
	char	*result;

	result = malloc(sizeof(char) * (digits + 1));
	if (!result)
		return (NULL);
	return (result);
}

static int	ft_countdigits(long long int n)
{
	long int		digits;

	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static char	*assign(long int n1, int digits, int count, char *result)
{
	int		i;

	i = 0;
	if (n1 < 0)
	{
		i++;
		digits++;
		n1 *= -1;
	}
	while (i < digits)
	{
		result[digits - count] = ((n1 % 10) + '0');
		n1 /= 10;
		i++;
		count++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int			digits;
	char		*result;
	int			count;
	long long	n1;

	n1 = n;
	digits = ft_countdigits(n);
	count = 1;
	if (n1 == 0)
	{
		result = malloc(2);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	else
		result = ft_allocspace(digits);
	if (!result)
		return (NULL);
	assign(n1, digits, count, result);
	return (result);
}
