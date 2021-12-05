/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crc_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 00:20:48 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:13:26 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRC_BONUS_H
# define CRC_BONUS_H

# include "constants_bonus.h"
# include "message_list_bonus.h"
# include "utils_bonus.h"

unsigned char	calc_crc8(unsigned int origin);
unsigned int	calc_crc32(void *origin, unsigned int len);
int				check_crc8(struct s_message_node *mn);
int				check_crc32(struct s_message_node *mn);

#endif