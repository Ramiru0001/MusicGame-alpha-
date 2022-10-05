#pragma once
#include <Gllibrary.h>
#include "../Base/Base.h"

class Notes :public Base {
public:
	enum {
		eState_Left,
		eState_CenterLeft,
		eState_CenterRight,
		eState_Right,
	};
	//false�̏ꍇtime��0�ɂȂ�܂őҋ@
	bool state = false;
	int m_time;
	CImage m_img;
	CImage CircleNotes;
	CImage SquareNotes;
	CVector2D Right_pos;
	CVector2D CenterRight_pos;
	CVector2D CenterLeft_pos;
	CVector2D Left_pos;
	CVector2D m_pos;
public:
	Notes(int area,int time);
	void Draw();
	void Update();
	void Collision();
	void CheckHitNotes();
	void Timer();
	void ImageSet();
};
