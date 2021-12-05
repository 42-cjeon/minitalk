/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:24:26 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 21:50:46 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	struct sigaction	sa;
	sigset_t			ss;
	int					i;

	sigemptyset(&ss);
	sigaddset(&ss, SIGUSR1);
	sigaddset(&ss, SIGUSR1);
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = ss;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("[-] PID : %d\n", getpid());
	while (42)
	{
		process_messages();
		i = 10;
		while (i--)
			usleep(USERVER_TIMEOUT / 10);
	}
}

static struct s_message_node	*check_status(struct s_message_node *prev, \
										struct s_message_node *mn)
{
	int	sender;

	sender = mn->sender;
	if (mn->status == READY)
	{
		print_node(mn);
		remove_node(prev, mn);
		kill(sender, SIGUSR2);
		return (prev);
	}
	else if (!mn->updated)
	{
		remove_node(prev, mn);
		kill(sender, SIGUSR1);
		return (prev);
	}
	mn->updated = 0;
	return (mn);
}

static void	process_messages(void)
{
	struct s_message_node	*mn;
	struct s_message_node	*prev;
	struct s_message_node	*next;

	mn = *get_message_head();
	prev = NULL;
	while (mn)
	{
		next = mn->next;
		prev = check_status(prev, mn);
		mn = next;
	}
}

static void	handle_client(int sig, int pid)
{
	struct s_message_node	*mn;

	mn = search_message_node(pid);
	mn->updated = 1;
	if (mn->status == HEADER)
		receive_header(sig, mn);
	else if (mn->status == HEADER_CRC)
	{
		if (receive_header_crc(sig, mn) == FAILURE)
			mn->status = CRC_FAIL;
	}
	else if (mn->status == PAYLOAD)
		receive_payload(sig, mn);
	else if (mn->status == PAYLOAD_CRC)
	{
		if (receive_payload_crc(sig, mn) == FAILURE)
			mn->status = CRC_FAIL;
	}
}

static void	sig_handler(int sig, siginfo_t *siginfo, void *context)
{
	handle_client(sig, siginfo->si_pid);
	(void)context;
}
