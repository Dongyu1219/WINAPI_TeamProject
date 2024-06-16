#include <windows.h>
#include "Boss.h"
#include "resource1.h"

//기라티나: 198 199
//ㅇ:200 201 202 203
HBITMAP hBoss;

void DrawBoss(HDC mDC, HINSTANCE g_hInst, int animationNum, HBITMAP* hBoss) {

	if (*hBoss) {
		DeleteObject(*hBoss);
	}

	HDC hDC = CreateCompatibleDC(mDC);

	if (animationNum == 0) {
		*hBoss = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP198));
	}
	else if (animationNum == 1) {
		*hBoss = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP199));
	}

	SelectObject(hDC, *hBoss);
	TransparentBlt(mDC, 1100, 700, 234, 200, hDC, 0, 0, 58, 50, RGB(0, 0, 128));
	DeleteDC(hDC);
}