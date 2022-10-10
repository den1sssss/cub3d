#include "cub3d.h"
// void read_map(int i,game)
// {

// }
// void check_data(t_game *game)
// {

// }
//get_params
void parse_param_value(char **param,int *i,t_game *game)
{
    int	pos;

	pos = 0;
	if (*param)
	{
		write(1, "Error: parameter already exists\n", 32);
		exit(0);
	}
	while (game->file[*i] && (game->file[*i] == ' ' || game->file[*i] == '\t'))
		(*i)++;
	pos = *i;
	while (game->file[*i] && game->file[*i] != ' ' && game->file[*i] != '\n' && game->file[*i] != '\t')
		(*i)++;
	if (pos == (*i))
	{
        printf("Parse_param_value error\n");
		exit(0);
	}
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
            {
                printf("Value parse error\n");
                exit(0);
            }
        }
    }
    else if(flag == 0)
    {
        if(target[0] == game->file[i])
        {
            if (game->file[i + 1] == ' ' || game->file[i + 1] == '\t')
                return (1);
            else
            {
                printf("Color parse error\n");
                exit(0);
            }
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
    int i;

    if(game)
        printf("\n--------\ncool.Parsing started...\n-------\n");
	i = 0;
	while (game->file[i])
	{
		if (is_complete(game))
			break ;
		get_params(&i, game);
		i++;
	}
    printf("Parse results:\n");
    printf("n = %s\n",game->n);
    printf("s = %s\n",game->s);
    printf("w = %s\n",game->w);
    printf("e = %s\n",game->e);
    printf("bottom = %s\n",game->bottom);
    printf("floor = %s\n",game->top);

	// check_data(game);
	parse_map(i, game);

}