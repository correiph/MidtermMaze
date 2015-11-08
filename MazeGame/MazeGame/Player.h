#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(sf::Vector2f pos, sf::Vector2f size, float speed, sf::Texture tex);
	virtual ~Player();

	void Move(float delta);
	void SetDirection(sf::Vector2f newDir);
private:
	int walking_frame;
	sf::Texture player_tex;
	sf::RectangleShape m_drawShape;
	sf::Vector2f m_direction;
	float m_speed;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

