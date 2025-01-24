/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:45:04 by smillan-          #+#    #+#             */
/*   Updated: 2025/01/21 12:47:36 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_mini	*server_ini(void)
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

void	server_recieve(int boolean)
{
	static int	bit_displacement = 0;
	static char	letter = 0;
	
	letter += ((boolean & 1) << bit_displacement++);
	if (bit_displacement == 7)
	{
		write(1, &letter, 1);
		if (!letter)
			write(1, "\n", 1);
		bit_displacement = 0;
		letter = 0;
	}
	return ;
}

void	server_loop(t_mini *talk)
{
	while (1)
	{
		if ((signal(SIGUSR1, server_recieve) == SIG_ERR)
			|| (signal(SIGUSR2, server_recieve) == SIG_ERR))
		{
			ft_putstr("ERROR\n");
			free(talk);
			exit(EXIT_FAILURE);
		}
		sleep(2);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_mini	*talk;
	
	(void)argv;
	talk = NULL;
	if (argc != 1)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		talk = server_ini();
		talk->pid_server = getpid();
		ft_putstr("SUCCESS!, The PID: ");
		ft_putnbr(talk->pid_server);
		write(1, "\n", 1);
		server_loop(talk);
	}
	free(talk);
	return (EXIT_SUCCESS);
}