#include "Player.h"

Player::Player()
	:mMoney(0.0), mMousePressed(false), mMoneyMin(0.1), mMoneyMax(1.10), mRd(), mRng(mRd()), mRandomDistribution(mMoneyMin, mMoneyMax)
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

sf::Sprite Player::getSprite() const
{
	return mSprite;
}

void Player::UpgradeMoneyMax()
{
	mMoneyMax += 1.5;
	std::uniform_real_distribution<double> tempDistribution(mMoneyMin, mMoneyMax);

	mRandomDistribution = tempDistribution;

}

void Player::Update(sf::RenderWindow* window)
{
	mSprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(*window)));

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mMousePressed)
	{
		mMoney += mRandomDistribution(mRng);
		mMousePressed = true;
	}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		mMousePressed = false;
	}

	std::stringstream ss;

	ss << "Money: " << mMoney << '\n';
	ss << "Max Money range is: " << mMoneyMin << '/' << mMoneyMax;

	mText.setString(ss.str());

}

void Player::Render(sf::RenderTarget& target)
{
	target.draw(mSprite);
	target.draw(mText);
}
