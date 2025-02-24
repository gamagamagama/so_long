CC := gcc
NAME := so_long
FLAGS := -Wextra -Wall -Werror 
H_HEADERS := -I./h

MLX_REPO := https://github.com/codam-coding-college/MLX42.git
MLX_DIR := ./MLX42
MLXLIB_INC     := $(MLX_DIR)/include
MLXLIB_BUILD   := build

#LIBMLX := ./MLX42
MLX_HEADERS := -I$(MLXLIB_INC)
LIBMLX := -L$(MLX_DIR)/$(MLXLIB_BUILD)/ -lmlx42 -lglfw -pthread -lm -ldl

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

#########INSTALL_MLX#########

all: get_mlx
get_mlx:
	if [ ! -d "$(MLX_DIR)/.git" ]; then \
		git clone $(MLX_REPO); \
	fi
all: build_mlx
build_mlx: get_mlx
	@echo "Configuring MLX"
	cd $(MLX_DIR) && cmake -B $(MLXLIB_BUILD)
	@echo "Building MLX"
	cd $(MLX_DIR) && cmake --build $(MLXLIB_BUILD) -j4

####----MAIN----####
norm:
	norminette $(SRCS) h/*.h


all: $(NAME)

debug: all
	valgrind --leak-check=full --track-origins=yes ./$(NAME) ./map_file/map.ber

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(MLX_HEADERS) $(H_HEADERS) $(LIBMLX) -o $(NAME)

%.o: %.c | get_mlx
	$(CC) $(FLAGS) $(MLX_HEADERS) $(H_HEADERS) -c $< -o $@


clean:
	rm -rf $(OBJS)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re