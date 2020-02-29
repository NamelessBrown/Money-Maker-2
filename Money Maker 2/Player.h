#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <random>
#include <iostream>

class Player
{
public:
	Player();
	virtual ~Player();

	sf::Sprite getSprite() const;

	void UpgradeMoneyMax();
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderTarget& target);
private:
	sf::Texture* mTexture;
	sf::Sprite mSprite;
	sf::Text mText;
	sf::Font mFont;

	double mMoney;
	double mMoneyMin;
	double mMoneyMax;

	std::random_device mRd;
	std::mt19937 mRng;
	std::uniform_real_distribution<double> mRandomDistribution;


	bool mMousePressed;
};

