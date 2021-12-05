/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 20:29:14 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:13:49 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <unistd.h>
# include "constants_bonus.h"
# include "ft_printf.h"
# include "message_list_bonus.h"
# include "receive_bonus.h"

static void						sig_handler(int sig, siginfo_t *siginfo, \
															void *context);
static void						handle_client(int sig, int pid);
static void						process_messages(void);
static struct s_message_node	*check_status(struct s_message_node *prev, \
										struct s_message_node *mn);

#endif