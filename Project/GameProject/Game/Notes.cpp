#include "Notes.h"
#include "ShareNum.h"
#include <iostream>
//#include "Hit.h"

Notes::Notes(int area,int time,int speed) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 180;
	m_speed = speed;
	SpeedSet();
	if (m_time <= 0) {
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
}
void Notes::Draw() {
	if (state == true) {
		m_img.SetPos(m_pos);
		m_img.Draw();
	}
};
void Notes::Update() {
	if (state == true) {
		CheckHitNotes();
		m_pos.y += m_speed;
	}
	Timer();
}
void Notes::CheckHitNotes() {
	/*if (895 < m_pos.y + 118 && m_pos.y + 118 < 905 ) {
		SOUND("Tap")->Play();
		m_kill = true;
	}*/
	if (PUSH(CInput::eButton1)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 5) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
	if (PUSH(CInput::eButton2)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 241) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
	if (PUSH(CInput::eButton3)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 482) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
	if (PUSH(CInput::eButton4)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 723) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
}
void Notes::Timer() {
	m_time--;
	if (m_time <= 0) {
		state = true;
	}
	//std::cout << m_time << std::endl;
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
void Notes::SpeedSet() {
	//Šî€‚ðspeed = 8‚Æ‚·‚é
	if(m_speed < 8) {
		int temp= 780 / m_speed - 780 / 8;
		m_time -= temp;
	}
	else if (m_speed > 8) {
		int temp = 780 / 8 - 780 / m_speed;
		m_time +=temp;
	}
}