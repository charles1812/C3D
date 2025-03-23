/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspreafi <cspreafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:14:55 by jgerbaul          #+#    #+#             */
/*   Updated: 2025/03/23 01:19:22 by cspreafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_H
# define INCLUDE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define ERROR 1
# define VALID 0
# define SCREENWIDTH 800
# define SCREENHEIGHT 600
# define TEXHEIGHT 64
# define TEXWIDTH 64

# include "libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_gc
{
	int				imp;
	void			*alloc;
	size_t			size;
	struct s_gc		*next;
}	t_gc;

typedef struct s_raycast
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
}				t_raycast;

typedef struct s_texture
{
	void		*img;
	int			*data;
	int			width;
	int			height;
}				t_texture;

typedef struct s_player
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			forward;
	int			side;
	int			rot;
	double		movespeed;
	double		rotspeed;
}				t_player;

typedef struct s_cube
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		**worldmap;
	int			mapwidth;
	int			mapheight;
	int			fd_no_tex;
	char		*no_tex_name;
	int			fd_so_tex;
	char		*so_tex_name;
	int			fd_we_tex;
	char		*we_tex_name;
	int			fd_ea_tex;
	char		*ea_tex_name;
	int			color_c;
	int			color_f;
	int			texnum;
	bool		loaded;
	int			size_map;
	int			start_map;
	int			half_screen;
	t_player	*player;
	t_raycast	*ray;
	t_texture	*texture;
	t_texture	*texture1;
	t_texture	*texture2;
	t_texture	*texture3;
}				t_cube;

void		*gc_alloc(size_t sz, int imp);
void		gc_free(void *ptr);
void		gc_free_p(int imp);
void		gc_free_all(void);
void		print_addr(void);
char		*ft_strdup_gc(const char *s, int imp);
char		*ft_strjoin_gc(char const *s1, char const *s2, int imp);
void		*ft_calloc_gc(size_t nmemb, size_t size, int imp);
char		**ft_split_gc(char const *s, char c, int imp);
char		*ft_substr_gc(char const *s, unsigned int start,
				size_t len, int imp);
char		*get_next_line(int fd);
char		**make_map(int fd);
void		free_tab(char **tab);
int			map_len(char **tab);
void		cast_ray(t_cube *cube, int x);
int			draw_loop(t_cube *cube);
int			gest_key_press(int keycode, t_cube *cube);
int			gest_key_relase(int keycode, t_cube *cube);
int			movement(t_cube *cube);
int			check_symbols(t_cube *cube);
int			checkmap(t_cube *cube);
int			check_ext(char *s, int len);
char		*ft_sstrndup(char *s, int n, int start, int imp);
int			htoi(const char *s);
int			get_color(char *s);
int			ft_exit(t_cube *cube);
void		get_color_texture(t_cube *cube, int y, int texx, int x);
char		*ft_itoa_base(int value, int base);
void		rotation_left(t_cube *cube, double olddirx, double oldplanex);
void		rotation_right(t_cube *cube, double olddirx, double oldplanex);
int			check_direction_player(char c, t_cube *cube);
int			check_textures(t_cube *cube);
bool		set_player_pos(int x, int y, t_cube *cube);
int			ft_strcmp_sl(char *s, char *c);
int			get_start_map(t_cube *cube);
int			check_symbols(t_cube *cube);
int			check_tab(t_cube *cube, int y);
bool		check_north(t_cube *cube, char *str);
bool		check_south(t_cube *cube, char *str);
bool		check_west(t_cube *cube, char *str);
bool		check_east(t_cube *cube, char *str);
int			check_color(t_cube *cube);
void		move_forward(t_cube *cube);
void		move_backward(t_cube *cube);
void		move_right(t_cube *cube);
void		move_left(t_cube *cube);
void		error_initmap_free(t_cube *cube, int ret);
void		check_ray_collision_with_wall(t_cube *cube);
void		draw(t_cube *cube, int x, int y, int color);
void		draw_background(t_cube *cube, int y);
int			get_player_pos(t_cube *cube);
int			check_height_texture(t_cube *cube);
int			check_length_texture(t_cube *cube);
int			check_texture_size(t_cube *cube);
int			ft_exit_windowless(t_cube *cube);
int			get_color_north(t_cube *cube, int y, int texx);
int			get_color_south(t_cube *cube, int y, int texx);
int			get_color_east(t_cube *cube, int y, int texx);
int			get_color_west(t_cube *cube, int y, int texx);
int			error_arg(void);
int			get_size(t_cube *cube);
t_texture	*load_xpm_texture(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture1(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture2(const char *filepath, t_cube *cube);
t_texture	*load_xpm_texture3(const char *filepath, t_cube *cube);
void		error_tex_free(t_cube *cube);

#endif