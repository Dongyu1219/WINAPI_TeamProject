#include <windows.h>
#include "resource1.h"
#include "Skill.h"

void DrawHpBox(HDC mDC, int x, int y, int MaxHp, int currentHp) {
	Rectangle(mDC, x + 22 - MaxHp, y - 12, x + 22 + MaxHp, y  - 5);

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
	Rectangle(mDC, x + 22 - MaxHp, y - 12, x + 22 + currentHp-5, y - 5);
	SelectObject(mDC, oldBrush); 
	DeleteObject(hBrush); 
}

void FireBullet(int x, int y, int dx, int dy, int MAX_BULLETS, Bullet* bullets, int bulletDirection){
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (!bullets[i].active) {
			bullets[i].x = x;
			bullets[i].y = y;
			bullets[i].dx = dx;
			bullets[i].dy = dy;
			bullets[i].active = true;
			bullets[i].bulletDirection = bulletDirection;
			break;
		}
	}
}

void UpdateBullets(int MAX_BULLETS, Bullet* bullets) {
	for (int i = 0; i < MAX_BULLETS; i++) {
		if (bullets[i].active) {
			bullets[i].x += bullets[i].dx;
			bullets[i].y += bullets[i].dy;

			POINT point = { bullets[i].x, bullets[i].y };

			// �Ѿ��� ȭ�� ������ ������ ��Ȱ��ȭ
			if (bullets[i].x < 0 || bullets[i].x > 1200 || bullets[i].y < 0 || bullets[i].y > 800) {
				bullets[i].active = false;
			}
		}
	}
}

void DrawBullets(HINSTANCE g_hInst, HDC mDC, int MAX_BULLETS, Bullet* bullets, int bulletLevel, HBITMAP* hBitmapBullet) {

	for (int i = 0; i < MAX_BULLETS; i++) {
		HDC hDC = CreateCompatibleDC(mDC);

		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);

		if (bullets[i].active) {
			switch (bullets[i].bulletDirection) {
			case 1: // ������ ����
				if (bulletLevel == 1) {
					Ellipse(mDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				}
				else if (bulletLevel == 3) {
					if (*hBitmapBullet) {
						DeleteObject(*hBitmapBullet); // ���� ��Ʈ�� ����
					}
					*hBitmapBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP112));
					SelectObject(hDC, *hBitmapBullet);
					TransparentBlt(mDC, bullets[i].x, bullets[i].y, 54, 22, hDC, 0, 0, 54, 22, RGB(0, 248, 248));
				}
				break;
			case 2: // ���� ����
				if (bulletLevel == 1) {
					Ellipse(mDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				}
				else if (bulletLevel == 3) {
					if (*hBitmapBullet) {
						DeleteObject(*hBitmapBullet); // ���� ��Ʈ�� ����
					}
					*hBitmapBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP113));
					SelectObject(hDC, *hBitmapBullet);
					TransparentBlt(mDC, bullets[i].x, bullets[i].y, 55, 22, hDC, 0, 0, 55, 22, RGB(0, 248, 248));
				}
				break;

			case 3: // ���� ����
				if (bulletLevel == 1) {
					Ellipse(mDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				}
				else if (bulletLevel == 3) {
					if (*hBitmapBullet) {
						DeleteObject(*hBitmapBullet); // ���� ��Ʈ�� ����
					}
					*hBitmapBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP111));
					SelectObject(hDC, *hBitmapBullet);
					TransparentBlt(mDC, bullets[i].x-5, bullets[i].y, 22, 55, hDC, 0, 0, 22, 55, RGB(0, 248, 248));
				}
				break;
			case 4: 
				if (bulletLevel == 1) {
					Ellipse(mDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				}
				else if (bulletLevel == 3) {
					if (*hBitmapBullet) {
						DeleteObject(*hBitmapBullet); // ���� ��Ʈ�� ����
					}
					*hBitmapBullet = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP110));
					SelectObject(hDC, *hBitmapBullet);
					TransparentBlt(mDC, bullets[i].x-5, bullets[i].y, 22, 55, hDC, 0, 0, 22, 55, RGB(0, 248, 248));
				}
				break;

				//if (bullets[i].dx == -10) { // ����
				//	Ellipse(hDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				//}
				//else if (bullets[i].dx == 10) { // ������
				//	Ellipse(hDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				//}
				//else if (bullets[i].dy == 10) { // �Ʒ���
				//	Ellipse(hDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				//}
				//else if (bullets[i].dy == -10) { // ����
				//	Ellipse(hDC, bullets[i].x - 5, bullets[i].y - 5, bullets[i].x + 5, bullets[i].y + 5);
				//}
			}

		}

		SelectObject(mDC, oldBrush);
		DeleteObject(hBrush);
		DeleteDC(hDC);
		}
}
