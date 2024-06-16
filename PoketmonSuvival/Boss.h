#pragma once
#include <windows.h>



void DrawBoss(HDC mDC, HINSTANCE g_hInst, int animationNum, HBITMAP* hBoss);
void DrawOrora(HDC mDC, HINSTANCE g_hInst, int TextCount, HBITMAP* hOrora);
void DrawBossHpBox(HDC mDC, int BossMaxHp, int BosscurrentHp);
void DrawLazer(HDC mDC, HINSTANCE g_hInst, int TextCount, HBITMAP* hLight, HBITMAP* hLight2);