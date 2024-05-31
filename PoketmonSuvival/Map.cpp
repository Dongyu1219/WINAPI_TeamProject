#include "windows.h"

#define WIDTH  200		// x 24
#define HEIGHT 100

void DrawGrassMap(HDC mDC, HBITMAP hbitmapMap0) {
	HDC hmemDC = CreateCompatibleDC(mDC);
	SelectObject(hmemDC, hbitmapMap0);
	for (int mapRow = 0; mapRow < WIDTH; mapRow++)
	{
		for (int mapColumn = 0; mapColumn < HEIGHT; mapColumn++)
		{
			StretchBlt(mDC, 24 * mapRow, 24 * mapColumn, 24, 24, hmemDC, 0, 0, 24, 24, SRCCOPY);
		}
	}

	DeleteDC(hmemDC);
}
