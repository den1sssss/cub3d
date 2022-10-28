#include "cub3d.h"

int	create_trgb( int r, int g, int b)
{
	return ( r << 16 | g << 8 | b);
}
void	check_numbers(char **str)
{
    int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
                print_error("Error: incorrect color value");
			j++;
		}
		i++;
	}
}
void check_color(t_game *game, char *str, char color)
{
    char		**param;
	int         r;
	int         g;
	int         b;
    int         i;

    i = 0;
    param = ft_split(str,',');
    while(param[i])
        i++;
    printf("%d",i);
    if(i != 3)
        print_error("Error: problem with colors\n");
    check_numbers(param);
	r = ft_atoi(param[0]);
	g = ft_atoi(param[1]);
	b = ft_atoi(param[2]);
	if (r > 255 || g > 255 || b > 255)
        print_error("Error: incorrect color values");
    if (color == 'F')
		game->floor = create_trgb( r, g, b);
	else if (color == 'C')
		game->ceiling = create_trgb( r, g, b);
    free(param);
}
