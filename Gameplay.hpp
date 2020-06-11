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

		void level_1_Init(); void level_1_Update(float dt); void level_1_Draw();
		void level_2_Update(float dt); void level_2_Draw();

	private:
		GameDataRef _data;
		sf::Music _bgm;

		Heart* _heart;
		dialog* _dialog;
		box* _box;
		Health* _health;
		Sans *_sans;

		bool stopdelay, firstStandAnim;
		int level;
		float delay;
		sf::RectangleShape hp, hpback, skuy;
		sf::Sprite pohon;

		sf::Sprite stand;
		int nFrames = 10;
		sf::IntRect frames[10];
		int iFrame = 0;
		float holdtime = 0.2f;
		float time = 0.0f;
	};
}