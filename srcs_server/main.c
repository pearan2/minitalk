/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:34:44 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 13:57:45 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/util.h"
#include "../includes/server.h"

t_msg_info		g_info;

void			init_msg_info(void)
{
	if (g_info.msg != NULL)
	{
		ft_print("Received Msg : ", 0);
		ft_print(g_info.msg, 1);
		ft_print("\n", 0);
	}
	g_info.msg = 0;
	g_info.msg_bit_num = 0;
	g_info.msg_idx = 0;
	g_info.msg_len_bit_num = 0;
	g_info.msg_len = 0;
}

void			make_msg_len(int add_value)
{
	int		idx;

	idx = -1;
	g_info.msg_len_bit_num++;
	g_info.msg_len = g_info.msg_len << 1;
	g_info.msg_len += add_value;
	if (g_info.msg_len_bit_num == (int)(sizeof(int) * 8))
	{
		g_info.msg = (char *)malloc(g_info.msg_len + 1);
		if (g_info.msg == 0)
			exit(1);
		g_info.msg[g_info.msg_len] = 0;
		while (g_info.msg[++idx] != 0)
			g_info.msg[idx] = 0;
	}
}

void			sig_handler(int signo)
{
	if (g_info.msg_len_bit_num < (int)(sizeof(int) * 8))
		return (make_msg_len(signo == SIGUSR1));
	g_info.msg_bit_num++;
	g_info.msg[g_info.msg_idx] = g_info.msg[g_info.msg_idx] << 1;
	g_info.msg[g_info.msg_idx] += (signo == SIGUSR1);
	if (g_info.msg_bit_num > 7)
	{
		g_info.msg_bit_num = 0;
		g_info.msg_idx++;
	}
	if (g_info.msg_idx == g_info.msg_len)
		init_msg_info();
}

int				main(void)
{
	ft_print(WELCOME_MSG, 0);
	ft_print(ft_itoa(getpid()), 1);
	ft_print("\n", 0);
	init_msg_info();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
}
