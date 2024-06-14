#include <windows.h>
#include "resource1.h"
#include "Monsters.h"
#include <random>
#include <time.h>

//void MoveEnemies(int x, int y, int monsterDirection) {
//	for (int i = 0; i < MAX_ENEMIES; i++) {
//		if (enemy[i].active) { // 활성화된 적인 경우에만 
//			// 플레이어의 위치와 적의 위치를 비교
//			if (enemy[i].x < x) { // 플레이어가 오른쪽에 있으면
//				enemy[i].x++; // 적을 오른쪽으로 이동
//				monsterDirection = 0;
//			}
//			else if (enemy[i].x > x) {
//				enemy[i].x--;
//				monsterDirection = 2;
//			}
//
//			if (enemy[i].y < y) { // 플레이어가 아래쪽에 있으면
//				enemy[i].y++; // 적을 아래쪽으로 이동
//				monsterDirection = 1;
//			}
//			else if (enemy[i].y > y) {
//				enemy[i].y--;	//위
//				monsterDirection = 3;
//			}
//
//			if (enemy[i].x < 0) enemy[i].x = 0;
//			if (enemy[i].x > 1200) enemy[i].x = 1200;
//			if (enemy[i].y < 125) enemy[i].y = 125;
//			if (enemy[i].y > 800) enemy[i].y = 800;
//		}
//	}
//}

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

void DrawGyarados(HDC mDC, int x, int y, HBITMAP hBitmapGyara) {
	HDC hDC = CreateCompatibleDC(mDC);
	SelectObject(hDC, hBitmapGyara);

	TransparentBlt(mDC, x - 20, y - 40, 40, 80, hDC, 0, 0, 39, 72, RGB(0, 128, 128));
	DeleteDC(hDC);
}

void CreateEnemy(HWND g_hWnd, int* x, int* y) {
	srand((unsigned)time(NULL));
	*x = rand() % 1000+100; // 적 캐릭터의 x 좌표
	*y = rand() % 700 + 100; // 적 캐릭터의 y 좌표
}

void DrawEpicMonster(HDC mDC, HDC characterDC, HBITMAP hBitmapGyara, int x, int y) {
	SelectObject(characterDC, hBitmapGyara);;
	TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 50, 50, RGB(255, 255, 255));
}