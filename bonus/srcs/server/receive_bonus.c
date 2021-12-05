/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receive_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:00:50 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:18:31 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "receive_bonus.h"

void	receive_header(int sig, struct s_message_node *mn)
{
	if (sig == SIGUSR1)
		mn->nbyte &= ~(1U << (INT_BITS - mn->index % INT_BITS - 1));
	else
		mn->nbyte |= (1U << (INT_BITS - mn->index % INT_BITS - 1));
	if (++mn->index == INT_BITS)
	{
		mn->index = 0;
		mn->status = HEADER_CRC;
	}
}

int	receive_header_crc(int sig, struct s_message_node *mn)
{
	if (sig == SIGUSR1)
		mn->crc8 &= ~(1U << (CHAR_BITS - mn->index % CHAR_BITS - 1));
	else
		mn->crc8 |= (1U << (CHAR_BITS - mn->index % CHAR_BITS - 1));
	if (++mn->index == CHAR_BITS)
	{
		if (check_crc8(mn))
		{
			mn->payload = (unsigned char *) \
				strict_malloc(sizeof(unsigned char) * mn->nbyte);
			mn->status = PAYLOAD;
			mn->index = 0;
			return (SUCCESS);
		}
		return (FAILURE);
	}
	return (SUCCESS);
}

void	receive_payload(int sig, struct s_message_node *mn)
{
	if (sig == SIGUSR1)
		mn->payload[mn->index / 8] \
			&= ~(1U << (CHAR_BITS - mn->index % CHAR_BITS - 1));
	else
		mn->payload[mn->index / 8] \
			|= (1U << (CHAR_BITS - mn->index % CHAR_BITS - 1));
	if (++mn->index == CHAR_BITS * mn->nbyte)
	{
		mn->status = PAYLOAD_CRC;
		mn->index = 0;
	}
}

int	receive_payload_crc(int sig, struct s_message_node *mn)
{
	if (sig == SIGUSR1)
		mn->crc32 &= ~(1U << (INT_BITS - mn->index % INT_BITS - 1));
	else
		mn->crc32 |= (1U << (INT_BITS - mn->index % INT_BITS - 1));
	if (++mn->index == INT_BITS)
	{
		if (check_crc32(mn))
		{
			mn->status = READY;
			return (SUCCESS);
		}
		return (FAILURE);
	}
	return (SUCCESS);
}
