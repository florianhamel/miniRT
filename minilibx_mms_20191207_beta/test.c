#include "mlx.h"

int main()
{
	void	*mlx_win;
	void	*mlx_ptr;
	void	*img_ptr;
	char	*img_add;
	int		bpp;
	int		sl;
	int		end;
	int		i;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1000, 1000, "coucou");
	img_ptr = mlx_new_image(mlx_ptr, 1000, 1000);
	img_add = mlx_get_data_addr(img_ptr, &bpp, &sl, &end);
	i = 0;
	bpp = bpp / 8;
	while (i < sl / bpp * 1000)
	{
		*(int*)(&img_add[i * bpp]) = 16777215; 
		++i;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}