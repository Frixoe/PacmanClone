#pragma once

#include <deque>
#include <memory>
#include <algorithm>

#include "../State/State.h"

namespace ss
{
	typedef std::shared_ptr<State> StatePtr;

	class StateManager
	{
	public:
		StateManager();
		~StateManager();

		void addState(StatePtr state, bool replace = true);
		void removeState(StatePtr state);
		void removeState();
		void updateStates(float dt);
		void drawStates();
		void handleEvents(sf::RenderWindow&);

		StatePtr getActiveState();

	private:
		std::deque<StatePtr> _states;
	};
}

