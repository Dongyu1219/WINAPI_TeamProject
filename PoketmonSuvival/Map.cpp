#include "windows.h"
#include "resource1.h"

#define WIDTH  100		// x 24
#define HEIGHT 67		//1608

static HBITMAP hbitmapMap1, hbitmapMap2, hbitmapWaterWall0, hbitmapWaterWall1, hbitmapWaterWall2, hbitmapWaterWall3, hbitmapWaterWall4;

void DrawGrassMap(HDC mDC, HBITMAP hbitmapMap0, HBITMAP  hbitmapWall0, HBITMAP hbitmapWall1, HBITMAP hbitmapWall2) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap0);
	for (int mapRow = 0; mapRow < WIDTH; mapRow++)
	{
		for (int mapColumn = 0; mapColumn < HEIGHT; mapColumn++)
		{
			StretchBlt(mDC, 24 * mapRow, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		}
	}

	SelectObject(hmemDC, hbitmapWall0);
	StretchBlt(mDC, 0, 72, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);

	SelectObject(hmemDC, hbitmapWall1);
	for (int mapRow = 1; mapRow < 79; mapRow++)
	{
		StretchBlt(mDC, 24 * mapRow, 72, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
	}


	SelectObject(hmemDC, hbitmapWall2);
	for (int mapColumn = 4; mapColumn < 100; mapColumn++)
	{
		StretchBlt(mDC, 0, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
	}

	DeleteDC(hmemDC);
}


void DrawWaterMap(HDC mDC, HINSTANCE g_hInst) {

	hbitmapMap1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP51));
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap1);

	for (int mapRow = 0; mapRow < WIDTH; mapRow++)
	{
		for (int mapColumn = 0; mapColumn < HEIGHT; mapColumn++)
		{
			StretchBlt(mDC, 24 * mapRow, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		}
	}

	hbitmapWaterWall1 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP52));
	SelectObject(hmemDC, hbitmapWaterWall1);
	StretchBlt(mDC, 0, 72, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);

	hbitmapWaterWall3 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP53));
	SelectObject(hmemDC, hbitmapWaterWall3);
	for (int mapRow = 1; mapRow < 79; mapRow++)
	{
		StretchBlt(mDC, 24 * mapRow, 72, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		StretchBlt(mDC, 24 * mapRow, 66*24, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
	}

	hbitmapWaterWall2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP57));
	SelectObject(hmemDC, hbitmapWaterWall2);
	for (int mapColumn = 4; mapColumn < 100; mapColumn++)
	{
		StretchBlt(mDC, 0, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		StretchBlt(mDC, 2376, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
	}

	hbitmapWaterWall4 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP56));
	SelectObject(hmemDC, hbitmapWaterWall1);
	StretchBlt(mDC, 0, 66 * 24, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);

	hbitmapWaterWall4 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP55));
	SelectObject(hmemDC, hbitmapWaterWall1);
	StretchBlt(mDC, 2376, 66 * 24, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);


	DeleteDC(hmemDC);

}

void DrawFireMap(HDC mDC, HINSTANCE g_hInst) {
	hbitmapMap2 = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP50));
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap2);
	for (int mapRow = 0; mapRow < WIDTH; mapRow++)
	{
		for (int mapColumn = 0; mapColumn < HEIGHT; mapColumn++)
		{
			StretchBlt(mDC, 24 * mapRow, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		}
	}

	DeleteDC(hmemDC);
}