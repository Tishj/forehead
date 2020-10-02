/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tbruinem <tbruinem@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/10 12:35:38 by tbruinem       #+#    #+#                */
/*   Updated: 2020/02/26 20:03:55 by tbruinem      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_enum.h"

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

# ifndef MAX_WIDTH
#  define MAX_WIDTH 2560
# endif
# ifndef MAX_HEIGHT
#  define MAX_HEIGHT 1460
# endif

# define FILE_TYPE ".cub"
# define ROT_SPEED 2
# define MOV_SPEED 0.080
# ifndef SPRITESCALE
#  define SPRITESCALE 1
# endif
# ifndef SPRITEHEIGHT
#  define SPRITEHEIGHT 0
# endif

# define ID_RES "R"
# define ID_NORTH "NO"
# define ID_WEST "WE"
# define ID_EAST "EA"
# define ID_SOUTH "SO"
# define ID_SPRITE "S"
# define ID_FLOOR "F"
# define ID_CEILING "C"

# define ERR_STR_ARG "Please (only) supply a scene file."
# define ERR_STR_TYPE "Please provide a .cub file."
# define ERR_STR_RANGE "Provided value is out of valid range."
# define ERR_STR_FILE "Failed to open file."
# define ERR_STR_MEM "Ran out of memory."
# define ERR_STR_ORDER "Invalid order, has to end with map."
# define ERR_STR_OBSTRUCT "Map is obstructed."
# define ERR_STR_MAPCHAR "Invalid map character."
# define ERR_STR_OPENMAP "Map isn't closed."
# define ERR_STR_MAPERROR "Map is either not closed or too big to parse"
# define ERR_STR_ID "Line doesnt start with a (valid) identifier."
# define ERR_STR_NODIR "No player direction is specified."
# define ERR_STR_DOUBLEDIR "Player direction specified more than once."
# define ERR_STR_DOUBLEID "Identifier used more than once."
# define ERR_STR_TEX_NORTH "Missing texture for north wall."
# define ERR_STR_TEX_SOUTH "Missing texte for south wall."
# define ERR_STR_TEX_EAST "Missing texture for east wall."
# define ERR_STR_TEX_WEST "Missing texture for west wall."
# define ERR_STR_RES "Missing resolution."
# define ERR_STR_FLOOR "Missing floor color."
# define ERR_STR_CEILING "Missing ceiling color."
# define ERR_STR_SPRITE "Missing sprite texture."

typedef struct	s_col
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}				t_col;

typedef union	u_color
{
	unsigned int	color;
	t_col			packed;
}				t_color;

typedef struct	s_png
{
	int			width;
	int			height;
	void		*img;
	int			bpp;
	int			ll;
	int			end;
}				t_png;

typedef struct	s_texdata
{
	int			x;
	double		y_step;
}				t_texdata;

typedef struct	s_line
{
	int			x;
	int			length;
	int			start;
	int			end;
}				t_line;

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_vec
{
	double		x;
	double		y;
}				t_vec;

typedef struct	s_ray
{
	t_vec		pos;
	t_vec		dir;
}				t_ray;

typedef struct	s_mlx
{
	void			*data;
	void			*image1;
	void			*image2;
	char			*addr1;
	char			*addr2;
	void			*window;
	int				bpp;
	int				ll;
	int				width;
	int				height;
	int				endian;
	int				keys[6];
	unsigned char	frame;
}				t_mlx;

typedef struct	s_cam
{
	t_vec		pos;
	t_ray		ray;
	t_vec		dir;
	t_vec		plane;
}				t_cam;

typedef struct	s_dda
{
	t_vec		sidedist;
	t_vec		deltadist;
	t_coord		mappos;
	t_coord		step;
	t_coord		tex;
	int			texstep;
	int			side;
}				t_dda;

typedef struct	s_scene
{
	t_color		floor;
	char		floor_set;
	t_color		ceiling;
	char		ceiling_set;
	int			direction;
	t_png		walls[4];
	char		*tex[4];
	t_png		sprite;
	char		*sprite_tex;
}				t_scene;

typedef struct	s_sprite
{
	double		dist;
	t_coord		pos;
}				t_sprite;

typedef struct	s_map
{
	int			width;
	int			height;
	char		**map;
	t_sprite	*sprites;
	int			*indices;
	double		*dist;
	int			numsprites;
}				t_map;

typedef struct	s_drawer
{
	int			x;
	int			y_start;
	int			y_end;
	t_color		color;
}				t_drawer;

typedef struct	s_merger
{
	int			left;
	int			lsize;
	int			rsize;
	int			right;
	int			middle;
}				t_merger;

typedef struct	s_reader
{
	int			id;
	int			map;
	int			end;
	char		*line;
	int			linenr;
}				t_reader;

typedef struct	s_spriterender
{
	t_vec		spriteres;
	t_coord		tex;
	t_vec		drawstart;
	t_vec		drawend;
	t_vec		transform;
}				t_spriterender;

typedef struct	s_data
{
	t_scene		scene;
	t_reader	reader;
	t_map		mapdata;
	t_mlx		mlx;
	t_cam		cam;
	int			bmp;
}				t_data;

/*
**				UTILS
*/

