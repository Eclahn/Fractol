NAME = fractol

SRCS = main.c \
	   initiation.c \
	   palettes.c \
	   events.c \
	   mandelbrot.c \
	   julia.c \
	   burning_ship.c \
	   help.c \

OBJ = $(SRCS:.c=.o)

LIBFT_PATH = ./libft

MLX_PATH = ./minilibx_macos

CFLAGS = -Wall -Wextra -Werror

LFLAGS = -framework AppKit -framework OpenGL -lpthread

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(MLX_PATH)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(OBJ) $(LFLAGS) $(LIBFT_PATH)/libft.a $(MLX_PATH)/libmlx.a -o $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(MLX_PATH)
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(MLX_PATH)/libmlx.a
	@rm -f $(NAME)

re: fclean all
	@make re -C $(LIBFT_PATH)
	@make re -C $(MLX_PATH)
