#include <Gllibrary.h>
#include "../Base/Base.h"
#include "SoundBar.h"

SoundBar::SoundBar(int SoundNum) :Base(eType_Play) {
	switch(SoundNum) {
	case LeanOn:
		SongLen = 7080;
	}
}
void SoundBar::Update() {
	SongCount++;
	if(SongCount>=7080){
	}
}
void SoundBar::ImageSet() {
	Bar = COPY_RESOURCE("SoundBar", CImage);
	Bar.SetRect(1,20,1 +1918 * SongCount / 7080, 31);
	Bar.SetSize(1918 * SongCount / 7080, 11);
	BarFrame = COPY_RESOURCE("SoundBar", CImage);
	BarFrame.SetRect(0,0,1920,15);
}
void SoundBar::Draw() {
	BarFrame.Draw();
	Bar.Draw();
}