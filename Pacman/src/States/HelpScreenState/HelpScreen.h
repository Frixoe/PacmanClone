#pragma once

#include "../../Engine/StateManager/StateManager.h"

namespace ss
{
	class HelpScreen : virtual public State
	{
	public:
		HelpScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im);
		~HelpScreen();

		// Inherited via State
		virtual void handleEventsContent(sf::Event &) override;
		virtual void updateContent(float dt) override;
		virtual void draw() override;
	private:
		sf::RectangleShape rect;
	};
}

