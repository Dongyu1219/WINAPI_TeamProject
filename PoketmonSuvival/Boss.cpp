#include <windows.h>
#include "Boss.h"
#include "resource1.h"

//기라티나: 198 199
//ㅇ:200 201 202 203
static HBITMAP hBoss;

void DrawBoss(HDC mDC, HINSTANCE g_hInst, int animationNum) {

	if (animationNum == 0) {
		hBoss = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP198));
	}
	else if (animationNum == 1) {
		hBoss = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP199));
	}

	//TransparentBlt(mDC, 1100, 700, 58 * 4, 50 * 4, mDC, 0, 0, 58, 50, RGB(0, 0, 128));
}