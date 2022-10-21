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
