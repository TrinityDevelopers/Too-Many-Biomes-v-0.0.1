#ifndef __CREATEWORLDSCREEN_H__
#define __CREATEWORLDSCREEN_H__

#pragma once
#include "Screen.h"
#include "../element/Button.h"
#include "../element/TextBox.h"
#include "../element/Label.h"
#include "../element/TButton.h"
#include <string>
#include <vector>
#include <memory>

class CreateWorldScreen : public Screen {
public:	
	typedef void (*InitReal)(CreateWorldScreen*);
	typedef void (*SetupPositionsReal)(CreateWorldScreen*);
	typedef void (*ButtonClickedReal)(CreateWorldScreen*, Button*);
	typedef void (*TickReal)(CreateWorldScreen*);
	
	static InitReal init_real;
	static SetupPositionsReal setupPositions_real;
	static ButtonClickedReal buttonClicked_real;
	static TickReal tick_real;
public:
	static Touch::TButton* tooManyBiomesBtn;
public:
	bool isAdvanced; // 200
	bool isFlat; // 201
	char levelList_seed[18]; // 202
	int gamemode; // 220
	int generator; // 224
	std::vector<Button*, std::allocator<Button*>> gameModeBtns; // 228
	std::vector<Button*, std::allocator<Button*>> worldTypeBtns; // 240
	Button* selectedGameModeBtn; // 252
	Button* selectedWorldTypeBtn; // 256
	Button* createWorldBtn; // 260
	Button* closeBtn; // 264
	Button* headerBtn; // 268
	Button* advancedBtn; // 272
	Button* limitedWorldsErrorBtn; // 276
	TextBox* worldNameBox; // 280
	TextBox* seedBox; // 284
	Label* worldNameLabel; // 288
	Label* seedLabel; // 292
	virtual void init();
	virtual void setupPositions();
	virtual void buttonClicked(Button*);
	virtual void tick();
	
	static void init_hook(CreateWorldScreen *);
	static void setupPositions_hook(CreateWorldScreen *);
	static void buttonClicked_hook(CreateWorldScreen *, Button *);
	static void tick_hook(CreateWorldScreen*);
};

#endif
