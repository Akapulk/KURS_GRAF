#include "pyramid_4.h"

pyramid_4::pyramid_4(BitMap* bmp, size_t numVer, size_t numFace)
	: figure(bmp, numVer, numFace) {


	Ver[0].setVector(290.0, 90.0, 90.0, 1.0);
	Ver[1].setVector(390.0, 90.0, 90.0, 1.0);
	Ver[2].setVector(395.0, 190.0, 90.0, 1.0);
	Ver[3].setVector(295.0, 190.0, 90.0, 1.0);
	Ver[4].setVector(320.0, 110.0, 190.0, 1.0);

	SetCenter();
	Body();
	Test();
	result = e * V;
	SetBitMap();
}
void pyramid_4::Body() {

	uint32_t i, j;

	double a, b, c, d;
	double t;


	j = 1;
	for (i = 0; i < 4; ++i, j = (j + 1) % 4) {

		d = 0;

		a = Ver[i][1] - Ver[j][1];
		a *= (Ver[4][2] - Ver[j][2]);
		t = Ver[i][2] - Ver[j][2];
		t *= (Ver[4][1] - Ver[j][1]);
		a -= t;
		d -= (a * Ver[j][0]);

		b = Ver[i][0] - Ver[j][0];
		b *= (Ver[4][2] - Ver[j][2]);
		t = Ver[i][2] - Ver[j][2];
		t *= (Ver[4][0] - Ver[j][0]);
		b = t - b;
		d -= (b * Ver[j][1]);

		c = Ver[i][0] - Ver[j][0];
		c *= (Ver[4][1] - Ver[j][1]);
		t = Ver[i][1] - Ver[j][1];
		t *= (Ver[4][0] - Ver[j][0]);
		c -= t;
		d -= (c * Ver[j][2]);

		V(0, i) = a;
		V(1, i) = b;
		V(2, i) = c;
		V(3, i) = d;

	}

	d = 0;

	a = Ver[2][1] - Ver[1][1];
	a *= (Ver[3][2] - Ver[1][2]);
	t = Ver[2][2] - Ver[1][2];
	t *= (Ver[3][1] - Ver[1][1]);
	a -= t;
	d -= (a * Ver[1][0]);

	b = Ver[2][0] - Ver[1][0];
	b *= (Ver[3][2] - Ver[1][2]);
	t = Ver[2][2] - Ver[1][2];
	t *= (Ver[3][0] - Ver[1][0]);
	b = t - b;
	d -= (b * Ver[1][1]);

	c = Ver[2][0] - Ver[1][0];
	c *= (Ver[3][1] - Ver[1][1]);
	t = Ver[2][1] - Ver[1][1];
	t *= (Ver[3][0] - Ver[1][0]);
	c -= t;
	d -= (c * Ver[1][2]);

	V(0, 4) = a;
	V(1, 4) = b;
	V(2, 4) = c;
	V(3, 4) = d;
}
void pyramid_4::ClrFigure() {

	paintTRIN(bmp, VerSHDW[0], VerSHDW[1], VerSHDW[4], COLORREF(COL_BMP::clear));
	paintTRIN(bmp, VerSHDW[1], VerSHDW[2], VerSHDW[4], COLORREF(COL_BMP::clear));
	paintTRIN(bmp, VerSHDW[2], VerSHDW[3], VerSHDW[4], COLORREF(COL_BMP::clear));
	paintTRIN(bmp, VerSHDW[3], VerSHDW[0], VerSHDW[4], COLORREF(COL_BMP::clear));
	paintTRIN(bmp, VerSHDW[0], VerSHDW[1], VerSHDW[2], COLORREF(COL_BMP::clear));
	paintTRIN(bmp, VerSHDW[0], VerSHDW[2], VerSHDW[3], COLORREF(COL_BMP::clear));


	if (result[0] > 0) {
		paintTRIN(bmp, VerPR[0], VerPR[1], VerPR[4], COLORREF(COL_BMP::clear));
	}
	if (result[1] > 0) {
		paintTRIN(bmp, VerPR[1], VerPR[2], VerPR[4], COLORREF(COL_BMP::clear));
	}
	if (result[2] > 0) {
		paintTRIN(bmp, VerPR[2], VerPR[3], VerPR[4], COLORREF(COL_BMP::clear));
	}
	if (result[3] > 0) {
		paintTRIN(bmp, VerPR[3], VerPR[0], VerPR[4], COLORREF(COL_BMP::clear));
	}
	if (result[4] > 0) {
		paintTRIN(bmp, VerPR[0], VerPR[1], VerPR[2], COLORREF(COL_BMP::clear));
		paintTRIN(bmp, VerPR[0], VerPR[2], VerPR[3], COLORREF(COL_BMP::clear));
	}

}
void pyramid_4::SetFigure() {

	paintTRIN(bmp, VerSHDW[0], VerSHDW[1], VerSHDW[4], COLORREF(COL_BMP::shadow));
	paintTRIN(bmp, VerSHDW[1], VerSHDW[2], VerSHDW[4], COLORREF(COL_BMP::shadow));
	paintTRIN(bmp, VerSHDW[2], VerSHDW[3], VerSHDW[4], COLORREF(COL_BMP::shadow));
	paintTRIN(bmp, VerSHDW[3], VerSHDW[0], VerSHDW[4], COLORREF(COL_BMP::shadow));
	paintTRIN(bmp, VerSHDW[0], VerSHDW[1], VerSHDW[2], COLORREF(COL_BMP::shadow));
	paintTRIN(bmp, VerSHDW[0], VerSHDW[2], VerSHDW[3], COLORREF(COL_BMP::shadow));

	if (result[0] > 0) {
		paintTRIN(bmp, VerPR[0], VerPR[1], VerPR[4], COLORREF(PYR::one));
	}
	if (result[1] > 0) {
		paintTRIN(bmp, VerPR[1], VerPR[2], VerPR[4], COLORREF(PYR::two));
	}
	if (result[2] > 0) {
		paintTRIN(bmp, VerPR[2], VerPR[3], VerPR[4], COLORREF(PYR::three));
	}
	if (result[3] > 0) {
		paintTRIN(bmp, VerPR[3], VerPR[0], VerPR[4], COLORREF(PYR::four));
	}
	if (result[4] > 0) {
		paintTRIN(bmp, VerPR[0], VerPR[1], VerPR[2], COLORREF(PYR::zero));
		paintTRIN(bmp, VerPR[0], VerPR[2], VerPR[3], COLORREF(PYR::zero));
	}

}