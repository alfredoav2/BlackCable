#include "GameStateManager.h"
#include <iostream>


GameStateManager::GameStateManager()
{
	platform = Platform::GetPtr();
}

GameStateManager::~GameStateManager()
{
}
GameStateManager* GameStateManager::getPtr()
{
	if (ptr = nullptr)
	{
		ptr =  GameStateManager();
	}
	else
	{
		return ptr;
	}
}
void GameStateManager::GameLoop()
{
	while (true)
	{
		try
		{
			if (states.size() == 0)
				throw std::exception("Error");
			auto state = states.top();
			if (state == nullptr)
			{
				break;
			}
			platform->CheckEvent(state, &GameState::Input, &GameState::MouseInput);
			state->Update();
			state->Draw();

		}
		catch (...)
		{
			std::cout << "Critical error BlackCable is closing";
			break;
		}
	}
}

void GameStateManager::SetState(GameState* state)
{
	state->Init();
	states.push(state);
}

void GameStateManager::RealaseState()
{
	auto state = states.top();
	state->Close();
	states.pop();
}