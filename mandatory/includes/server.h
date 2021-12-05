/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:14 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 21:54:52 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <signal.h>
# include <unistd.h>
# include "constants.h"
# include "ft_printf.h"
# include "message_list.h"
# include "receive.h"

static void						sig_handler(int sig, siginfo_t *siginfo, \
															void *context);
static void						handle_client(int sig, int pid);
static void						process_messages(void);
static struct s_message_node	*check_status(struct s_message_node *prev, \
										struct s_message_node *mn);

#endif