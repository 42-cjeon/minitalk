/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:11:00 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:59:08 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned char	get_bit_32(unsigned int k, int index)
{
	if (k & (1U << (32 - index - 1)))
		return (1);
	return (0);
}

unsigned char	get_bit_8(unsigned char k, int index)
{
	if (k & (1U << (8 - index - 1)))
		return (1);
	return (0);
}

void	*strict_malloc(size_t size)
{
	void	*mem;

	mem = malloc(size);
	if (mem == NULL)
		exit(1);
	return (mem);
}
