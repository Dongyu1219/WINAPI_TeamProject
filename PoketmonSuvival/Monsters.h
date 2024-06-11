#pragma once
#include <windows.h>
#define MAX_ENEMIES 2000

void CreateEnemy(HWND g_hWnd);
void DrawMon(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1);
void MoveEnemies(int mainx, int mainy, int monsterDirection);
void DrawGyarados(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1);
