#include "StartScreen.h"

namespace ss
{
	StartScreen::StartScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
	}

	StartScreen::~StartScreen()
	{
	}

	void StartScreen::handleEventsContent(sf::Event & evnt)
	{
	}

	void StartScreen::updateContent(float dt)
	{
	}

	void StartScreen::draw()
	{
	}
}

