#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	CImage CircleNotes;
	CImage SquareNotes;
	CImage Lane;
	CVideo* video;
public:
	Play();
	void Draw();
	void Update();
};