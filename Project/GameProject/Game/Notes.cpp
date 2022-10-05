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
	/*if (state == true) {
		SquareNotes.SetPos(m_pos);
		SquareNotes.Draw();
	}*/
	m_img.SetPos(m_pos);
	m_img.Draw();
	//printf("%d %d\n", m_pos.x,m_pos.y);
};
void Notes::Update() {
	if (state == true) {
		//CheckHitNotes();
		m_pos.y += 8;
	}
	//printf("%d %d\n", m_pos.x, m_pos.y);
	std::cout << m_pos.x <<" " << m_pos.y << std::endl;
	std::cout << CenterRight_pos.x << " " << CenterRight_pos.y << std::endl;
	Timer();
}
void Notes::CheckHitNotes() {
	/*if (PUSH(CInput::eButton1)) {
		if (620 < m_pos.y && m_pos.y < 680 && m_pos.x == 113) {
			Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (620 < m_pos.y && m_pos.y < 680 && m_pos.x == 1167) {
			Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
		}
	}*/
}
void Notes::Timer() {
	m_time--;
	/*if (m_time <= 0) {
		state = true;
	}*/
}
void Notes::ImageSet() {
	Left_pos = CVector2D(5 + 236 * 0, 0);
	CenterLeft_pos = CVector2D(5 * 1 + 236 * 1, 0);
	CenterRight_pos = CVector2D(5 * 2 + 236 * 2 + 5, 0);
	Right_pos = CVector2D(5 * 3 + 236 * 3 + 5, 0);
	CircleNotes = COPY_RESOURCE("Notes", CImage);
	SquareNotes = COPY_RESOURCE("Notes", CImage);
	CircleNotes.SetRect(263, 157, 596, 493);
	SquareNotes.SetRect(767, 445, 1154, 636);
	//CircleNotes.SetSize(240,240);
	SquareNotes.SetSize(236, 118);
	//SquareNotes.SetPos(5, 100);
}