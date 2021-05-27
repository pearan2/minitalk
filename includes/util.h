/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honlee <honlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 10:35:53 by honlee            #+#    #+#             */
/*   Updated: 2021/05/27 13:59:36 by honlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# define WELCOME_MSG ">>>  SERVER START ! <<<\nSERVER pid : "

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

/*
** utils
*/
char				*ft_itoa(int n);
int					ft_strlen(const char *str);
int					ft_print(const char *str, int is_free);
int					ft_print_err(const char *str, int is_free);
int					ft_atoi(const char *str);

#endif
