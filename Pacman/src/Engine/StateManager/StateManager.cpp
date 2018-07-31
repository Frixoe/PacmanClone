#include "StateManager.h"
#include <iostream>

namespace ss
{
	StateManager::StateManager()
	{
	}


	StateManager::~StateManager()
	{
	}

	void StateManager::addState(StatePtr state, bool replace, bool keepPrevStateRunning, bool pausePrevState)
	{
		bool hadStates = !this->_states.empty();
		
		StatePtr prevState = hadStates ? this->_states.front() : nullptr;

		state->init(state);
		this->_states.push_front(state);

		if (hadStates && replace) this->removeState(prevState);
		else if (hadStates) {
			if (!keepPrevStateRunning) prevState->setIsRunning(false);
			if (pausePrevState) prevState->setPaused(true);
		}
	}

	void StateManager::removeState(StatePtr state)
	{
		for (size_t i = 0; i < this->_states.size(); ++i)
		{
			if (this->_states.at(i) == state)
			{
				this->_states.erase(this->_states.begin() + i);
				return;
			}
		}
	}

	void StateManager::removeState()
	{
		if (!this->_states.empty())
		{
			this->_states.erase(this->_states.begin());
		}
	}

	void StateManager::updateStates(float dt)
	{
		for (StatePtr state : this->_states) { state->update(dt); }
	}

	void StateManager::drawStates()
	{
		for (StatePtr s : this->_states) { if (s->isRunning()) s->draw(); }
	}

	void StateManager::handleEvents(sf::RenderWindow& win)
	{
		sf::Event evnt;
		while (win.pollEvent(evnt))
		{
			if (evnt.type == sf::Event::Closed) win.close();

			this->_states.front()->handleEventsContent(evnt);
		}
	}

	StatePtr StateManager::getActiveState()
	{
		return this->_states.front();
	}

	StatePtr StateManager::getStateAt(const size_t idx)
	{
		return this->_states.at(idx);
	}

	void StateManager::resumePrevState()
	{
		if (!this->_states.empty())
		{
			this->_states.erase(this->_states.begin());
			this->_states.front()->setIsRunning(true);
		}
	}
}

