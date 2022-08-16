#include "../mlx/mlx.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
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
	{1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

double posX, posY;	   // 플레이어의 실제 위치
double dirX, dirY;	   // 플레이어의 시선
double planeX, planeY; // 카메라 평면
double moveSpeed;
double rotSpeed;
void *mlx_ptr; // mlx 연결 포인터
void *win_ptr;

void drawScreen(void)
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
		// 그릴 색깔 정하기
		int color;
		if (map[mapY][mapX] == 1)
			color = 0x00FF0000;
		else if (map[mapY][mapX] == 2)
			color = 0x0000FF00;
		else if (map[mapY][mapX] == 3)
			color = 0x000000FF;
		else if (map[mapY][mapX] == 4)
			color = 0x00FFFFFF;
		else
			color = 0x00F9D71C;
		// give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}
		// 선 그리기 (aka verLine)
		for (int i = 0; i < screenHeight; i++)
		{
			if (i < drawStart) // 바닥
				mlx_pixel_put(mlx_ptr, win_ptr, x, i, 0x00FFC0CB);
			else if (i >= drawStart && i < drawEnd)
				mlx_pixel_put(mlx_ptr, win_ptr, x, i, color);
			else // 천장
				mlx_pixel_put(mlx_ptr, win_ptr, x, i, 0x00E6E6FA);
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

int main_loop(void *temp)
{
	(void)temp;
	drawScreen();
	return (0);
}

int main(void)
{

	mlx_ptr = mlx_init();

	// 변수들 초기화
	posX = 12;
	posY = 5;
	dirX = -1;
	dirY = 0;
	planeX = 0;
	planeY = 0.66;
	// planeY = 1;
	moveSpeed = 0.05;
	rotSpeed = 0.05;
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "test");
	//  KEYHOOK
	mlx_loop_hook(mlx_ptr, &main_loop, NULL);
	mlx_hook(win_ptr, KEYPRESS, 0, &key_press, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
