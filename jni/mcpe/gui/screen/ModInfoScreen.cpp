#include "../../../shared.h"
#include "BiomesMainScreen.h"
#include "ModInfoScreen.h"
#include "../../MinecraftClient.h"
#include "../element/TButton.h"
#include "../element/THeader.h"

ModInfoScreen::ModInfoScreen() {
	_backModInfoButton = NULL;
	_ModInfoHeader = NULL;
}

ModInfoScreen::~ModInfoScreen() {
	delete _backModInfoButton; 
	delete _ModInfoHeader; 
}

void ModInfoScreen::render(int i1, int i2, float f1) {
	renderMenuBackground(f1);
	
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "In order to activate the Too Many Biomes mod", _width / 2, 33, Color::GREEN);
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "world generation, press the Too Many Biomes", _width / 2, 48, Color::GREEN);
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "World Generator type in the create world screen.", _width / 2, 63, Color::GREEN);
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "When the world is created you should start", _width / 2, 78, Color::GREEN);
	_screenRenderer.drawCenteredString(_minecraftClient->_font, "seeing some awesome new biomes!", _width / 2, 93, Color::GREEN);
	
	Screen::render(i1, i2, f1);
}

void ModInfoScreen::init() {
	_backModInfoButton = new Touch::TButton(0, "Back", NULL, false);

	_ModInfoHeader = new Touch::THeader(1, "Mod Information");

	_backModInfoButton->init(_minecraftClient);

	_vecBtn.push_back(_backModInfoButton);
	
	_vecGui2E.push_back(_ModInfoHeader);
}

void ModInfoScreen::setupPositions() {
	_ModInfoHeader->_width = _width;

	_backModInfoButton->_x = 4;

	_backModInfoButton->_y = 4;
	
	_backModInfoButton->_width = 38;
	
	_backModInfoButton->_height = 18;
}

bool ModInfoScreen::handleBackEvent(bool b1) {
	if(!b1) {
		closeScreen();
	}

	return true;
}

void ModInfoScreen::buttonClicked(Button *button) {
	if(button->_buttonId == _backModInfoButton->_buttonId) {
		closeScreen();
	}
}

void ModInfoScreen::closeScreen() {
	_minecraftClient->setScreen(new BiomesMainScreen());
}