#pragma once

#include "../../Headers/CustomButton/CustomButton.h"

#include "../GameScreenState/GameScreen.h"
#include "../ScoresScreenState/ScoresScreen.h"
#include "../HelpScreenState/HelpScreen.h"

#include <vector>

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

		void playBtnPressed();
		void scoresBtnPressed();
		void helpBtnPressed();
	private:
		sf::Sprite title;
		sf::Sprite background;

		std::vector<CustomButton> btns;

		CustomButton playBtn;
		CustomButton scoresBtn;
		CustomButton helpBtn;
		CustomButton quitBtn;

		sf::Text pacmanEatingGhost;

		int cBtnId;
	};
}

