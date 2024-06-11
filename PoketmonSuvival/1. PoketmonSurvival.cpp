#pragma comment (lib, "msimg32.lib")
#include <windows.h>
#include "Map.h"
#include "Monsters.h"
#include "StageUI.h"
#include "Player.h"
#include "resource1.h"

//WIDTH  200
//HEIGHT 100

HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Poketmon Survival";

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);

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

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC, mDC, characterDC, mapDC;
	HBITMAP hBitmap;
	static int mx, my;								//마우스 입력
	static HBITMAP hbitmapMap0, hbitmapWall0, hbitmapWall1, hbitmapWall2;
	static HBITMAP  hBitmapCharacter, hBitmapPause, hBitmapMap;
	static HBITMAP hBitmapSavedMap = NULL;
	RECT rt;
	static int Timer1Count, gamePlayminute = 0;		//게임 플레이 타이머
	static int pauseCount = 0;

	static RECT rect = { 600, 400, 1800, 1200 };

	static int C_direction = 1;		//캐릭터 방향	
	static int animationNum, animationNum1 = 0;		//캐릭터 애니매이션
	static int x = 575;				//캐릭터 위치
	static int y = 320;
	static int mainx = 575;				//캐릭터 초기위치
	static int mainy = 320;
	static int begin = 0;

	static int monsterDirection = -1;

	switch (uMsg) {
	case WM_CREATE:
		hbitmapMap0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		hbitmapWall0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP23));
		hbitmapWall1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP24));
		hbitmapWall2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP25));
		hBitmapPause = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP58));
		SetTimer(hWnd, 3, 1000, NULL); // Prsee 'p' to Start 타이머
		break;
	case WM_PAINT:
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

		if(pDown == 0) { // 시작 화면
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
			} else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP96));
			SelectObject(IntroDC, hBitmap);
			TransparentBlt(hDC, 200, 300, 200, 200, IntroDC, 0, 0, 39, 39, RGB(255, 255, 255));

			if (characterNum == 2) {
				hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP97)); // 파이리
			} else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP98));
			SelectObject(IntroDC, hBitmap);
			TransparentBlt(hDC, 500, 300, 200, 200, IntroDC, 0, 0, 58, 58, RGB(255, 255, 255));

			if (characterNum == 3) {
				hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP99)); // 꼬부기
			} else hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP100));
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
		
			// 저장된 맵 비트맵을 사용하여 그리기
			SelectObject(mapDC, hBitmapSavedMap);
			StretchBlt(mDC, 0, 0, rt.right, rt.bottom, mapDC, rect.left, rect.top, 1200, 800, SRCCOPY);

			//stage UI
			DrawEXP_Bar(mDC);
			TimeBar(mDC, Timer1Count, gamePlayminute);
			DrawPauseBar(mDC, hBitmapPause);
			//캐릭터
			GetCharacterImage(C_direction, animationNum, &hBitmapCharacter, g_hInst, characterNum);
			DrawCharacter(mDC, characterDC, hBitmapCharacter, x, y);
			//몬스터
			CreateEnemy(hWnd);
			DrawMon(g_hInst, mDC, monsterDirection, animationNum1);
			MoveEnemies(x, y, monsterDirection);

			//멈춤pause
			if (maptype == 4) {
				DrawPauseMenu(mDC, g_hInst);
			}

			BitBlt(hDC, 0, 0, rt.right, rt.bottom, mDC, 0, 0, SRCCOPY);

			DeleteObject(hBitmap);
			DeleteObject(hBitmapMap);
			DeleteDC(mDC);
			DeleteDC(mapDC);
			DeleteDC(characterDC);
			EndPaint(hWnd, &ps);
		}
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_UP:
			if (up == 0) {
				C_direction = 0;
				SetTimer(hWnd, 4, 10, NULL);
				up = 1;
			}
			break;
		case VK_DOWN:
			if (down == 0) {
				C_direction = 1;
				SetTimer(hWnd, 5, 10, NULL);
				down = 1;
			}
			break;
		case VK_RIGHT:
			if (right == 0) {
				C_direction = 3;
				SetTimer(hWnd, 7, 10, NULL);
				right = 1;
			}
			break;
		case VK_LEFT:
			if (left == 0) {
				C_direction = 2;
				SetTimer(hWnd, 6, 10, NULL);
				left = 1;
			}
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
				SetTimer(hWnd, 10, 500, NULL);
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
		case VK_UP:
			KillTimer(hWnd, 4);
			up = 0;
			break;
		case VK_DOWN:
			KillTimer(hWnd, 5);
			down = 0;
			break;
		case VK_LEFT:
			KillTimer(hWnd, 6);
			left = 0;
			break;
		case VK_RIGHT:
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
			UpdateCharacter(C_direction, &x, &y, &rect);
			break;
		case 8:				//몬스터 생성 타이머 
			if (maptype == 1) {
				CreateEnemy(hWnd);
				break;
			}
			else if (maptype == 2) {
				CreateEnemy(hWnd);
				break;
			}
			else if (maptype == 3) {
				CreateEnemy(hWnd);
				break;
			}
			break;
		case 10:		//중형 몬스터 움직임
			if (animationNum1 == 0) {
				animationNum1 = 1;
			}
			else if(animationNum1 ==1) {
				animationNum1 = 2;
			}
			else{
				animationNum1 = 0;
			}
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
			else if ((250 < mx && mx < 350) && (270 < my && my < 370)) {											// 계속
				SetTimer(hWnd, 1, 100, NULL);
				maptype = 1;
			}
			else if ((850 < mx && mx < 950) && (270 < my && my < 370)) {											// 종료
				PostQuitMessage(0);
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