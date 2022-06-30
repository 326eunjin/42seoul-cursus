[fract-ol.pdf](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8b1e52dd-507d-46fa-848e-ee71ac725137/fract-ol.pdf)

*“This project is meant to create graphically beautiful fractals”*

---

## **서브젝트 분석**

- 프렉탈 중 (망델브로 집합, 줄리아 집합)을 구현해라
- 줌인 줌아웃 기능을 거의 무한한대로 구현해라
- mlx을 사용할 것
- 그럼 이제 알아야 할 것 :
    - mlx란 무엇인가?
    - 프렉탈이란 무엇인가?
    - 구현을 어떻게 할 것인가?
- mlx
    - [https://42kchoi.tistory.com/229](https://42kchoi.tistory.com/229)
    - [https://velog.io/@jeunghoon/MiniLibX를-공부해보자#initC](https://velog.io/@jeunghoon/MiniLibX%EB%A5%BC-%EA%B3%B5%EB%B6%80%ED%95%B4%EB%B3%B4%EC%9E%90#initC)
    - [https://malbongcode.tistory.com/149](https://malbongcode.tistory.com/149)
    - [https://velog.io/@serity/42-fractol](https://velog.io/@serity/42-fractol)
    - [https://bingu.tistory.com/2](https://bingu.tistory.com/2)
    - [https://bingu.tistory.com/2](https://bingu.tistory.com/2)

mlx란 : **학생을 위한 간단한 window 인터페이스 라이브러리**

## **코드 구상**

- $z_{n+1} = z_{n}^{2} + c$
- $(a_n+b_ni)^2 + c = a_{n+1} + b_{n+1}i$
- $(a_{n}^2 + 2a_nb_ni-b_n^2 + c)=a_{n+1}^2+b_{n+1}$
- $a_{n+1} = a_n^2 -b_n^2 + c$
- $b_{n+1} = 2a_nb_n$
- 망델브로 집합
    - 망델브로 집합은 다음 점화식으로 정의된 수열이 발산하지 않는 성질을 갖도록 하는 [복소수](https://ko.wikipedia.org/wiki/%EB%B3%B5%EC%86%8C%EC%88%98)
     c의 집합으로 정의된다.
        - $z_0 = 0$
    - pseudo code
    
    ```c
    for each pixel (Px, Py) on the screen do
        x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
        y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
        x := 0.0
        y := 0.0
        iteration := 0
        max_iteration := 1000
        while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
            xtemp := x*x - y*y + x0
            y := 2*x*y + y0
            x := xtemp
            iteration := iteration + 1
        
        color := palette[iteration]
        plot(Px, Py, color)
    ```
    
- 줄리아 집합
    - 쥘리아 집합은 주어진 [복소수](https://ko.wikipedia.org/wiki/%EB%B3%B5%EC%86%8C%EC%88%98) c에 대해서 다음 점화식에 따라 정의된 수열이 발산하지 않는 성질을 갖도록 하는 [복소수](https://ko.wikipedia.org/wiki/%EB%B3%B5%EC%86%8C%EC%88%98) z의 집합으로 정의된다
    - pseudo code
    
    ```c
    R = escape radius  # choose R > 0 such that R**2 - R >= sqrt(cx**2 + cy**2)
    
    for each pixel (x, y) on the screen, do:   
    {
        zx = scaled x coordinate of pixel # (scale to be between -R and R)
           # zx represents the real part of z.
        zy = scaled y coordinate of pixel # (scale to be between -R and R)
           # zy represents the imaginary part of z.
    
        iteration = 0
        max_iteration = 1000
      
        while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration) 
        {
            xtemp = zx * zx - zy * zy
            zy = 2 * zx * zy  + cy 
            zx = xtemp + cx
        
            iteration = iteration + 1 
        }
      
        if (iteration == max_iteration)
            return black;
        else
            return iteration;
    }
    ```
    
- 다음과 같은 그림을 바탕으로 복소좌표와 mlx 창을 맞춰주었다.
- ex. (800,400) == (2,0)

![Untitled](https://user-images.githubusercontent.com/50578785/176636985-d8a17e26-2e2d-4781-ac90-9ce15fa24258.png)

## **코드**

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:07:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 17:58:05 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

# define HEIGHT 800
# define WIDTH 800
# define ITER_MAX 30

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
}	t_color;

typedef struct s_img{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_color	color;
	int		status;
	double	julia_re;
	double	julia_im;
	double	zoom;
}	t_mlx;

int		press_esc_key(int key);
int		zoom(int key, int x, int y, t_mlx *mlx);
int		press_x_button(void);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	draw_pixel(t_mlx *mlx);
int		set_color(int iter, t_mlx *mlx);

void	error_check(t_mlx *mlx, int argc, char **argv);
void	print_error(void);
int		check_status(t_mlx *mlx, char **argv, int argc);

long	ft_atol(char *str);
double	ft_atod(char *str);
double	cal_ret2(int i, char *str);
void	is_right(char *str);

int		mandelbrot_set(int height_start, int width_start, int iter, t_mlx *mlx);
int		julia_set(int height_start, int width_start, int iter, t_mlx *mlx);

int		init(t_mlx *mlx);

#endif
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:34:27 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 11:19:34 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	set_color(int iter, t_mlx *mlx)//색깔 설정
{
	mlx->color.r = 13 * (iter / 16);
	mlx->color.g = 18 * iter;
	mlx->color.b = 255 - iter / 16;
	return (mlx->color.r * 256 * 256 + mlx->color.g * 256 + mlx->color.b);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
//mlx_pixel_put() 함수 대신에 동작을 모방하여 구현한 함수
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixel(t_mlx *mlx)
{
	int	height_start;
	int	width_start;
	int	iter;
	int	color;

	height_start = -1;
	while (++height_start < HEIGHT)
	{
		width_start = 0;
		while (width_start < WIDTH)
		{
			iter = 0;
			if (mlx->status == 1)
				iter = mandelbrot_set(height_start, width_start, iter, mlx);
			else if (mlx->status == 2)
				iter = julia_set(height_start, width_start, iter, mlx);
			color = set_color(iter, mlx);
			if (iter == ITER_MAX)
				my_mlx_pixel_put(&mlx->img, \
				width_start, height_start, 0xDDFFFFFF);
			else
				my_mlx_pixel_put(&mlx->img, width_start, height_start, color);
			width_start++;
		}
	}
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:25:50 by ejang             #+#    #+#             */
/*   Updated: 2022/05/21 18:42:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	error_check(t_mlx *mlx, int argc, char **argv)
{
	if (argc < 2 || check_status(mlx, argv, argc) == 0)
	{
		print_error();
		exit(0);
	}
	if (argc > 2 && check_status(mlx, argv, argc) == 1)
	{
		print_error();
		exit(0);
	}
	if (argc != 4 && check_status(mlx, argv, argc) == 2)
	{
		print_error();
		exit(0);
	}
}

void	print_error(void)
{
	ft_putstr_fd("INVALID PARAMETER\n", 1);
	ft_putstr_fd("MANDELBROT SET\n", 1);
	ft_putstr_fd("ex) ./fractol mandelbrot\n", 1);
	ft_putstr_fd("JULIA SET\n", 1);
	ft_putstr_fd("format : ./fractol julia float float\n", 1);
	ft_putstr_fd("ex) ./fractol julia -0.7 -0.27014", 1);
	exit(0);
}

int	check_status(t_mlx *mlx, char	**argv, int argc)
{
	mlx->zoom = 2;
	mlx->status = 0;
	mlx->julia_im = 0;
	mlx->julia_re = 0;
	if (ft_strncmp(argv[1], "mandelbrot", ft_strlen("mandelbrot")) == 0)
		mlx->status = 1;
	else if (ft_strncmp(argv[1], "julia", ft_strlen("julia")) == 0)
	{
		mlx->status = 2;
		if (argc == 4)
		{
			is_right(argv[2]);
			is_right(argv[3]);
			mlx->julia_re = ft_atod(argv[2]);
			mlx->julia_im = ft_atod(argv[3]);
		}
		else
		{
			mlx->julia_re = 0;
			mlx->julia_im = 0;
		}
	}
	return (mlx->status);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:35:23 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 17:14:09 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	press_esc_key(int key)//esc키에 대한 훅 설정
{
	if (key == 53)
		exit(0);
	return (0);
}

int	zoom(int key, int x, int y, t_mlx *mlx)//마우스 휠에 대해서 확대 비율 줄이기 
{
	if (key == 4 || key == 5)
	{
		if (key == 4)
			mlx->zoom = mlx->zoom - 0.01;
		else
			mlx->zoom = mlx->zoom + 0.01;
	}
	draw_pixel(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img.img, 0, 0);
	return (0);
}

int	press_x_button(void)//x버튼에 대한 훅 설정
{
	exit(0);
	return (0);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 02:41:53 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 18:00:29 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

long	ft_atol(char *str)
{
	long		ret;
	int			minus;
	int			i;

	ret = 0;
	minus = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i])
	{
		ret = ret * 10 + (str[i] - '0');
		i++;
	}
	if (minus == -1)
		ret = ret * minus;
	return (ret);
}

double	ft_atod(char *str)
{
	double	ret;
	double	ret_2;
	int		i;
	char	*tmp;

	ret = 0;
	ret_2 = 0;
	i = 0;
	while (str[i] != '.')
		i++;
	tmp = (char *)malloc(i + 1);
	ft_strlcpy(tmp, str, i + 1);
	ret = ft_atol(tmp);
	free(tmp);
	ret_2 = cal_ret2(i, str);
	if (str[0] == '-')
		ret = ret - ret_2;
	else
		ret = ret + ret_2;
	return (ret);
}

double	cal_ret2(int i, char *str)
{
	int		decimal_loc;
	int		decimal_len;
	int		j;
	double	ret_2;
	char	*tmp;

	ret_2 = 0;
	decimal_loc = i + 1;
	decimal_len = ft_strlen(str) - decimal_loc;
	tmp = (char *)malloc(decimal_len + 1);
	ft_strlcpy(tmp, str + decimal_loc, decimal_len + 1);
	j = 0;
	while (str[decimal_loc])
	{
		ret_2 = ret_2 + (str[decimal_loc] - 48) * pow(0.1, j + 1);
		j++;
		decimal_loc++;
	}
	free(tmp);
	return (ret_2);
}

void	is_right(char *str)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] == '.')
			cnt++;
		i++;
	}
	if (cnt != 1)
		print_error();
	if (!(str[0] == '-' || (str[0] >= '0' && str[0] <= '9')))
		print_error();
	if (str[0] == '-' && (str[1] < '0' || str[1] > '9'))
		print_error();
	i = 1;
	while (str[i])
	{
		if (!(str[i] == '.' || (str[i] <= '9' && str[i] >= '0')))
			print_error();
		i++;
	}
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:30:18 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 02:23:24 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, HEIGHT, WIDTH, "fractol");//창 위 이름 프렉탈로 설정
	mlx->img.img = mlx_new_image(mlx->mlx_ptr, HEIGHT, WIDTH);
	mlx->img.addr = mlx_get_data_addr(mlx->img.img, &mlx->img.bits_per_pixel, \
	&mlx->img.line_length, &mlx->img.endian);
	return (1);
}
```

```jsx
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mandelbrot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang < ejang@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:33:46 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 10:43:30 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	mandelbrot_set(int height_start, int width_start, int iter, t_mlx *mlx)
{
	double	a_re;
	double	b_im;
	double	x;
	double	x_temp;
	double	y;

	a_re = (double) width_start * ((2 * mlx->zoom) / 800) - mlx->zoom;
	b_im = (-1) * (double) height_start * ((2 * mlx->zoom) / 800) + mlx->zoom;
	x = 0;
	y = 0;
	while ((x * x + y * y <= 4) && (iter < ITER_MAX))
	{
		x_temp = x * x - y * y + a_re;
		y = 2 * x * y + b_im;
		x = x_temp;
		iter++;
	}
	return (iter);
}

int	julia_set(int height_start, int width_start, int iter, t_mlx *mlx)
{
	double	x;
	double	x_temp;
	double	y;

	x = (double) width_start * ((2 * mlx->zoom) / 800) - mlx->zoom;
	y = (-1) * (double) height_start * ((2 * mlx->zoom) / 800) + mlx->zoom;
	while ((x * x + y * y <= 4) && (iter < ITER_MAX))
	{
		x_temp = x * x - y * y;
		y = 2 * x * y + mlx->julia_im;
		x = x_temp + mlx->julia_re;
		iter++;
	}
	return (iter);
}
```

```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejang <ejang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:11:08 by ejang             #+#    #+#             */
/*   Updated: 2022/05/20 17:09:43 by ejang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	error_check(&mlx, argc, argv);//파싱 에러 체크
	if (!init(&mlx))//할당 및 초기화
		return (0);
	draw_pixel(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img.img, 0, 0);//윈도우에 그리기
	mlx_key_hook(mlx.win_ptr, press_esc_key, 0);//esc 키에 대한 훅 설정
	mlx_hook(mlx.win_ptr, 17, 0, press_x_button, &mlx);//종료 버튼에 대한 훅 설정
	mlx_hook(mlx.win_ptr, 4, 1L << 2, zoom, &mlx);//마우스 휠에 대한 훅 설정
	mlx_loop(mlx.mlx_ptr);//무한대기 상태
}
```

## 구현 결과

![image](https://user-images.githubusercontent.com/50578785/176637303-d1a69d30-ffa9-4d8a-85b4-4f25f31ff93c.png)

![image](https://user-images.githubusercontent.com/50578785/176637336-08514fc1-3132-49e8-b083-6990ffb78dd0.png)

