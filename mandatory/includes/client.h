/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:21:21 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 21:29:15 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <signal.h>
# include "send.h"
# include "libft.h"
# include "ft_printf.h"
# include "constants.h"

# define SERVER 0
# define CLIENT 1

static void	sig_handler(int sig);
static void	register_handler(void);
static int	send_msg_with_retry(int pid, char *msg);

#endif