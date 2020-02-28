#include "Player.h"

Player::Player()
	:mMoney(0.0), mMousePressed(false)
{
	mTexture = new sf::Texture();
	mTexture->loadFromFile("Graphics/money.png");
	mSprite.setTexture(*mTexture);
	mSprite.setOrigin(sf::Vector2f(mTexture->getSize() / (unsigned)2 ));

	mFont.loadFromFile("Font/fast_money.ttf");
	mText.setFont(mFont);
}

Player::~Player()
{
	delete mTexture;
}

void Player::Update(sf::RenderWindow* window)
{
	mSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mMousePressed)
	{
		mMoney += .1;
		mMousePressed = true;
	}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mMousePressed = false;
	}

	std::stringstream ss;

	ss << "Money: " << mMoney;

	mText.setString(ss.str());

}

void Player::Render(sf::RenderTarget& target)
{
	target.draw(mSprite);
	target.draw(mText);
}
