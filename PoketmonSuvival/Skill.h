#pragma once
#include <windows.h>
typedef struct Bullet {
	int x, y;
	int dx, dy;
	bool active;
	int bulletDirection;
} Bullet;

typedef struct Skills {
	int selected;
}Skills;

typedef struct Bomb {
	int x, y;
	bool active;
}Bomb;

void DrawHpBox(HDC mDC, int x, int y, int MaxHp, int currentHp);
void FireBullet(int x, int y, int dx, int dy, int MAX_BULLETS, Bullet* bullets, int bulletDirection);
void UpdateBullets(int MAX_BULLETS, Bullet* bullets);
void DrawBullets(HINSTANCE g_hInst, HDC mDC, int MAX_BULLETS, Bullet* bullets, int bulletLevel, HBITMAP* hBitmapBullet);



void FireBomb(int MAX_BOMB, Bomb *bomb);
void DrawBomb(HINSTANCE g_hInst, HDC mDC, int MAX_BULLETS, Bomb *bomb, HBITMAP* hBomb, int animationNum);

void skillChoices0(HDC mDC, int SKILLS, HINSTANCE g_hInst);
void skillChoices1(HDC mDC, int SKILLS, HINSTANCE g_hInst);
void skillChoices2(HDC mDC, int SKILLS, HINSTANCE g_hInst);

void DrawRotatingBullet(HDC mDC, int mainx, int mainy, int angle);