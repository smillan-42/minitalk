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

typedef struct s_mini
{
	int	pid_server;
	int	pid_client;
}	t_mini;

t_mini	*client_start(void);
t_mini	*server_start(void);
void	client_send(t_mini *talk, char *message);
void	server_receive(int boolean);
int		ft_strlen(char *s);
int		ft_atoi(char *nptr);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

#endif