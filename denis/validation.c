// #include "cub3d.h"
// int	getheight(char *file)
// {
// 	int		height;
// 	int		fd;
// 	char	*str;

// 	height = 0;
// 	str = NULL;
// 	fd = open(file, O_RDONLY);
// 	str = get_next_line(fd);
// 	while (str != NULL)
// 	{
// 		height++;
// 		free(str);
// 		str = get_next_line(fd);
// 	}
// 	close(fd);
// 	return (height);
// }

// int	getwidth(char *file)
// {
// 	char	*arr;
// 	int		fd;
// 	int		i;
// 	int		words;

// 	fd = open(file, O_RDONLY);
// 	arr = get_next_line(fd);
// 	words = 0;
// 	i = 0;
// 	while (arr[i])
// 	{
// 		while (arr[i] == ' ' && arr[i])
// 			i++;
// 		if (arr[i])
// 			words++;
// 		while (arr[i] != ' ' && arr[i])
// 			i++;
// 	}
// 	close(fd);
// 	return (words);
// }

// int	**getmap(char *file, char **str)
// {
// 	int		i;
// 	int		j;
// 	int		fd;
// 	int		**map;
// 	int		*massiv;

// 	fd = open(file, O_RDONLY);
// 	i = 0;
// 	map = (int **)malloc(sizeof(int *) * getheight(file));
// 	while (i < getheight(file))
// 	{
// 		map[i] = (int *)malloc(sizeof(int) * getwidth(file));
// 		str = ft_split(get_next_line(fd), ' ');
// 		j = 0;
// 		massiv = map[i];
// 		while (str[++j])
// 			massiv[j] = ft_atoi(str[j]);
// 		i++;
// 	}
// 	return (map);
// }
// int validation(int argc,char **argv)
// {
//     if(argc && argv)
//         return(1);
//     return (0);
// }