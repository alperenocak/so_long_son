NAME = so_long
CC = cc 
CFLAGS		= -Wall -Wextra -Werror -Imlx_linux
MLXFLAG		= -Imlx_linux -lXext -lX11 -lm -lz
SRC			= 	src/ft_control.c \
				src/ft_error_and_exit.c \
				src/ft_init.c \
				src/ft_map_control.c \
				src/ft_map_create.c \
				src/get_next_line.c  \
				src/so_long.c \
				src/ft_control_args.c \
				src/flood_fill.c \
				src/ft_init_mlx.c \
				src/map_height_utils.c  

LIBFT		= libft/libft.a
FT_PRINTF	= ft_printf/libftprintf.a
MLX			= minilibx/libmlx.a
OBJ_DIR		= obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:		$(NAME)

$(NAME):	$(MLX) $(LIBFT) $(FT_PRINTF) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) $(FT_PRINTF) $(MLX) $(MLXFLAG)

$(OBJ_DIR)/%.o:	%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C libft

$(FT_PRINTF):
	@make -C ft_printf

$(MLX):
	@make -C minilibx

clean:
	@make -C libft clean
	@make -C ft_printf clean
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@make -C libft fclean
	@make -C ft_printf fclean
	@make -C minilibx clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re