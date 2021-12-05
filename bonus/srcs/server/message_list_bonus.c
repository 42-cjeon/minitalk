/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message_list_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:00:10 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:18:32 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "message_list_bonus.h"

struct s_message_node	**get_message_head(void)
{
	static struct s_message_node	*mn;

	return (&mn);
}

struct s_message_node	*get_message_node(int pid)
{
	struct s_message_node	*new;

	new = (struct s_message_node *) \
			strict_malloc(sizeof(struct s_message_node));
	new->status = HEADER;
	new->sender = pid;
	new->index = 0;
	new->next = NULL;
	new->updated = 0;
	new->payload = NULL;
	return (new);
}

struct s_message_node	*search_message_node(int pid)
{
	struct s_message_node	**head;
	struct s_message_node	*prev;
	struct s_message_node	*curr;

	head = get_message_head();
	if (*head == NULL)
	{
		*head = get_message_node(pid);
		return (*head);
	}
	prev = NULL;
	curr = *head;
	while (curr)
	{
		if (curr->sender == pid)
			return (curr);
		prev = curr;
		curr = curr->next;
	}
	prev->next = get_message_node(pid);
	return (prev->next);
}

void	remove_node(struct s_message_node *prev, struct s_message_node *curr)
{
	struct s_message_node	**head;

	if (curr == NULL)
		return ;
	if (prev == NULL)
	{
		head = get_message_head();
		*head = curr->next;
	}
	else
		prev->next = curr->next;
	free(curr->payload);
	free(curr);
}

void	print_node(struct s_message_node *mn)
{
	ft_printf("<MSG FROM=%d>\n", mn->sender);
	write(1, mn->payload, mn->nbyte);
	ft_printf("\n</END OF MSG>\n");
}
