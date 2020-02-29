#include "Button.h"

Button::Button(const sf::Vector2f& position, const std::string& buttonName, const sf::Vector2f& buttonSize, const sf::Color& buttonColor)
	:mClicked(false)
{
	mFont.loadFromFile("Font/fast_money.ttf");
	mText.setFont(mFont);
	mText.setString(buttonName);

	mText.setPosition(position.x + 50, position.y);

	mButtonRect.setPosition(position);

	mButtonRect.setFillColor(buttonColor);
	mButtonRect.setSize(buttonSize);
}

Button::~Button()
{
}

bool Button::IsClicked(const sf::Sprite& sprite)
{
	if (mButtonRect.getGlobalBounds().contains(sprite.getPosition()))
		return true;

	return false;
}

void Button::Draw(sf::RenderTarget& target)
{
	target.draw(mButtonRect);
	target.draw(mText);
}
