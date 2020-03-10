#ifndef MINIRT_H
# define MINIRT_H

typedef	struct	s_data
{
	t_resolution	*R;
	t_amb_light		*A;
	void			**cameras;
	void			**lights;
	void			**objects;
}				t_data;

typedef	struct	s_resolution
{
	char	*id;
	int		x;
	int		y;
	void	*next;
}				t_resolution;

typedef	struct	s_amb_light
{
	char	*id;
	float	power;
	char	*color;
	void	*next;
}				t_amb_light;

typedef	struct	s_camera
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
}				t_camera;

typedef	struct	s_light
{
	float	x;
	float	y;
	float	z;
	float	power;
	char	*color;
}				t_light;

typedef	struct	s_sphere
{
	char	*id;
	float	x;
	float	y;
	float	z;
	float	diameter;
	char	*color;
	void	*next;
}				t_sphere;

typedef	struct	s_plane
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
}				t_plane;

typedef	struct	s_square
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
}				t_square;

typedef	struct	s_cylinder
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
}				t_cylinder;

typedef	struct s_triangle
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
}				t_triangle;
