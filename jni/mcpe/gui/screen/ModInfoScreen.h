// 한번만 포함(include) 하기 위함
#ifndef __MODINFOSCREEN_H__
#define __MODINFOSCREEN_H__

#include "Screen.h"
#include "../element/TButton.h"
#include "../element/THeader.h"

class ModInfoScreen : public Screen {
public:
	// 버튼
	Touch::TButton *_backModInfoButton;

	Touch::THeader *_ModInfoHeader;

public:
	ModInfoScreen();
	virtual ~ModInfoScreen();
	virtual void render(int, int, float);
	virtual void init();
	virtual void setupPositions();
	virtual bool handleBackEvent(bool);
	virtual void buttonClicked(Button *);
	void closeScreen();
};

#endif