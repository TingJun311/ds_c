#include "lib.h"

// Fibonacci starts here
int	recursive(int	n)
{
	if (n <= 1)
		return (n);
	return (recursive(n - 1) + recursive(n - 2));
}

int	iter(int n)
{
	int	*fibo;
	int	c;

	fibo = 0;
	c = 2;
	if (n <= 1)
		return (n);
	else
	{
		fibo = (int *)malloc(sizeof(int) * n);
		fibo[0] = 0;
		fibo[1] = 1;
		while (c <= n)
		{
			fibo[c] = fibo[c - 1] + fibo[c - 2];	
			c++;
		}
		return (fibo[c - 1]);
	}
}

int	memo[50];
int	memoization(int	n)
{
	if (n <= 1)
	{
		memo[n] = n; 
		return (n);
	}
	else
	{
		if (memo[n - 1] == -1)
			memo[n - 1] = memoization(n - 1);
		if (memo[n - 2] == -1)
			memo[n - 2] = memoization(n - 2);
		return (memo[n - 1] + memo[n - 2]);
	}
}

int	main(int ac, char **av)
{
	int	r;

	r = 0;
	if (ac > 1)
	{
		while (r < ft_atoi(av[1]))
		{
			memo[r] = -1;
			r++;
		}
		ft_putnbr(memoization(ft_atoi(av[1])));
		write(1, "\n", 1);
		ft_putnbr(recursive(ft_atoi(av[2])));
		write(1, "\n", 1);
		ft_putnbr(iter(ft_atoi(av[3])));
	}
	else
		write(1, "\n", 1);
	return (0);
}
