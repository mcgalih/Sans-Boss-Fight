#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"

namespace Gl
{
	Gameplay::Gameplay(GameDataRef data) :_data(data)
	{

	}

	void Gameplay::Init()
	{
		_bgm.openFromFile(BGM_FILE_PATH);
		_bgm.play();

		level_1_Init();
	}

	void Gameplay::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
			}
		}
	}

	void Gameplay::Update(float dt)
	{
		level_1_Update(dt);
	}

	void Gameplay::Draw(float dt)
	{
		level_1_Draw();
	}
}