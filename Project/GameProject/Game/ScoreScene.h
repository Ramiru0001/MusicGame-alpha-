#pragma once
#include "../Base/Base.h"
class ScoreScene :public Base {
public:
	CFont text;
	CFont PushEnter_Text;
	CImage m_img[11];
public:
	ScoreScene();
	~ScoreScene();
	void Draw();
	void ImageSet();
	void Update();
};