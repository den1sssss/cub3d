#include "cub3d.h"
void print_error(char *str)
{
    write(2,str,ft_strlen(str));
    exit(1);
}
void error_and_close(char *str,int fd)
{
    close(fd);
    write(2,str,ft_strlen(str));
    exit(1);
}
int main(int argc, char **argv)
{
    t_game *game;

	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
        print_error("Error: bad arguments: try ./cub3d <___.cub>\n");
    else
    {
        game = (t_game *)malloc(sizeof(t_game));
        if (!game)
            print_error("Error: cannot allocate memory\n");
        denispart(game,argv);
        andreypart(game);
    }   
    return (0);
}