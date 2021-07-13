/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 16:40:10 by mmunoz-f          #+#    #+#             */
/*   Updated: 2021/07/13 04:10:17 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

void	pass_string_to_signals(pid_t pid, const char *string)
{
	size_t			i;
	unsigned int	j;

	(void)pid;
	i = 0;
	while (string[i])
	{
		j = 0;
		while (j < 8)
		{
			if (string[i] & (128 >> j))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j++;
			usleep(100);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Wrong number of arguments\n", STDOUT_FILENO);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	pass_string_to_signals(pid, argv[2]);
	return (0);
}
