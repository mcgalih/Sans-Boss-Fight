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
		void level_2_Init(); void level_2_Update(float dt); void level_2_Draw();

	private:
		GameDataRef _data;
		sf::Music _bgm;

		std::vector<Heart> _heartvec;
		Heart* _heart;
		dialog* _dialog;
		box* _box;
		Health* _health;

		Sans *_sans, *sans2;

		bool firststate, stopdelay, firstStandAnim;
		std::vector<bool> change;
		float delay;
		sf::RectangleShape hp, hpback, skuy, fixglitch;
		sf::Sprite pohon;
		//float health;

		sf::Sprite stand;
		int nFrames = 10;
		sf::IntRect frames[10];
		int iFrame = 0;
		float holdtime = 0.2f;
		float time = 0.0f;
	};
}