/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:30:17 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:26:20 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SEND_H
# define SEND_H

# include <signal.h>
# include <unistd.h>
# include "crc.h"

void	send_8bit(int pid, unsigned char k, int delay);
void	send_32bit(int pid, unsigned int k, int delay);
void	send_message(int pid, char *msg, size_t msg_len, int delay);

#endif