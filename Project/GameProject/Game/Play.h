#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	CImage Lane;
	CImage CircleNotes;
	CImage SquareNotes;
	CVideo* video;
public:
	Play();
	void ImageSet();
	void Draw();
	void Update();
};