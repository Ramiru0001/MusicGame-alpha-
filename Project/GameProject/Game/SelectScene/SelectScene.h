#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectScene :public Base {
	enum {
		//ゲームタイトルのstateを作る
		eState_LeanOn,
	};
private:
	char game_title[10][100] = { "LeanOn"/*,"ABC","ABC"*/ };
	CFont title_text;
	CFont select_title_text;
public:
	SelectScene();
	void Draw();
	void Update();
};
