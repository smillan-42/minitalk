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


int	main(int argv, char ** argc)
{
	if (argc !=  3)
	{
		write(1,"ERROR",5);
		return (1);
	}
	talk->pid_server = ft_atoi(argv[1]);
	if (talk->pid_server < 0)
	{
		write(1, "ERROR", 5);
		return (1);
	}	
	client_send(talk, argv[2]);
	return (0);
}

