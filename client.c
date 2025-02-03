/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:37:03 by smillan-          #+#    #+#             */
/*   Updated: 2025/01/21 12:44:54 by smillan-         ###   ########.fr       */
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

t_mini	*client_ini(void)
{
	t_mini	*talk;

	talk = malloc(sizeof(t_mini));
	if (!talk)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	talk->pid_server = 0;
	talk->pid_client = 0;
	return (talk);
}

static void	client_send_int(t_mini *talk, int number)
{
	int	bit;

	bit = 0;
	while (bit < 32)
	{
		if ((number >> bit) & 1)
			kill(talk->pid_server, SIGUSR2);
		else
			kill(talk->pid_server, SIGUSR1);
		usleep(200);
		bit++;
	}
}

void	client_send(t_mini *talk, char *message)
{
	int	bit_displacement;
	int	i;
	int	signal;

	i = -1;
	while (++i < ft_strlen(message))
	{
		bit_displacement = -1;
		while (++bit_displacement < 8)
		{
			if ((message[i] >> bit_displacement) & 1)
				signal = SIGUSR2;
			else
				signal = SIGUSR1;
			kill(talk->pid_server, signal);
			usleep(200);
		}
	}
}

int	main(int argc, char **argv)
{
	t_mini	*talk;
	int		msg_length;

	if (argc != 3)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	talk = client_ini();
	talk->pid_server = ft_atoi(argv[1]);
	if (talk->pid_server <= 0)
	{
		ft_putstr("ERROR\n");
		free(talk);
		exit(EXIT_FAILURE);
	}
	msg_length = ft_strlen(argv[2]);
	client_send_int(talk, msg_length);
	kill(talk->pid_server, SIGUSR1);
	usleep(200);
	client_send(talk, argv[2]);
	free(talk);
	return (EXIT_SUCCESS);
}
