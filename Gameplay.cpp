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

		_heart = new Heart(_data, { 0.0f,0.0f });

		left.setSize(sf::Vector2f{ 4.0f,150.0f });
		left.setPosition(SCREEN_WIDTH/2-150, SCREEN_HEIGHT/2);
		left.setFillColor(sf::Color::Green);
		box.setSize(sf::Vector2f{ 250.0f,180.0f });
		box.setOrigin(sf::Vector2f{ 250.0f / 2.0f, 180.0f / 2.0f });
		box.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);
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
		level_1(dt);
	}

	void Gameplay::Draw(float dt)
	{
		Draw_level_1();
	}
}