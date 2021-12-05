/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:28:15 by cjeon             #+#    #+#             */
/*   Updated: 2021/11/10 19:08:07 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	prefix_len;
	size_t	suffix_len;

	prefix_len = ft_strlen(s1);
	suffix_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (prefix_len + suffix_len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, prefix_len + 1);
	ft_strlcpy(str + prefix_len, s2, suffix_len + 1);
	return (str);
}
