#include "Notes.h"
#include <iostream>
//#include "Hit.h"

Notes::Notes(int area,int time) :Base(eType_Notes) {
	ImageSet();
	if (time <= 0) {
		state = true;
	}
	switch (area) {
	case eState_Left:
		m_pos = Left_pos;
		m_img = SquareNotes;
		break;
	case eState_CenterLeft:
		m_pos = CenterLeft_pos;
		m_img = SquareNotes;
		break;
	case eState_CenterRight:
		m_pos = CenterRight_pos;
		m_img = SquareNotes;
		break;
	case eState_Right:
		m_pos =Right_pos;
		m_img = SquareNotes;
		break;
	}
	m_time = time;
}
void Notes::Draw() {
	if (state == true) {
		m_img.SetPos(m_pos);
		m_img.Draw();
	}
	//printf("%d %d\n", m_pos.x,m_pos.y);
};
void Notes::Update() {
	if (state == true) {
		CheckHitNotes();
		m_pos.y += 8;
	}
	Timer();
}
void Notes::CheckHitNotes() {
	if (PUSH(CInput::eButton1)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 5) {
			//Base::Add(new Hit(m_pos));
			//SOUND("Tap")->Play();
			m_kill = true;
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 241) {
			//Base::Add(new Hit(m_pos));
			//SOUND("Tap")->Play();
			m_kill = true;
		}
	}
	if (PUSH(CInput::eButton3)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 482) {
			//Base::Add(new Hit(m_pos));
			//SOUND("Tap")->Play();
			m_kill = true;
		}
	}
	if (PUSH(CInput::eButton4)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 723) {
			//Base::Add(new Hit(m_pos));
			//SOUND("Tap")->Play();
			m_kill = true;
		}
	}
}
void Notes::Timer() {
	m_time--;
	if (m_time <= 0) {
		state = true;
	}
}
void Notes::ImageSet() {
	Left_pos = CVector2D(5, 0);
	CenterLeft_pos = CVector2D(241, 0);
	CenterRight_pos = CVector2D(482, 0);
	Right_pos = CVector2D(723, 0);
	CircleNotes = COPY_RESOURCE("Notes", CImage);
	SquareNotes = COPY_RESOURCE("Notes", CImage);
	CircleNotes.SetRect(263, 157, 596, 493);
	SquareNotes.SetRect(767, 445, 1154, 636);
	//CircleNotes.SetSize(240,240);
	SquareNotes.SetSize(236, 118);
	//SquareNotes.SetPos(5, 100);
}