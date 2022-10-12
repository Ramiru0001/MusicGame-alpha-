#pragma once
#include <Gllibrary.h>
#include "../../Base/Base.h"
#include "../ShareNum.h"

class SelectScene :public Base {
	enum {
		//ゲームタイトルのstateを作る
		LeanOn,
		Baby,
	};
private:
	char game_title[10][100] = { "LeanOn","Baby"/*,"ABC","ABC"*/};
	CFont title_text;
	CFont select_title_text;
	CFont PushEnter_Text;
public:
	SelectScene();
	void Draw();
	void Update();
};
