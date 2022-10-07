#include "Play.h"
#include "Notes.h"
#include "SoundBar.h"
#include "Score.h"
#include "SelectScene/SelectScene.h" 
#include <Gllibrary.h>
#include <iostream>
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
	if (CountDownToStart == 0) {
		switch (SoundNum) {
		case eNum_LeanOn:
			LeanOn();
		}
	}
	if (CountUpToEnd >= 7080) {
		Base::KillAll();
		Base::Add(new SelectScene());
	}
}
void Play::ImageSet() {
	Lane = COPY_RESOURCE("Lane", CImage);
	NotesBar = COPY_RESOURCE("NotesBar", CImage);
}
void Play::LeanOn() {
	video->Play();
	OneNotes = 18.125;
	Base::Add(new SoundBar(0));
	Base;; Add(new Score());
	NotesSet();
}
void Play::NotesPreSet(int SetNum) {
	switch (SetNum) {
	case 0:
		//Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 5));
		//Base::Add(new Notes(1, OneNotes * 2 + NotesCount, 8));
		//Base::Add(new Notes(2, OneNotes * 4 + NotesCount, 20));
	case 1:
		Base::Add(new Notes(0, OneNotes * 0 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 0 + NotesCount, 8));
	case 2:
		Base::Add(new Notes(1, OneNotes * 1.9+ NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 1.9 + NotesCount, 8));
	case 3:
		Base::Add(new Notes(0, OneNotes * 3.5 + NotesCount, 8));
		Base::Add(new Notes(3, OneNotes * 3.5+ NotesCount, 8));
	case 4:
		Base::Add(new Notes(1, OneNotes * 5 + NotesCount, 8));
		Base::Add(new Notes(2, OneNotes * 5 + NotesCount, 8));
	case 5:
		Base::Add(new Notes(0, OneNotes * 7.3 + NotesCount, 8));
		Base::Add(new Notes(1, OneNotes * 7.3 + NotesCount, 8));
	case 6:
		Base::Add(new Notes(0, OneNotes * 8.6 + NotesCount, 10));
		Base::Add(new Notes(0, OneNotes * 8.2 + NotesCount, 8));
	case 7:
		Base::Add(new Notes(3, OneNotes * 9.5 + NotesCount, 3));
	
	}
	
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount += 145.1;
	}
}
void Play::NotesSet() {
	switch (SoundNum) {
	case eNum_LeanOn:
		NotesCount = -117.75;
		NotesPreSet(1);
		NotesPreSet(2);
		NotesPreSet(3);
		NotesPreSet(4);
		NotesPreSet(5);
		NotesPreSet(6);
		NotesPreSet(7);
		NotesPreSet(8);
		NotesPreSet(2);
		NotesPreSet(1);
		NotesPreSet(6);
		NotesPreSet(7);
		NotesPreSet(3);
		NotesPreSet(4);
		NotesPreSet(8);
		NotesPreSet(5);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
		NotesPreSet(0);
	}
}