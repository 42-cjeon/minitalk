/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:21:45 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:26:09 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

void			*strict_malloc(size_t size);
unsigned char	get_bit_8(unsigned char k, int index);
unsigned char	get_bit_32(unsigned int k, int index);

#endif