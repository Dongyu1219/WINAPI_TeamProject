#include <windows.h>
#include "resource.h"

HDC hDC, mDC, characterDC;
static HBITMAP hBitmapCharacter;

void DrawGyarados(HINSTANCE g_hInst, HDC mDC) {
	int C_direction = 0;
	int animationNum = 0;

	if (C_direction == 0) {
		if (animationNum == 0) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		}
		else if (animationNum == 1) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
		}
		else if (animationNum == 2) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
		}
	}
	else if (C_direction == 1) {
		if (animationNum == 0) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		}
		else if (animationNum == 1) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		}
		else if (animationNum == 2) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		}
	}
	//¿ÞÂÊ
	else if (C_direction == 2) {
		if (animationNum == 0) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		}
		else if (animationNum == 1) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
		}
		else if (animationNum == 2) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
		}
	}
	else if (C_direction == 3) {
		if (animationNum == 0) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
		}
		else if (animationNum == 1) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP12));
		}
		else if (animationNum == 2) {
			hBitmapCharacter = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		}
	}
}