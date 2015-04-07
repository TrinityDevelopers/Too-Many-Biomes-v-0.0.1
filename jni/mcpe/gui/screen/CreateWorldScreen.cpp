#include <string>
#include <vector>

#include "../../../shared.h"
#include "../element/Button.h"
#include "CreateWorldScreen.h"
#include "../element/TButton.h"

CreateWorldScreen::InitReal CreateWorldScreen::init_real = NULL;
CreateWorldScreen::SetupPositionsReal CreateWorldScreen::setupPositions_real = NULL;
CreateWorldScreen::ButtonClickedReal CreateWorldScreen::buttonClicked_real = NULL;
CreateWorldScreen::TickReal CreateWorldScreen::tick_real = NULL;
Touch::TButton* CreateWorldScreen::tooManyBiomesBtn = NULL;

void CreateWorldScreen::init_hook(CreateWorldScreen* screen) {
	if(!tooManyBiomesBtn) {
		tooManyBiomesBtn = new Touch::TButton(34, "Too Many Biomes", screen->_minecraftClient, false);
		tooManyBiomesBtn->init(screen->_minecraftClient);
	}
	screen->_vecBtn.emplace_back(tooManyBiomesBtn);
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "init_hook");
	// Call real init() function.
	CreateWorldScreen::init_real(screen);
}

void CreateWorldScreen::setupPositions_hook(CreateWorldScreen* screen) {
	CreateWorldScreen::setupPositions_real(screen);
	
	tooManyBiomesBtn->_x = ((screen->_width - 36) * 3) / 4;
	tooManyBiomesBtn->_y = (screen->_height / 100) * 55;
	tooManyBiomesBtn->_width = (screen->_width - 36) / 4;
	tooManyBiomesBtn->_height = 20;
	tooManyBiomesBtn->_color = Color::GREEN;
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "setupPositions_hook");
}

void CreateWorldScreen::buttonClicked_hook(CreateWorldScreen* screen, Button* button) {
	if(button->_buttonId == tooManyBiomesBtn->_buttonId) { //Too Many Biomes Button
		screen->generator = 3;
		screen->selectedWorldTypeBtn = button;
		return;
	}
	__android_log_print(ANDROID_LOG_INFO, LOG_TAG, "buttonClicked_hook");
	CreateWorldScreen::buttonClicked_real(screen, button);
}

void CreateWorldScreen::tick_hook(CreateWorldScreen* screen) {
	CreateWorldScreen::tick_real(screen);
	/*if(tooManyBiomesBtn == NULL) return;
	if(screen->isAdvanced == true) {
		tooManyBiomesBtn->_isVisible = true;
	} else {
		tooManyBiomesBtn->_isVisible = false;
	}*/
}