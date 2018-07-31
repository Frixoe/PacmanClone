#pragma once

#include "../../Engine/StateManager/StateManager.h"

namespace ss
{
	class ScoresScreen : virtual public State
	{
	public:
		ScoresScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im);
		~ScoresScreen();

		// Inherited via State
		virtual void handleEventsContent(sf::Event &) override;
		virtual void updateContent(float dt) override;
		virtual void draw() override;
	private:
		sf::RectangleShape rect;
	};
}

