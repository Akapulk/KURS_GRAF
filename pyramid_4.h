#ifndef PYRAMID_4_H_
#define PYRAMID_4_H_

#include "figure.h"

class pyramid_4 : public figure {
public:
	pyramid_4(BitMap* bmp, size_t numVer, size_t numFace);
private:
	void SetFigure();
	void ClrFigure();
	void Body();
};

#endif // !PYRAMID_4_H_


