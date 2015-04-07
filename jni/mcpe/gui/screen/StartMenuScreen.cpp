#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h> 
#include <time.h>
#include <Substrate.h>

#include "../../../shared.h"
#include "StartMenuScreen.h"
#include "BiomesMainScreen.h"
#include "../element/TButton.h"
#include "../element/ImageWithBackground.h"
#include "../../MinecraftClient.h"

static char** gSplashes;
void biomesMainScreen();
void createWorldScreen();
int dimentionsArray[4];

static std::string (*Name_Real)(void* p);

// initialize static elements
Touch::StartMenuScreen::InitReal Touch::StartMenuScreen::init_real = NULL;
Touch::StartMenuScreen::SetupPositionsReal Touch::StartMenuScreen::setupPositions_real = NULL;
Touch::StartMenuScreen::ButtonClickedReal Touch::StartMenuScreen::buttonClicked_real = NULL;
Touch::StartMenuScreen::ChooseRandomSplashReal Touch::StartMenuScreen::chooseRandomSplash_real = NULL;
Touch::TButton* Touch::StartMenuScreen::_mainScreenButton = NULL;

// Hooked function of init()
void Touch::StartMenuScreen::init_hook(Touch::StartMenuScreen* screen) {
	if(!_mainScreenButton) {
		_mainScreenButton = new Touch::TButton(0, "Too Many Biomes", screen->_minecraftClient, false);
		_mainScreenButton->init(screen->_minecraftClient);
	}
	srand(time(0));
	screen->_vecBtn.emplace_back(_mainScreenButton);

	// Call real init() function.
	Touch::StartMenuScreen::init_real(screen);
}

// Hooked function of setupPositions()
void Touch::StartMenuScreen::setupPositions_hook(Touch::StartMenuScreen* screen) {
	// Call real setupPositions() function.
	Touch::StartMenuScreen::setupPositions_real(screen);

	// Get a play button.
	ImageWithBackground* optionButton = screen->_optionButton;
	// Put the button under the play button.
	
	_mainScreenButton->_x = (screen->_width / 2) - ((optionButton->_width * 3 + 4) / 2);
	_mainScreenButton->_y = (screen->_height * 3) / 4;
	_mainScreenButton->_width = optionButton->_width * 3 + 4;
	_mainScreenButton->_height = optionButton->_height - 12;
	dimentionsArray[0] = _mainScreenButton->_x;
	dimentionsArray[1] = _mainScreenButton->_width;
	dimentionsArray[2] = _mainScreenButton->_height;
	dimentionsArray[3] = screen->_width / 2;
}

// Hooked function of buttonClicked().
void Touch::StartMenuScreen::buttonClicked_hook(Touch::StartMenuScreen* screen, Button* button) {
	// Call real buttonClicked() function.
	Touch::StartMenuScreen::buttonClicked_real(screen, button);

	// If the clicked button is what we added:
	if(button->_buttonId == _mainScreenButton->_buttonId) {
		// Move to ExampleScreen!
		screen->_minecraftClient->setScreen(new BiomesMainScreen());
	}
}
void Touch::StartMenuScreen::chooseRandomSplash_hook(Touch::StartMenuScreen* screen) {
	gSplashes[0] = "Biomes Revamped!";
	gSplashes[1] = "New Biomes!";
	gSplashes[2] = "Yay for addon mods!";
	gSplashes[3] = "Too Many Biomes!";
	
	screen->currentSplash = rand() % 4;
}

std::string versionNameHook(void* p) {
	return "Too Many Biomes v0.0.1 by MRAndyPE";
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
	void* getVersion = dlsym(RTLD_DEFAULT, "_ZN6Common20getGameVersionStringEv");
	MSHookFunction(getVersion, (void*) &versionNameHook, (void**) &Name_Real);
	
	gSplashes = (char**) dlsym(handle, "gSplashes");
	biomesMainScreen();
	createWorldScreen();
	
	return JNI_VERSION_1_2;
}
