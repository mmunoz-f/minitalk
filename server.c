/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 01:57:23 by miguel            #+#    #+#             */
/*   Updated: 2021/07/13 04:56:25 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_client(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
		c |= (128 >> i);
	i++;
	if (i == 8)
	{
		if (c)
			write(STDOUT_FILENO, &c, 1);
		else
			write(STDOUT_FILENO, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t pid;

	pid = getpid();
	write(STDOUT_FILENO, "PID: ", ft_strlen("PID: "));
	ft_putnbr_fd(pid, STDOUT_FILENO);
	write(1, "\n", 1);
	signal(SIGUSR1, print_client);
	signal(SIGUSR2, print_client);
	while(1)
		pause();
	return (0);
}
