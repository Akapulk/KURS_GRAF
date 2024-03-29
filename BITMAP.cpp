#include "BITMAP.h"

BitMap::BitMap(int w, int h, int x0, int y0, COLORREF col) : width(w), height(h), x(x0), y(y0) {
	hDC = GetDC(GetConsoleWindow());
	color = col;
	mapIMG = new COLORREF[width * height * k];
	for (int i = 0; i < width * height * k; ++i)
		mapIMG[i] = col;
	bmp = { 0, w, h, 32 * w, 1, 32, NULL };
	bmp.bmBits = (COLORREF*)mapIMG;
}
BitMap::~BitMap() {
	delete[] mapIMG;
}
COLORREF& BitMap::operator()(int i, int j) {
	return mapIMG[i * width * k + j];
}
void BitMap::line(int x0, int y0, int x1, int y1, COLORREF col) {
	int
		d = 0,
		dy = (y1 - y0 > 0) ? dy = 1 : dy = -1,
		dx = (x1 - x0 > 0) ? dx = 1 : dx = -1,
		lengthX = abs(x1 - x0),
		lengthY = abs(y1 - y0),
		length = max(lengthX, lengthY);
	if (x0 >= 0 && y0 >= 0 && x0 < width && y0 < height) mapIMG[y0 * width * k + x0] = col;
	if (lengthX >= lengthY) {
		while(length--) {
			d += lengthY;
			if (d >= lengthX) {
				y0 += dy;
				d -= lengthX;
			}
			x0 += dx;
			if (x0 >= 0 && y0 >= 0 && x0 < width && y0 < height) mapIMG[y0 * width * k + x0] = col;
		}
	}
	else {
		while(length--) {
			d += lengthX;
			if (d >= lengthY) {
				x0 += dx;
				d -= lengthY;
			}
			y0 += dy;
			if (x0 >= 0 && y0 >= 0 && x0 < width && y0 < height) mapIMG[y0 * width * k + x0] = col;
		}
	}
}
void BitMap::clear(int x0, int y0, int x1, int y1) {
	for (int j; y0 <= y1; ++y0) {
		for (j = x0; j <= x1; ++j)
			mapIMG[y0 * width * k + j] = color;
	}
}
void BitMap::DrawBitmap() {
	hBitmap = CreateBitmapIndirect(&bmp);

	// ������� �������� ������, �����������
	// � ���������� �����������
	hMemDC = CreateCompatibleDC(hDC);

	// �������� ����������� bitmap � �������� ������
	hOldbm = (HBITMAP)SelectObject(hMemDC, hBitmap);

	// ���� �� ���� ������, ���������� ������
	if (hOldbm) {
		// ��� ��������� ������ ������������� ��� ��
		// ����� �����������, ��� ������������ �
		// ��������� �����������
		SetMapMode(hMemDC, GetMapMode(hDC));

		// ���������� ������� �����������
		GetObject(hBitmap, sizeof(BITMAP), (COLORREF*)&bm);

		ptSize.x = bm.bmWidth;   // ������
		ptSize.y = bm.bmHeight;  // ������

		// ����������� ���������� ���������� � ����������
		// ��� ���������� ������
		DPtoLP(hDC, &ptSize, 1);

		ptOrg.x = 0;
		ptOrg.y = 0;

		// ����������� ���������� ���������� � ����������
		// ��� ��������� ������
		DPtoLP(hMemDC, &ptOrg, 1);

		// ������ ����������� bitmap
		BitBlt(hDC, x, y, ptSize.x, ptSize.y,
			hMemDC, ptOrg.x, ptOrg.y, SRCCOPY);

		// ��������������� �������� ������
		SelectObject(hMemDC, hOldbm);
	}
	else {
		system("pause");
	}
	// ������� �������� ������
	DeleteDC(hMemDC);
	DeleteObject(hBitmap);
}