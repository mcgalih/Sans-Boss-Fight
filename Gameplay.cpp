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
		_bgm.setVolume(60);

		_dialog = new dialog(_data);
		_heart = new Heart(_data);
		_box = new box(_data, _heart);
		_health = new Health(_data);
		_sans = new Sans(_data);
		_shake = new Shake(_data);

		skuy.setSize(sf::Vector2f{ 120.0f, 25.0f });
		skuy.setFillColor(sf::Color::Green);
		skuy.setOrigin(120.0f / 2.0f, 0.0f);
		skuy.setPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 + 50);

		stand.setTexture(_data->assets.GetTexture(STAND));
		stand.setPosition(80.0f, 200.0f);

		int width = stand.getLocalBounds().width;
		int height = stand.getLocalBounds().height;
		for (int i = 0; i < nFrames; i++)
		{
			frames[i] = { 0 + i * width / nFrames , 0, width / nFrames , height };
		}

		level_1_Init();
		level = 1;
	}

	void Gameplay::HandleInput()
	{
		sf::Event event;
		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{
				_data->window.close();
				_bgm.stop();
			}
		}
	}

	void Gameplay::Update(float dt)
	{

		switch (level)
		{
		case 1: level_1_Update(dt);
			break;
		case 2: level_2_Update(dt);
			break;
		default:
			break;
		}
	}

	void Gameplay::Draw(float dt)
	{
		_data->window.clear();
		_health->draw();

		switch (level)
		{
		case 1: level_1_Draw();
			break;
		case 2: level_2_Draw();
			break;
		default:
			break;
		}
		
		_data->window.display();
	}
}