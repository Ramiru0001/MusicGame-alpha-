#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"
class Play :public Base {
private:
	enum {
		eNum_LeanOn,
	};
	CImage Lane;
	CImage NotesBar;
	CVideo* video;
	CFont score_text;
	int CountDownToStart;
	int CountUpToEnd;
	int SoundNum;
	float OneNotes;
	float NotesCount;
public:
	Play(int ChoiceSound);
	~Play();
	void ImageSet();
	void Draw();
	void Update();
	void LeanOn();
	void NotesSet();
	void NotesPreSet(int SetNum);
};