#include "Gameplay.hpp"
#include "DEFINITIONS.hpp"
#include <iostream>

namespace Gl
{
	Gameplay::Gameplay(GameDataRef data) :_data(data)
	{

	}

	void Gameplay::Init()
	{
		_bgm.openFromFile(BGM_FILE_PATH);
		_bgm.play();
		_bgm.setVolume(80);

		health = 120.0f;
		hp.setFillColor(sf::Color::Yellow);
		hp.setOrigin(120.0f / 2.0f, 0.0f);
		hp.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 138);

		hpback.setSize(sf::Vector2f{ 120.0f, 25.0f });
		hpback.setFillColor(sf::Color::Red);
		hpback.setOrigin(120.0f / 2.0f, 0.0f);
		hpback.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 138);

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
		hp.setSize(sf::Vector2f{ health, 25.0f });
		level_1_Update(dt);
	}

	void Gameplay::Draw(float dt)
	{
		_data->window.clear();
		_data->window.draw(hpback);
		_data->window.draw(hp);

		level_1_Draw();
		
		_data->window.display();
	}
}