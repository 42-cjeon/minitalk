/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_string_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:47:47 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 21:54:12 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

struct s_string_info	int_to_string(char *buf, union u_arg *arg, \
										struct s_format_info *fi)
{
	struct s_string_info	si;
	size_t					prefix_len;
	size_t					main_len;

	init_si(&si);
	si.prefix[0] = int_selector(si.prefix[0], '-', arg->i < 0);
	si.prefix[0] = int_selector(si.prefix[0], '+', \
									(fi->flag & POS_SIGN) && (0 <= arg->i));
	si.prefix[0] = int_selector(si.prefix[0], ' ', \
									(fi->flag & EMPTY_SPACE) && (0 <= arg->i));
	si.left_sign = ((fi->flag & ZERO_PAD) && !(fi->flag & LEFT_ALIGN) \
					&& (si.prefix[0]) && !(fi->flag & PRECISION));
	prefix_len = (si.prefix[0] != '\0');
	main_len = itoa_int(buf, arg->i);
	main_len -= ((fi->flag & PRECISION) && arg->i == 0);
	si.mid_padding = ((fi->flag & PRECISION) != 0) \
						* (main_len < fi->max_len) \
						* (fi->max_len - main_len);
	si.main_part = buf;
	si.total_len = prefix_len + main_len + si.mid_padding;
	return (si);
}

struct s_string_info	uint_to_string(char *buf, union u_arg *arg, \
										struct s_format_info *fi)
{
	size_t					main_len;
	struct s_string_info	si;

	init_si(&si);
	main_len = itoa_ulong(buf, arg->u, 10, "0123456789");
	main_len -= ((fi->flag & PRECISION) && arg->u == 0);
	si.mid_padding = ((fi->flag & PRECISION) != 0) \
						* (main_len < fi->max_len) \
						* (fi->max_len - main_len);
	si.main_part = buf;
	si.total_len = main_len + si.mid_padding;
	return (si);
}
