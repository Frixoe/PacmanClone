#include "ScoresScreen.h"

namespace ss
{
	ScoresScreen::ScoresScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		: State(win, man, am, im)
	{
		this->rect = sf::RectangleShape(sf::Vector2f(100.0f, 300.0f));
		this->rect.setPosition({ 20.0f, 20.0f });
	}


	ScoresScreen::~ScoresScreen()
	{
	}

	void ScoresScreen::handleEventsContent(sf::Event & evnt)
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			this->man->resumePrevState();
			break;
		}
	}

	void ScoresScreen::updateContent(float dt)
	{
	}

	void ScoresScreen::draw()
	{
		this->win->draw(this->rect);
	}
}

