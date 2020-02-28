#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>

class Player
{
public:
	Player();
	virtual ~Player();

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

