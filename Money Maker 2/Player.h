#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

class Player
{
public:
	Player();
	virtual ~Player();

	sf::Sprite getSprite() const;

	void Update(sf::RenderWindow* window);
	void Render(sf::RenderTarget& target);
private:
	sf::Texture* mTexture;
	sf::Sprite mSprite;
	sf::Text mText;
	sf::Font mFont;

	double mMoney;
	bool mMousePressed;
};

