/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:21:46 by fhamel            #+#    #+#             */
/*   Updated: 2020/04/14 16:30:33 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

typedef	struct		s_test
{
	int 			res_amb;
	int				cams_lgts;
	int				objs;
	int 			res;
	int 			amb;
	int 			cams;
	int 			lgts;
	int				pl;
	int				sp;
	int				sq;
	int				cy;
	int				tr;
}					t_test;

typedef	struct		s_res
{
	int				id;
	int				x;
	int				y;
}					t_res;

typedef	struct		s_amb
{
	int				id;
	double			power;
	int				r;
	int				g;
	int				b;
}					t_amb;

typedef	struct		s_cam
{
	int				id;
	double			x;
	double			y;
	double			z;
	double 			vec_x;
	double			vec_y;
	double			vec_z;
	int				fov;
	struct s_cam	*next;
}					t_cam;

typedef	struct		s_lgt
{
	int				id;
	double			x;
	double			y;
	double			z;
	double			power;
	int				r;
	int				g;
	int				b;
	struct s_lgt	*next;
}					t_lgt;

typedef	struct		s_pl
{
	int				id;
	double			x;
	double			y;
	double			z;
	double 			vec_x;
	double			vec_y;
	double			vec_z;
	int				r;
	int				g;
	int				b;
	struct s_pl		*next;
}					t_pl;

typedef	struct		s_sp
{
	int				id;
	double			x;
	double			y;
	double			z;
	double			diam;
	int				r;
	int				g;
	int				b;
	struct s_sp		*next;
}					t_sp;


typedef	struct		s_sq
{
	int				id;
	double			x;
	double			y;
	double			z;
	double			vec_x;
	double			vec_y;
	double			vec_z;
	double			height;
	int				r;
	int				g;
	int				b;
	struct s_sq		*next;
}					t_sq;

typedef	struct		s_cy
{
	int				id;
	double			x;
	double			y;
	double			z;
	double			vec_x;
	double			vec_y;
	double			vec_z;
	double			diam;
	double			height;
	int				r;
	int				g;
	int				b;
	struct s_cy		*next;
}					t_cy;

typedef	struct		s_tr
{
	int				id;
	double			x_a;
	double			y_a;
	double			z_a;
	double			x_b;
	double			y_b;
	double			z_b;
	double			x_c;
	double			y_c;
	double			z_c;
	int				r;
	int				g;
	int				b;
	struct s_tr		*next;
}					t_tr;

typedef	struct		s_data
{
	t_res			*res;
	t_amb			*amb;
	t_cam			*cam;
	t_lgt			*lgt;
	t_pl			*pl;
	t_sp			*sp;
	t_sq			*sq;
	t_cy			*cy;
	t_tr			*tr;
}					t_data;

typedef	struct		s_vec
{
	double			x;
	double			y;
	double			z;
}					t_vec;

typedef	struct		s_obj
{
	int				id;
	double			x;
	double			y;
	double			z;
	double			len;
	void			*ptr;
}					t_obj;

typedef	struct		s_root
{
	double			t1;
	double			t2;	
}					t_root;

typedef	struct		s_mtx4
{
	t_vec			r;
	t_vec			u;
	t_vec			f;
	t_vec			c;
}					t_mtx4;

typedef	struct		s_win
{
	void			*mlx;
	void			*win;
}					t_win;

/*
mini_rt.c
*/
int					mini_rt(char *file);

/*
gnl
*/
int					get_next_line(int fd, char **line);

/*
ft_atoi.c
*/
int					ft_atoi(char *str);

/*
parsing.c
*/
int					parsing(int fd, t_data *data);
int					get_type(char *line);
int					check_format(int type, char *line);
int					error_function(int err);

/*
data.c
*/
int					init_data(t_data **data);
int					get_data(t_data *data, int type, char *line);
int					get_res(t_data *data, char *line);
int					get_amb(t_data *data, char *line);
int					get_cam(t_data *data, char *line);
int					get_lgt(t_data *data, char *line);
int					get_pl(t_data *data, char *line);
int					get_sp(t_data *data, char *line);
int					get_sq(t_data *data, char *line);
int					get_cy(t_data *data, char *line);
int					get_tr(t_data *data, char *line);

