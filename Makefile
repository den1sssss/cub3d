SRCS	= 			src/andreypart.c \
					src/check_colors.c \
					src/denispart.c \
					src/denispart_p2.c \
					src/ft_mlx.c \
					src/ft_mlx_p2.c \
					src/ft_raycasting.c \
					src/ft_raycasting_p2.c \
					src/ft_raycasting_p3.c \
					src/gnl.c \
					src/main.c \
					src/parse.c \
					src/parse_p2.c \
					src/parse_map.c \
					src/validation.c \
		
OBJS		= ${SRCS:.c=.o}

NAME		= cub3D

HEADER		= src/cub3D.h

CC		= cc

CFLAGS		= -Wall -Wextra -Werror

INC			= libft/libft.a MLX/libmlx.a

FRAMEWORKS=-framework OpenGL -framework AppKit

.c.o:
	${CC} $(CFLAGS) -c $< -o ${<:.c=.o}

all: $(NAME)
	
$(NAME): $(OBJS) $(HEADER)
	@make -C libft/ all
	@make -C MLX/
	$(CC) $(CFLAGS) ${INC} $(FRAMEWORKS) $(OBJS) -o $(NAME)

clean:
	@make -C libft/ clean
	@make -C MLX/ clean
	@rm -rf ${OBJS}

fclean:	clean
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@make -C MLX/ fclean

re: clean all

.PHONY: all clean fclean re
