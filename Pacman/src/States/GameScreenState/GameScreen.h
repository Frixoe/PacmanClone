#pragma once

#include "../../Engine/StateManager/StateManager.h"

namespace ss
{
	class GameScreen : virtual public State
	{
	public:
		GameScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im);
		~GameScreen();

		// Inherited via State
		virtual void handleEventsContent(sf::Event &) override;
		virtual void updateContent(float dt) override;
		virtual void draw() override;
	private:
		sf::RectangleShape rect;
	};
}

