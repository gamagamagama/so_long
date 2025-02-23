CC := gcc
NAME := so_long
FLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := ../MLX42
HEADERS := -I ./include -I $(LIBMLX)/include
LIBMLX := -L $(LIBMLX)/build/ -lmlx42 -lglfw -pthread -lm -ldl
SRCS := customize0.c \
		customize1.c \
		draw.c \
		free_map.c \
		free0.c \
		free1.c \
		gnl_helpers.c \
		gnl.c \
		init_var.c \
		init0.c \
		init1.c \
		init2.c \
		key_loop0.c \
		key_loop1.c \
		key_loop2.c \
		link0.c \
		link1.c \
		load_map.c \
		loop_back.c \
		loop_exit.c \
		main.c \
		map_checks.c \
		map_events.c \
		map0.c \
		pattern.c \
		render.c \
		set_cords.c

OBJS := $(SRCS:.c=.o)


$(NAME): $(OBJS)