# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# SRC = ft_check_file_name.c ft_check_maps_errors.c ft_check_valid_map.c ft_del_txt_img.c\
# 		ft_keyboard_key.c ft_len.c 

# SRC_OBJ = $(SRC:%.c=%.o)

# GNL = get_next_line/get_next_line_utils.c get_next_line/get_next_line.c

# GNL_OBJ = $(GNL:%.c=%.o)

# NAME = so_long


# all : $(NAME)

# $(NAME): $(SRC_OBJ)
# 	$(CC) $(CFLAGS) $(SRC_OBJ) -o $(NAME)

# %.o: %.c so_long.h
# 	$(CC) $(CFLAGS) -c $< -o $@


# get_next_line/get_next_line.o: get_next_line/get_next_line.c get_next_line/get_next_line.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	rm -rf $(SRC_OBJ) $(GNL_OBJ)

# fclean: clean
# 	rm -rf $(NAME) $(SRC_OBJ) $(GNL_OBJ)


# re: fclean all

# .PHONY: clean
MLX = /Users/maeskhai/Desktop/MLX42/libmlx42.a
LIBFLAGS = -framework Cocoa -framework OpenGL -framework IOKit -L/Users/maeskhai/Desktop/MLX42 -lglfw3

all :
	@clear
	@rm -rf so_long
	@gcc *.c ./get_next_lines/*.c $(LIBFLAGS) $(MLX) -o so_long
