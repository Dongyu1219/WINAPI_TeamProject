#pragma once
#include <windows.h>

void GetCharacterImage(int C_direction, int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst, int characterNum);
void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y);
void UpdateCharacter(int C_direction, int* x, int* y, RECT* rect);