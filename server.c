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

void server_loop(t_mini *talk)

int	main()
{
	talk = server_initial();
	talk->pid_server = getpid();
	server_loop(talk);
	return (0);
}