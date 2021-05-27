/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:40:12 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 17:22:33 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

static size_t		ft_get_size(int n)
{
	size_t			ret;
	unsigned int	nbr;

	nbr = n < 0 ? n * (-1) : n;
	ret = n < 0 ? 1 : 0;
	while (nbr / 10 != 0)
	{
		ret++;
		nbr = nbr / 10;
	}
	ret++;
	return (ret);
}

char				*ft_itoa(int n)
{
	size_t			ret_size;
	char			*ret;
	size_t			idx;
	unsigned int	nbr;

	idx = 1;
	ret_size = ft_get_size(n);
	if (!(ret = malloc(ret_size + 1)))
		exit(1);
	nbr = n < 0 ? n * (-1) : n;
	if (n < 0)
		ret[0] = '-';
	ret[ret_size] = 0;
	while (nbr / 10 != 0)
	{
		ret[ret_size - idx] = (nbr % 10) + '0';
		idx++;
		nbr = nbr / 10;
	}
	ret[ret_size - idx] = nbr + '0';
	return (ret);
}

int					ft_print(const char *str, int is_free)
{
	write(1, str, ft_strlen(str));
	if (is_free == 1)
		free((void *)str);
	return (1);
}

int					ft_print_err(const char *str, int is_free)
{
	write(2, str, ft_strlen(str));
	if (is_free == 1)
		free((void *)str);
	return (0);
}

int					ft_strlen(const char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] != 0)
		ret++;
	return (ret);
}
