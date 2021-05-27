/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:56:36 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 14:01:47 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"

void			kill_signo(int pid, int signo)
{
	if (kill(pid, signo) != 0)
		exit(1);
}

void			send_msg_size(int pid, int len)
{
	int			bit_mask;
	int			bit_shifter;
	int			idx;

	ft_print("SEND MSG SIZE : ", 0);
	ft_print(ft_itoa(len), 1);
	ft_print("\n", 0);
	bit_shifter = (sizeof(int) * 8) - 1;
	bit_mask = (1 << bit_shifter);
	idx = -1;
	while (++idx <= bit_shifter)
	{
		usleep(20);
		if (((len << idx) & bit_mask) == bit_mask)
			kill_signo(pid, SIGUSR1);
		else
			kill_signo(pid, SIGUSR2);
	}
}

int				send_msg(int pid, const char *msg)
{
	int			idx;
	int			bit_idx;
	int			bit_mask;

	idx = -1;
	bit_mask = 1 << 7;
	while (msg[++idx] != 0)
	{
		bit_idx = -1;
		while (++bit_idx < 8)
		{
			usleep(20);
			if (((msg[idx] << bit_idx) & bit_mask) == bit_mask)
				kill_signo(pid, SIGUSR1);
			else
				kill_signo(pid, SIGUSR2);
		}
	}
	return (0);
}

int				main(int ac, char **av)
{
	int server_pid;

	if (ac != 3 || av == 0)
		return (ft_print_err("plz input 2 parameters\n", 0));
	if (av[2][0] == 0)
		return (ft_print_err("plz not input not null string\n", 0));
	ft_print(">>> CLIENT START ! <<<\n", 0);
	server_pid = ft_atoi(av[1]);
	if (server_pid < 0)
		return (ft_print_err("plz check your first parameter\n", 0));
	send_msg_size(server_pid, ft_strlen(av[2]));
	usleep(100);
	return (send_msg(server_pid, av[2]));
}
