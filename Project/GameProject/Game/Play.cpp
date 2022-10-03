#include "Play.h"
Play::Play(): Base(eType_Play){
	CircleNotes = COPY_RESOURCE("Notes",CImage);
	SquareNotes = COPY_RESOURCE("Notes", CImage);
	Lane = COPY_RESOURCE("Lane", CImage);
	CircleNotes.SetRect(263, 157, 596, 493);
	SquareNotes.SetRect(767,445,1154,636);
	//CircleNotes.SetSize(240,240);
	SquareNotes.SetSize(240,120);
	video = new CVideo("Movie/LeanOn.mp4");
	video->Play();
}
void Play::Draw() {
	video->Draw();
	SquareNotes.Draw();
	Lane.Draw();
}
void Play::Update() {
}
