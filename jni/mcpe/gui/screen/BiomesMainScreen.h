// 한번만 포함(include) 하기 위함
#ifndef __BIOMESMAINSCREEN_H__
#define __BIOMESMAINSCREEN_H__

#include "Screen.h"
#include "../element/TButton.h"
#include "../element/THeader.h"

class BiomesMainScreen : public Screen {
public:
	// 버튼
	Touch::TButton *_backMainButton;
	
	Touch::TButton *_modInfoButton;

	Touch::TButton *_biomesInfoButton;

	Touch::THeader *_biomesMainHeader;

public:
	BiomesMainScreen();
	virtual ~BiomesMainScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	void closeScreen();
};

#endif