#include "../mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 600
#define screenHeight 480
#define texWidth 64	 // 텍스쳐의 텍셀(texel) 이 갖는 너비
#define texHeight 64 // 텍스쳐의 텍셀(texel) 이 갖는 높이
#define KEYPRESS 2
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_LEFT 123  //왼쪽
#define KEY_RIGHT 124 //오른쪽

int map[24][24] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

typedef struct s_img
{
	void *img;
	int *data;

	int size_l;
	int bpp;
	int endian;

	int img_width;
	int img_height;
} t_img;

typedef struct s_info
{
	double posX, posY;	   // 플레이어의 실제 위치
	double dirX, dirY;	   // 플레이어의 시선
	double planeX, planeY; // 카메라 평면
	double moveSpeed;
	double rotSpeed;
	void *mlx_ptr; // mlx 연결 포인터
	void *win_ptr;
	int **buf;
	int texture[4][texHeight * texWidth];
	t_img img;
} t_info;

void calMap(t_info *info);
void draw(t_info *info)
{
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			info->img.data[y * screenWidth + x] = info->buf[y][x];
		}
	}
	mlx_put_image_to_window(info->mlx_ptr, info->win_ptr, info->img.img, 0, 0);
}

int main_loop(t_info *info)
{
	calMap(info);
	draw(info);
	return (0);
}

void calMap(t_info *info)
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int x;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	int stepX;
	int stepY;
	int hit;
	int side;
	double perpWallDist;

	for (int x = 0; x < screenWidth; x++)
	{
		for (int y = 0; y < screenHeight; y++)
		{
			// info->buf[y][x] = 0;
			info->buf[y][x] = 0xFFFFAA;
			info->buf[screenHeight - y - 1][x] = 0x00FFAB;
		}
	}
	x = 0;
	while (x < screenWidth)
	{
		cameraX = (2 * x / (double)screenWidth) - 1;
		rayDirX = info->dirX + info->planeX * cameraX;
		rayDirY = info->dirY + info->planeY * cameraX;
		// DDA algorithm
		mapX = (int)info->posX;
		mapY = (int)info->posY;

		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		if (rayDirX > 0)
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;
		}
		else // if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (info->posX - mapX) * deltaDistX;
		}
		if (rayDirY > 0)
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;
		}
		else // if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (info->posY - mapY) * deltaDistY;
		}
		// DDA 알고리즘
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				// side = 0; 동, 서
				if (stepX == 1)
					side = 0;
				else if (stepX == -1)
					side = 1;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				// side = 1;
				if (stepY == 1)
					side = 2;
				else if (stepY == -1)
					side = 3;
			}
			if (map[mapX][mapY] > 0) // 벽이 아니라면
				hit = 1;			 // 이러면 다음 루프에서 종료되게 됨.
		}
		// 벽 부딪힘 이동 거리 계산
		if (side == 0 || side == 1)
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;
		// 벽 높이 구하기
		int lineHeight = (int)(screenHeight / perpWallDist);
		// 선 시작/끝 지점 구하기
		int drawStart = -lineHeight / 2 + screenHeight / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + screenHeight / 2;
		if (drawEnd >= screenHeight)
			drawEnd = screenHeight - 1;
		// textured version
		int texNum = side; // 맵의 요소에 해당하는 텍스쳐의 인덱스
		// calculate value of wallX
		double wallX;
		if (side == 0 || side == 1)
			wallX = info->posY + perpWallDist * rayDirY;
		else
			wallX = info->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);

		if ((side == 0 || side == 1) && rayDirX > 0)
			texX = texWidth - texX - 1;
		if ((side == 2 || side == 3) && rayDirY < 0)
			texX = texWidth - texX - 1;
		// 선 그리기 (aka verLine)
		// How much to increase the texture coordinate perscreen pixel
		double step = 1.0 * texHeight / lineHeight;
		// Starting texture coordinate
		double texPos = (drawStart - screenHeight / 2 + lineHeight / 2) * step;
		// 고쳐야함
		for (int i = drawStart; i < drawEnd; i++)
		{
			// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = info->texture[texNum][texHeight * texY + texX];
			if (side == 2 || side == 3)
				color = (color >> 1) & 8355711;
			info->buf[i][x] = color;
		}
		x++;
	}
}

void movePlayer(t_info *info, int x, int y)
{
	if (map[(int)(info->posX + x * info->dirX * info->moveSpeed)][(int)(info->posY)] == 0)
		info->posX += x * info->dirX * info->moveSpeed;
	if (map[(int)(info->posX)][(int)(info->posY + y * info->dirY * info->moveSpeed)] == 0)
		info->posY += y * info->dirY * info->moveSpeed;
}

