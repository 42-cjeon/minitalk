/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:03:43 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:18:22 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "crc_bonus.h"

unsigned char	calc_crc8(unsigned int origin)
{
	int				i;
	unsigned char	crc;

	crc = 0;
	i = 0;
	while (i < 8)
	{
		if (get_bit_8(crc, 0) ^ get_bit_8(origin, i))
			crc = ((crc << 1) ^ CRC8_POLYNOMINAL);
		else
			crc <<= 1;
		i++;
	}
	return (crc);
}

unsigned int	calc_crc32(void *origin, unsigned int len)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	crc;
	unsigned char	*data;

	data = (unsigned char *)origin;
	crc = 0;
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < 8)
		{
			if (get_bit_32(crc, 0) ^ get_bit_8(data[i], j))
				crc = ((crc << 1) ^ CRC32_POLYNOMINAL);
			else
				crc <<= 1;
			j++;
		}
		i++;
	}
	return (crc);
}

int	check_crc8(struct s_message_node *mn)
{
	if (mn->crc8 == calc_crc8(mn->nbyte))
		return (SUCCESS);
	return (FAILURE);
}

int	check_crc32(struct s_message_node *mn)
{
	if (mn->crc32 == calc_crc32(mn->payload, mn->nbyte))
		return (SUCCESS);
	return (FAILURE);
}
