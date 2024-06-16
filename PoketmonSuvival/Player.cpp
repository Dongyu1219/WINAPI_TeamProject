#include <windows.h>
#include "resource1.h"
#include "Player.h"
#include "Monsters.h"
#include "Skill.h"

void GetCharacterImage(int C_direction,int animationNum, HBITMAP* hBitmapCharacter, HINSTANCE g_hInst, int characterNum, int evolution) {
	if (*hBitmapCharacter) {
		DeleteObject(*hBitmapCharacter); // 기존 비트맵 해제
	}

	if (evolution == 1) {
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
	else if (evolution == 2) {
		if (characterNum == 1) { // 이상해풀
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP165));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP166));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP167));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP168));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP169));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP170));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP171));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP172));
				}
			}
		}
		else if (characterNum == 2) { // 리자드
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP157));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP158));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP159));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP160));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP161));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP162));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP163));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP164));
				}
			}
		}
		else if (characterNum == 3) { // 어니부기
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP181));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP182));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP183));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP184));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP185));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP186));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP187));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP188));
				}
			}
		}
	}
	else if (evolution == 3) {
		if (characterNum == 1) { // 이상해꽃
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP173));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP174));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP175));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP176));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP177));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP178));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP179));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP180));
				}
			}
		}
		else if (characterNum == 2) { // 리자몽
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP149));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP150));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP151));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP152));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP153));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP154));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP155));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP156));
				}
			}
		}
		else if (characterNum == 3) { // 거북왕
			if (C_direction == 0) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP141));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP142));
				}

			}
			else if (C_direction == 1) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP143));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP144));
				}

			}
			else if (C_direction == 2) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP145));
				}

				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP146));
				}
			}
			else if (C_direction == 3) {
				if (animationNum == 0) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP147));
				}
				else if (animationNum == 1) {
					*hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP148));
				}
			}
		}
	}
}

void DrawCharacter(HDC mDC, HDC characterDC, HBITMAP hBitmapCharacter, int x, int y, int evolution) {
	SelectObject(characterDC, hBitmapCharacter);;
	if (evolution == 1) TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 20, 20, RGB(255, 255, 255));
	else if (evolution == 2)TransparentBlt(mDC, x, y, 70, 70, characterDC, 0, 0, 22, 22, RGB(255, 255, 255));
	else if (evolution == 3) TransparentBlt(mDC, x, y, 90, 90, characterDC, 0, 0, 28, 26, RGB(255, 255, 255));
}

void UpdateCharacter(int C_direction, int* x, int* y, RECT* rect, Enemy* enemy, Exp* expnc) {
	switch (C_direction) {
	case 0: 
		if (rect->bottom == 1600 && *y > 400) {
			*y -= 5;
		}
		else {
			if (rect->top > 0) {
				rect->top -= 5;
				rect->bottom -= 5;
				for (int i = 0; i < 1000; i++) {
					if (enemy[i].active) {
						enemy[i].y += 5;
					}
				}

				for (int i = 0; i < 100; i++) {
					if (expnc[i].active) {
						expnc[i].y += 5;
					}
				}
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
				for (int i = 0; i < 1000; i++) {
					if (enemy[i].active) {
						enemy[i].y -= 5;
					}
				}
				for (int i = 0; i < 100; i++) {
					if (expnc[i].active) {
						expnc[i].y -= 5;
					}
				}
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
				for (int i = 0; i < 1000; i++) {
					if (enemy[i].active) {
						enemy[i].x += 5;
					}
				}
				for (int i = 0; i < 100; i++) {
					if (expnc[i].active) {
						expnc[i].x += 5;
					}
				}
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
				for (int i = 0; i < 1000; i++) {
					if (enemy[i].active) {
						enemy[i].x -= 5;
					}
				}
				for (int i = 0; i < 100; i++) {
					if (expnc[i].active) {
						expnc[i].x -= 5;
					}
				}
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

void DrawExp(Exp* expnc, HDC mDC, HINSTANCE g_hInst) {
	HDC hDC = CreateCompatibleDC(mDC);
	HBITMAP hBitmapExp = 0;

	for (int i = 0; i < 100; i++) {
		if (hBitmapExp) {
			DeleteObject(hBitmapExp);
		}

		if (expnc[i].active) {
			switch (expnc[i].type) {
			case 0:
			case 1:
				hBitmapExp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP139));
				SelectObject(hDC, hBitmapExp);
				TransparentBlt(mDC, expnc[i].x - 10, expnc[i].y - 10, 20, 20, hDC, 0, 0, 17, 19, RGB(255, 255, 255));
				break;
			case 2:
				hBitmapExp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP140));
				SelectObject(hDC, hBitmapExp);
				TransparentBlt(mDC, expnc[i].x - 10, expnc[i].y - 10, 20, 20, hDC, 0, 0, 20, 22, RGB(255, 255, 255));
				break;
			case 3:
				hBitmapExp = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP213));
				SelectObject(hDC, hBitmapExp);
				TransparentBlt(mDC, expnc[i].x - 15, expnc[i].y - 15, 30, 30, hDC, 0, 0, 25, 25, RGB(255, 255, 255));
				break;
			}
		}
	}
	DeleteDC(hDC);
}

