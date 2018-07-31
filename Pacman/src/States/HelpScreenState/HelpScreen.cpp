#include "HelpScreen.h"

namespace ss
{
	HelpScreen::HelpScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
		this->rect = sf::RectangleShape(sf::Vector2f(10.0f, 20.0f));
		this->rect.setPosition({ 50.0f, 50.0f });
	}

	HelpScreen::~HelpScreen()
	{
	}

	void HelpScreen::handleEventsContent(sf::Event & evnt)
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			this->man->resumePrevState();
			break;
		}
	}

	void HelpScreen::updateContent(float dt)
	{
	}

	void HelpScreen::draw()
	{
		this->win->draw(this->rect);
	}
}

