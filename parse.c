#include "cub3d.h"
// void read_map(int i,game)
// {

// }
int	check_extention(t_game *game)
{
	if (ft_strncmp(&game->e[ft_strlen(game->e) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->n[ft_strlen(game->n) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->s[ft_strlen(game->s) - 4], ".xpm", 4))
		return (1);
	if (ft_strncmp(&game->w[ft_strlen(game->w) - 4], ".xpm", 4))
		return (1);
	return (0);
}
void check_permission(t_game *game)
{
    int fd;

    fd = open(game->n,O_RDONLY);
    if(fd == -1)
        error_and_close("Error: dont have a permission to read or open or wrong path\n",fd);
    fd = open(game->e,O_RDONLY);
    if(fd == -1)
        error_and_close("Error: dont have a permission to read or open or wrong path\n",fd);
    fd = open(game->s,O_RDONLY);
    if(fd == -1)
        error_and_close("Error: dont have a permission to read or open or wrong path\n",fd);
    fd = open(game->w,O_RDONLY);
    if(fd == -1)
        error_and_close("Error: dont have a permission to read or open or wrong path\n",fd);
}

void check_params(t_game *game)
{
	if (game->e == NULL || game->n == NULL || game->s == NULL || game->w == NULL)
        print_error("Error: blank parameter\n");
    if(check_extention(game))
        print_error("Error: wrong extention\n");
    check_permission(game); // раскомментить потом
    check_color(game,game->bottom,'F');
    check_color(game,game->top,'C');
    printf("FLOOR = %d",game->floor);
    printf("FLOOR = %d",game->ceiling);


}
//get_params
void parse_param_value(char **param,int *i,t_game *game)
{
    int	pos;

	pos = 0;
	if (*param)
        print_error("Error: parameter already exists\n");
	while (game->file[*i] && (game->file[*i] == ' ' || game->file[*i] == '\t'))
		(*i)++;
	pos = *i;
	while (game->file[*i] && game->file[*i] != ' ' && game->file[*i] != '\n' && game->file[*i] != '\t')
		(*i)++;
	if (pos == (*i))
        print_error("Parse_param_value error\n");
	*param = ft_substr(game->file, pos, (*i) - pos);
}
int check_param_value(char *target,int i,t_game *game, int flag)
{
    if(flag == 1)
    {
        if(target[0] == game->file[i] && target[1] == game->file[i + 1])
        {
            if (game->file[i + 2] == ' ' || game->file[i + 2] == '\t')
                return (1);
            else
                print_error("Value parse error\n");
        }
    }
    else if(flag == 0)
    {
        if(target[0] == game->file[i])
        {
            if (game->file[i + 1] == ' ' || game->file[i + 1] == '\t')
                return (1);
            else
                print_error("Color parse error\n");
        }
    }
    return (0);
}
void get_params(int *i, t_game *game)
{
	while (game->file[*i] && (game->file[*i] == ' ' || game->file[*i] == '\t' || game->file[*i] == '\n'))
		(*i)++;
    if(check_param_value("NO", *i,game,1))
    {
        (*i)+=2;
        parse_param_value(&(game->n),i,game);
    }
    else if(check_param_value("WE", *i,game,1))
    {
        (*i)+=2;
        parse_param_value(&(game->w),i,game);
    }
    else if(check_param_value("SO", *i,game,1))
    {
        (*i)+=2;
        parse_param_value(&(game->s),i,game);
    }
    else if(check_param_value("EA", *i,game,1))
    {
        (*i)+=2;
        parse_param_value(&(game->e),i,game);
    }
    else if(check_param_value("F",*i,game,0))
    {
        (*i)+=2;
        parse_param_value(&(game->bottom),i,game);
    }
    else if(check_param_value("C",*i,game,0))
    {
        (*i)+=2;
        parse_param_value(&(game->top),i,game);
    }
}
//
int is_complete(t_game *game)
{
    if(game->bottom && game->top && game->e \
    && game->s && game->n && game->w)
        return(1);
    return(0);
}
void parse(t_game *game)
{
    if(game)
        printf("\n--------\ncool.Parsing started...\n-------\n");
    int i;

	i = 0;
	while (game->file[i])
	{
		if (is_complete(game))
			break ;
		get_params(&i, game);
		i++;
	}
    check_params(game);
    printf("Parse results:\n");
    printf("n = %s\n",game->n);
    printf("s = %s\n",game->s);
    printf("w = %s\n",game->w);
    printf("e = %s\n",game->e);
    printf("bottom = %s\n",game->bottom);
    printf("top= %s\n",game->top);
	parse_map(i, game);
    

}