#pragma once

typedef unsigned int gid;

class Tile
{
public:
	Tile(gid g);
	~Tile();
	gid const GID;
};

