#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Button
{
public:
	Button() = delete;
	Button operator=(const Button&) = delete;
	Button(const Button&) = delete;

	//Button(const sf::Vector2f& position, const std::string& buttonName, const sf::Vector2f& buttonSize, const sf::Color& buttonColor);
	Button(const sf::Vector2f& position = { 10.f, 10.f }, const std::string& buttonName = "Defualt", const sf::Color& buttonColor = sf::Color::Red,
		const sf::Vector2f& buttonSize = {50.f, 50.f} );

	virtual ~Button();

	bool IsClicked(const sf::Sprite& sprite);
	void MovePosition(const sf::Vector2f& newPosition);


	void Draw(sf::RenderTarget& target);
private:
	sf::RectangleShape mButtonRect;
	sf::Text mText;
	sf::Font mFont;

	bool mClicked;
};

