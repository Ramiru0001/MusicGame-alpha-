#include "Notes.h"
#include "ShareNum.h"
#include <iostream>
Notes::Notes(int area,int time,int speed) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 180;
	m_speed = speed;
	NotesArea = area;
	if (m_time <= 0) {
		state = true;
	}
	switch (area) {
	case eState_Left:
		LSpeedSet();
		m_pos = Left_pos;
		m_img = SquareNotes;
		break;
	case eState_CenterLeft:
		LSpeedSet();
		m_pos = CenterLeft_pos;
		m_img = SquareNotes;
		break;
	case eState_CenterRight:
		LSpeedSet();
		m_pos = CenterRight_pos;
		m_img = SquareNotes;
		break;
	case eState_Right:
		LSpeedSet();
		m_pos = Right_pos;
		m_img = SquareNotes;
		break;
	/*case eState_RightSide:
		RNotesCount = 0;
		RArea(0, 0);
		m_img = CircleNotes;*/
	}
}
Notes::Notes(int area, int time, int x,int y) :Base(eType_Notes) {
	ImageSet();
	m_time = time + 216;
	NotesArea = area;
	if (m_time <= 0) {
		state = true;
	}
	RNotesCount = 0;
	RNotesCountToDelete = 20;
	RArea(x,y);
	m_img = CircleNotes;
}
void Notes::Draw() {
	switch (NotesArea) {
	case eState_Left:
	case eState_CenterLeft:
	case eState_CenterRight:
	case eState_Right:
		if (state == true) {
			m_img.SetPos(m_pos);
			m_img.Draw();
		}
		break;
	case  eState_RightSide:
		if (state == true) {
			RSizeSet();
			CircleNotesFrame.Draw();
			m_img.Draw();
		}
		break;
	}
};
void Notes::Update() {
	switch (NotesArea) {
	case eState_Left:
	case eState_CenterLeft:
	case eState_CenterRight:
	case eState_Right:
		if (state == true) {
			LCheckHitNotes();
			m_pos.y += m_speed;
		}
		break;
	case  eState_RightSide:
		if (state == true) {
			RCheckHitNotes();
			CountDownToDelete();
		}
		break;
	}
	Timer();
}
void Notes::LCheckHitNotes() {
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
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 245) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
	if (PUSH(CInput::eButton3)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 485) {
			//Base::Add(new Hit(m_pos));
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
	if (PUSH(CInput::eButton4)) {
		if (870 < m_pos.y + 118 && m_pos.y + 118 < 930 && m_pos.x == 725) {
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
	CenterLeft_pos = CVector2D(245, 0);
	CenterRight_pos = CVector2D(485, 0);
	Right_pos = CVector2D(725, 0);
	CircleNotes = COPY_RESOURCE("Notes", CImage);
	SquareNotes = COPY_RESOURCE("Notes", CImage);
	CircleNotesFrame = COPY_RESOURCE("Notes", CImage);
	CircleNotes.SetRect(263, 157, 596, 493);
	CircleNotesFrame.SetRect(1595, 0, 1920, 325);
	SquareNotes.SetRect(767, 445, 1154, 636);
	SquareNotes.SetSize(236, 118);
	CircleNotes.SetSize(120, 120);
}
void Notes::LSpeedSet() {
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
void Notes::RNotes() {}
void Notes::RSizeSet() {
	if (RNotesCount <60) {
		RNotesCount++;
	}
	m_img.SetSize(120, 120);
	CircleNotesFrame.SetSize(180 - RNotesCount , 180 - RNotesCount );
	m_img.SetPos(m_pos);
	CircleNotesFrame.SetPos(m_pos.x-30 + RNotesCount / 2, m_pos.y-30 + RNotesCount / 2);
}
void Notes::RCheckHitNotes() {
	CVector2D mouse_pos = CInput::GetMousePoint();
	if (PUSH(CInput::eMouseL)) {
		if (std::pow((mouse_pos.x - m_pos.x - 60), 2.0) + std::pow((mouse_pos.y - m_pos.y - 60), 2.0) <= 3600 ) {
			SOUND("Tap")->Play();
			m_kill = true;
			ShareNum::score += 500;
		}
	}
}
void Notes::RArea(int x,int y) {
	m_pos.x = 1025 + x * 725 / 9;
	m_pos.y = 172 + y * 728 / 9;
}
void Notes::CountDownToDelete() {
	if (RNotesCount >= 60) {
		RNotesCountToDelete--;
		if (RNotesCountToDelete <= 0) {
			m_kill = true;
		}
	}
}