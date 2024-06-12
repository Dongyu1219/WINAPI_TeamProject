#include <windows.h>
#include "resource1.h"

HDC hDC, mDC, characterDC;
static HBITMAP hBitmapGyara;
static int monsterDirection;

#define MAX_ENEMIES 2000
#define CELL 60

typedef struct {
	bool active;
	int x;
	int y;
	int explosion;
	int shakeCounter;
} Enemy;
Enemy enemy[MAX_ENEMIES];

static int enemySpawnTime = 6000; // �ʱ� ���� �ð� 6��


void MoveEnemies(int x, int y, int monsterDirection) {
	for (int i = 0; i < MAX_ENEMIES; i++) {
		if (enemy[i].active) { // Ȱ��ȭ�� ���� ��쿡�� 
			// �÷��̾��� ��ġ�� ���� ��ġ�� ��
			if (enemy[i].x < x) { // �÷��̾ �����ʿ� ������
				enemy[i].x++; // ���� ���������� �̵�
				monsterDirection = 0;
			}
			else if (enemy[i].x > x) {
				enemy[i].x--;
				monsterDirection = 2;
			}
			if (enemy[i].y < y) { // �÷��̾ �Ʒ��ʿ� ������
				enemy[i].y++; // ���� �Ʒ������� �̵�
				monsterDirection = 1;
			}
			else if (enemy[i].y > y) {
				enemy[i].y--;	//��
				monsterDirection = 3;
			}

			if (enemy[i].x < 0) enemy[i].x = 0;
			if (enemy[i].x > 1200) enemy[i].x = 1200;
			if (enemy[i].y < 125) enemy[i].y = 125;
			if (enemy[i].y > 800) enemy[i].y = 800;
		}
	}
}

void DrawGyarados(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1) {

	if (monsterDirection == 0) {
		if (animationNum1 == 0) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP5));
		}
		else if (animationNum1 == 1) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP6));
		}
		else if (animationNum1 == 2) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP7));
		}
	}
	else if (monsterDirection == 1) {
		if (animationNum1 == 0) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		}
		else if (animationNum1 == 1) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP3));
		}
		else if (animationNum1 == 2) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP4));
		}
	}
	//����
	else if (monsterDirection == 2) {
		if (animationNum1 == 0) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		}
		else if (animationNum1 == 1) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP9));
		}
		else if (animationNum1 == 2) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP10));
		}
	}
	else if (monsterDirection == 3) {
		if (animationNum1 == 0) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP11));
		}
		else if (animationNum1 == 1) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP12));
		}
		else if (animationNum1 == 2) {
			hBitmapGyara = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		}
	}
}

void CreateEnemy(HWND g_hWnd) {

	for (int i = 1; i < MAX_ENEMIES; ++i) {
		if (!enemy[i].active) { // ��Ȱ��ȭ�� �� 
			enemy[i].active = true;
			enemy[i].x = 85 + (rand() % 12 + 1) * 60; // �� ĳ������ x ��ǥ
			enemy[i].y = 85 + (rand() % 8 + 1) * 60; // �� ĳ������ y ��ǥ
			break;
		}
	}

	enemySpawnTime = max(1000, enemySpawnTime - 100); // ���� ���� �ð� ª����, �ּ� 1��
	SetTimer(g_hWnd, 8, enemySpawnTime, NULL);
}


void DrawMon(HINSTANCE g_hInst, HDC mDC, int monsterDirection, int animationNum1) {
	for (int i = 0; i < MAX_ENEMIES; ++i) {
		if (enemy[i].active) { //�� Ȱ��ȭ
			DrawGyarados(g_hInst,mDC, monsterDirection, animationNum1);
			
		}
	}
}

void DrawEpicMonster(HDC mDC, HDC characterDC, HBITMAP hBitmapGyara, int x, int y) {
	SelectObject(characterDC, hBitmapGyara);;
	TransparentBlt(mDC, x, y, 50, 50, characterDC, 0, 0, 50, 50, RGB(255, 255, 255));
}