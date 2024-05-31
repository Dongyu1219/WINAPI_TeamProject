#include <windows.h>
#include "resource1.h"

void GetCharacterImage(int C_direction,int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst) {
	if (C_direction == 0) {
		if (animationNum == 0) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP15));
		}
		else if (animationNum == 1) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP16));
		}
	}
	else if (C_direction == 1) {
		if (animationNum == 0) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		}
		else if (animationNum == 1) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP18));
		}
	}
	else if (C_direction == 2) {
		if (animationNum == 0) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP19));
		}
		else if (animationNum == 1) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP20));
		}
	}
	else if (C_direction == 3) {
		if (animationNum == 0) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP21));
		}
		else if (animationNum == 1) {
			*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP22));
		}
	}
}

void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y) {
	SelectObject(characterDC, hBitmapCharacter);;
	TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 20, 20, RGB(255, 255, 255));
}