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
		GameDataRef _data;
		sf::Music _bgm;
		Heart* _heart;
		Sans* _sans;
		dialog* _dialog;

		sf::RectangleShape left, up, bottom, right;
		sf::RectangleShape box, hp, hpback, skuy;
		float health;
		sf::Sprite stand;
	};
}