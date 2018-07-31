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

		void addState(StatePtr state, bool replace = true, bool keepPrevStateRunning = false, bool pausePrevState = false);
		void removeState(StatePtr state);
		void removeState();
		void updateStates(float dt);
		void drawStates();
		void handleEvents(sf::RenderWindow&);

		StatePtr getActiveState();
		StatePtr getStateAt(const size_t idx);

		void resumePrevState();

	private:
		std::deque<StatePtr> _states;
	};
}

