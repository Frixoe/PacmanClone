#include "StartScreen.h"

namespace ss
{
	StartScreen::StartScreen(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
		:
		State(win, man, am, im),
		cBtnId(0),
		title(*this->aMan->getTexture("pacman_title", "Resources/Images/pacman_title.png")),
		background(*this->aMan->getTexture("sc_background", "Resources/Images/startscreen_background.jpg"))
	{
		this->title.move({ 115.0f, 0.0f });

		const float scale = 0.49f;
		this->background.setPosition({ 6.5f, 5.0f });
		this->background.setScale(scale, scale - 0.045f);

		const int textSize = 50;
		//const float spacing = 65.0f;
		const float spacing = 80.0f;
		const float btnXs = this->win->getSize().x / 2.0f;

		sf::Font* font = this->aMan->getFont("emulogic", "Resources/Fonts/pacfont.ttf");

		sf::Color btnSC = sf::Color::Color(0, 149, 255);

		this->playBtn = CustomButton(
			{ btnXs, 230.0f },
			{ 0.0f, 0.0f },
			"play",
			font,
			textSize,
			this->iMan,
			true,
			0,
			btnSC,
			sf::Color::Yellow
		);

		this->scoresBtn = CustomButton(
			{ btnXs, this->playBtn.getRect().getPosition().y + spacing },
			{ 0.0f, 0.0f },
			"scores",
			font,
			textSize,
			this->iMan,
			true,
			1,
			btnSC,
			sf::Color::Yellow
		);

		this->helpBtn = CustomButton(
			{ btnXs, this->scoresBtn.getRect().getPosition().y + spacing },
			{ 0.0f, 0.0f },
			"help",
			font,
			textSize,
			this->iMan,
			true,
			2,
			btnSC,
			sf::Color::Yellow
		);

		this->quitBtn = CustomButton(
			{ btnXs, this->helpBtn.getRect().getPosition().y + spacing },
			{ 0.0f, 0.0f },
			"quit",
			font,
			textSize,
			this->iMan,
			true,
			3,
			btnSC,
			sf::Color::Yellow
		);

		this->btns = { this->playBtn, this->scoresBtn, this->helpBtn, this->quitBtn };
	}

	StartScreen::~StartScreen()
	{
	}

	void StartScreen::handleEventsContent(sf::Event & evnt)
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				--this->cBtnId;
				if (this->cBtnId < 0) this->cBtnId = this->btns.size() - 1;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				++this->cBtnId;
				if (this->cBtnId > this->btns.size() - 1) this->cBtnId = 0;
			}

			if (this->scoresBtn.idMatch(this->cBtnId)) this->scoresBtnPressed();
			if (this->quitBtn.idMatch(this->cBtnId)) this->win->close();
			if (this->playBtn.idMatch(this->cBtnId)) this->playBtnPressed();
			if (this->helpBtn.idMatch(this->cBtnId)) this->helpBtnPressed();
			break;
		case sf::Event::MouseButtonPressed:
			if (this->quitBtn.wasClicked(sf::Mouse::Left, *this->win)) this->win->close();
			if (this->helpBtn.wasClicked(sf::Mouse::Left, *this->win)) this->helpBtnPressed();
			if (this->playBtn.wasClicked(sf::Mouse::Left, *this->win)) this->playBtnPressed();
			if (this->scoresBtn.wasClicked(sf::Mouse::Left, *this->win)) this->scoresBtnPressed();
			break;
		}
	}

	void StartScreen::updateContent(float dt)
	{
		for (auto& btn : this->btns) btn.update(*this->win, this->cBtnId);
	}

	void StartScreen::draw()
	{
		this->win->draw(this->background);
		this->win->draw(this->title);
		for (auto& btn : this->btns) btn.draw(*this->win);
	}

	void StartScreen::playBtnPressed()
	{
		this->man->addState(std::make_shared<GameScreen>(this->win, this->man, this->aMan, this->iMan), false);
	}

	void StartScreen::scoresBtnPressed()
	{
		this->man->addState(std::make_shared<ScoresScreen>(this->win, this->man, this->aMan, this->iMan), false);
	}

	void StartScreen::helpBtnPressed()
	{
		this->man->addState(std::make_shared<HelpScreen>(this->win, this->man, this->aMan, this->iMan), false);
	}
}

