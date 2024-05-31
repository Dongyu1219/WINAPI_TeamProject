#include "windows.h"

#define WIDTH  200		// x 24
#define HEIGHT 100

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
