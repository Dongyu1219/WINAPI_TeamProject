#pragma once

void DrawEXP_Bar(HDC mDC, HINSTANCE g_hInst, int currentEXP, int level);
void TimeBar(HDC mDC, int Timer1Count, int gamePlayminute);
void DrawPauseBar(HDC mDC, HBITMAP hBitmapPause);
void DrawPauseMenu(HDC mDC, HINSTANCE g_hInst);

void pauseMouseMove(HDC mDC, HINSTANCE g_hInst, int pauseMouse);

void DrawMiniMap(HDC mDC, HINSTANCE g_hInst, int x, int y);