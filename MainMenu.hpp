#pragma once
#include "State.hpp"
#include "Game.hpp"

namespace Gl
{
	class MainMenu : public State
	{
	public:
		MainMenu(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;
		sf::Sprite _background;
	};
}