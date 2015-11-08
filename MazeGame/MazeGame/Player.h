#pragma once
#include "Entity.h"
class Player :
	public Entity
{
public:
	Player(sf::Vector2f pos, sf::Vector2f size, float speed, sf::Texture tex);
	virtual ~Player();
	enum PLAYER_DIRECTION : int{
		DOWN = 0,
		LEFT = 1,
		RIGHT = 2,
		UP = 3,
		DOWNLEFT = 4,
		UPLEFT = 5,
		DOWNRIGHT = 6,
		UPRIGHT = 7,
		IDLE = 8
	};
	void Move(float delta);
	void SetDirection(sf::Vector2f newDir);
	sf::Vector2f *GetDirection(){ return &m_direction; };
	void SetAnimDirection(int state);

private:
	int walking_frame, walking_dir, frame_tick;
	sf::Texture player_tex;
	sf::RectangleShape m_drawShape;
	sf::Vector2f m_direction;
	float m_speed;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

