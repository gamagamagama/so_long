CC := gcc
NAME := so_long
FLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
H_HEADERS := -I ./h
LIBMLX := ./MLX42
MLX_HEADERS := -I ./include -I $(LIBMLX)/include -I $(H_HEADERS)
LIBMLX := -L $(LIBMLX)/build/ -lmlx42 -lglfw -pthread -lm -ldl

SRCS_CUSTOM :=	./custom/customize0.c \
				./custom/customize1.c

SRCS_FREE :=	./free/free_map.c \
				./free/free0.c \
				./free/free1.c

SRCS_GNL := 	./gnl/gnl_helpers.c \
				./gnl/gnl.c

SRCS_INIT :=	./init/init_var.c \
				./init/init0.c \
				./init/init1.c \
				./init/init2.c

SRCS_LINK :=	./link/link0.c \
				./link/link1.c

SRCS_LOOP := 	./loop/key_loop0.c \
				./loop/key_loop1.c \
				./loop/key_loop2.c \
				./loop/loop_back.c \
				./loop/loop_exit.c

SRCS_MAP := 	./map/map0.c \
				./map/load_map.c \
				./map/map_checks.c \
				./map/map_events.c 

SRCS_RENDER :=	./render/draw.c \
				./render/pattern.c \
				./render/render.c \
				./render/set_cords.c
SRCS_MAIN :=	main.c

SRCS := $(SRCS_CUSTOM) $(SRCS_FREE) $(SRCS_GNL) $(SRCS_INIT) $(SRCS_LINK) \
		$(SRCS_LOOP) $(SRCS_MAP) $(SRCS_RENDER) $(SRCS_MAIN)

OBJS := $(SRCS:.c=.o)


$(NAME): $(OBJS)