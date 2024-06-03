#pragma comment (lib, "msimg32.lib")
#include <windows.h>
#include "Map.h"
//#include "Monsters.h"
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

int C_direction = 1;		//캐릭터 방향	
int animationNum = 0;		//캐릭터 애니매이션
int x = 575;				//캐릭터 위치
int y = 320;

//맵 선택
int maptype = 1;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hDC, mDC, characterDC;
	HBITMAP hBitmap;
	static int mx, my;								//마우스 입력
	static HBITMAP hbitmapMap0, hbitmapWall0, hbitmapWall1, hbitmapWall2;
	static HBITMAP  hBitmapCharacter, hBitmapPause;
	RECT rt;
	static int Timer1Count, gamePlayminute = 0;		//게임 플레이 타이머
	static int pauseCount = 0;

	switch (uMsg) {
	case WM_CREATE:
		hbitmapMap0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		hBitmapCharacter = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP17));
		hbitmapWall0 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP23));
		hbitmapWall1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP24));
		hbitmapWall2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP25));
		hBitmapPause = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP58));

		SetTimer(hWnd, 2, 500, NULL); // 캐릭터 애니메이션 타이머
		SetTimer(hWnd, 1, 100, NULL);
		break;
	case WM_PAINT:
		GetClientRect(hWnd, &rt);
		hDC = BeginPaint(hWnd, &ps);
		mDC = CreateCompatibleDC(hDC);	//더블 버퍼링
		characterDC = CreateCompatibleDC(mDC);
		hBitmap = CreateCompatibleBitmap(hDC, rt.right, rt.bottom);
		SelectObject(mDC, (HBITMAP)hBitmap);
		SelectObject(characterDC, (HBITMAP)hBitmapCharacter);
		Rectangle(mDC, 0, 0, rt.right, rt.bottom);


		//맵그리기 
		if (maptype == 0)
		{
			DrawGrassMap(mDC, hbitmapMap0, hbitmapWall0, hbitmapWall1, hbitmapWall2);
		}
		else if(maptype == 1){	
			DrawWaterMap(mDC, g_hInst);
		}
		else if (maptype == 2) {
			DrawFireMap(mDC, g_hInst);
		}
		else if (maptype == 4) {
			DrawPauseMenu(mDC);
		}
		
		//stage UI
		DrawEXP_Bar(mDC);
		TimeBar(mDC, Timer1Count, gamePlayminute);
		DrawPauseBar(mDC, hBitmapPause);

		GetCharacterImage(C_direction, animationNum, &hBitmapCharacter, g_hInst);
		DrawCharacter(mDC, characterDC, hBitmapCharacter, x, y);

		BitBlt(hDC, 0, 0, rt.right, rt.bottom, mDC, 0, 0, SRCCOPY);
		DeleteDC(mDC);
		DeleteDC(characterDC);
		DeleteObject(hBitmap);
		EndPaint(hWnd, &ps);
		break;
	case WM_KEYDOWN:
		switch (wParam) {
		case VK_UP:
			C_direction = 0;
			break;
		case VK_DOWN:
			C_direction = 1;
			break;
		case VK_RIGHT:
			C_direction = 3;
			break;
		case VK_LEFT:
			C_direction = 2;
			break;
		case VK_ESCAPE:
			KillTimer(hWnd, 1);
			break;
			SetTimer(hWnd, 1, 100, NULL);
		}
		InvalidateRect(hWnd, NULL, false);
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
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_LBUTTONDOWN:
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
		}
		InvalidateRect(hWnd, NULL, false);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}