size_t			ft_strslen(char *str, char *set);
size_t			ft_strclenb(char *str, char c);
size_t			ft_strskipc(char *str, char c);
char			ft_chrmatchs(char c, char *set);
void			ft_memset(void *mem, size_t len, char c);
void			*ft_calloc(size_t size, size_t len);
void			ft_validate_color_entry(t_data *data, char *line, char *errstr);
size_t			ft_strlens(char *str, char *set);
size_t			ft_strlenc(char *str, char c);
int				get_next_line(int fd, char **line);
int				ft_error(t_data *data, char *errorstr, int line);
void			ft_freedom(t_data *data);
void			ft_map_del(char **map);
double			ft_abs(double n);
char			*ft_strdupc(char *str, char c);
size_t			ft_strclen(char *str, char c);
size_t			ft_strlen(char *str);
int				ft_strcmp(char *str, char *comp);
int				ft_strlencskip(char *str, char c);
char			*ft_strdup(char *str);
int				ft_match(char *str, char c);
double			ft_deg2rad(double angle);
int				ft_atoi(char *str, int *i);
double			ft_atod(char *str, int *i);
void			ft_putnbr(int fd, int nb, int base);
void			ft_putchar(int fd, char c);
void			ft_putstrfd(int fd, char *str);

/*
**				MLX
*/

void			ft_mlx_key_init(t_data *data);
int				ft_mlx_update(t_data *data);
void			ft_mlx_key_init(t_data *data);
int				ft_mlx_keyup(int keycode, void *param);
int				ft_mlx_keydown(int keycode, void *param);
int				ft_mlx_keypress(int keycode, void *param);
void			ft_mlx_img_to_win(t_data *data);
void			ft_mlx_pixel_to_img(t_data *data, int x,
				int y, unsigned int col);
void			ft_mlx_init(t_data *data);
int				ft_mlx_exit(t_data *data);

/*
**				INITIALIZATION
*/

void			ft_data_init(t_data *data);
void			ft_data_read(t_data *data, int fd);
void			ft_init_ceiling(t_data *data, char *line, int i, int linenr);
void			ft_init_floor(t_data *data, char *line, int i, int linenr);
void			ft_init_res(t_data *data, char *line, int i, int linenr);
void			ft_init_sprite(t_data *data, char *line, int i, int linenr);
void			ft_init_north(t_data *data, char *line, int i, int linenr);
void			ft_init_south(t_data *data, char *line, int i, int linenr);
void			ft_init_east(t_data *data, char *line, int i, int linenr);
void			ft_init_west(t_data *data, char *line, int i, int linenr);
void			ft_init_map(t_data *data, char *line, int i, int linenr);
int				ft_identifier_parse(char *id);
int				ft_identifier_get(char *line, int *i);
int				ft_texture_fd(t_data *data, char *line, int i, char **path);

void			ft_reader_init(t_reader *reader);
t_drawer		ft_drawer_init(int x, int start, int end, t_color color);
t_color			ft_color_init(int r, int g, int b);
t_coord			ft_coord_init(int y, int x);
typedef void	(*t_initf)(t_data *data, char *line, int i, int linenr);
t_initf			ft_init_funct(int id);
void			ft_direction_init(t_data *data);

void			ft_sprite_realloc(t_data *data);
void			ft_sprite_array(t_data *data);
double			*ft_dist_array(t_data *data);
void			ft_map_edit(t_data *data, char **reachable);
int				ft_map_size(char **map);

/*
**				VALIDATION
*/

int				ft_mapcheck(char **map, int x, int y, int maxrec);
int				ft_validate_range(int min, int max, int nb);
int				ft_validate_input(t_data *data, int argc, char **input);
int				ft_validate_type(char *str);
void			ft_validate_data(t_data *data);
void			ft_validate_map(t_data *data);

/*
**				RAYCASTING
*/

void			ft_sprite_dist(t_data *data);
void			ft_merge_sort(t_data *data, int s, int e);
void			ft_direction_rot(t_data *data, double angle);
double			ft_dist_calc(t_data *data, t_dda *dda);
void			ft_raycast(t_data *data);

/*
**				RENDERING
*/

double			ft_tex_y_get(t_data *data, t_dda *dda, t_line line);
int				ft_tex_x_get(t_data *data, t_dda *dda, double dist);
t_color			ft_texture_get(t_data *data, t_dda *dda, int x, int y);
void			ft_line_draw(t_data *data, t_dda *dda,
				t_line line, t_texdata tex);
void			ft_draw(t_data *data, t_dda *dda, double dist, int x);
t_color			ft_color_get(t_data *data, int side);
t_texdata		ft_texdata_get(t_data *data, t_dda *dda,
				double dist, t_line line);
t_line			ft_linedata(t_data *data, double dist, int x);
void			ft_sprite_render(t_data *data, int index);
void			ft_img_to_bmp(t_data *data);

#endif
