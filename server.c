/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmunoz-f <mmunoz-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 01:57:23 by miguel            #+#    #+#             */
/*   Updated: 2021/07/14 19:35:51 by mmunoz-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_client(int signum, siginfo_t *siginfo, void *something)
{
	static char	c = 0;
	static int	i = 0;

	(void)something;
	if (signum == SIGUSR1)
		c |= (128 >> i);
	i++;
	if (i == 8)
	{
		if (c)
			write(STDOUT_FILENO, &c, 1);
		else
		{
			kill(siginfo->si_pid, SIGUSR1);
			write(STDOUT_FILENO, "\n", 1);
		}
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	signal_set;

	pid = getpid();
	write(STDOUT_FILENO, "PID: ", ft_strlen("PID: "));
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	sigemptyset(&signal_set.sa_mask);
	signal_set.sa_sigaction = print_client;
	signal_set.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &signal_set, NULL);
	sigaction(SIGUSR2, &signal_set, NULL);
	while (1)
		pause();
	return (0);
}
