#include "StartScreen.h"

namespace ss
{
	StartScreen::StartScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
		this->btn = CustomButton(
			{ 50.0f, 50.0f },
			{ 100.0f, 190.0f },
			"Button!",
			this->aMan->getFont("roboto_regular", "Resources/Fonts/roboto_regular.ttf"),
			30,
			this->iMan,
			true
		);
	}

	StartScreen::~StartScreen()
	{
	}

	void StartScreen::handleEventsContent(sf::Event & evnt)
	{
	}

	void StartScreen::updateContent(float dt)
	{
		this->btn.update(*this->win);
	}

	void StartScreen::draw()
	{
		this->btn.draw(*this->win);
	}
}

