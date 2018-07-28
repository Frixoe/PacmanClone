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

	void StateManager::addState(StatePtr state, bool replace)
	{
		bool hadStates = !this->_states.empty();

		this->_states.emplace_front(state);
		this->_states.front()->init(state);

		if (hadStates && replace) this->_states.erase(this->_states.begin() + 1);
	}

	void StateManager::removeState(StatePtr state)
	{
		for (size_t i = 0; i < this->_states.size(); ++i)
		{
			if (this->_states.at(i) == state && i != 0)
			{
				this->_states.erase(this->_states.begin() + i);
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
		for (StatePtr s : this->_states) { s->draw(); }
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
}

