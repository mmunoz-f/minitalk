#include "minitalk.h"

int	print_client(int signum)
{
	static char	c = 0;
	static int	i = 0;

	if (signum == SIGUSR1)
		c |= (0b10000000 >> i);
	i++;
	if (i > 8)
	{
		write(STDOUT_FILENO, &c, 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid =getpid();
	ft_putnbr_fd(pid, STDOUT_FILENO);
	signal(SIGUSR1, print_client);
	signal(SIGUSR2, print_client);
	return (0);
}
