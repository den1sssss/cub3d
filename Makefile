# NAME = cub3D

# SRC = *.c

# LIB = minilibx/libmlx.a


# OBJ = $(SRC:.c=.o)

# MINILIB = -framework OpenGL -framework AppKit

# %.o: %.c
# 	gcc  -Wall -Werror -Wextra -g -I /usr/local/include -c $< -o $@

# all: $(NAME)

# $(NAME): $(OBJ)
# 		$(MAKE) -C minilibx/
# 		gcc -Wall -Werror -Wextra -g $(OBJ) -I /usr/local/include $(LIB) $(MINILIB) -o $(NAME)

# clean:
# 		make -C minilibx clean
# 		rm -rf $(OBJ)

# fclean: clean
# 		make -C minilibx clean
# 		rm -rf $(NAME)

# re : fclean all
FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=cub3D
SRC=*.c
INCLUDES=libft/libft.a MLX/libmlx.a

all:
	@make -C libft/ all
	@make -C MLX/
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C MLX/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus