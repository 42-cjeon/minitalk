/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:23:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:13:39 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECEIVE_BONUS_H
# define RECEIVE_BONUS_H

# include <signal.h>
# include "crc_bonus.h"
# include "message_list_bonus.h"
# include "utils_bonus.h"

# define CHAR_BITS 8
# define INT_BITS 32

void	receive_header(int sig, struct s_message_node *mn);
int		receive_header_crc(int sig, struct s_message_node *mn);
void	receive_payload(int sig, struct s_message_node *mn);
int		receive_payload_crc(int sig, struct s_message_node *mn);

#endif