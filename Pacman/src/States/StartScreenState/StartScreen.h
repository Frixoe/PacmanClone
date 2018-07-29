#pragma once

#include "../../Engine/StateManager/StateManager.h"

namespace ss
{
	class StartScreen : virtual public State
	{
	public:
		StartScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im);
		~StartScreen();

		// Inherited via State
		virtual void handleEventsContent(sf::Event &) override;
		virtual void updateContent(float dt) override;
		virtual void draw() override;
	private:
	};
}

