/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matus <matus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:36:42 by matus             #+#    #+#             */
/*   Updated: 2025/02/23 21:54:24 by matus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef M_PI
#  undef M_PI
# endif

# include "MLX42/MLX42.h"
# include "MLX42/MLX42_Int.h"
# include <fcntl.h>
# include <inttypes.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define M_PI 3.14159265358979323846
# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 600
# define VIEWPORT_SIZE 50

# define BUFFER_SIZE 1024

# define RESET "\x1b[0m"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN "\x1b[36m"
# define WHITE "\x1b[37m"

typedef struct s_data		t_data;
typedef struct s_assets		t_assets;
typedef struct s_cord		t_cord;
typedef struct s_program	t_program;
typedef struct s_object		t_object;
typedef struct s_map		t_map;
typedef struct s_holder		t_holder;
typedef struct s_wl_pl_bb	t_wl_pl_bb;
typedef struct s_view_port	t_vp;
typedef enum s_error		t_error;

typedef struct s_wl_pl_bb
{
	int						wl;
	int						wr;
	int						wt;
	int						wb;
	int						pl;
	int						pr;
	int						pt;
	int						pb;
	int						of;
}							t_wl_pl_bb;

typedef struct s_complex_data
{
	double					wave_amplitude;
	double					wave_freq;
	double					aa;
	double					bb;
	double					a;
	double					b;
	double					delta;
	double					scale_fact;
	double					time;
	double					spiral_fact;
	double					depth;
	double					variable;
}							t_complex_data;

typedef struct s_graph_data
{
	int						delta_x;
	int						delta_y;
	int						start_x;
	int						start_y;
	int						end_x;
	int						end_y;
	int						step_x;
	int						step_y;
	int						error;
	int						pixel_x;
	int						pixel_y;
	uint32_t				color;
	double					thickness;

}							t_graph_data;

typedef struct s_view_port
{
	double					vp_position_x;
	double					vp_position_y;
	double					vp_size_x;
	double					vp_size_y;
	int32_t					vp_size;
	struct s_view_port		*next;
}							t_vp;

typedef struct s_setup
{
	t_vp					*data;
	t_complex_data			*complex;
	t_graph_data			*graph;
	mlx_image_t				*image;
	mlx_t					*mlx;
	mlx_image_t				*img_env_front;
	mlx_image_t				*img_env_back;
	mlx_image_t				*img_collect;
	size_t					dep;
	size_t					counteee;
}							t_setup;

typedef struct s_game
{
	t_setup					*setup;
	t_assets				*assets;
	t_cord					*cord;
}							t_game;

typedef struct assets_s
{
	t_game					*game;
	t_game					*env_back;
	t_game					*env_front;
	t_game					*colect;
	t_game					*player;
	t_game					*exit;
	t_map					*map;
	t_holder				*holder;
	int						count;
}							t_assets;

typedef struct s_map
{
	t_assets				*assets;
	char					**grid;
	char					**grid_visited;
	size_t					rows;
	size_t					cols;
	int						player_count;
	int						cord_x;
	int						cord_y;
	int						collectible_count;
	int						tmp_count;
	int						walls;
	int						rect;
	int						exit_count;
	int						flood;
	bool					is_valid;

}							t_map;

typedef struct s_cord
{
	int						cx;
	int						cy;
	struct s_cord			*next;
}							t_cord;

typedef struct holder_s
{
	mlx_t					*mlx;
	mlx_image_t				*image;
	t_vp					*vp;
	t_complex_data			*complex;
	t_graph_data			*graph;
	t_setup					*setup;
	t_cord					*cord;
	t_assets				*assets;
	t_game					*game;
	t_map					*map;
}							t_holder;

typedef enum s_error
{
	WRONG_CHAR,
	WRONG_FILE,
	WRONG_MAP,
	MAP_NOT_FOUND,
	MAP_NOT_VALID,
	MAP_NOT_RECT,
	MAP_NOT_WALLS,
	MAP_NOT_EXIT,
	MAP_NOT_PLAYER,
	MAP_NOT_COLLECT,
	MAP_NOT_FLOOD,
	MAP_NOT_PLAYABLE,
}							t_error;

// set_cords.c
void						set_env_back_cord(t_map *map, size_t i, size_t j);
void						set_collectible_cord(t_map *map, size_t i, size_t j,
								int *count);
void						set_exit_cord(t_map *map, size_t i, size_t j);
void						set_player_cord(t_map *map, size_t i, size_t j);
void						set_env_front_cord(t_map *map, size_t i, size_t j);

// render.c
void						render(t_assets *assets);
void						del_and_draw(t_game *asset);
void						static_viewport(t_game *asset, double thickness);
void						update_viewport(t_game *asset, double thickness);
mlx_image_t					*ft_draw_collect(mlx_t *mlx, t_game *asset,
								mlx_image_t *image, t_cord *cords);

// pattern.c
int							compute_end_x(int center_x, t_complex_data *c);
int							compute_end_y(int center_y, t_complex_data *c);
void						dcp_end(t_graph_data *g, t_complex_data *c);
void						draw_complex_pattern(t_game *asset,
								mlx_image_t *img, t_graph_data *g);
void						recompute_c_variable(t_complex_data *c,
								t_assets *asset, t_game *ass);

// map0.c
void						map_wrapper(mlx_t *mlx, t_holder *holder,
								char *path);
t_map						*init_map(mlx_t *mlx, t_game *game,
								t_holder *holder);

// map_events.c
int							map_events(t_map *map);
int							init_grid(t_map *map);
static void					init_visited(t_map *map);
static void					flood_fill(int x, int y, t_map *map);

// map_checks.c
void						er_mp_chck(t_map *map, size_t i, size_t j);
void						map_checks(t_map *map);
void						check_walls(t_map *map);
void						find_exit_cords(t_map *map);

// loop_exit.c
void						wrapper(void *param);
void						time_hook(void *param);
void						exit_animation(t_game *who);

// loop_back.c
void						k_hook_b_w(t_complex_data *c);
void						k_hook_b_s(t_complex_data *c);
void						k_hook_b_a(t_complex_data *c);
void						k_hook_b_d(t_complex_data *c);
void						key_hooker_back(mlx_key_data_t keydata,
								void *param);

// load_map.c

void						mp_gr(t_map *map, int x, char *line);
void						mp_gr_lst(t_map *map, int x);
t_map						*allocate_map_grid(char *path, t_map *map);
t_map						*load_map(char *path, t_map *map);
static int					count_lines(const char *path);

// link1.c
void						map_ass_links(t_holder *holder);
void						map_cord_links(t_holder *holder);
void						map_mlx_links(t_holder *holder, mlx_t *mlx);

// link0.c
void						assets_links(t_holder *holder);
void						cord_links(t_holder *holder);
void						mlx_links(t_holder *holder);

// key_loop2.c
void						key_hook_end_wr(t_game *who, t_vp *vp);
void						set_bb_pl_sec(t_wl_pl_bb *bb, int new_x, int new_y,
								t_game *player);
void						check_exit(t_game *player, int new_x, int new_y);
void						check_tile(t_game *player, int new_x, int new_y);

// key_loop1.c
void						set_bb_pl(t_wl_pl_bb *bb, int new_x, int new_y,
								t_game *player);
void						set_bb_wl(t_wl_pl_bb *bb, t_cord *wall,
								uint32_t wid, uint32_t hig);
bool						is_wsad(mlx_key_data_t keydata);
bool						is_pressed(mlx_key_data_t keydata);
bool						check_movement(t_game *player, int new_x,
								int new_y);

// key_loop0.c
void						event_handler(mlx_key_data_t keydata, void *param);
void						key_hook(mlx_key_data_t keydata, void *param);
void						key_sw(mlx_key_data_t keydata, int *new_y, int *wa);
void						key_da(mlx_key_data_t keydata, int *new_x,
								t_complex_data *c);
void						key_esc(t_game *who, mlx_key_data_t keydata);

// init2.c
void						init_structures(mlx_t *mlx, char *path);
void						null_holder(t_holder *holder);
void						map_wrapper(mlx_t *mlx, t_holder *holder,
								char *path);
void						def_map(t_map *map);

// init1.c
t_cord						*init_cord(t_cord **cord);
t_game						*init_game(mlx_t *mlx, t_holder *holder,
								char *ident);
t_assets					*init_assets(mlx_t *mlx, t_cord *cord, t_map *map,
								t_holder *holder);
t_holder					*init_holder(t_holder **holder);
t_wl_pl_bb					*init_bb(void);

// init0.c
mlx_image_t					*init_image(mlx_t *mlx);
t_vp						*init_viewport(void);
t_complex_data				*init_complex_data(void);
t_graph_data				*init_graph_data(void);
t_setup						*init_setup(mlx_t *mlx, mlx_image_t *image,
								t_holder *holder);

// init_var.c
void						init_vp_var(t_vp *vp);
void						init_complex_var(t_complex_data *complex);
void						init_graph_var(t_graph_data *graph);

// gnl.c
char						*get_next_line(int fd);
char						*ft_reader(int fd, char *result);
char						*ft_line(char *string_buffer);
char						*ft_next(char *string_buffer);

// gnl_helpers.c
char						*ft_strrchr(char *result, int c);
char						*ft_strjoin(char *result, char *string_buffer);
size_t						ft_strlen(char *result);
t_map						*read_map_from_file(int fd, t_map *map);

// free0.c
void						all_frees(mlx_t *mlx, t_holder *holder);
void						wrapper_free_cord(t_holder *holder);
void						wrapper_free_colect(mlx_t *mlx, t_holder *holder);
void						wrapper_free_player(mlx_t *mlx, t_holder *holder);
void						wrapper_free_env_back(mlx_t *mlx, t_holder *holder);

// free1.c
void						wrapper_free_exit(mlx_t *mlx, t_holder *holder);
void						wrapper_free_env_front(mlx_t *mlx,
								t_holder *holder);
void						wrapper_free_game(mlx_t *mlx, t_holder *holder);
void						wrapper_null(t_holder *holder);
void						free_cord(t_cord *cord);

// free_map.c
void						free_map_grid(t_map *map);
void						free_map_vis(t_map *map);
void						free_map(t_map *map);

// draw.c
void						step_g_er(t_graph_data *g);
void						draw_thick_line(mlx_image_t *img, t_graph_data *g);
void						draw_filled_square(mlx_image_t *img,
								t_graph_data *g);
void						print_image_instances(mlx_image_t *image,
								size_t dep, t_game *a, int z);

// customize0.c
void						custumizer_pass(t_assets *assets);
void						customizer(t_game *aset, t_assets *assets);
void						custumize_game(t_game *game);

// customize1.c
void						custumize_env_back(t_game *env_back);
void						custumize_env_front(t_game *env_front);
void						custumize_exit(t_game *exit);
void						custumize_colect(t_game *colect);
void						custumize_player(t_game *player);

#endif
