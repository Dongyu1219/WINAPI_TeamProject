#include "windows.h"
#include "resource1.h"

#define WIDTH  100		// x 24
#define HEIGHT 67		//1608

static HBITMAP hbitmapMap1, hbitmapMap2, hbitmapWaterWall0, hbitmapWaterWall1, hbitmapWaterWall2, hbitmapWaterWall3, hbitmapWaterWall4;
static HBITMAP hUpgradeMenu;

void DrawGrassMap(HDC mDC, HBITMAP hbitmapMap0) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap0);
	StretchBlt(mDC, 0, 0, 2400, 1608, hmemDC, 0, 0, 240, 160, SRCCOPY);

	DeleteDC(hmemDC);
}

void DrawWaterMap(HDC mDC, HBITMAP hbitmapMap0) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap0);
	StretchBlt(mDC, 0, 0, 2400, 1608, hmemDC, 0, 0, 240, 160, SRCCOPY);

	DeleteDC(hmemDC);
}

void DrawFireMap(HDC mDC, HBITMAP hbitmapMap0) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap0);
	StretchBlt(mDC, 0, 0, 2400, 1608, hmemDC, 0, 0, 240, 160, SRCCOPY);
	DeleteDC(hmemDC);
}


//189
void DrawUpgradeMenu(HDC mDC, HINSTANCE g_hInst){
	HDC hmemDC = CreateCompatibleDC(mDC);
	hUpgradeMenu = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP189));
	SelectObject(hmemDC, hUpgradeMenu);
	StretchBlt(mDC, 10, 25, 1160, 740, hmemDC, 0, 0, 255, 182, SRCCOPY);
	DeleteDC(hmemDC);
}