CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_check_file_name.c ft_check_maps_errors.c ft_check_valid_map.c ft_del_txt_img.c\
		ft_keyboard_key.c ft_len.c ft_linejoin.c ft_print_error.c ft_putnbr.c ft_putstr.c\
		ft_read_maps.c ft_split.c ft_start_game.c ft_strdup.c ft_substr.c so_long.c\
		get_next_line_utils.c get_next_line.c

SRC_OBJ = $(SRC:%.c=%.o)

MLX = /Users/maeskhai/Desktop/MLX42/libmlx42.a

NAME = so_long

LIBFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -L/Users/maeskhai/Desktop/MLX42 -lglfw3

all : $(NAME)

$(NAME): $(SRC_OBJ)
	$(CC) $(CFLAGS) $(LIBFLAGS) $(MLX) $(SRC_OBJ) -o so_long

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@


get_next_lines/get_next_line.o: get_next_line.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line/get_next_line_utils.o: get_next_line_utils.c get_next_line.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(SRC_OBJ) $(GNL_OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf MLX42

re: fclean all

.PHONY: clean
