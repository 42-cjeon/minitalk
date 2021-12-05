/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjeon <cjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:29:50 by cjeon             #+#    #+#             */
/*   Updated: 2021/12/05 22:18:18 by cjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

static int	g_commucate_ch[2];

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("[-] Usage : ./client {PID} {MESSAGE}\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid == 0 || kill(pid, 0) == -1)
	{
		ft_printf("[-] not valid server: %s\n", argv[1]);
		return (1);
	}
	register_handler();
	if (!send_msg_with_retry(pid, argv[2]))
		return (1);
	return (0);
}

static void	sig_handler(int sig)
{
	int	i;

	if (sig == SIGUSR1)
	{
		g_commucate_ch[SERVER] = 0;
		i = g_commucate_ch[CLIENT];
		while (i--)
			usleep(UDELAY);
		usleep(UCLIENT_TIMEOUT);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("[-] message successfully sent.\n");
		g_commucate_ch[SERVER] = 1;
	}
}

static void	register_handler(void)
{
	struct sigaction	sa;
	sigset_t			set;

	sigemptyset(&set);
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	sa.sa_handler = sig_handler;
	sa.sa_flags = 0;
	sa.sa_mask = set;
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
}

static int	send_msg_with_retry(int pid, char *msg)
{
	int		attempt;
	size_t	msg_len;

	msg_len = ft_strlen(msg);
	if (msg_len == 0)
	{
		ft_printf("[!] message cannot be empty!\n");
		return (0);
	}
	g_commucate_ch[CLIENT] = msg_len;
	attempt = 1;
	while (attempt <= MAX_RETRY)
	{
		send_message(pid, msg, msg_len, UDELAY * attempt);
		attempt++;
		usleep(UCLIENT_TIMEOUT);
		if (g_commucate_ch[SERVER])
			return (1);
		ft_printf("[!] failed to send message. retry..\n");
	}
	return (0);
}
