#pragma once
#include <windows.h>

void DrawGrassMap(HDC mDC, HBITMAP hbitmapMap0, HBITMAP  hbitmapWall0, HBITMAP hbitmapWall1, HBITMAP hbitmapWall2);
void DrawWaterMap(HDC mDC, HINSTANCE g_hInst);
void DrawFireMap(HDC mDC, HINSTANCE g_hInst);
