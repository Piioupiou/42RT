/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgallois <pgallois@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/31 00:49:38 by pgallois          #+#    #+#             */
/*   Updated: 2015/05/29 15:29:37 by pgallois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# define WINDOW_X 1080
# define WINDOW_Y 800
# define ASPR ((float)WINDOW_X / (float)WINDOW_Y)
# define BLOCK 256
# define BUFF_SIZE 1
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>

typedef struct		s_color
{
	float			r;
	float			g;
	float			b;
}					t_color;

typedef struct		s_new_img
{
	char			*img;
	unsigned long	color;
	int				bits;
	int				sizeline;
	int				endian;
	int				size_x;
	int				size_y;
	int				pos_x;
	int				pos_y;
	char			*data;
}					t_new_img;

typedef struct		s_vec
{
	float			x;
	float			y;
	float			z;
}					t_vec;

typedef struct		s_ray
{
	t_vec			*start;
	t_vec			*dir;
}					t_ray;

typedef struct		s_objet
{
	float			tab[36];
	t_vec			**m_vec;
	t_vec			*normal_ext;
	t_vec			*point;
	t_vec			*normal;
	t_vec			*ori;
	t_color			*color;
	float			radius;
	t_vec			*angle;
	float			h;
	float			intensity;
	int				type;
	t_vec			*normali;
}					t_objet;

typedef struct		s_camera
{
	t_vec			*campos;
	t_vec			*camdir;
	t_vec			*camright;
	t_vec			*camdown;
	t_vec			*vise;
}					t_camera;

typedef struct		s_option
{
	int				level;
	int				level_max;
	float			coef;
	int				activate_reflection;
	int				activate_antialiasing;
	int				activate_light;
	int				activate_shadow;
	int				activate_gama;
	int				activate_exposure;
}					t_option;

typedef struct		s_data
{
	t_ray			lray;
	t_vec			*v1;
	t_vec			*v2;
	t_vec			*new_start;
	t_vec			*vec_simple;
	t_vec			*blinn_dir;
	t_vec			*dist;
	t_option		*option;
	int				fd;
	int				n;
	void			*ptr;
	void			*win;
	t_new_img		**img;
	char			**argv;
	t_vec			**vec;
	t_objet			**objet;
	t_color			*color;
	t_color			*tmp2clr;
	t_color			*tmpcolor;
	float			coef;
	t_camera		*cam2;
	t_ray			*ray;
	t_ray			*light_ray;
	int				qrender;
	int				current;
}					t_data;

typedef struct		s_rotation
{
	t_vec			*point;
}					t_rotation;

typedef struct		s_rot
{
	t_vec			*s;
	t_vec			*c;
	t_vec			*a;
	float			xy;
	float			xz;
	float			yz;
	float			yx;
	float			zx;
	float			zy;
}					t_rot;

void				interface(t_data *d);
void				option_normal(t_data *d);
void				create_vec(t_data *d, int number);
void				free_all(t_data *d);
int					get_next_line(int const fd, char **line);
void				ft_putendl(char const *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				*ft_memalloc(size_t size);
int					ft_atoi(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlen(const char *string);
char				**ft_strsplit(char const *s, const char c);
void				ft_bzero(void *s, size_t n);
char				*ft_strdup(const char *s1);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strnew(size_t size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *s1, const char *s2);

float				ft_rad(float angle);
float				square(float nbr);

void				put_all_image(t_data *data);
void				img_to_img(t_new_img *s, t_new_img *d);

int					expose(t_data *data);
void				rtv1(t_data data);
int					main(int ac, char **av);
int					send_key(int key, t_data *d);

t_new_img			*create_img(t_new_img *i, t_data *d, unsigned long c,
					int *t);
void				background(t_data *data, t_new_img *b);
void				init(t_data *d);
int					parse(t_data *d);

void				color_assigne(t_color *c, float r, float g, float b);
float				ft_min(float a, float b);
float				ft_max(float a, float b);
void				pixel_put(t_new_img *img, int x, int y, t_color *color);
t_color				*new_color_rgb(float r, float g, float b);

t_vec				*vector_assign(t_vec *a, t_vec *b);
float				magnitude(t_vec *v);
t_vec				*normalize(t_vec *v1);
float				vector_dot(t_vec a, t_vec b);
t_vec				*vector_copy(t_vec *a);
t_vec				vector_sub(t_vec a, t_vec b);
t_vec				*ft_vec(float x, float y, float z);
t_vec				vector_add(t_vec a, t_vec b);
t_vec				vector_dot_float(float c, t_vec v1);
t_vec				*negative(t_vec *v1);
t_vec				*cross_product(t_vec *v1, t_vec *v2);
t_vec				*vector_divise_float(float c, t_vec *v1);
void				assign_value_vec(t_vec vec1, t_vec *vec2);
int					hit_cone(t_objet *p, t_ray *ray, float *t);
int					hit_plane(t_objet *p, t_ray *ray, float *t);
int					hit_sphere(t_ray *r, t_objet *s, float *t);
int					hit_cylinder(t_objet *p, t_ray *ray, float *t);
int					hit_cylinder2(float *tab, t_vec **vect, t_objet *p,
					float *t);
int					find_cylinder_intersection(t_objet *p, t_ray *ray,
					float *t);
t_ray				*rotation(t_ray *vect, t_objet *object);
t_vec				*rotatepoint(t_vec *point, t_rotation *rotation);

void				create_cone(t_data *d, char **split);
void				create_sphere(t_data *d, char **split);
void				create_light(t_data *d, char **split);
void				create_plane(t_data *d, char **split);
void				create_cylinder(t_data *d, char **split);
void				cone(t_data *d, t_vec *vec, t_color *color, t_vec *angle);
void				sphere(t_data *d, t_vec *vec, int rayon, t_color *color);
void				plane(t_data *d, t_vec *vec, t_vec *vec2, t_vec *angle);
void				cylinder(t_data *d, t_vec *vec1, t_vec *vec2, t_vec *vec3);
void				camera(t_data *d, int x, int y, int z);
void				light(t_data *d, t_vec *vec, float intensity,
					t_color *color);
float				get_x_point(float x);
float				get_y_point(float y);
void				display(t_data *d);
int					col_object(t_data *d, float *t, t_ray *ray);
t_vec				*calcul_light_shadow(t_data *d, float *t,
					t_vec *newstart, int currentobject);
void				calcul_next_iteration(t_data *d, t_ray *ray,
					t_vec *n, t_vec *newstart);
void				init_cam(t_data *d, char **split);

void				rotate_x(float *x, float *y, float *z, float alpha);
void				rotate_y(float *x, float *y, float *z, float alpha);
void				rotate_z(float *x, float *y, float *z, float alpha);
void				rotate_vec_axe(t_vec *v, t_vec *axe);

void				clear(t_data *d);
void				gama(t_color *color);
void				exposure(t_color *color);

int					normal_sphere(t_ray *r, t_objet *p, float *t);
int					normal_plane(float dv, t_vec *normal_tmp, t_objet *p);
int					normal_cone(t_vec *pp, t_objet *p, t_vec **rr, float *tab);
int					normal_cylindre(float *tab, t_vec **vect,
					t_objet *p, float *t);
#endif
