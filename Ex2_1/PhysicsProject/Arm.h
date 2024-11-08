#pragma once
#include "Utils.h"
#include "IKSegment.h"

class Arm
{
public:
	Arm(vec2f _startPos);
	~Arm();
	void Update(sf::RenderWindow& _window);
	void Draw(sf::RenderWindow& _window);

private:
	// Rendering
	Vert m_Line[2];
	
	std::vector<IKSegment*> m_Segments;
};

