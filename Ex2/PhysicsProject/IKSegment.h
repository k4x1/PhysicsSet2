#pragma once
#include "Utils.h"
class IKSegment
{
public:
	IKSegment(float _length, vec2f _starPos = { 0.0f, 0.0f });
	
	void UpdateEndLocation();

	void Draw(sf::RenderWindow& _window, Vert _lines[2]);

	void Follow(vec2f _targetPos);

	vec2f GetStartPos();

private:
	vec2f m_StartPos;
	vec2f m_EndPos;

	float m_Length = 1.0f;
	float m_Angle = 0.0f;
};

