#include "push_swap.h"

void	oopsie(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	maximini(const char *s)
{
	long	sign;
	long	res;
	int		i;

	sign = 1;
	res = 0;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (!s[i])
		oopsie();
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			oopsie();
		res = res * 10 + (s[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			oopsie();
		i++;
	}
    return (res * sign);
}

void	areyoudig(char **list)
{
	int i;
	int j;

	if (!list)
			oopsie();
	i = 0;
	while (list[i])
	{
		j = 0;
		if (list[i][j] == '+' || list[i][j] == '-')
			j++;
		if (list[i][j] == '\0')
			oopsie();
		while (list[i][j])
		{
			if (!ft_isdigit((unsigned char)list[i][j]))
				oopsie();
			j++;
		}
		i++;
	}
}

void	dduupplliiccaattee(const int *vals, int n)
{
	int i;
	int j;

	if (!vals || n <= 1)
		return;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (vals[i] == vals[j])  
				oopsie();
			j++;
		}
		i++;
	}
}

int	ft_issorted(int *vals, int count)
{
	int	i;

	if (count <= 1)
		return (1);
	i = 0;
	while (i < count - 1)
	{
		if (vals[i] > vals[i + 1])
			return (0);
		i++;
	}
	return (1);
}
