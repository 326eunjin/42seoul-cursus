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
#define KEY_W 13	  // MacOS의 키보드 코드들이다.
#define KEY_A 0		  //
#define KEY_S 1		  // 위에서 부터 차례대로
#define KEY_D 2		  //
#define KEY_LEFT 123  //왼쪽
#define KEY_RIGHT 124 //오른쪽

int map[mapWidth][mapHeight] = {
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

double posX = 22, posY = 12;
double dirX = -1, dirY = 0;	   // 플레이어 방향은 W
double planeX = 0, planeY = 1; //	플레이어 방향벡터와 수직인 카메라 평면
void *mlx_ptr;				   // mlx 연결 포인터
void *win_ptr;

void drawScreen(void)
{
	/*
		3 ~ 7. 게임 루프
	*/
	// raycasting 시작
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

	// while (1)
	// {
	x = 0;
	while (x < screenWidth)
	{
		cameraX = 2 * x / (double)screenWidth - 1;
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
			sideDistX = (mapX + 1 - posX) * deltaDistX;
		}
		else // if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		if (rayDirY > 0)
		{
			stepY = 1;
			sideDistY = (mapY + 1 - posY) * deltaDistY;
		}
		else // if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		// else
		// 	stepY = 42;

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
			if (map[mapX][mapY] != 0) // 벽이 아니라면
				hit = 1;			  // 이러면 다음 루프에서 종료되게 됨.
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
		switch (map[mapX][mapY])
		{
		case 1:
			//(r * 256 * 256) + (g * 256) + b
			color = 0x00FF0000;
			break; // red
		case 2:
			color = 0x0000FF00;
			break; // green
		case 3:
			color = 0x000000FF;
			break; // blue
		case 4:
			color = 0x00FFFFFF;
			break; // white
		default:
			color = 0x00F9D71C;
			break; // yellow
		}
		// give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}
		// 선 그리기
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

	if (map[(int)floor(posX) + x][(int)floor(posY) + y] != 0)
		return;
	posX += x;
	posY += y;
	drawScreen();
}

/*
cosθ * x− sinθ * y = x'
sinθ * x + cosθ * y = y'
*/

void rotatePlayer(double angle)
{
	double dist;

	dirX = dirX * cos(angle) - dirY * sin(angle);
	dirY = dirY * cos(angle) + dirX * sin(angle);
	dist = hypot(dirX, dirY);
	dirX /= dist;
	dirY /= dist;
	drawScreen();
}

int key_press(int keycode, void *temp)
{
	(void)temp;
	if (keycode == KEY_W) //위로
		movePlayer(-1, 0);
	else if (keycode == KEY_A) //왼쪽
		movePlayer(0, -1);
	else if (keycode == KEY_S) //아래
		movePlayer(1, 0);
	else if (keycode == KEY_D) //오른쪽
		movePlayer(0, 1);
	else if (keycode == KEY_LEFT) //왼
		rotatePlayer(0.05);
	else if (keycode == KEY_RIGHT) //오
		rotatePlayer(-0.05);
	return (0);
}

int main(void)
{
	/*
		1. main 시작에서의 변수 초기화
	*/
	// 길이는 동일하게 했다.
	// // 어떻게 써야할지 모르겠으니까 일단 주석처리
	// double time = 0;
	// double oldTime = 0;

	/*
		2. 화면 생성 (mlx)
	*/

	mlx_ptr = mlx_init();
	if (mlx_ptr == 0)
		exit(1);
	win_ptr = mlx_new_window(mlx_ptr, screenWidth, screenHeight, "test");
	if (win_ptr == 0)
		exit(1);
	drawScreen();
	// KEYHOOK
	mlx_hook(win_ptr, KEYPRESS, 0, &key_press, NULL);
	mlx_loop(mlx_ptr);
	//}

	return (0);
}
