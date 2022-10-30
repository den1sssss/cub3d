FRAMEWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=cub3D
SRC=*.c
INCLUDES=libft/libft.a MLX/libmlx.a

all:
	@make -C libft/ all
	@make -C MLX/
	@gcc $(SRC) -o $(NAME) $(INCLUDES) $(FRAMEWORKS)

clean:
	
	@make -C libft/ clean
	@make -C MLX/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus
