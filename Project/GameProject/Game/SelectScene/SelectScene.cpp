#include "SelectScene.h"
#include "../Ranking.h"
#include "../ShareNum.h"
#include "../Play.h"

SelectScene::SelectScene() :Base(eType_Scene)
, title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
, select_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 80) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	ShareNum::GameNum = 0;
	ShareNum::debug = false;
	Base::Add(new Ranking(0));
}
void SelectScene::Draw() {
	//選択中のタイトルを大きく表示
	for (int i = 0; i < ShareNum::MaxGame; i++) {
		if (ShareNum::GameNum != i) {
			title_text.Draw(274, 214 + i * 150, 0, 0, 0, game_title[i]);
		}
		else {
			select_title_text.Draw(274, 214 + i * 150, 0, 0, 0, game_title[i]);
		}
	}
}
void SelectScene::Update() {
	if (PUSH(CInput::eUp)) {
		if (ShareNum::GameNum > 0) {
			ShareNum::GameNum--;
		}
	}
	if (PUSH(CInput::eDown)) {
		if (ShareNum::GameNum < ShareNum::MaxGame - 1) {
			ShareNum::GameNum++;
		}
	}
	if (PUSH(CInput::eButton10)) {
		Base::KillAll();
		switch (ShareNum::GameNum) {
		case LeanOn:
			Base::Add(new Play(LeanOn));
			break;
		}
	}
}
