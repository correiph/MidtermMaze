#pragma once
#include <vector>
#include <SFML\Graphics\Drawable.hpp>
#include "Tile.h"
#include "TileSet.h"

class Layer :
	public sf::Drawable
{
public:
	Layer(std::string name);
	virtual ~Layer();
	void SetTileSet(TileSet &ts) {
		m_tileSet = &ts;
	}
	bool loadFromXML(tinyxml2::XMLElement *el);
	std::string name;
	std::vector<std::vector<Tile>>* GetTiles(){ return &m_tiles; };
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	TileSet *m_tileSet;
	std::vector<std::vector<Tile>> m_tiles;
	int m_width, m_height;
};

