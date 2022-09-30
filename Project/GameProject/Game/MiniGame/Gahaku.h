#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"

class Gahaku :public Base {
	CImage m_img;
	enum {

		eState_GameTitle
	};
public:
	
	

	void Collision();
	void Draw();
	void Update();
};