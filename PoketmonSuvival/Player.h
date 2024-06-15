#pragma once
#include <windows.h>
#include "Monsters.h"
#include "Skill.h"

typedef struct Exp {
	bool active;
	int type;
	int x, y;
}Exp;

void GetCharacterImage(int C_direction, int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst, int characterNum);
void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y);
void UpdateCharacter(int C_direction, int* x, int* y, RECT* rect, Enemy* enemy, Exp* expnc);
void DrawExp(Exp* expnc, HDC mDC, HINSTANCE g_hInst);