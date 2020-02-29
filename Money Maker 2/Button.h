#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button() = delete;
	Button operator=(const Button&) = delete;
	Button(const Button&) = delete;

	Button(const sf::Vector2f& position, const std::string& buttonName, const sf::Vector2f& buttonSize, const sf::Color& buttonColor);

	virtual ~Button();

	bool IsClicked(const sf::Sprite& sprite);

	void Draw(sf::RenderTarget& target);
private:
	sf::RectangleShape mButtonRect;
	sf::Text mText;
	sf::Font mFont;
	sf::Vector2f mPosition;

	bool mClicked;
};

