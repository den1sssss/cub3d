#include "cub3d.h"

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_abs(int x)
{
	if (x <= 0)
		return (-x);
	return (x);
}

double	rup_d(double x)
{
	return ((double)((int)x / 1 + 1));
}


double	dup_d(double x)
{
	return ((double)((int)x / 1));
}

int	rup_i(int x)
{
	return (x / 1 + 1);
}



int	dup_i(int x)
{
	return (x / 1);
}
