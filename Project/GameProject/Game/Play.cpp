#include "Play.h"
#include "Notes.h"
#include "SoundBar.h"
#include "Score.h"
#include "SelectScene/SelectScene.h" 
#include "ScoreScene.h"
#include <Gllibrary.h>
#include <iostream>
#include <fstream>
#include "../Base/Base.h"
Play::Play(int ChoiceSound) : Base(eType_Play),
score_text("C:\\Windows\\Fonts\\msgothic.ttc", 64) {
	glClearColor(0, 0, 0, 0);
	CountDownToStart = 190;
	CountUpToEnd = 0;
	SoundNum = ChoiceSound;
	ImageSet();
	switch (ChoiceSound) {
	case eNum_LeanOn:
		video = new CVideo("Movie/LeanOn60.mp4");
		break;
	case eNum_Baby:
		video = new CVideo("Movie/Baby.mp4");
		break;
	}
}
void Play::Draw() {
	if (CountDownToStart <= 0) {
		video->Draw();
	}
	Lane.Draw();
	NotesBar.Draw();
}
void Play::Update() {
	CountDownToStart--;
	CountUpToEnd++;
	switch (ShareNum::GameNum) {
	case eNum_LeanOn:
		if (CountDownToStart == 0) {
			LeanOn();
		}
		if (CountUpToEnd >= 7080) {
			m_kill = true;
		}
		break;
	case eNum_Baby:
		if (CountDownToStart == 0) {
			Baby();
		}
		/*if (CountUpToEnd >= 7080) {
			m_kill = true;
		}*/
	}
}	
Play::~Play() {
	std::ofstream Lfile("Score/LeanOn.txt", std::ios_base::app | std::ios_base::in);
	std::ofstream Bfile("Score/Baby.txt", std::ios_base::app | std::ios_base::in);
	switch (ShareNum::GameNum) {
	case eNum_LeanOn:
		Lfile << ShareNum::score << std::endl;
		break;
	case eNum_Baby:
		Bfile << ShareNum::score << std::endl;
		break;
	}
	video->Stop();
	Base::KillAll();
	Base::Add(new ScoreScene());
}
void Play::ImageSet() {
	Lane = COPY_RESOURCE("Lane", CImage);
	NotesBar = COPY_RESOURCE("NotesBar", CImage);
}
void Play::Baby() {
	video->Play();
	//OneNotes = ;
	Base::Add(new SoundBar(0));
	Base::Add(new Score());
	NotesSet();
}
void Play::LeanOn() {
	video->Play();
	OneNotes = 18.125;
	Base::Add(new SoundBar(0));
	Base::Add(new Score());
	NotesSet();
}
void Play::NotesPreSet(int SetNum) {
	switch (SetNum) {
	case 0:
		Base::Add(new Notes(4, OneNotes * 0 + NotesCount,2,6));
		Base::Add(new Notes(4, OneNotes * 4 + NotesCount, 0, 7));
		Base::Add(new Notes(4, OneNotes * 15 + NotesCount, 6, 0));
		Base::Add(new Notes(4, OneNotes * 23 + NotesCount, 1, 3));
		Base::Add(new Notes(4, OneNotes * 34 + NotesCount, 0, 1));
		Base::Add(new Notes(4, OneNotes * 47 + NotesCount, 0, 6));
		Base::Add(new Notes(4, OneNotes * 59 + NotesCount, 5, 5));
		Base::Add(new Notes(4, OneNotes * 78 + NotesCount, 4, 9));
		Base::Add(new Notes(4, OneNotes * 86 + NotesCount, 7, 2));
		Base::Add(new Notes(4, OneNotes * 104 + NotesCount, 6, 6));
		Base::Add(new Notes(4, OneNotes * 112 + NotesCount, 4, 1));
		Base::Add(new Notes(4, OneNotes * 123 + NotesCount, 9, 4));
		Base::Add(new Notes(4, OneNotes * 137 + NotesCount, 2, 1));
		Base::Add(new Notes(4, OneNotes * 144 + NotesCount, 3, 6));
		Base::Add(new Notes(4, OneNotes * 170 + NotesCount, 8, 7));
		Base::Add(new Notes(4, OneNotes * 188 + NotesCount, 4, 2));
		Base::Add(new Notes(4, OneNotes * 199 + NotesCount, 2, 6));
		Base::Add(new Notes(4, OneNotes * 210 + NotesCount, 0, 7));

		Base::Add(new Notes(4, OneNotes * 270 + NotesCount, 0, 0));
		Base::Add(new Notes(4, OneNotes * 275 + NotesCount, 1, 0));
		Base::Add(new Notes(4, OneNotes * 280 + NotesCount, 2, 0));
		Base::Add(new Notes(4, OneNotes * 285 + NotesCount, 3, 0));
		Base::Add(new Notes(4, OneNotes * 290 + NotesCount, 4, 0));
		Base::Add(new Notes(4, OneNotes * 295 + NotesCount, 5, 0));

		Base::Add(new Notes(4, OneNotes * 310 + NotesCount, 2, 2));
		Base::Add(new Notes(4, OneNotes * 330 + NotesCount, 4, 8));
		Base::Add(new Notes(4, OneNotes * 345 + NotesCount, 3, 5));
		Base::Add(new Notes(4, OneNotes * 354 + NotesCount, 9, 0));
		Base::Add(new Notes(4, OneNotes * 367 + NotesCount, 0, 6));
		Base::Add(new Notes(4, OneNotes * 371 + NotesCount, 1, 6));
		Base::Add(new Notes(4, OneNotes * 389 + NotesCount, 4, 8));
		Base::Add(new Notes(4, OneNotes * 427 + NotesCount, 5, 0));
		//Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		//Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 20));
		break;
	case 1:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
		break;
	case 2:
		Base::Add(new Notes(1, OneNotes * 1.9+ NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1.9 + NotesCount, 8));
		break;
	case 3:
		Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3.5+ NotesCount, 8));
		break;
	case 4:
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 8));
		break;
	case 5:
		Base::Add(new Notes(0, OneNotes * 7.3 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 7.3 + NotesCount, 8));
		break;
	case 6:
		Base::Add(new Notes(0, OneNotes * 8.6 + NotesCount, 10));
		Base::Add(new Notes(0, OneNotes * 8.2 + NotesCount, 8));
		break;
	case 7:
		Base::Add(new Notes(3, OneNotes * 9.5 + NotesCount, 3));
		break;
	case 8:
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 9:
		Base::Add(new Notes(0, OneNotes * 2 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 3 + NotesCount, 8));
		break;
	case 10:
		Base::Add(new Notes(0, OneNotes * 10 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 10.5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 11 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 11.5 + NotesCount, 8));
		break;
	case 11:
		Base::Add(new Notes(3, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 6 + NotesCount, 8));
		break;
	case 12:
		Base::Add(new Notes(3, OneNotes * 9 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 10 + NotesCount, 8));
		break;
	case 13:
		Base::Add(new Notes(1, OneNotes * 6 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 7 + NotesCount, 8));
		break;
	case 14:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 8));
		break;
	case 15:
		Base::Add(new Notes(1, OneNotes * 5.2 + NotesCount, 10));
		Base::Add(new Notes(1, OneNotes * 5.6 + NotesCount, 10));
		break;
	case 16:
		Base::Add(new Notes(2, OneNotes * 9.2 + NotesCount, 9));
		Base::Add(new Notes(2, OneNotes * 9.6 + NotesCount, 9));
		break;
	case 17:
		Base::Add(new Notes(3, OneNotes * 4.2 + NotesCount, 9));
		Base::Add(new Notes(3, OneNotes * 4.6 + NotesCount, 9));
		break;
	case 18:
		Base::Add(new Notes(3, OneNotes * 7 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 7.5 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 8 + NotesCount, 8));
		Base::Add(new Notes(0, OneNotes * 8.5 + NotesCount, 8));
		break;
	}
	
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount += 145.1;
		break;
	case eNum_Baby:
		//NotesCount += 145.1;
		break;
	}
}
void Play::NotesSet() {
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount = -117.75;	
		NotesPreSet(0);
		NotesPreSet(1);
		NotesPreSet(2);
		NotesPreSet(3);
		NotesPreSet(4);
		NotesPreSet(15);
		NotesPreSet(5);
		NotesPreSet(6);
		NotesPreSet(17);
		NotesPreSet(7);
		NotesPreSet(8);
		NotesPreSet(16);
		NotesPreSet(2);
		NotesPreSet(1);
		NotesPreSet(17);
		NotesPreSet(6);
		NotesPreSet(12);
		NotesPreSet(7);
		NotesPreSet(3);
		NotesPreSet(15);
		NotesPreSet(4);
		NotesPreSet(11);
		NotesPreSet(8);
		NotesPreSet(5);
		NotesPreSet(11);
		NotesPreSet(3);
		NotesPreSet(12);
		NotesPreSet(10);
		NotesPreSet(13);
		NotesPreSet(4);
		NotesPreSet(14);
		NotesPreSet(7);
		NotesPreSet(15);
		NotesPreSet(18);
		NotesPreSet(9);
		NotesPreSet(13);
		NotesPreSet(16);
		NotesPreSet(15);
		NotesPreSet(17);
		NotesPreSet(12);
		NotesPreSet(11);
		NotesPreSet(14);
		NotesPreSet(13);
		NotesPreSet(15);
		NotesPreSet(12);
		NotesPreSet(4);
		NotesPreSet(5);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
	case eNum_Baby:
		//NotesCount = -117.75;
		NotesPreSet(0);
		NotesPreSet(1);
		NotesPreSet(2);
		NotesPreSet(3);
		NotesPreSet(4);
		NotesPreSet(15);
		NotesPreSet(0);
	}
}