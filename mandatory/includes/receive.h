/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:23:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:28:26 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_H
# define RECEIVE_H

# include <signal.h>
# include "crc.h"
# include "message_list.h"
# include "utils.h"

# define CHAR_BITS 8
# define INT_BITS 32

void	receive_header(int sig, struct s_message_node *mn);
int		receive_header_crc(int sig, struct s_message_node *mn);
void	receive_payload(int sig, struct s_message_node *mn);
int		receive_payload_crc(int sig, struct s_message_node *mn);

#endif