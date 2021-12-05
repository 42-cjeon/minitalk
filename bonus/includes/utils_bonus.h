/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:21:45 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:13:53 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include <stdlib.h>

void			*strict_malloc(size_t size);
unsigned char	get_bit_8(unsigned char k, int index);
unsigned char	get_bit_32(unsigned int k, int index);

#endif