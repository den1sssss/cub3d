#include "cub3d.h"
int	ft_strlenn(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	indexkek(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strdupp(char *str)
{
	char	*kek;
	size_t	i;

	kek = malloc(ft_strlenn(str) + 1);
	i = 0;
	while (str[i])
	{
		kek[i] = str[i];
		i++;
	}
	kek[i] = '\0';
	return (kek);
}

char	*ft_strjoinn(char *str, char *kek)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = -1;
	j = 0;
	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !kek)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlenn(str) + ft_strlenn(kek)) + 1);
	if (result == NULL)
		return (NULL);
	if (str)
		while (str[++i] != '\0')
			result[i] = str[i];
	while (kek[j] != '\0')
		result[i++] = kek[j++];
	result[ft_strlenn(str) + ft_strlenn(kek)] = '\0';
	free(str);
	return (result);
}

char	*perdelstr(char *str)
{
	int		i;
	char	*perdelstroka;

	i = indexkek(str);
	if (i == -1)
	{
		free(str);
		return (NULL);
	}
	perdelstroka = ft_strdupp(str + i + 1);
	free(str);
	return (perdelstroka);
}
char	*ostatok(char *str, int fd)
{
	char	*buf;
	int		prochitannoe;

	if (indexkek(str) != -1)
		return (str);
	buf = malloc(BUFFER_SIZE + 1);
	buf[0] = 0;
	while (indexkek(buf) == -1)
	{
		prochitannoe = read(fd, buf, BUFFER_SIZE);
		if (prochitannoe == -1)
		{
			free(buf);
			return (NULL);
		}
		if (prochitannoe == 0)
			break ;
		buf[prochitannoe] = 0;
		str = ft_strjoinn(str, buf);
	}
	free(buf);
	return (str);
}

char	*strochka(char *str)
{
	int		i;
	char	*kek;
	int		j;

	if (!str)
		return (NULL);
	if (!str[0])
		return (NULL);
	i = indexkek(str);
	if (i == -1)
		return (ft_strdupp(str));
	kek = malloc(i + 1);
	j = 0;
	while (j < i + 1)
	{
		kek[j] = str[j];
		j++;
	}
	kek[j] = '\0';
	return (kek);
}

char	*get_next_line(int fd)
{
	static char	*ostatki;
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ostatki = ostatok(ostatki, fd);
	if (!ostatki)
		return (NULL);
	str = strochka(ostatki);
	ostatki = perdelstr(ostatki);
	return (str);
}