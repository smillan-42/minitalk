/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:45:04 by smillan-          #+#    #+#             */
/*   Updated: 2025/02/03 11:00:00 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	process_state_zero(t_server_state *s, int signum)
{
	if (signum == SIGUSR2)
		s->length |= (1 << s->bit_count);
	s->bit_count++;
	if (s->bit_count == 32)
	{
		s->state = 1;
		s->bit_count = 0;
	}
}

void	process_state_two(t_server_state *s, int signum)
{
	if (signum == SIGUSR2)
		s->c |= (1 << s->char_bit_count);
	s->char_bit_count++;
	if (s->char_bit_count == 8)
	{
		s->message[s->message_index++] = s->c;
		s->char_bit_count = 0;
		s->c = 0;
		if (s->message_index == s->length)
		{
			s->message[s->message_index] = '\0';
			ft_putstr(s->message);
			ft_putstr("\n");
			free(s->message);
			s->state = 0;
			s->bit_count = 0;
			s->length = 0;
			s->message_index = 0;
		}
	}
}

void	server_receive(int signum)
{
	static t_server_state	s = {0, 0, 0, 0, 0, NULL, 0};

	if (s.state == 0)
		process_state_zero(&s, signum);
	else if (s.state == 1)
		process_state_one(&s);
	else if (s.state == 2)
		process_state_two(&s, signum);
}

void	server_loop(t_mini *talk)
{
	if ((signal(SIGUSR1, server_receive) == SIG_ERR)
		|| (signal(SIGUSR2, server_receive) == SIG_ERR))
	{
		ft_putstr("ERROR\n");
		free(talk);
		exit(EXIT_FAILURE);
	}
	while (1)
		pause();
}

int	main(int argc, char **argv)
{
	t_mini	*talk;

	(void)argv;
	if (argc != 1)
	{
		ft_putstr("ERROR\n");
		exit(EXIT_FAILURE);
	}
	talk = server_ini();
	talk->pid_server = getpid();
	ft_putstr("SUCCESS!, The PID: ");
	ft_putnbr(talk->pid_server);
	write(1, "\n", 1);
	server_loop(talk);
	free(talk);
	return (EXIT_SUCCESS);
}
