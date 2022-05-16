#include <stdio.h>
#include "mlx/mlx.h"

int main	()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 50, 50, "ejang");
	mlx_loop(mlx);
	return 0;
}