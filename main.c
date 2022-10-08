#include "cub3d.h"

int main(int argc, char **argv)
{
    // int **map;
    t_game *game;
	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
	{
		write(2, "Error: bad arguments: try ./cub3d <___.cub>\n", 45);
		return (1);
	}
    else
    {

        game = (t_game *)malloc(sizeof(t_game));
        if (!game)
		{
			write(2, "Error: cannot allocate memory\n", 31);
			exit(1);
		}
        denispart(game,argv);
        // reading_file(game,argv[1]);
        

        // andreypart(&rc);
    }   
    return (0);
}