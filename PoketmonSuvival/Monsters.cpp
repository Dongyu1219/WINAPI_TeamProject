#include <windows.h>
#include "resource1.h"
#include "Monsters.h"
#include <random>
#include <time.h>

void GetGyaradosImage(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1, HBITMAP* hBitmapGyara) {

	// 위
	if (monsterDirection == 0) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		}
	
	}
	else if (monsterDirection == 1) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
		}
	}
	//왼쪽
	else if (monsterDirection == 2) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
		}
		
	}
	else if (monsterDirection == 3) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP12));
		}
		
	}
}

void DrawGyarados(HDC mDC, int x, int y, HBITMAP hBitmapGyara, int monsterDirection) {
	HDC hDC = CreateCompatibleDC(mDC);
	SelectObject(hDC, hBitmapGyara);
	if(monsterDirection == 1)TransparentBlt(mDC, x - 37, y - 55, 37, 55, hDC, 0, 0, 37, 55, RGB(0, 128, 128));
	else if(monsterDirection == 3)TransparentBlt(mDC, x - 20, y - 40, 40, 80, hDC, 0, 0, 39, 72, RGB(0, 128, 128));
	else if (monsterDirection == 0)TransparentBlt(mDC, x - 120, y - 80, 120, 80, hDC, 0, 0, 83, 67, RGB(0, 128, 128));
	else if (monsterDirection == 2)TransparentBlt(mDC, x - 120, y - 80, 120, 80, hDC, 0, 0, 83, 67, RGB(0, 128, 128));
	DeleteDC(hDC);
}

void CreateEnemy(HWND g_hWnd, int* x, int* y) {
	srand((unsigned)time(NULL));
	*x = rand() % 1000+100; // 적 캐릭터의 x 좌표
	*y = rand() % 700 + 100; // 적 캐릭터의 y 좌표
}

void DrawBasicEnemy(HINSTANCE g_hInst, HDC mDC, HBITMAP BasicMonster, int x, int y) {
	HDC hDC = CreateCompatibleDC(mDC);
	BasicMonster = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP109));
	SelectObject(hDC, BasicMonster);
	TransparentBlt(mDC, x, y, 35, 40, hDC, 0, 0, 56, 56, RGB(112, 154, 209));
}

void DrawEpicMonster(HDC mDC, HDC characterDC, HBITMAP hBitmapGyara, int x, int y) {
	SelectObject(characterDC, hBitmapGyara);;
	TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 50, 50, RGB(255, 255, 255));
}
