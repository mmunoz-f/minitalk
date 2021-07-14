/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:28:37 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/14 18:58:04 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static unsigned int	ft_nlength(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	nbr;
	unsigned int	size;
	char			*a;

	size = ft_nlength(n);
	a = (char *)malloc(size + 1);
	if (!a)
		return (0);
	if (n < 0)
	{
		a[0] = '-';
		nbr = -(unsigned int)n;
	}
	else
		nbr = (unsigned int)n;
	a[size] = 0;
	while (nbr || !(n--))
	{
		a[--size] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (a);
}

int	ft_atoi(const char *nptr)
{
	unsigned int	i;
	unsigned int	nbr;
	int				n;

	i = 0;
	nbr = 0;
	n = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] < 14 && nptr[i] > 8)))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			n = 1;
		i++;
	}
	while (nptr[i] < 58 && nptr[i] > 47)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (n == 0)
		return ((int)nbr);
	return (-(int)nbr);
}
