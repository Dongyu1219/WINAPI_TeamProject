#pragma once
#include <windows.h>

#define MAX_ENEMIES 2000
#define CELL 60

typedef struct Enemy{
	bool active;
	int x;
	int y;
	int type;
	int explosion;
	int monsterDirection;
} Enemy;

void CreateEnemy(HWND g_hWnd, int* x ,int* y);
void GetGyaradosImage(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1, HBITMAP* hBitmapGyara);
//void MoveEnemies(int mainx, int mainy, int monsterDirection);
void DrawGyarados(HDC mDC, int x, int y, HBITMAP hBitmapGyara);
void DrawEpicMonster(HDC mDC, HDC characterDC, HBITMAP hBitmapGyara, int x, int y);