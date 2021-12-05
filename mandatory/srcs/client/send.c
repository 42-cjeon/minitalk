/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:00:47 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:24:33 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "send.h"

void	send_8bit(int pid, unsigned char k, int delay)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (k & (1U << (8 - i - 1)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(delay);
		i++;
	}
}

void	send_32bit(int pid, unsigned int k, int delay)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (k & (1U << (32 - i - 1)))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(delay);
		i++;
	}
}

void	send_message(int pid, char *msg, size_t msg_len, int delay)
{
	size_t	i;

	send_32bit(pid, msg_len, delay);
	send_8bit(pid, calc_crc8(msg_len), delay);
	i = 0;
	while (i < msg_len)
	{
		send_8bit(pid, msg[i], delay);
		i++;
	}
	send_32bit(pid, calc_crc32(msg, msg_len), delay);
}
