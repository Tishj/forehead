#ifndef TEST_H
# define TEST_H

void			ft_sort(int *left, int *right, t_data *data, t_merger *merge);
int				ft_strcmp(char *str, char *comp);
void			ft_copy_arr(int *dst, int *src, int start, int len);
t_vec			ft_sprite_transform(t_data *data, int i);
unsigned int	ft_pixel_from_img(t_data *data, int x, int y);
void			ft_sprite_drawy(t_data *data, t_spriterender *render, int x);
void			ft_raycast(t_data *data);
void			ft_sprite_loop(t_data *data);
t_ray			ft_ray_direction(t_data *data, int x);
void			ft_new_window(t_data *data);
int				ft_mapcheck(char **map, int x, int y, int maxdepth);
void			ft_map_edit(t_data *data, char **reachable);
t_line			ft_linedata(t_data *data, double dist, int x);
void			ft_position_update(t_data *data, t_vec incr, double speed);
int				ft_validate_input(t_data *data, int argc, char **input);
void			ft_line_draw(t_data *data, t_dda *dda, t_line line,
				t_texdata tex);
int				ft_mlx_keyup(int keycode, void *param);
void			ft_sprite_dist(t_data *data);
void			ft_free_line_and_exit(t_data *data, char *line, char *errstr,
				int linenr);
int				ft_mlx_keydown(int keycode, void *param);
void			ft_init_ceiling(t_data *data, char *line, int i, int linenr);
void			ft_mlx_pixel_to_img(t_data *data, int x, int y,
				unsigned int col);
void			ft_mlx_img_to_win(t_data *data);
int				ft_mlx_exit(t_data *data);
void			ft_sprite_arrayfill(t_data *data);
void			ft_init_north(t_data *data, char *line, int i, int linenr);
void			ft_init_map(t_data *data, char *line, int i, int linenr);
char			*ft_map_add(t_data *data, char *line, int linenr);
void			ft_map_validate(t_data *data, char *str, int i, int linenr);
int				ft_identifier_get(char *line, int *i);
t_initf			ft_init_funct(int id);
void			ft_drawdata_get(t_data *data, t_spriterender *render,
				int spritescreen_x);
void			ft_reader_init(t_reader *reader);
void			ft_memset(void *mem, size_t len, char c);
void			ft_png_del(t_data *data, t_png *png);
double			ft_atod(char *str, int *i);
void			ft_step_init(t_cam cam, t_dda *dda);
int				ft_tex_x_get(t_data *data, t_dda *dda, double dist);
void			ft_init_east(t_data *data, char *line, int i, int linenr);
void			ft_sprite_array(t_data *data);
size_t			ft_strclen(char *str, char c);
void			ft_merge_sort(t_data *data, int s, int e);
void			*ft_calloc(size_t size, size_t len);
void			ft_header_write(t_data *data);
void			ft_data_read(t_data *data, int fd);
void			ft_mlx_init(t_data *data);
void			ft_zeropad(int fd, int len);
void			ft_init_sprite(t_data *data, char *line, int i, int linenr);
void			ft_validate_color_entry(t_data *data, char *line,
				char *errstr);
char			*ft_strdupc(char *str, char c);
int				ft_validate_range(int min, int max, int nb);
int				ft_match(char *str, char c);
t_texdata		ft_texdata_get(t_data *data, t_dda *dda, double dist,
				t_line line);
char			*ft_strdup(char *str);
void			ft_tex_init(char **tex);
void			ft_validate_map(t_data *data);
int				ft_validate_type(char *str);
void			ft_data_mlx_init(t_data *data);
void			ft_direction_rot(t_data *data, double angle);
int				ft_iseq(double c1, double c2);
int				ft_side_set(int nb, int opt1, int opt2);
void			ft_error_line(int line);
double			ft_deg2rad(double angle);
size_t			ft_strskipc(char *str, char c);
double			ft_tex_y_get(t_data *data, t_dda *dda, t_line line);
int				ft_mlx_update(t_data *data);
t_color			ft_texture_get(t_data *data, t_dda *dda, int x, int y);
void			ft_validate_data(t_data *data);
size_t			ft_strslen(char *str, char *set);
t_coord			ft_coord_init(int y, int x);
int				ft_map_size(char **map);
void			ft_sprite_render(t_data *data, int index);
void			ft_putchar(int fd, char c);
size_t			ft_strlens(char *str, char *set);
void			ft_map_placeplayer(t_data *data, int x);
t_vec			ft_bumpifround(char **map, t_vec orig);
int				ft_strlencskip(char *str, char c);
double			*ft_dist_array(t_data *data);
void			ft_init_south(t_data *data, char *line, int i, int linenr);
double			ft_abs(double n);
double			ft_distget(t_data *data, int *index, int id);
void			ft_putstrfd(int fd, char *str);
size_t			ft_strlen(char *str);
int				ft_texture_fd(t_data *data, char *line, int i, char **path);
void			ft_data_identifier(t_data *data, char *line, int linenr);
void			ft_init_res(t_data *data, char *line, int i, int linenr);
void			ft_map_del(char **map);
void			ft_mlx_key_init(t_data *data);
size_t			ft_strclenb(char *str, char c);
double			ft_dist_calc(t_data *data, t_dda *dda);
void			ft_putnbr(int fd, int nb, int base);
void			ft_write_color(int fd, t_color col);
void			ft_init_floor(t_data *data, char *line, int i, int linenr);
int				ft_identifier_parse(char *id);
void			ft_sprite_drawx(t_data *data, t_spriterender *render,
				int spritescreen_x);
char			ft_chrmatchs(char c, char *set);
int				ft_atoi(char *str, int *i);
char			*ft_add_to_id(char *id, char *line, int *c, int *i);
void			ft_mlx_key_update(t_data *data, int keycode, int state);
void			ft_img_to_bmp(t_data *data);
void			ft_direction_init(t_data *data);
void			ft_freedom(t_data *data);
void			ft_dda(t_data *data, t_dda *dda);
void			ft_validate_mapwall(t_data *data, char *field, int start);
t_drawer		ft_drawer_init(int x, int start, int end, t_color color);
int				ft_error(t_data *data, char *errorstr, int line);
t_color			ft_color_init(int r, int g, int b);
size_t			ft_strlenc(char *str, char c);
void			ft_data_errorcheck(t_data *data, int linenr, char *line);
void			ft_data_init(t_data *data);
void			ft_init_west(t_data *data, char *line, int i, int linenr);

#endif
