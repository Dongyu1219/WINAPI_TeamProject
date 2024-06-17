#include <windows.h>
#include "resource1.h"
#include "Monsters.h"
#include <random>
#include <time.h>

void GetGhostImage(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1, HBITMAP* hBitmapGyara) {

	if (*hBitmapGyara) {
		DeleteObject(*hBitmapGyara); // ±âÁ¸ ºñÆ®¸Ê ÇØÁ¦
	}

	// À§
	if (monsterDirection == 0) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP115));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP116));
		}
	
	}
	else if (monsterDirection == 1) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP117));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP118));
		}
	}
	//¿ÞÂÊ
	else if (monsterDirection == 2) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP119));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP120));
		}
		
	}
	else if (monsterDirection == 3) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP121));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP122));
		}
		
	}
}

void DrawGhost(HDC mDC, int x, int y, HBITMAP hBitmapGyara, int monsterDirection) { // °í¿À½º Æø : 50
	HDC hDC = CreateCompatibleDC(mDC);
	SelectObject(hDC, hBitmapGyara);
	if (monsterDirection == 0) {
		TransparentBlt(mDC, x - 25, y - 25, 50, 50, hDC, 0, 0, 22, 20, RGB(255, 255, 255));
	}
	else if (monsterDirection == 1) {
		TransparentBlt(mDC, x - 25, y - 25, 50, 50, hDC, 0, 0, 22, 20, RGB(255, 255, 255));
	}
	else if (monsterDirection == 2) {
		TransparentBlt(mDC, x - 25, y - 25, 50, 50, hDC, 0, 0, 19, 20, RGB(255, 255, 255));
	}
	else if (monsterDirection == 3) {
		TransparentBlt(mDC, x - 25, y - 25, 50, 50, hDC, 0, 0, 19, 20, RGB(255, 255, 255));
	}
	DeleteDC(hDC);
}

void GetGhoustImage(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1, HBITMAP* hBitmapGyara) {

	if (*hBitmapGyara) {
		DeleteObject(*hBitmapGyara); // ±âÁ¸ ºñÆ®¸Ê ÇØÁ¦
	}

	// À§
	if (monsterDirection == 0) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP123));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP124));
		}

	}
	else if (monsterDirection == 1) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP125));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP126));
		}
	}
	//¿ÞÂÊ
	else if (monsterDirection == 2) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP127));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP128));
		}

	}
	else if (monsterDirection == 3) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP129));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP130));
		}

	}
}

void DrawGhoust(HDC mDC, int x, int y, HBITMAP hBitmapGyara, int monsterDirection) { // °í¿ì½ºÆ® Æø : 70
	HDC hDC = CreateCompatibleDC(mDC);
	SelectObject(hDC, hBitmapGyara);
	if (monsterDirection == 0) {
		TransparentBlt(mDC, x - 35, y - 35, 70, 70, hDC, 0, 0, 24, 21, RGB(255, 255, 255));
	}
	else if (monsterDirection == 1) {
		TransparentBlt(mDC, x - 35, y - 35, 70, 70, hDC, 0, 0, 24, 19, RGB(255, 255, 255));
	}
	else if (monsterDirection == 2) {
		TransparentBlt(mDC, x - 35, y - 35, 70, 70, hDC, 0, 0, 19, 21, RGB(255, 255, 255));
	}
	else if (monsterDirection == 3) {
		TransparentBlt(mDC, x - 35, y - 35, 70, 70, hDC, 0, 0, 19, 21, RGB(255, 255, 255));
	}
	DeleteDC(hDC);
}

void GetPhantomImage(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1, HBITMAP* hBitmapGyara) {

	if (*hBitmapGyara) {
		DeleteObject(*hBitmapGyara); // ±âÁ¸ ºñÆ®¸Ê ÇØÁ¦
	}

	// À§
	if (monsterDirection == 0) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP131));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP132));
		}

	}
	else if (monsterDirection == 1) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP133));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP134));
		}
	}
	//¿ÞÂÊ
	else if (monsterDirection == 2) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP135));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP136));
		}

	}
	else if (monsterDirection == 3) {
		if (animationNum1 == 0) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP137));
		}
		else if (animationNum1 == 1) {
			*hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP138));
		}

	}
}

void DrawPhantom(HDC mDC, int x, int y, HBITMAP hBitmapGyara, int monsterDirection) { // ÆÒÅÒ Æø : 90
	HDC hDC = CreateCompatibleDC(mDC);
	SelectObject(hDC, hBitmapGyara);
	if (monsterDirection == 0) {
		TransparentBlt(mDC, x - 45, y - 45, 90, 90, hDC, 0, 0, 24, 21, RGB(255, 255, 255));
	}
	else if (monsterDirection == 1) {
		TransparentBlt(mDC, x - 45, y - 45, 90, 90, hDC, 0, 0, 23, 21, RGB(255, 255, 255));
	}
	else if (monsterDirection == 2) {
		TransparentBlt(mDC, x - 45, y - 45, 90, 90, hDC, 0, 0, 20, 22, RGB(255, 255, 255));
	}
	else if (monsterDirection == 3) {
		TransparentBlt(mDC, x - 45, y - 45, 90, 90, hDC, 0, 0, 20, 22, RGB(255, 255, 255));
	}
	DeleteDC(hDC);
}

void CreateEnemy(HWND g_hWnd, int* x, int* y, int* type, int* hp, int evolution) {
	*x = rand() % 1000+100; // Àû Ä³¸¯ÅÍÀÇ x ÁÂÇ¥
	*y = rand() % 700 + 100; // Àû Ä³¸¯ÅÍÀÇ y ÁÂÇ¥
	*type = rand() % evolution; // 0 1 2
	switch (*type) {
	case 0:
		*hp = 100;
		break;
	case 1:
		*hp = 200;
		break;
	case 2:
		*hp = 400;
		break;
	}
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
