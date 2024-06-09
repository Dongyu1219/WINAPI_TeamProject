#include <windows.h>
#include "resource1.h"

void GetCharacterImage(int C_direction,int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst, int characterNum) {
	if (*hBitmapCharacter) {
		DeleteObject(*hBitmapCharacter); // 기존 비트맵 해제
	}

	if (characterNum == 1) { // 이상해씨
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
	else if (characterNum == 2) { // 파이리
		if (C_direction == 0) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP78));
			}
			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP79));
			}

		}
		else if (C_direction == 1) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP80));
			}

			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP81));
			}

		}
		else if (C_direction == 2) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP82));
			}

			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP83));
			}
		}
		else if (C_direction == 3) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP84));
			}
			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP85));
			}
		}
	}
	else if (characterNum == 3) { // 꼬부기
		if (C_direction == 0) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP86));
			}
			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP87));
			}

		}
		else if (C_direction == 1) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP88));
			}

			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP89));
			}

		}
		else if (C_direction == 2) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP90));
			}

			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP91));
			}
		}
		else if (C_direction == 3) {
			if (animationNum == 0) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP92));
			}
			else if (animationNum == 1) {
				*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP93));
			}
		}
	}
}

void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y) {
	SelectObject(characterDC, hBitmapCharacter);;
	TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 20, 20, RGB(255, 255, 255));
}

void UpdateCharacter(int C_direction, int* x, int* y, RECT* rect) {
	switch (C_direction) {
	case 0: 
		if (rect->bottom == 1600 && *y > 400) {
			*y -= 5;
		}
		else {
			if (rect->top > 0) {
				rect->top -= 5;
				rect->bottom -= 5;
			}
			else {
				if (*y > 75) {
					*y -= 5;
				}
			}
		}
		break;
	case 1:
		if (rect->top == 0 && *y < 400) {
			*y += 5;
		}
		else {
			if (rect->bottom < 1600) {
				rect->top += 5;
				rect->bottom += 5;
			}
			else {
				if (*y < 775) {
					*y += 5;
				}
			}
		}
		break;
	case 2:
		if (rect->right == 2400 && *x > 600) {
			*x -= 5;
		}
		else {
			if (rect->left > 0) {
				rect->left -= 5;
				rect->right -= 5;
			}
			else {
				if (*x > 25) {
					*x -= 5;
				}
			}
		}
		break;
	case 3:
		if (rect->left == 0 && *x < 600) {
			*x += 5;
		}
		else {
			if (rect->right < 2400) {
				rect->left += 5;
				rect->right += 5;
			}
			else {
				if (*x < 1175) {
					*x += 5;
				}
			}
		}
		break;
	}
}