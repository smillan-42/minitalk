/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smillan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:37:03 by smillan-          #+#    #+#             */
/*   Updated: 2025/01/21 12:44:54 by smillan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_mini
{
	int	pid_server;
	int	pid_client;
}				t_mini;

typedef struct s_server_state
{
	int		state;
	int		bit_count;
	int		length;
	char	c;
	int		char_bit_count;
	char	*message;
	int		message_index;
}				t_server_state;

t_mini	*client_ini(void);
t_mini	*server_ini(void);
void	process_state_zero(t_server_state *s, int signum);
void	process_state_one(t_server_state *s);
void	process_state_two(t_server_state *s, int signum);
void	client_send(t_mini *talk, char *message);
void	server_receive(int signum);
void	server_loop(t_mini *talk);
int		ft_strlen(char *s);
int		ft_atoi(char *nptr);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif
