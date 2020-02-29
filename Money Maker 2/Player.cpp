#include "Player.h"

Player::Player()
	:mMoney(0.0), mMousePressed(false), mMoneyMin(0.1), mMoneyMax(1.10), mRd(), mRng(mRd()), mRandomDistribution(mMoneyMin, mMoneyMax), mLife()
{
	mTexture = new sf::Texture();
	mTexture->loadFromFile("Graphics/money.png");
	mSprite.setTexture(*mTexture);
	mSprite.setOrigin(sf::Vector2f(mTexture->getSize() / (unsigned)2 ));

	const sf::Vector2f newScale{ 4.f, 4.f };  

	mSprite.setScale(mSprite.getScale().x / newScale.x , mSprite.getScale().y / newScale.y);

	mFont.loadFromFile("Font/fast_money.ttf");
	mText.setFont(mFont);
	mText.setCharacterSize(20);
}

Player::~Player()
{
	delete mTexture;
}

sf::Sprite Player::getSprite() const
{
	return mSprite;
}

void Player::Reborn()
{
	if (mMoney >= mLife.rebornPrice)
	{
		mMoneyMax += 1.5;
		std::uniform_real_distribution<double> tempDistribution(mMoneyMin, mMoneyMax);
		mRandomDistribution = tempDistribution;

		mMoney -= mLife.rebornPrice;

		mLife.rebornPrice += 75 * double((mLife.life - 1)) + 200;
	}

}

void Player::ChangeFont(std::string filename)
{
	mFont.loadFromFile(filename);
	mText.setFont(mFont);
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
	ss << "Max Money range is: " << mMoneyMin << '/' << mMoneyMax << '\n';
	ss << "Your life is: " << mLife.life << '\n';
	ss << "Your reborn price is: " << mLife.rebornPrice << '\n';

	mText.setString(ss.str());

}

void Player::Render(sf::RenderTarget& target)
{
	target.draw(mSprite);
	target.draw(mText);
}
