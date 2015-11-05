#include "Enemy.h"


Enemy::Enemy(sf::Vector2f pos, sf::Vector2f size)
	: Entity(pos, size)
{
}


Enemy::~Enemy()
{
}

void Enemy::Move(float delta) {
	m_position += m_direction * m_speed * delta;
	m_drawShape.setPosition(m_position);
}

void Enemy::SetDirection(sf::Vector2f newDir) {
	m_direction = newDir;
}

void Enemy::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(m_drawShape, states);
}