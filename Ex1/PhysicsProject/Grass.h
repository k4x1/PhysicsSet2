#pragma once
#include "Utils.h"
#include "FKSegment.h"

class Grass
{
public:
	Grass(sf::RenderWindow& _window);

	void Update(Clock& _clock);

	void Draw(sf::RenderWindow& _window);

private:
	std::vector<class FKSegment*> m_RootSegments;

	Vert m_Line[2];
};

