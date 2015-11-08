#pragma once
#include <string>
#include <vector>
#include <SFML\Graphics\Drawable.hpp>
#include "Layer.h"
#include "TileSet.h"

class Map :
	public sf::Drawable
{
public:
	Map();
	bool loadFromFile(std::string file);
	virtual ~Map();

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	std::vector<Layer>* GetLayers(){ return &m_layers; };
private:
	TileSet m_tileset;
	std::vector<Layer> m_layers;
	int m_width, m_height, m_tileWidth, m_tileHeight;
};

