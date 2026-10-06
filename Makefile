NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

SRCS_M = so_long.c utils.c utils1.c utils2.c utlis1_lite.c ft_split.c ft_putnbr.c\
		g_n_l/get_next_line_utils.c\
		g_n_l/get_next_line.c\
		fenetre00.c fenetre01.c

OBJS_M = $(SRCS_M:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_M)
	$(CC) $(CFLAGS) $(OBJS_M) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_M): so_long.h

clean:
	rm -f $(OBJS_M)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re