void rotatePlayer(t_info *info, int i)
{
	double tmp;
	if (i == 0)
		tmp = info->rotSpeed;
	else
		tmp = info->rotSpeed * (-1);
	double olddirX = info->dirX;
	info->dirX = info->dirX * cos(tmp) - info->dirY * sin(tmp);
	info->dirY = olddirX * sin(tmp) + info->dirY * cos(tmp);
	double oldPlaneX = info->planeX;
	info->planeX = info->planeX * cos(tmp) - info->planeY * sin(tmp);
	info->planeY = oldPlaneX * sin(tmp) + info->planeY * cos(tmp);
}

int key_press(int keycode, t_info *info)
{
	if (keycode == KEY_W) //위로
	{
		if (!map[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!map[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	else if (keycode == KEY_S) //아래
	{
		if (!map[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!map[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
	}
	else if (keycode == KEY_A) //왼
	{
		if (!map[(int)(info->posX - info->planeX * info->moveSpeed)][(int)info->posY])
			info->posX -= info->planeX * info->moveSpeed;
		if (!map[(int)(info->posX)][(int)(info->posY - info->planeY * info->moveSpeed)])
			info->posY -= info->planeY * info->moveSpeed;
	}
	else if (keycode == KEY_D) //오
	{
		if (!map[(int)(info->posX + info->planeX * info->moveSpeed)][(int)info->posY])
			info->posX += info->planeX * info->moveSpeed;
		if (!map[(int)(info->posX)][(int)(info->posY + info->planeY * info->moveSpeed)])
			info->posY += info->planeY * info->moveSpeed;
	}
	else if (keycode == KEY_LEFT) //왼
		rotatePlayer(info, 0);
	else if (keycode == KEY_RIGHT) //오
		rotatePlayer(info, 1);
	// printf("posX : %f | posY : %f\n", posX, posY);
	// printf("dirX : %f | dirY : %f\n", dirX, dirY);
	return (0);
}

void load_image(t_info *info, int *texture, char *path, t_img *img)
{
	img->img = mlx_xpm_file_to_image(info->mlx_ptr, path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, &img->bpp, &img->size_l, &img->endian);
	for (int y = 0; y < img->img_height; y++)
	{
		for (int x = 0; x < img->img_width; x++)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
		}
	}
	mlx_destroy_image(info->mlx_ptr, img->img);
}

void load_texture(t_info *info)
{
	t_img img;
	load_image(info, info->texture[0], "textures/wall1.xpm", &img);
	load_image(info, info->texture[1], "textures/wall2.xpm", &img);
	load_image(info, info->texture[2], "textures/wall3.xpm", &img);
	load_image(info, info->texture[3], "textures/wall4.xpm", &img);
}

int main(void)
{
	t_info info;
	info.mlx_ptr = mlx_init();

	// 변수들 초기화
	info.posX = 22.0;
	info.posY = 11.5;
	info.dirX = -1;
	info.dirY = 0;
	info.planeX = 0;
	info.planeY = 0.66;
	// planeY = 1;
	info.moveSpeed = 0.3;
	info.rotSpeed = 0.05;
	info.win_ptr = mlx_new_window(info.mlx_ptr, screenWidth, screenHeight, "test");
	/*
		texture 버전에 추가되는 부분 시작
	*/
	info.buf = (int **)malloc(sizeof(int *) * screenHeight);
	for (int i = 0; i < screenHeight; i++)
		info.buf[i] = (int *)malloc(sizeof(int) * screenWidth);
	// buffer 초기화
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++)
			info.buf[i][j] = 0;
	// texture 초기화
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < texHeight * texWidth; j++)
			info.texture[i][j] = 0;
	// 이미지 초기화
	load_texture(&info);
	// // generate some textures
	// for (int x = 0; x < texWidth; x++)
	// 	for (int y = 0; y < texHeight; y++)
	// 	{
	// 		int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
	// 		// int xcolor = x * 256 / texWidth;
	// 		int ycolor = y * 256 / texHeight;
	// 		int xycolor = y * 128 / texHeight + x * 128 / texWidth;
	// 		texture[0][texWidth * y + x] = 65536 * 250 * (x != y && x != texWidth - y);	 // flat red texture with black cross
	// 		texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;	 // sloped greyscale
	// 		texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor;				 // sloped yellow gradient
	// 		texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; // xor greyscale
	// 		texture[0][texWidth * y + x] = 256 * xorcolor;								 // xor green
	// 		texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16);			 // red bricks
	// 		texture[6][texWidth * y + x] = 65536 * ycolor;								 // red gradient
	// 		texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128;				 // flat grey texture
	// 	}
	info.img.img = mlx_new_image(info.mlx_ptr, screenWidth, screenHeight);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx_ptr, &main_loop, &info);
	mlx_hook(info.win_ptr, KEYPRESS, 0, &key_press, &info);
	mlx_loop(info.mlx_ptr);
	return (0);
}
