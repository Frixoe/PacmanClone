#pragma once
#include <SFML/Graphics.hpp>

#include "../AssetManager/AssetManager.h"
#include "../InteractionManager/InteractionManager.h"
#include <memory>

namespace ss
{
	class StateManager;
	class State;
	typedef std::shared_ptr<State> StatePtr;

	class State
	{
	public:
		State(sf::RenderWindow* win, StateManager* man, AssetManager* am, InteractionManager* im)
			: win(win), man(man), aMan(am), iMan(im) {}

		// Overridable methods
		virtual void init(StatePtr me) { this->_pause = false; this->_isRunning = true; this->myPtr = me; }
		virtual void handleEventsContent(sf::Event&) = 0;
		virtual void updateContent(float dt) = 0;
		virtual void draw() = 0;

		// Inheritable methods
		bool isPaused() { return _pause; }
		void setPaused(bool a) { this->_pause = a; }

		bool isRunning() { return _isRunning; }
		void setIsRunning(bool a) { this->_isRunning = a; }

		void update(float dt) { if (!this->_pause && this->_isRunning) this->updateContent(dt); }

	protected:
		bool _pause;
		bool _isRunning;

		sf::RenderWindow* win;
		StateManager* man;
		AssetManager* aMan;
		InteractionManager* iMan;
		StatePtr myPtr;
	};
}