/*
data_utils.c
*/
int					nb_len(char *str);
double				floatoi(char *line);
double				get_xyz(int coord, char *line);
int					get_color(int coord, char *line);

/*
data_utils2.c
*/
int					skip_ws(char *line);
int					skip_float(char *line);
int					skip_coord(char *line);

/*
check_objs.c
*/
int					check_r(char *line);
int					check_a(char *line);
int					check_c(char *line);
int					check_l(char *line);
int					check_sp(char *line);
int					check_pl(char *line);
int					check_sq(char *line);
int					check_cy(char *line);
int					check_tr(char *line);

/*
check_utils.c
*/
int					check_nb(char *line);
int					check_coord(char *line);
int					check_vec(char *line);
int					check_color(char *line);

/*
check_test.c
*/
void				init_test(t_test *test);
void				fill_test(int type, t_test *test);
int					check_test(t_test *test);
int					check_current(int type, t_test *test);

/*
ray_tracer.c
*/
int					ray_tracer(t_data *data);
int					**init_tab_pix(int res_y, int res_x);
int					get_pix(t_data *data, int y, int x);
int					color_obj(t_obj obj, t_data *data);
t_vec				get_film(t_data *data);
t_vec				get_cam_ray(t_data *data, t_vec film, int y, int x);
double				get_x_cam(t_data *data, t_vec film, int x);
double				get_y_cam(t_data *data, t_vec film, int y);
t_mtx4				mtx4_world(t_data *data, t_vec film);
t_vec				mtx4_p(t_mtx4 m, t_vec p);

/*
ray_tracer_utils.c
*/
void				normalize(t_vec *vec);
double				dot_p(t_vec a, t_vec b);
t_vec				cross_p(t_vec a, t_vec b);
void				init_obj(t_obj *obj);
void				fill_obj(t_data *data, t_obj *obj, double t, t_vec cam_ray);


/*
scene.c
*/
t_obj				closest_obj(t_data *data, t_vec cam_ray);
t_obj				closest_sp(t_data *data, t_vec cam_ray);
t_obj				closest_pl(t_data *data, t_vec cam_ray);
t_obj				closest_sq(t_data *data, t_vec cam_ray);
t_obj				closest_cy(t_data *data, t_vec cam_ray);
t_obj				closest_tr(t_data *data, t_vec cam_ray);
void				print_scene(t_data *data, int **pix);

/*
intersections.c
*/
double				pl_intersection(t_vec cam_ray, t_pl *pl, t_cam *cam);
double				sp_intersection(t_vec cam_ray, t_sp *sp, t_cam *cam);
double				sq_intersection(t_vec cam_ray, t_sq *sq, t_cam *cam);
double				cy_intersection(t_vec cam_ray, t_cy *sq, t_cam *cam);
double				tr_intersection(t_vec cam_ray, t_tr *tr, t_cam *cam);

/*
intersections_utils.c
*/
double				sp_roots(double a, double b, double c, double delta);
int					sq_base(t_vec n, t_vec m, t_sq *sq);
int					sq_corners(t_vec u, t_vec v, t_vec m, t_sq *sq);
int					sq_final(t_vec a, t_vec b, t_vec d, t_vec m);
void				cy_fill_tab(t_vec tab[3], t_cy *cy, t_cam *cam);
double				cy_roots(t_vec tab[3], t_vec cam_ray, t_cy *cy, t_cam *cam);
double				cy_best_root(t_root t, t_cy *cy, t_cam *cam, t_vec cam_ray);

/*
facing_ratio.c
*/
double				f_ratio(t_obj obj, t_data *data);
double				f_ratio_pl(t_obj obj, t_data *data);
double				f_ratio_sp(t_obj obj, t_data *data);
double				f_ratio_sq(t_obj obj, t_data *data);
double				f_ratio_cy(t_obj obj, t_data *data);
double				f_ratio_tr(t_obj obj, t_data *data);


/*
color.c
*/
int					color_pl(t_obj obj, double ratio);
int					color_sp(t_obj obj, double ratio);
int					color_sq(t_obj obj, double ratio);
int					color_cy(t_obj obj, double ratio);
int					color_tr(t_obj obj, double ratio);

#endif