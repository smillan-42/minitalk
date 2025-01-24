/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_talk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:45:04 by smillan-          #+#    #+#             */
/*   Updated: 2025/01/21 12:47:36 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi(char *nptr)
{
	int	a;
	int	num;
	int	i;

	i = 0;
	a = 1;
	num = 0;
	while ((((nptr[i] >= 9) && (nptr[i] <= 13))
			|| (nptr[i] == ' ')) && (nptr[i] != '\0'))
	{
		i++;
	}
	if (((nptr[i] == '+') || (nptr[i] == '-')) && (nptr[i] != '\0'))
	{
		if (nptr[i] == '-')
			a = (-1) * a;
		i++;
	}
	while ((nptr[i] <= '9') && (nptr[i] >= '0') && (nptr[i] != '\0'))
	{
		num = (num * 10) + (nptr[i] - '0');
		i++;
	}
	return (a * num);
}

void ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}	
}

void ft_putnbr(int n)
{
    char	c;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
        c = n + '0';
        write(1, &c, 1);
	}
}