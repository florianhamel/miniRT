/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianhamel <florianhamel@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:21:46 by fhamel            #+#    #+#             */
/*   Updated: 2020/03/28 19:45:50 by florianhame      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdlib.h>

typedef	struct	s_test
{
	int res_amb;
	int	cams_lgts;
	int	objs;
	int res;
	int amb;
	int cams;
	int lgts;
	int	pl;
	int	sp;
	int	sq;
	int	cy;
	int	tr;
}				t_test;

typedef	struct	s_res
{
	char	*id;
	int		x;
	int		y;
	void	*next;
}				t_res;

typedef	struct	s_amb
{
	char	*id;
	float	power;
	char	*color;
	void	*next;
}				t_amb;

typedef	struct	s_cam
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float 	vec_x;
	float	vec_y;
	float	vec_z;
	int		fov;
	void	*next;
}				t_cam;

typedef	struct	s_lgt
{
	float	x;
	float	y;
	float	z;
	float	power;
	char	*color;
}				t_lgt;

typedef	struct	s_pl
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float 	vec_x;
	float	vec_y;
	float	vec_z;
	char	*color; // need a conversion from RGB
	void	*next;
}				t_pl;

typedef	struct	s_sp
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float	diameter;
	char	*color;
	void	*next;
}				t_sp;


typedef	struct	s_sq
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	float	height;
	char	*color;
	void	*next;
}				t_sq;

typedef	struct	s_cy
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float	vec_x;
	float	vec_y;
	float	vec_z;
	float	diameter;
	float	height;
	char	*color;
	void	*next;
}				t_cy;

typedef	struct	s_tr
{
	char	*id;
	float	x_p1;
	float	y_p1;
	float	z_p1;
	float	x_p2;
	float	y_p2;
	float	z_p2;
	float	x_p3;
	float	y_p3;
	float	z_p3;
	char	*color;
	void	*next;
}				t_tr;

typedef	struct	s_data
{
	t_res	*r;
	t_amb	*a;
	void	**cams;
	void	**lgts;
	void	**objs;
}				t_data;

/*
mini_rt.c
*/
int		mini_rt(char *file);
int		init_data(t_data **data);

/*
gnl
*/
int		get_next_line(int fd, char **line);
int		ft_atoi(char *str);

/*
parsing.c
*/
int		parsing(int fd, t_data **data);
int		get_type(char *line);
int		check_format(int type, char *line);
int		get_data(t_data **data, int type, char *line);
int		error_function(int err);

/*
check_objs.c
*/
int		check_r(char *line);
int		check_a(char *line);
int		check_c(char *line);
int		check_l(char *line);
int		check_sp(char *line);
int		check_pl(char *line);
int		check_sq(char *line);
int		check_cy(char *line);
int		check_tr(char *line);

/*
check_utils.c
*/
int		check_nb(char *line);
int		check_coord(char *line);
int		check_vec(char *line);
int		check_color(char *line);

/*
check_test.c
*/
void	init_test(t_test *test);
void	fill_test(int type, t_test *test);
int		check_test(t_test *test);
int		check_current(int type, t_test *test);

#endif