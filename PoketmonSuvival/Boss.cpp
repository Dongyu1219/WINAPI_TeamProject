#include <windows.h>
#include "Boss.h"
#include "resource1.h"

//기라티나: 198 199

//HBITMAP hBoss, hOrora;

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
	TransparentBlt(mDC, 1100, 700, 58*5, 50*5, hDC, 0, 0, 58, 50, RGB(0, 0, 128));
	DeleteDC(hDC);
}

void DrawOrora(HDC mDC, HINSTANCE g_hInst, int TextCount, HBITMAP* hOrora){

	if (*hOrora) {
		DeleteObject(*hOrora);
	}

	HDC hDC = CreateCompatibleDC(mDC);

	if ((TextCount%4) == 0) {
		*hOrora = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP200));
	}
	else if ((TextCount%4) == 1) {
		*hOrora = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP201));
	}
	else if ((TextCount % 4) == 2) {
		*hOrora = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP202));
	}
	else if ((TextCount % 4) == 3) {
		*hOrora = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP203));
	}

	SelectObject(hDC, *hOrora);
	TransparentBlt(mDC, 1082, 755, 62*5, 62*5, hDC, 0, 0, 62, 62, RGB(255, 255, 255));
	DeleteDC(hDC);
}

void DrawBossHpBox(HDC mDC, int BossMaxHp, int BosscurrentHp) {
	Rectangle(mDC, 1237 - BossMaxHp, 680, 1237 + BossMaxHp, 692);

	HBRUSH hBrush = CreateSolidBrush(RGB(128, 50, 128));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
	Rectangle(mDC, 1237 - BossMaxHp, 680, 1237 + BosscurrentHp -5, 692);
	SelectObject(mDC, oldBrush);
	DeleteObject(hBrush);
}

void DrawLazer(HDC mDC, HINSTANCE g_hInst, int TextCount, HBITMAP* hLight, HBITMAP* hLight2) {
	HDC hDC = CreateCompatibleDC(mDC);

	if (*hLight) {
		DeleteObject(*hLight);
	}
	if (*hLight2) {
		DeleteObject(*hLight2);
	}

	if ((TextCount % 4) == 0) {
		*hLight = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP217));
		*hLight2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP221));
	}
	else if ((TextCount % 4) == 1) {
		*hLight = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP216));
		*hLight2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP220));
	}
	else if ((TextCount % 4) == 2) {
		*hLight = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP215));
		*hLight2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP219));
	}
	else if ((TextCount % 4) == 3) {
		*hLight = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP214));
		*hLight2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP218));
	}

	SelectObject(hDC, *hLight);
	TransparentBlt(mDC, 200, 795, 127* 7, 38 * 2, hDC, 0, 0, 127, 38, RGB(255, 255, 255));
	SelectObject(hDC, *hLight2);
	TransparentBlt(mDC, 1350, 795, 127 * 5, 38 * 2, hDC, 0, 0, 127, 38, RGB(255, 255, 255));
	DeleteDC(hDC);

}

