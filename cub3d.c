#include "cub3d.h"
int main(int argc, char **argv)
{
    // int **map;
    if (argc != 2)
		write(2, "error\n", 6);

    //
    // t_game *game;

    // game = malloc(sizeof(t_game));
    // init_game(game);
    if(!validation(argc,argv))
        perror("ti dolbaeb, peredalivai");
    else
        printf("ok");
    
    //...
    return (0);
}