#include <windows.h>
#include <time.h>
#include <tchar.h>
#include <random>
#include "resource1.h"
#include "math.h"
#include "Skill.h"


#define PI 3.14159265

static HBITMAP hSkillMenu1, hSkillMenu2, hSkillMenu3;	//190 191 192
//193 �
//194 ��ȭ�� ��
//195 �ν�Ʈ ��


void DrawHpBox(HDC mDC, int x, int y, int MaxHp, int currentHp) {
	Rectangle(mDC, x + 22 - MaxHp, y - 12, x + 22 + MaxHp, y  - 5);

	HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);
	Rectangle(mDC, x + 22 - MaxHp, y - 12, x + 22 + currentHp-1, y - 5);
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
void skillChoices0(HDC mDC, int SKILLS, HINSTANCE g_hInst) {
	HDC hmemDC = CreateCompatibleDC(mDC);
HFONT hFont, hFont1, oldfont;
hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
hFont1 = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP190));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 230, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP197));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 510, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP193));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 790, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);


		oldfont = (HFONT)SelectObject(mDC, hFont);
		TextOut(mDC, 270, 330, L"��ó��", lstrlen(L"��ó��"));
		SelectObject(mDC, oldfont);
		oldfont = (HFONT)SelectObject(mDC, hFont1);
		TextOut(mDC, 210, 430, L"�ִ� ü���� �����մϴ�.", lstrlen(L"�ִ� ü���� �����մϴ�."));
		SelectObject(mDC, oldfont);

		oldfont = (HFONT)SelectObject(mDC, hFont);
		TextOut(mDC, 270+250, 330, L"������ ����", lstrlen(L"������ ����"));
		SelectObject(mDC, oldfont);
		oldfont = (HFONT)SelectObject(mDC, hFont1);
		TextOut(mDC, 210+300, 425, L"������ ����̵���", lstrlen(L"������ ����̵���"));
		TextOut(mDC, 210 + 300, 445, L"�����մϴ�.", lstrlen(L"�����մϴ�."));
		SelectObject(mDC, oldfont);

		oldfont = (HFONT)SelectObject(mDC, hFont);
		TextOut(mDC, 270 + 260+260, 330, L"���׸� ����", lstrlen(L"���׸� ����"));
		SelectObject(mDC, oldfont);
		oldfont = (HFONT)SelectObject(mDC, hFont1);
		TextOut(mDC, 210 + 280+305, 425, L"�����ϰ� ���", lstrlen(L"�����ϰ� ���"));
		TextOut(mDC, 210 + 280 + 320, 445, L"�����ϴ�.", lstrlen(L"�����ϴ�."));
		SelectObject(mDC, oldfont);

		DeleteDC(hmemDC);
		DeleteObject(hFont);
}
void skillChoices1(HDC mDC, int SKILLS, HINSTANCE g_hInst) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	HFONT hFont, hFont1, oldfont;
	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
	hFont1 = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP193));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 230, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP191));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 510, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP195));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 790, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);


	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 240 , 330, L"���׸� ����+", lstrlen(L"���׸� ����+"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210 , 430, L"�� ū ��� �����ϴ�.", lstrlen(L"�� ū ��� �����ϴ�."));
	SelectObject(mDC, oldfont);

	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 270+255, 330, L"���� ��ó��", lstrlen(L"���� ��ó��"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210+270, 430, L"�ִ� ü���� �����մϴ�.", lstrlen(L"�ִ� ü���� �����մϴ�."));
	SelectObject(mDC, oldfont);

	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 270 + 260 + 260, 330, L"��-������", lstrlen(L"��-������"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210 + 270 + 300, 430, L"�������� �����մϴ�.", lstrlen(L"�������� �����մϴ�."));
	SelectObject(mDC, oldfont);

	DeleteDC(hmemDC);
	DeleteObject(hFont);
}
void skillChoices2(HDC mDC, int SKILLS, HINSTANCE g_hInst) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	HFONT hFont, hFont1, oldfont;
	hFont = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
	hFont1 = CreateFont(20, 0, 0, 0, 0, 0, 0, 0, HANGEUL_CHARSET, 0, 0, 0, 0, _T("�ü�"));
	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP192));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 230, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP195));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 510, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);

	hSkillMenu1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP193));
	SelectObject(hmemDC, hSkillMenu1);
	StretchBlt(mDC, 790, 140, 160, 160, hmemDC, 0, 0, 160, 160, SRCCOPY);


	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 250, 330, L"��� ��ó��", lstrlen(L"��� ��ó��"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210, 430, L"�ִ� ü���� �����մϴ�.", lstrlen(L"�ִ� ü���� �����մϴ�."));
	SelectObject(mDC, oldfont);

	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 270 + 240, 330, L"��-������++", lstrlen(L"��-������++"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210 + 280 , 430, L"�������� �����մϴ�.", lstrlen(L"�������� �����մϴ�."));
	SelectObject(mDC, oldfont);

	oldfont = (HFONT)SelectObject(mDC, hFont);
	TextOut(mDC, 270 + 240 + 260, 330, L"���׸� ����++", lstrlen(L"���׸� ����++"));
	SelectObject(mDC, oldfont);
	oldfont = (HFONT)SelectObject(mDC, hFont1);
	TextOut(mDC, 210 + 280 + 280, 425, L"�� ū ���", lstrlen(L"�� ū ���"));
	TextOut(mDC, 210 + 310 + 340, 445, L"�����ϴ�.", lstrlen(L"�����ϴ�."));
	SelectObject(mDC, oldfont);

	DeleteDC(hmemDC);
	DeleteObject(hFont);
}


void DrawBomb(HINSTANCE g_hInst, HDC mDC, int MAX_BOMB, Bomb bomb, HBITMAP* hBomb, int animationNum) {
	srand((unsigned)time(NULL));
	HDC hDC = CreateCompatibleDC(mDC);
	int bombx, bomby;
	int rr;

	rr = rand() % 100;
	bombx = rand() % 1100 + 100;
	bomby = rand() % 600 + 100;

	if (*hBomb) {
		DeleteObject(*hBomb);
	}

	if (animationNum == 0) {
		*hBomb = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP222));
	}
	else if (animationNum == 1) {
		*hBomb = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP223));
	}

	SelectObject(hDC, *hBomb);
	TransparentBlt(mDC, bombx, bomby, 66, 116, hDC, 0, 0, 66, 116, RGB(255, 255, 255));


	DeleteDC(hDC);
}


void DrawRotatingBullet(HDC mDC, int mainx, int mainy, int angle) {
	HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255)); // ���ο� ��ü �����: �귯��
	HBRUSH oldBrush = (HBRUSH)SelectObject(mDC, hBrush);

	for (int j = 6; j > 0; j--)
	{

			for (int i = 0; i < j; i++)
			{
				Ellipse(mDC, mainx-12  + 40 * cos(angle + (PI / 3) * i) - 7+50, mainy  + 40 * sin(angle + (PI / 3) * i) - 7 + 50, mainx-12  + 40 * cos(angle + (PI / 3) * i) + 7 + 50, mainy  + 40 * sin(angle + (PI / 3) * i) + 7 + 50);
			}
	}

	SelectObject(mDC, oldBrush);

	DeleteObject(hBrush);

}
