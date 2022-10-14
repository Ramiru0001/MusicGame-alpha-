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
		eState_RightSide,
	};
	//falseの場合timeが0になるまで待機
	bool state = false;
	int m_time;
	int NotesArea;
	int RNotesCount;
	int RNotesCountToDelete;
	double m_speed;
	CImage m_img;
	CImage CircleNotes;
	CImage SquareNotes;
	CImage CircleNotesFrame;
	CVector2D Right_pos;
	CVector2D CenterRight_pos;
	CVector2D CenterLeft_pos;
	CVector2D Left_pos;
	CVector2D m_pos;
public:
	Notes(int area,int time,int speed);
	Notes(int area, int time, int x, int y);
	void Draw();
	void Update();
	void Timer();
	void ImageSet();
	void LSpeedSet();
	void LCheckHitNotes();
	void RSizeSet();
	void RCheckHitNotes();
	void RArea(int x,int y);
	void CountDownToDelete();
};
