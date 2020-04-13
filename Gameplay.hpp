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

		void level_1_Init();
		void level_1_Update(float dt);
		void level_1_Draw();

	private:
		sf::RectangleShape left, up, bottom, right;
		sf::RectangleShape box, hp, hpback, skuy;
		float health;
		sf::Music _bgm;
		sf::Clock _clock;
		GameDataRef _data;
		Heart* _heart;
		Sans* _sans;
	};
}