#include "cub3d.h"
int	get_next_line(int fd, char **line)
{
	int		i;
	int		len;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	len = 1;
	*line = malloc(len);
	(*line)[0] = 0;
	if (!line)
		return (-1);
	while ((r = read(fd, &c, 1)) && len++ && c != '\n')
	{
		tmp = malloc(len);
		if (!tmp)
		{
			free(*line);
			return (-1);
		}
		i = 0;
		while (i < len - 2)
		{
			tmp[i] = (*line)[i];
			i++;
		}
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(*line);
		*line = tmp;
	}
	return (r);
}