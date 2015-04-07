#include <Substrate.h>
#include "shared.h"
#include "mcpe/gui/screen/StartMenuScreen.h"
#include "mcpe/gui/screen/CreateWorldScreen.h"

void biomesMainScreen() {
	// You should hook these functions to create button in the start menu: init(), setupPositions(), buttonClicked().
	MSHookFunction((void *) &Touch::StartMenuScreen::init,		(void *) &Touch::StartMenuScreen::init_hook,			(void **) &Touch::StartMenuScreen::init_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::setupPositions,	(void *) &Touch::StartMenuScreen::setupPositions_hook,		(void **) &Touch::StartMenuScreen::setupPositions_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::buttonClicked, (void *) &Touch::StartMenuScreen::buttonClicked_hook,		(void **) &Touch::StartMenuScreen::buttonClicked_real);
	MSHookFunction((void *) &Touch::StartMenuScreen::chooseRandomSplash, (void *) &Touch::StartMenuScreen::chooseRandomSplash_hook, (void**) &Touch::StartMenuScreen::chooseRandomSplash_real);
}

void createWorldScreen() {
	MSHookFunction((void*) &CreateWorldScreen::init, (void*) &CreateWorldScreen::init_hook, (void**) &CreateWorldScreen::init_real);
	MSHookFunction((void *) &CreateWorldScreen::setupPositions, (void *) &CreateWorldScreen::setupPositions_hook, (void **) &CreateWorldScreen::setupPositions_real);
	MSHookFunction((void *) &CreateWorldScreen::buttonClicked, (void *) &CreateWorldScreen::buttonClicked_hook, (void **) &CreateWorldScreen::buttonClicked_real);
	MSHookFunction((void *) &CreateWorldScreen::tick, (void *) &CreateWorldScreen::tick_hook, (void **) &CreateWorldScreen::tick_real);
}
