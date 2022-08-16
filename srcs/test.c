#include "../mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
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

int map[mapWidth][mapHeight] =
	{
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 7, 7, 7, 7, 7, 7, 7, 7},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 7},
		{4, 0, 4, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7, 7, 0, 7, 7, 7, 7, 7},
		{4, 0, 5, 0, 0, 0, 0, 5, 0, 5, 0, 5, 0, 5, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 6, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
		{4, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 8, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 0, 0, 0, 8},
		{4, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 7, 0, 0, 0, 7, 7, 7, 1},
		{4, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 0, 5, 5, 5, 5, 7, 7, 7, 7, 7, 7, 7, 1},
		{6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
		{8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
		{6, 6, 6, 6, 6, 6, 0, 6, 6, 6, 6, 0, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6},
		{4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 6, 0, 6, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
		{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 2},
		{4, 0, 0, 5, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2},
		{4, 0, 6, 0, 6, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 5, 0, 0, 2, 0, 0, 0, 2},
		{4, 0, 0, 0, 0, 0, 0, 0, 0, 4, 6, 0, 6, 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2},
		{4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3}};

double posX, posY;	   // 플레이어의 실제 위치
double dirX, dirY;	   // 플레이어의 시선
double planeX, planeY; // 카메라 평면
double moveSpeed;
double rotSpeed;
void *mlx_ptr; // mlx 연결 포인터
void *win_ptr;
int **buf;
int texture[8][texHeight * texWidth];

//
typedef struct s_img
{
	void *img;
	int *data;

	int size_l;
	int bpp;
	int endian;
} t_img;

t_img img;
void calMap(void);
void draw()
{
	for (int y = 0; y < screenHeight; y++)
	{
		for (int x = 0; x < screenWidth; x++)
		{
			img.data[y * screenWidth + x] = buf[y][x];
		}
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
}

int main_loop(void *temp)
{
	(void)temp;
	calMap();
	draw();
	return (0);
}

void calMap(void)
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
			buf[y][x] = 0xFFFFFF;
			buf[screenHeight - y - 1][x] = 0x000000;
		}
	}
	x = 0;
	while (x < screenWidth)
	{
		cameraX = (2 * x / (double)screenWidth) - 1;
		rayDirX = dirX + planeX * cameraX;
		rayDirY = dirY + planeY * cameraX;
		// DDA algorithm
		mapX = (int)posX;
		mapY = (int)posY;

		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		if (rayDirX > 0)
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		else // if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		if (rayDirY > 0)
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		else // if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		// DDA 알고리즘
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (map[mapX][mapY] > 0) // 벽이 아니라면
				hit = 1;			 // 이러면 다음 루프에서 종료되게 됨.
		}
		// 벽 부딪힘 이동 거리 계산
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
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
		int texNum = map[mapX][mapY] - 1; // 맵의 요소에 해당하는 텍스쳐의 인덱스
		// calculate value of wallX
		double wallX;
		if (side == 0)
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		// x coordinate on the texture
		int texX = (int)(wallX * (double)texWidth);

		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
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
			int color = texture[texNum][texHeight * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			buf[i][x] = color;
		}
		x++;
	}
}

void movePlayer(int x, int y)
{
	if (map[(int)(posX + x * dirX * moveSpeed)][(int)(posY)] == 0)
		posX += x * dirX * moveSpeed;
	if (map[(int)(posX)][(int)(posY + y * dirY * moveSpeed)] == 0)
		posY += y * dirY * moveSpeed;
}

void rotatePlayer(double angle)
{
	double olddirX = dirX;
	dirX = dirX * cos(angle) - dirY * sin(angle);
	dirY = olddirX * sin(angle) + dirY * cos(angle);
	double oldPlaneX = planeX;
	planeX = planeX * cos(angle) - planeY * sin(angle);
	planeY = oldPlaneX * sin(angle) + planeY * cos(angle);
}

int key_press(int keycode, void *temp)
{
	(void)temp;
	if (keycode == KEY_W) //위로
	{
		if (!map[(int)(posX + dirX * moveSpeed)][(int)(posY)])
			posX += dirX * moveSpeed;
		if (!map[(int)(posX)][(int)(posY + dirY * moveSpeed)])
			posY += dirY * moveSpeed;
	}
	else if (keycode == KEY_S) //아래
	{
		if (!map[(int)(posX - dirX * moveSpeed)][(int)(posY)])
			posX -= dirX * moveSpeed;
		if (!map[(int)(posX)][(int)(posY - dirY * moveSpeed)])
			posY -= dirY * moveSpeed;
	}
	else if (keycode == KEY_A) //왼
	{
		if (!map[(int)(posX - planeX * moveSpeed)][(int)posY])
			posX -= planeX * moveSpeed;
		if (!map[(int)(posX)][(int)(posY - planeY * moveSpeed)])
			posY -= planeY * moveSpeed;
	}
	else if (keycode == KEY_D) //오
	{
		if (!map[(int)(posX + planeX * moveSpeed)][(int)posY])
			posX += planeX * moveSpeed;
		if (!map[(int)(posX)][(int)(posY + planeY * moveSpeed)])
			posY += planeY * moveSpeed;
	}
	else if (keycode == KEY_LEFT) //왼
		rotatePlayer(0.05);
	else if (keycode == KEY_RIGHT) //오
		rotatePlayer(-0.05);
	// printf("posX : %f | posY : %f\n", posX, posY);
	// printf("dirX : %f | dirY : %f\n", dirX, dirY);
	return (0);
}

int main(void)
{
	mlx_ptr = mlx_init();

	// 변수들 초기화
	posX = 22.0;
	posY = 11.5;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	// planeY = 1;
	moveSpeed = 0.3;
	rotSpeed = 0.05;
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "test");

	/*
		texture 버전에 추가되는 부분 시작
	*/
	buf = (int **)malloc(sizeof(int *) * screenHeight);
	for (int i = 0; i < screenHeight; i++)
		buf[i] = (int *)malloc(sizeof(int) * screenWidth);
	// buffer 초기화
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++)
			buf[i][j] = 0;
	// texture 초기화
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < texHeight * texWidth; j++)
			texture[i][j] = 0;
	// generate some textures
	for (int x = 0; x < texWidth; x++)
		for (int y = 0; y < texHeight; y++)
		{
			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
			// int xcolor = x * 256 / texWidth;
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y);	 // flat red texture with black cross
			texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor;	 // sloped greyscale
			texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor;				 // sloped yellow gradient
			texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; // xor greyscale
			texture[4][texWidth * y + x] = 256 * xorcolor;								 // xor green
			texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16);			 // red bricks
			texture[6][texWidth * y + x] = 65536 * ycolor;								 // red gradient
			texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128;				 // flat grey texture
		}

	img.img = mlx_new_image(mlx_ptr, screenWidth, screenHeight);
	img.data = (int *)mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	mlx_loop_hook(mlx_ptr, &main_loop, NULL);
	mlx_hook(win_ptr, KEYPRESS, 0, &key_press, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
