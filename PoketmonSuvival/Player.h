#pragma once
#include <windows.h>

typedef struct Bullet {
	int x, y;
	int dx, dy;
	bool active;
} Bullet;

void GetCharacterImage(int C_direction, int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst, int characterNum);
void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y);
void UpdateCharacter(int C_direction, int* x, int* y, RECT* rect);
void FireBullet(int x, int y, int dx, int dy, int MAX_BULLETS, Bullet* bullets);
void UpdateBullets(int MAX_BULLETS, Bullet* bullets);
void DrawBullets(HDC hDC, int MAX_BULLETS, Bullet* bullets);