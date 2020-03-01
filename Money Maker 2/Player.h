#pragma once

#include <SFML/Graphics.hpp>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <random>
#include <iostream>

struct Life
{
	unsigned int life;
	double rebornPrice;
	double lifeMuilpier;

	Life(int lLife = 1, double rebornPrice = 100, double lifeMulilpy = 0.2)
		:life(lLife), rebornPrice(rebornPrice), lifeMuilpier(lifeMulilpy)
	{
	}
};


class Player
{
public:
	Player();
	virtual ~Player();

	sf::Sprite getSprite() const;

	void Reborn();
	void ChangeFont(std::string filename);
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

	Life mLife;

	bool mMousePressed;
};

