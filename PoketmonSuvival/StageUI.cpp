#include <Windows.h>
#include "resource1.h"
#include <tchar.h>

TCHAR gamePlayTime[20];

static HBITMAP hBitmapPuaseMenu1, hBitmapPuaseMenu2, hBitmapPuaseMenu3, hBitmapPuaseMenu4, hBitmapPuaseMenu5, hBitmapPuaseMenu6, hMiniMap;

void DrawEXP_Bar(HDC mDC, HINSTANCE g_hInst, int currentEXP, int level) {
	//HDC hDC = CreateCompatibleDC(mDC);
	//HBITMAP hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP108));
	//SelectObject(hDC, hBitmap);
	//StretchBlt(mDC, 0, 0, 1200, 80, hDC, 0, 0, 206, 37, SRCCOPY);
	HFONT hFont, oldfont;
	RoundRect(mDC, 100, 0, 1100, 30, 20, 20);
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 200, 100));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
	RoundRect(mDC, 100, 0, currentEXP, 30, 20, 20);
	hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("Airal"));
	oldfont = (HFONT)SelectObject(mDC, hFont);
	wsprintf(gamePlayTime, TEXT("Level : %d"),level);
	SetBkMode(mDC, TRANSPARENT);
	TextOut(mDC, 1000, 10,gamePlayTime, lstrlen(gamePlayTime));
	SelectObject(mDC, oldBrush);
	DeleteObject(hBrush);
	SelectObject(mDC, oldfont);
	DeleteObject(hFont);
	//DeleteDC(hDC);
}

void TimeBar(HDC mDC, int Timer1Count, int gamePlayminute) {
	HFONT hFont, oldfont;
	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("Arial"));
	oldfont = (HFONT)SelectObject(mDC, hFont);
	wsprintf(gamePlayTime, TEXT("%d : %d"), gamePlayminute, Timer1Count);
	TextOut(mDC, 550, 32, gamePlayTime, _tcslen(gamePlayTime));
	SelectObject(mDC, oldfont);
	DeleteObject(hFont);
}

void DrawPauseBar(HDC mDC, HBITMAP hBitmapPause) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hBitmapPause);
	//StretchBlt(mDC, 1120, 5, 50, 50, hmemDC, 0, 0, 512, 512, SRCCOPY);
	TransparentBlt(mDC, 1120, 5, 50, 50, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));
	DeleteDC(hmemDC);
}
void DrawPauseMenu(HDC mDC, HINSTANCE g_hInst) {
	HDC hmemDC = CreateCompatibleDC(mDC);

	hBitmapPuaseMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP101));
	hBitmapPuaseMenu3 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP103));
	hBitmapPuaseMenu4 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP104));
	hBitmapPuaseMenu5 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP105));
	hBitmapPuaseMenu6 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP106));

	/*hFont = CreateFont(150, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("±Ã¼­"));
	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 400, 200, _T("pause"), 30);
	SelectObject(mDC, oldfont);
	DeleteObject(hFont);*/

	SelectObject(hmemDC, hBitmapPuaseMenu1);
	//StretchBlt(mDC, 250, 270, 100, 100, hmemDC, 0, 0, 512, 512, SRCCOPY);
	TransparentBlt(mDC, 350, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));
	
	SelectObject(hmemDC, hBitmapPuaseMenu5);
	//StretchBlt(mDC, 550, 270, 100, 100, hmemDC, 0, 0, 512, 512, SRCCOPY);
	TransparentBlt(mDC, 550, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));

	SelectObject(hmemDC, hBitmapPuaseMenu3);
	//StretchBlt(mDC, 850, 270, 100, 100, hmemDC, 0, 0, 512, 512, SRCCOPY);
	TransparentBlt(mDC, 750, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));

	DeleteDC(hmemDC);
}
void pauseMouseMove(HDC mDC, HINSTANCE g_hInst, int pauseMouse) {
	HDC hmemDC = CreateCompatibleDC(mDC);

	hBitmapPuaseMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP101));
	hBitmapPuaseMenu2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP107));
	hBitmapPuaseMenu3 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP103));
	hBitmapPuaseMenu4 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP104));
	hBitmapPuaseMenu5 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP105));
	hBitmapPuaseMenu6 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP106));

	if (pauseMouse ==3) {
		SelectObject(hmemDC, hBitmapPuaseMenu4);
		TransparentBlt(mDC, 750, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));
	}
	else if (pauseMouse == 2) {
		SelectObject(hmemDC, hBitmapPuaseMenu6);
		TransparentBlt(mDC, 550, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));
	}
	else if (pauseMouse == 1) {
		SelectObject(hmemDC, hBitmapPuaseMenu2);
		
		TransparentBlt(mDC, 350, 270, 100, 100, hmemDC, 0, 0, 512, 512, RGB(255, 255, 255));
	}
	else {
		DrawPauseMenu(mDC, g_hInst);
	}
	DeleteDC(hmemDC);
}
void DrawMiniMap(HDC mDC, HINSTANCE g_hInst, int x, int y) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hMiniMap);

	hMiniMap = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP114));
	TransparentBlt(mDC, 20, 600, 210, 140, hmemDC, 0, 0, 240, 160, RGB(255, 255, 255));

	//Ellipse(mDC, x-50, y-35, x + 50, y + 35);

	DeleteDC(hmemDC);
}

