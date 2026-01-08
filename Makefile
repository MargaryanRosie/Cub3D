NAME = cub3D

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_DIR = src
INC_DIR = inc

INCS = -I$(INC_DIR)

SRCS = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/utils.c \
	$(SRC_DIR)/validation.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX_A   = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_LIBS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCS) $(MLX_INC) \
		$(MLX_LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCS) $(MLX_INC) -c $< -o $@

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus
