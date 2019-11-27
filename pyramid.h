#ifndef PYRAMID_H_
#define PYRAMID_H_

#include "figure.h"

class pyramid : public figure {
public:
	pyramid(BitMap *bmp, size_t numVer, size_t numFace);
private:
	void SetFigure();
	void ClrFigure();
	void Body();
};

#endif // !PYRAMID_H_


