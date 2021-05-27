/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 11:05:55 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 13:54:35 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int					ft_atoi(const char *str)
{
	unsigned int		ret;
	unsigned int		is_minus;

	ret = 0;
	is_minus = 0;
	while ((*str <= '\r' && *str >= '\t') || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			is_minus = 1;
		str++;
	}
	while (*str <= '9' && *str >= '0')
		ret = (ret * 10) + (*str++) - '0';
	if (is_minus)
		return (ret * (-1));
	return (ret);
}
