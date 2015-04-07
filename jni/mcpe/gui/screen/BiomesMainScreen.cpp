#include "../../../shared.h"
#include "BiomesMainScreen.h"
#include "ModInfoScreen.h"
#include "StartMenuScreen.h"
#include "../../MinecraftClient.h"
#include "../element/TButton.h"
#include "../element/THeader.h"

extern int dimentionsArray[4];

BiomesMainScreen::BiomesMainScreen() {
	_backMainButton = NULL;
	_modInfoButton = NULL;
	_biomesInfoButton = NULL;
	_biomesMainHeader = NULL;
}

BiomesMainScreen::~BiomesMainScreen() {
	delete _backMainButton; 
	delete _modInfoButton;
	delete _biomesInfoButton;
	delete _biomesMainHeader; 
}

void BiomesMainScreen::render(int i1, int i2, float f1) {
	renderMenuBackground(f1);
	
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "Thanks for using the Too Many Biomes mod!", _width / 2, 33, Color::GREEN);
	
	Screen::render(i1, i2, f1);
}

void BiomesMainScreen::init() {
	_backMainButton = new Touch::TButton(0, "Back", _minecraftClient, false);
	
	_modInfoButton = new Touch::TButton(1, "Mod Information", _minecraftClient, false);

	_biomesInfoButton = new Touch::TButton(2, "Biomes Information", _minecraftClient, false);

	_biomesMainHeader = new Touch::THeader(3, "Too Many Biomes");

	_backMainButton->init(_minecraftClient);
	
	_modInfoButton->init(_minecraftClient);

	_biomesInfoButton->init(_minecraftClient);

	_vecBtn.push_back(_backMainButton);
	
	_vecBtn.push_back(_modInfoButton);
	
	_vecBtn.push_back(_biomesInfoButton);
	
	_vecGui2E.push_back(_biomesMainHeader);
}

void BiomesMainScreen::setupPositions() {
	_biomesMainHeader->_width = _width;

	_backMainButton->_x = 4;

	_backMainButton->_y = 4;
	
	_backMainButton->_width = 38;
	
	_backMainButton->_height = 18;
	
	_modInfoButton->_x = dimentionsArray[0];

	_modInfoButton->_y = 48;
	
	_modInfoButton->_width = dimentionsArray[1];
	
	_modInfoButton->_height = dimentionsArray[2] + 4;

	_biomesInfoButton->_x = dimentionsArray[0];

	_biomesInfoButton->_y = 48 + dimentionsArray[2] + 8;

	_biomesInfoButton->_width = dimentionsArray[1];

	_biomesInfoButton->_height = dimentionsArray[2] + 4;
}

bool BiomesMainScreen::handleBackEvent(bool b1) {
	if(!b1) {
		closeScreen();
	}

	return true;
}

void BiomesMainScreen::buttonClicked(Button *button) {
	if(button->_buttonId == _backMainButton->_buttonId) {
		closeScreen();
	}else if(button->_buttonId == _modInfoButton->_buttonId) {
		_minecraftClient->setScreen(new ModInfoScreen());
	}else if(button->_buttonId == _biomesInfoButton->_buttonId) {
		closeScreen();
	}
}

void BiomesMainScreen::closeScreen() {
	_minecraftClient->setScreen(new Touch::StartMenuScreen());
}