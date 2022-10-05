#include "Play.h"
#include "Notes.h"
Play::Play(): Base(eType_Play){
	ImageSet();
	video = new CVideo("Movie/LeanOn.mp4");
	video->Play();
	Base::Add(new Notes(0, 0, 8));
	Base::Add(new Notes(0, 0, 10));
	Base::Add(new Notes(1, 100, 5));
	Base::Add(new Notes(2, 100, 8));
	Base::Add(new Notes(3, 100, 10));
}
void Play::Draw() {
	video->Draw();
	Lane.Draw();
	SoundBar.Draw();
	NotesBar.Draw();
}
void Play::Update() {
}
void Play::ImageSet() {
	Lane = COPY_RESOURCE("Lane", CImage);
	SoundBar = COPY_RESOURCE("SoundBar", CImage);
	NotesBar = COPY_RESOURCE("NotesBar", CImage);
}
