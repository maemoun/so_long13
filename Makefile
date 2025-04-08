# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# SRC = so_long.c ft_check_file_name.c ft_len.c ft_print_error.c ft_read_maps.c ft_strjoin.c ft_split.c\
# 		ft_substr.c ft_strdup.c

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

all :
	@clear
	@rm -rf so_long
	@gcc *.c ./get_next_line/*.c -o so_long