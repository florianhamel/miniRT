/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:21:46 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/31 10:35:24 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>
# include <math.h>

typedef	struct	s_test
{
	int 		res_amb;
	int			cams_lgts;
	int			objs;
	int 		res;
	int 		amb;
	int 		cams;
	int 		lgts;
	int			pl;
	int			sp;
	int			sq;
	int			cy;
	int			tr;
}				t_test;

typedef	struct	s_res
{
	int			id;
	int			x;
	int			y;
}				t_res;

typedef	struct	s_amb
{
	int			id;
	double		power;
	int			color;
}				t_amb;

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
	int				color;
	struct s_lgt	*next;
}					t_lgt;

typedef	struct	s_pl
{
	int			id;
	double		x;
	double		y;
	double		z;
	double 		vec_x;
	double		vec_y;
	double		vec_z;
	int			color;
	struct s_pl	*next;
}				t_pl;

typedef	struct	s_sp
{
	int			id;
	double		x;
	double		y;
	double		z;
	double		diam;
	int			color;
	struct s_sp	*next;
}				t_sp;


typedef	struct	s_sq
{
	int			id;
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	double		height;
	int			color;
	struct s_sq	*next;
}				t_sq;

typedef	struct	s_cy
{
	int			id;
	double		x;
	double		y;
	double		z;
	double		vec_x;
	double		vec_y;
	double		vec_z;
	double		diam;
	double		height;
	int			color;
	struct s_cy	*next;
}				t_cy;

typedef	struct	s_tr
{
	char	*id;
	double	x_p1;
	double	y_p1;
	double	z_p1;
	double	x_p2;
	double	y_p2;
	double	z_p2;
	double	x_p3;
	double	y_p3;
	double	z_p3;
	char	*color;
	void	*next;
}				t_tr;

typedef	struct	s_data
{
	t_res	*res;
	t_amb	*amb;
	t_cam	*cam;
	t_lgt	*lgt;
	t_pl	*pl;
	t_sp	*sp;
	t_sq	*sq;
	t_cy	*cy;
	t_tr	*tr;
}				t_data;

/*
mini_rt.c
*/
int				mini_rt(char *file);

/*
gnl
*/
int				get_next_line(int fd, char **line);

/*
ft_atoi.c
*/
int				ft_atoi(char *str);

/*
parsing.c
*/
int				parsing(int fd, t_data **data);
int				get_type(char *line);
int				check_format(int type, char *line);
int				error_function(int err);

/*
data.c
*/
int				init_data(t_data **data);
int				get_data(t_data *data, int type, char *line);
int				get_res(t_data *data, char *line);
int				get_amb(t_data *data, char *line);
int				get_cam(t_data *data, char *line);
int				get_lgt(t_data *data, char *line);
int				get_pl(t_data *data, char *line);
int				get_sp(t_data *data, char *line);
int				get_sq(t_data *data, char *line);

/*
data_utils.c
*/
int				nb_len(char *str);
double			floatoi(char *line);
double			get_xyz(int coord, char *line);
unsigned int	get_color(char *line);

/*
data_utils2.c
*/
int	skip_ws(char *line);
int	skip_float(char *line);
int	skip_coord(char *line);

/*
check_objs.c
*/
int				check_r(char *line);
int				check_a(char *line);
int				check_c(char *line);
int				check_l(char *line);
int				check_sp(char *line);
int				check_pl(char *line);
int				check_sq(char *line);
int				check_cy(char *line);
int				check_tr(char *line);

/*
check_utils.c
*/
int				check_nb(char *line);
int				check_coord(char *line);
int				check_vec(char *line);
int				check_color(char *line);

/*
check_test.c
*/
void			init_test(t_test *test);
void			fill_test(int type, t_test *test);
int				check_test(t_test *test);
int				check_current(int type, t_test *test);

#endif