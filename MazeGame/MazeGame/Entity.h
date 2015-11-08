#pragma once
#include <SFML\Graphics.hpp>
class Entity :
	public sf::Drawable
{
public:
	Entity(sf::Vector2f pos, sf::Vector2f size);
	~Entity();
	sf::Sprite sprite;
	sf::FloatRect GetBoundingBox() {
		return sf::FloatRect(m_position.x, m_position.y, m_size.x, m_size.y);
	}
protected:
	sf::Vector2f m_position;
	sf::Vector2f m_size;
};