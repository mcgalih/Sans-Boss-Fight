#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "Objects.hpp"

namespace Gl
{
	class Gameplay : public State
	{
	public:
		Gameplay(GameDataRef data);
		void Init();
		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		sf::Music _bgm;
		GameDataRef _data;
		Heart* _heart;
	};
}