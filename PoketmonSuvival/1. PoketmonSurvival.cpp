#pragma comment (lib, "msimg32.lib")
#include <windows.h>
#include <time.h>
#include <random>
#include "Map.h"
#include "Skill.h"
#include "Monsters.h"
#include "StageUI.h"
#include "Player.h"
#include "resource1.h"

//WIDTH  200
//HEIGHT 100
#define MAX_BULLETS 200 // 총알 개수

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Poketmon Survival";

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

void ColpsWithEnemy();
void ColpsWithBullet();
void DropExp(int type, int x, int y);
void GetExp();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)

{
	HWND hWnd;
	MSG Message;
	WNDCLASSEX WndClass;
	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_HAND);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_QUESTION);
	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPEDWINDOW, 50, 0, 1200, 800, NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, 0, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return Message.wParam;
}

// 총알
Bullet bullet[MAX_BULLETS];
Enemy enemy[MAX_ENEMIES];
Exp expnc[100];

// 시작 인트로
int intro = 0;
int pDown = 0;
int TextCount = 0;

//맵 선택
int maptype = 1;

// 방향키
int up = 0;
int down = 0;
int right = 0;
int left = 0;

// 캐릭터 선택
int characterNum = 0;
int characterHalfWidth = 25;
int x = 575;				//캐릭터 위치
int y = 320;

// 진화
int evolution = 2;
int level = 1;

//총알 데미지
int damage = 50;

//===============증강===============
int currentEXP = 0;		//경험치
int MaxHp = 22;				//체력 
int currentHp = MaxHp;
int bulletLevel = 1;			//공격

