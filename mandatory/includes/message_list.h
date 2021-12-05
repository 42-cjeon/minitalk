/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_list.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 16:55:31 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 20:27:44 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_LIST_H
# define MESSAGE_LIST_H

# include <stdlib.h>
# include <unistd.h>
# include "utils.h"
# include "ft_printf.h"

enum e_status
{
	CRC_FAIL,
	HEADER,
	HEADER_CRC,
	PAYLOAD,
	PAYLOAD_CRC,
	READY
};

enum e_result
{
	FAILURE,
	SUCCESS
};

struct s_message_node
{
	enum e_status			status;
	int						sender;
	int						updated;
	unsigned int			index;
	unsigned int			nbyte;
	unsigned char			crc8;
	unsigned char			*payload;
	unsigned int			crc32;
	struct s_message_node	*next;
};

struct s_message_node	**get_message_head(void);
struct s_message_node	*get_message_node(int pid);
struct s_message_node	*search_message_node(int pid);
void					remove_node(struct s_message_node *prev, \
										struct s_message_node *curr);
void					print_node(struct s_message_node *mn);

#endif