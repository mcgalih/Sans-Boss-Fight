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

		void level_1(float dt);
		void Draw_level_1();

	private:
		sf::RectangleShape left, up, bottom, right;
		sf::RectangleShape box;
		sf::Music _bgm;
		sf::Clock _clock;
		GameDataRef _data;
		Heart* _heart;
		bool _level1;
	};
}