/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:33:55 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 13:58:02 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

typedef	struct		s_msg_info
{
	char			*msg;
	int				msg_bit_num;
	int				msg_idx;
	int				msg_len;
	int				msg_len_bit_num;
}					t_msg_info;

#endif