int enemySpawnTime = 6000;
int monsterDirection = 3; 
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	srand((unsigned)time(NULL));
	PAINTSTRUCT ps;
	HDC hDC, mDC, characterDC, mapDC;
	HBITMAP hBitmap;
	static int mx, my;								//마우스 입력
	static HBITMAP hbitmapMap0, hbitmapWall0, hbitmapWall1, hbitmapWall2;
	static HBITMAP  hBitmapCharacter, hBitmapPause, hBitmapMap;
	static HBITMAP hBitmapSavedMap = NULL;
	static HBITMAP BasicMonster, hBitmapMonster;
	static HBITMAP hBitmapBullet;
	RECT rt;
	static int Timer1Count, gamePlayminute = 0;		//게임 플레이 타이머
	static int pauseCount = 0;
	static int pauseMouse = 0;

	static RECT rect = { 600, 400, 1800, 1200 };

	static int C_direction = 1;		//캐릭터 방향	
	static int animationNum = 0;		//캐릭터 애니매이션
	static int mainx = 575;				//캐릭터 초기위치
	static int mainy = 320;
	static int begin = 0;

	switch (uMsg) {
	case WM_CREATE: {
		hbitmapMap0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		hbitmapWall0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP23));
		hbitmapWall1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP24));
		hbitmapWall2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP25));
		hBitmapPause = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP58));
		SetTimer(hWnd, 3, 1000, NULL); // Prsee 'p' to Start 타이머
		// 총알 초기화
		for (int i = 0; i < MAX_BULLETS; i++) {
			bullet[i].active = false;
		}
	}
		break;

	case WM_PAINT: {
		GetClientRect(hWnd, &rt);
		hDC = BeginPaint(hWnd, &ps);
		mDC = CreateCompatibleDC(hDC);	//더블 버퍼링
		characterDC = CreateCompatibleDC(mDC);
		mapDC = CreateCompatibleDC(hDC);
		hBitmapMap = CreateCompatibleBitmap(hDC, 2400, 1608);
		hBitmap = CreateCompatibleBitmap(hDC, rt.right, rt.bottom);
		SelectObject(mDC, (HBITMAP)hBitmap);
		SelectObject(characterDC, (HBITMAP)hBitmapCharacter);
		SelectObject(mapDC, (HBITMAP)hBitmapMap);
		Rectangle(mDC, 0, 0, rt.right, rt.bottom);
		Rectangle(mapDC, 0, 0, 2600, 1608);

		if (intro == 0) {
			HDC IntroDC = CreateCompatibleDC(hDC);
			HBITMAP hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP59)); // 포켓몬 로고 이미지

			int speed = 100;

			SelectObject(IntroDC, hBitmap);
			StretchBlt(hDC, 0, 0, 1200, 800, IntroDC, 0, 0, 251, 190, SRCCOPY);
			Sleep(1000);

			hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP60)); // s1
			SelectObject(IntroDC, hBitmap);
			StretchBlt(hDC, 0, 0, 1200, 800, IntroDC, 0, 0, 251, 190, SRCCOPY);
			Sleep(speed);

			for (int i = 0; i < 17; i++) {
				hBitmap = LoadBitmap(g_hInst, (LPCWSTR)(161 + i)); //
				SelectObject(IntroDC, hBitmap);
				StretchBlt(hDC, 0, 0, 1200, 800, IntroDC, 0, 0, 256, 190, SRCCOPY);
				Sleep(speed);
			}
			intro = 1;
			DeleteDC(IntroDC);
		}
		if (pDown == 0) { // 시작 화면
			HFONT hFont, oldFont;
			HDC IntroDC = CreateCompatibleDC(hDC);
			HBITMAP hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP59)); // 포켓몬 로고 이미지
			hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP77));
			SelectObject(IntroDC, hBitmap);
			StretchBlt(hDC, 0, 0, 1200, 800, IntroDC, 0, 0, 1321, 931, SRCCOPY);

			SetBkMode(hDC, TRANSPARENT);
			SetTextColor(hDC, RGB(0, 0, 0));
			hFont = CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Courier New");
			oldFont = (HFONT)SelectObject(hDC, hFont);
			if (TextCount == 0) {
				TextOut(hDC, 55, 605, L"Press 'P' to Start", lstrlen(L"Press 'P' To Start"));
				SetTextColor(hDC, RGB(255, 255, 255));
				hFont = CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Courier New");
				oldFont = (HFONT)SelectObject(hDC, hFont);
				TextOut(hDC, 50, 600, L"Press 'P' to Start", lstrlen(L"Press 'P' To Start"));
			}

			DeleteDC(IntroDC);
			SelectObject(hDC, oldFont);
			DeleteObject(hFont);
		}
		else if (pDown == 1) { // 캐릭터 선택 화면
			HDC IntroDC = CreateCompatibleDC(hDC);
			HBITMAP hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP94)); // 포켓몬 선택 이미지
			HBRUSH hBrush, oldBrush;
			HFONT hFont, oldFont;
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			oldBrush = (HBRUSH)SelectObject(hDC, hBrush);
			SelectObject(IntroDC, hBitmap);
			StretchBlt(hDC, 0, 0, 1200, 800, IntroDC, 0, 0, 254, 204, SRCCOPY);

			if (characterNum == 1) {
				hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP95)); // 이상해씨
			}
			else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP96));
			SelectObject(IntroDC, hBitmap);
			TransparentBlt(hDC, 200, 300, 200, 200, IntroDC, 0, 0, 39, 39, RGB(255, 255, 255));

			if (characterNum == 2) {
				hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP97)); // 파이리
			}
			else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP98));
			SelectObject(IntroDC, hBitmap);
			TransparentBlt(hDC, 500, 300, 200, 200, IntroDC, 0, 0, 58, 58, RGB(255, 255, 255));

			if (characterNum == 3) {
				hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP99)); // 꼬부기
			}
			else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP100));
			SelectObject(IntroDC, hBitmap);
			TransparentBlt(hDC, 800, 300, 200, 200, IntroDC, 0, 0, 54, 54, RGB(255, 255, 255));

			hFont = CreateFont(100, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
			oldFont = (HFONT)SelectObject(hDC, hFont);
			SetBkColor(hDC, RGB(0, 0, 0));
			SetTextColor(hDC, RGB(255, 255, 255));
			hFont = CreateFont(50, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial");
			oldFont = (HFONT)SelectObject(hDC, hFont);
			TextOut(hDC, 800, 600, L"Press 'P' To Start", lstrlen(L"Press 'P' To Start"));
			DeleteDC(IntroDC);
			SelectObject(hDC, oldBrush);
			DeleteObject(hBrush);
			SelectObject(hDC, oldFont);
			DeleteObject(hFont);
		}
		else {
			if (hBitmapSavedMap == NULL) {
				// 맵을 한 번만 그리기
				hBitmapSavedMap = CreateCompatibleBitmap(hDC, 2400, 1608);
				HDC tempMapDC = CreateCompatibleDC(hDC);
				SelectObject(tempMapDC, hBitmapSavedMap);

				if (maptype == 0) {
					DrawGrassMap(tempMapDC, hbitmapMap0, hbitmapWall0, hbitmapWall1, hbitmapWall2);
				}
				else if (maptype == 1) {
					DrawWaterMap(tempMapDC, g_hInst);
				}
				else if (maptype == 2) {
					DrawFireMap(tempMapDC, g_hInst);
				}
				DeleteDC(tempMapDC);
			}

			GetExp();
			if (currentEXP >= 1100) {
				level = 10;
			}
			else if (currentEXP >= 1000) {
				level = 9;
			}
			else if (currentEXP >= 900) {
				level = 8;
			}
			else if (currentEXP >= 800) {
				level = 7;
				evolution = 3;
				bulletLevel = 3;
			}
			else if (currentEXP >= 700) {
				level = 6;
			}
			else if (currentEXP >= 600) {
				level = 5;
			}
			else if (currentEXP >= 500) {
				level = 4;
				evolution = 2;
			}
			else if (currentEXP >= 400) {
				level = 3;
			}
			else if (currentEXP >= 300) {
				level = 2;
			}

			// 저장된 맵 비트맵을 사용하여 그리기
			SelectObject(mapDC, hBitmapSavedMap);
			StretchBlt(mDC, 0, 0, rt.right, rt.bottom, mapDC, rect.left, rect.top, 1200, 800, SRCCOPY);

			DrawExp(expnc, mDC, g_hInst);

			//캐릭터
			GetCharacterImage(C_direction, animationNum, &hBitmapCharacter, g_hInst, characterNum, evolution);
			DrawCharacter(mDC, characterDC, hBitmapCharacter, x, y, evolution);

			//몬스터
			for (int i = 0; i < MAX_ENEMIES; i++) {
				if (enemy[i].active) {
					// 플레이어의 위치와 적의 위치를 비교

					if (enemy[i].y < y) { // 플레이어가 아래쪽에 있으면
						enemy[i].y++; // 적을 아래쪽으로 이동
						enemy[i].monsterDirection = 1;
					}
					else if (enemy[i].y > y) {
						enemy[i].y--;	//위
						enemy[i].monsterDirection = 0;
					}

					if (enemy[i].x < x) { // 플레이어가 오른쪽에 있으면
						enemy[i].x++; // 적을 오른쪽으로 이동
						enemy[i].monsterDirection = 3;
					}
					else if (enemy[i].x > x) {
						enemy[i].x--;
						enemy[i].monsterDirection = 2;
					}

					if (enemy[i].type == 0) {
						GetGhostImage(g_hInst, mDC, enemy[i].monsterDirection, animationNum, &hBitmapMonster);
						DrawGhost(mDC, enemy[i].x, enemy[i].y, hBitmapMonster, enemy[i].monsterDirection);
					}
					else if (enemy[i].type == 1) {
						GetGhoustImage(g_hInst, mDC, enemy[i].monsterDirection, animationNum, &hBitmapMonster);
						DrawGhoust(mDC, enemy[i].x, enemy[i].y, hBitmapMonster, enemy[i].monsterDirection);
					}
					else {
						GetPhantomImage(g_hInst, mDC, enemy[i].monsterDirection, animationNum, &hBitmapMonster);
						DrawPhantom(mDC, enemy[i].x, enemy[i].y, hBitmapMonster, enemy[i].monsterDirection);
					}
				}
			}

			//증강
			// 총알 그리기
			DrawHpBox(mDC, x, y, MaxHp, currentHp);
			DrawBullets(g_hInst, mDC, MAX_BULLETS, bullet, bulletLevel, &hBitmapBullet);

			//멈춤pause
			if (maptype == 4) {
				//DrawPauseMenu(mDC, g_hInst);
				//pauseMouseMove(mDC, g_hInst, pauseMouse);
			}

			//stage UI
			DrawEXP_Bar(mDC, g_hInst, currentEXP, level);
			TimeBar(mDC, Timer1Count, gamePlayminute);
			//DrawPauseBar(mDC, hBitmapPause);
			//DrawMiniMap(mDC, g_hInst, x, y);

			BitBlt(hDC, 0, 0, rt.right, rt.bottom, mDC, 0, 0, SRCCOPY);

			DeleteObject(hBitmap);
			DeleteObject(hBitmapMap);
			DeleteObject(hBitmapMonster);
			DeleteDC(mDC);
			DeleteDC(mapDC);
			DeleteDC(characterDC);
		}
	}
	EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case 'w': // 캐릭터 이동
		case 'W':
			if (up == 0) {
				C_direction = 0;
				SetTimer(hWnd, 4, 10, NULL);
				up = 1;
			}
			break;
		case 's':
		case 'S':
			if (down == 0) {
				C_direction = 1;
				SetTimer(hWnd, 5, 10, NULL);
				down = 1;
			}
			break;
		case 'd':
		case 'D':
			if (right == 0) {
				C_direction = 3;
				SetTimer(hWnd, 7, 10, NULL);
				right = 1;
			}
			break;
		case 'a':
		case 'A':
			if (left == 0) {
				C_direction = 2;
				SetTimer(hWnd, 6, 10, NULL);
				left = 1;
			}
			break;
		case VK_UP: // 총알 발사
			FireBullet(x + characterHalfWidth, y, 0, -10, MAX_BULLETS, bullet, 3);
			break;
		case VK_DOWN:
			FireBullet(x + characterHalfWidth, y + characterHalfWidth, 0, +10, MAX_BULLETS, bullet, 4);
			break;
		case VK_LEFT:
			FireBullet(x, y + characterHalfWidth, -10, 0, MAX_BULLETS, bullet, 2);
			break;
		case VK_RIGHT:
			FireBullet(x + characterHalfWidth*2, y + characterHalfWidth, 10, 0, MAX_BULLETS, bullet, 1);
			break;
		case 'P': 
		case 'p':
			if (pDown == 0) {
				pDown = 1;
				KillTimer(hWnd, 3);
			}
			else if (pDown == 1) {
				pDown = 2;
				SetTimer(hWnd, 2, 500, NULL); // 캐릭터 애니메이션 타이머
				SetTimer(hWnd, 1, 100, NULL); // 시간 타이머
				SetTimer(hWnd, 11, 50, NULL); // 총알 타이머
				SetTimer(hWnd, 10, 500, NULL);
				SetTimer(hWnd, 8, enemySpawnTime, NULL); // 몬스터 생성 타이머
			}
			break;
		case VK_ESCAPE:
			pauseCount++;
			if (pauseCount % 2) {
				KillTimer(hWnd, 1);
				maptype = 4;
			}
			else if (pauseCount % 2 == 0) {
				SetTimer(hWnd, 1, 100, NULL);
				maptype = 1;
			}
			break;
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_KEYUP:
		switch (wParam) {
		case 'w':
		case 'W':
			KillTimer(hWnd, 4);
			up = 0;
			break;
		case 's':
		case 'S':
			KillTimer(hWnd, 5);
			down = 0;
			break;
		case 'a':
		case 'A':
			KillTimer(hWnd, 6);
			left = 0;
			break;
		case 'd':
		case 'D':
			KillTimer(hWnd, 7);
			right = 0;
			break;
		}
		break;
	case WM_TIMER:
		switch (wParam) {
		case 1:
			Timer1Count++;
			if (Timer1Count > 59) {
				Timer1Count = 0;
				gamePlayminute++;
			}
			break;
		case 2: // 캐릭터 애니메이션 타이머
			if (animationNum == 0) {
				animationNum = 1;
			}
			else {
				animationNum = 0;
			}
			break;

		case 3: // Press 'p' to Start 타이머
			if (TextCount == 0) {
				TextCount = 1;
			}
			else TextCount = 0;
			break;
		case 4: // 방향키 타이머
		case 5:
		case 6:
		case 7:
			UpdateCharacter(C_direction, &x, &y, &rect, enemy, expnc);
			ColpsWithEnemy();
			break;
		case 8:				//몬스터 생성 타이머 
			for (int i = 0; i < MAX_ENEMIES; i++) {
				if (!enemy[i].active) {
					enemy[i].active = 1;
					CreateEnemy(hWnd, &(enemy[i].x), &(enemy[i].y), &(enemy[i].type), &(enemy[i].hp), evolution);
					break;
				}
			}
			enemySpawnTime = max(1000, enemySpawnTime - 100); // 점점 생성 시간 짧아짐, 최소 1초
			break;

		case 10:		//중형 몬스터 움직임


			break;
		case 11: // 총알 타이머
			UpdateBullets(MAX_BULLETS, bullet);
			ColpsWithBullet();
			break;
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_LBUTTONDOWN:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (pDown == 1) { // 포켓몬 선택
			mx = LOWORD(lParam);
			my = HIWORD(lParam);
			if ((200 < mx && mx < 400) && (300 < my && my < 500)) { 
				characterNum = 1; 
				maptype = 0;
			}
			if ((500 < mx && mx < 700) && (300 < my && my < 500)) { 
				characterNum = 2; 
				maptype = 2;
			}
			if ((800 < mx && mx < 1000) && (300 < my && my < 500)) { 
				characterNum = 3; 
				maptype = 1;
			}
		}
		else if (pDown == 2) {
			mx = LOWORD(lParam);
			my = HIWORD(lParam);

			if ((1120 < mx && mx < 1170) && (5 < my && my < 70)) {							//pause 버튼
				pauseCount++;
				if (pauseCount % 2) {
					KillTimer(hWnd, 1);
					maptype = 4;
				}
				else if (pauseCount % 2 == 0) {
					SetTimer(hWnd, 1, 100, NULL);
					maptype = 1;
				}
			} // Pause Button
		}
		//250, 270
		if (maptype == 4) {

			if ((550 < mx && mx < 650) && (270 < my && my < 370)) {													//다시	시작
				intro = 0;
				pDown = 0;
				x = 575;				//캐릭터 위치
				y = 320;
				Timer1Count, gamePlayminute = 0;
				KillTimer(hWnd, 1);
			}
			else if ((350 < mx && mx < 450) && (270 < my && my < 370)) {											// 계속
				SetTimer(hWnd, 1, 100, NULL);
				maptype = 1;
			}
			else if ((750 < mx && mx < 850) && (270 < my && my < 370)) {											// 종료
				PostQuitMessage(0);
			}
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_MOUSEMOVE:
		mx = LOWORD(lParam);
		my = HIWORD(lParam);
		if (maptype == 4) {
			if ((550 < mx && mx < 650) && (270 < my && my < 370)) {													//다시	시작
				pauseMouse = 2;
				break;
			}
			else if ((350 < mx && mx < 450) && (270 < my && my < 370)) {											// 계속
				pauseMouse = 1;
				break;
				
			}
			else if ((750 < mx && mx < 850) && (270 < my && my < 370)) {											// 종료
				pauseMouse = 3;
				break;
			}
			else {
				pauseMouse = 0;
				break;
			}
		}
		InvalidateRect(hWnd, NULL, false);
			break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void ColpsWithBullet() {
	for (int i = 0; i <  MAX_BULLETS; i++) {
		if (bullet[i].active) {
			for (int j = 0; j < MAX_ENEMIES; j++) {
				if (enemy[i].active) {
					RECT rect, rect2;
					if (bulletLevel == 3) {
						switch (bullet[i].bulletDirection) { // rect 설정
						case 1:
							rect = { bullet[i].x, bullet[i].y,  bullet[i].x + 55,  bullet[i].x - 22 };
							break;
						case 2:
							rect = { bullet[i].x, bullet[i].y,  bullet[i].x + 55,  bullet[i].x - 22 };
							break;
						case 3:
							rect = { bullet[i].x, bullet[i].y,  bullet[i].x + 22,  bullet[i].x - 55 };
							break;
						case 4:
							rect = { bullet[i].x, bullet[i].y,  bullet[i].x + 22,  bullet[i].x - 55 };
							break;
						}
					}
					else {
						switch (bullet[i].bulletDirection) {
						case 1:
						case 2:
						case 3:
						case 4:
							rect = { bullet[i].x - 5, bullet[i].y - 5, bullet[i].x + 5, bullet[i].y + 5 };
							break;
						}
					}
					switch (enemy[i].type) { // rect2 설정
					case 0:
						rect2 = { enemy[j].x - 25, enemy[j].y - 25, enemy[j].x + 25, enemy[j].y + 25 };
						break;
					case 1:
						rect2 = { enemy[j].x - 35, enemy[j].y - 35, enemy[j].x + 35, enemy[j].y + 35 };
						break;
					case 2:
						rect2 = { enemy[j].x - 45, enemy[j].y - 45, enemy[j].x + 45, enemy[j].y + 45 };
						break;
					}

					if ((rect.right > rect2.right) && (rect.left < rect.right)
						&& (rect.bottom > rect2.top) && (rect.top < rect2.bottom)) {
						bullet[i].active = false;
						enemy[j].hp -= damage;
						if (enemy[j].hp <= 0) {
							enemy[i].active = false;
							DropExp(enemy[j].type, enemy[j].x, enemy[j].y);
						}
					}
				}
			}
		}
	}
}

void ColpsWithEnemy() {
	for (int j = 0; j < MAX_ENEMIES; j++) {
		if (enemy[j].active) {
			RECT rect, rect2;
			int damage1;
			switch (evolution) { //rect 설정
			case 1:
				rect = { x, y, x + 50, y + 50 };
				break;
			case 2:
				rect = { x, y, x + 70, y + 70 };
				break;
			case 3:
				rect = { x, y, x + 90, y + 90 };
				break;
			}
			switch (enemy[j].type) { // rect2 설정
			case 0:
				rect2 = { enemy[j].x - 25, enemy[j].y - 25, enemy[j].x + 25, enemy[j].y + 25 };
				damage1 = 3;
				break;
			case 1:
				rect2 = { enemy[j].x - 35, enemy[j].y - 35, enemy[j].x + 35, enemy[j].y + 35 };
				damage1 = 5;
				break;
			case 2:
				rect2 = { enemy[j].x - 45, enemy[j].y - 45, enemy[j].x + 45, enemy[j].y + 45 };
				damage1 = 7;
				break;
			}
			if ((rect.right > rect2.right) && (rect.left < rect.right)
				&& (rect.bottom > rect2.top) && (rect.top < rect2.bottom)) {
				if (currentHp > 0) {
					currentHp -= 3;
				}
			}
		}
	}
}

void DropExp(int type, int x1, int y2) {
	for (int i = 0; i < 100; i++) {
		if (!expnc[i].active) {
			expnc[i].active = true;
			expnc[i].type = type;
			expnc[i].x = x1;
			expnc[i].y = y2;
			break;
		}
	}
}

void GetExp() {
	for (int i = 0; i < 100; i++) {
		if (expnc[i].active) {
			RECT rect, rect2;
			int getExp = 0;

			switch (expnc[i].type) {
			case 0:
			case 1:
				rect = { expnc[i].x - 10, expnc[i].y - 10, expnc[i].x + 10, expnc[i].y + 10 };
				getExp = 100;
				break;
			case 2:
				rect = { expnc[i].x - 10, expnc[i].y - 10, expnc[i].x + 10, expnc[i].y + 10 };
				getExp = 400;
				break;
			}
			rect2 = { x, y, x + 50, y + 50 };
			if ((rect.right > rect2.right) && (rect.left < rect.right)
				&& (rect.bottom > rect2.top) && (rect.top < rect2.bottom)) {
				expnc[i].active = false;
				currentEXP += getExp;
			}
		}
	}
}