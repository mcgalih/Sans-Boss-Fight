#include "Objects.hpp"

namespace Gl
{
	dialog::dialog(GameDataRef data) :_data(data)
	{
		//total karakter per baris = 24
		//panjang kotak typing per karakter = 10.0f
		Dialogbox.setTexture(_data->assets.GetTexture(DIALOG_BOX));
		Dialogbox.setPosition(450.0f, 40.0f);
		Dialogbox.setScale(0.6f, 0.6f);

		text1.setFont(_data->assets.GetFont(DIALOG_FONT));
		text1.setCharacterSize(15);
		text1.setPosition(500.0f, 60.0f);
		text1.setFillColor(sf::Color::Black);

		text2.setFont(_data->assets.GetFont(DIALOG_FONT));
		text2.setCharacterSize(15);
		text2.setPosition(500.0f, 80.0f);
		text2.setFillColor(sf::Color::Black);

		text3.setFont(_data->assets.GetFont(DIALOG_FONT));
		text3.setCharacterSize(15);
		text3.setPosition(500.0f, 100.0f);
		text3.setFillColor(sf::Color::Black);

		typing1.setPointCount(4);
		typing1.setPosition(500, 60);
		typing1.setFillColor(sf::Color::White);

		typing2.setPointCount(4);
		typing2.setPosition(500, 80);
		typing2.setFillColor(sf::Color::White);

		typing3.setPointCount(4);
		typing3.setPosition(500, 100);
		typing3.setFillColor(sf::Color::White);

		dialogsfx.setBuffer(_data->assets.GetBuffer(SANS_SOUND));
		soundstatus = true;
		display = true;
		//delay = 0.0f;

		widthmove1 = 0.0f;
		widthmove2 = 0.0f;
		widthmove3 = 0.0f;
	}

	void dialog::setString(std::string text)
	{
		str = text;
		std::string line1, line2, line3;

		typing1.setPoint(0, sf::Vector2f(widthmove1, 0.0f));
		typing1.setPoint(1, sf::Vector2f(width, 0.0f));
		typing1.setPoint(2, sf::Vector2f(width, 20.0f));
		typing1.setPoint(3, sf::Vector2f(widthmove1, 20.0f));

		typing2.setPoint(0, sf::Vector2f(widthmove2, 0.0f));
		typing2.setPoint(1, sf::Vector2f(width, 0.0f));
		typing2.setPoint(2, sf::Vector2f(width, 20.0f));
		typing2.setPoint(3, sf::Vector2f(widthmove2, 20.0f));

		typing3.setPoint(0, sf::Vector2f(widthmove3, 0.0f));
		typing3.setPoint(1, sf::Vector2f(width, 0.0f));
		typing3.setPoint(2, sf::Vector2f(width, 20.0f));
		typing3.setPoint(3, sf::Vector2f(widthmove3, 20.0f));

		if (text.length() <= 24)
		{
			line1.append(text.begin(), text.end());
			text1.setString(line1);

			widthmove1 += 5.0f;
			if (widthmove1 > width)
			{
				widthmove1 -= 5.0f;
				soundstatus = false;
			}
		}

		if ((text.length() > 24) && (text.length() <= 48))
		{
			line1.append(text.begin(), text.begin()+24);
			if(text.at(24) == ' ') line2.append(text.begin()+25, text.end());
			else line2.append(text.begin() + 24, text.end());
			text1.setString(line1);
			text2.setString(line2);

			widthmove1 += 5.0f;
			if (widthmove1 > width)
			{
				widthmove1 -= 5.0f;
				widthmove2 += 5.0f;
				if (widthmove2 > width)
				{
					widthmove2 -= 5.0f;
					soundstatus = false;
				}
			}
		}

		if ((text.length() > 48) && (text.length() <= 72))
		{
			line1.append(text.begin(), text.begin() + 24);
			if (text.at(24) == ' ') line2.append(text.begin() + 25, text.end());
			else line2.append(text.begin() + 24, text.begin() + 48);
			if (text.at(48) == ' ') line3.append(text.begin() + 49, text.end());
			else line3.append(text.begin() + 48, text.end());
			text1.setString(line1);
			text2.setString(line2);
			text3.setString(line3);

			widthmove1 += 5.0f;
			if (widthmove1 > width)
			{
				widthmove1 -= 5.0f;
				widthmove2 += 5.0f;
				if (widthmove2 > width)
				{
					widthmove2 -= 5.0f;
					widthmove3 += 5.0f;
					if (widthmove3 > width)
					{
						widthmove3 -= 5.0f;
						soundstatus = false;
					}
				}
			}
		}

		if (soundstatus == false)
		{
			dialogsfx.stop();
			//delay += 1.0f;
		}
		else
		{
			timesfx = dialogsfx.getPlayingOffset();
			dialogsfx.play();
			dialogsfx.setPlayingOffset(timesfx);
		}

	}

	bool dialog::displaying()
	{
		return display;
	}

	void dialog::draw()
	{
		if (soundstatus == true)
		{
			_data->window.draw(Dialogbox);
			_data->window.draw(text1);
			_data->window.draw(text2);
			_data->window.draw(text3);
			_data->window.draw(typing1);
			_data->window.draw(typing2);
			_data->window.draw(typing3);
		}
		else // soundstatus == false
		{
			if (display == true) // if (delay <= 40.0f)
			{
				_data->window.draw(Dialogbox);
				_data->window.draw(text1);
				_data->window.draw(text2);
				_data->window.draw(text3);
				_data->window.draw(typing1);
				_data->window.draw(typing2);
				_data->window.draw(typing3);
			}
			// if (delay == 40.0f)
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) display = false;
		}
	}











}