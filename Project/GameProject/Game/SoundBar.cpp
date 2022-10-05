#include <Gllibrary.h>
#include <iostream>
#include "../Base/Base.h"
#include "SoundBar.h"

SoundBar::SoundBar(int SoundNum) :Base(eType_Bar) {
	ImageSet();
	switch(SoundNum) {
	case LeanOn:
		SongLen = 7080;
	}
}
void SoundBar::Update() {
	SongCount++;
	/*if(SongCount>=7080){
	}*/
}
void SoundBar::ImageSet() {
	Bar = COPY_RESOURCE("SoundBar", CImage);
	BarFrame = COPY_RESOURCE("SoundBar", CImage);
	BarFrame.SetRect(0,0,1920,15);
	BarFrame.SetSize(1920, 15);
}
void SoundBar::Draw() {
	int temp = 1918 * SongCount / 7080;
	std::cout << temp << std::endl;
	Bar.SetRect(1, 20, 1 +temp, 31);
	Bar.SetSize(temp / 7080, 11);

	Bar.SetPos(0, 0);
	BarFrame.SetPos(0, 0);
	BarFrame.Draw();
	Bar.Draw();
}