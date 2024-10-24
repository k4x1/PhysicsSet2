#pragma once
#include "Utils.h"

class FKSegment
{
public:
	FKSegment(float _length, vec2f _startPos);
	~FKSegment();
	// Adds sway
	void Update(Clock& _clock);

	// Combined lenghts with angles to set end location
	void CalculateLocations();

	void Draw(sf::RenderWindow& _window, Vert _line[2]);

	// Adds segment to the end of the chain
	void AddChild(float _length);

	void SetStartPosition(vec2f _startPos);
	void AddParentAngle(float _parentAngle);
private:
	FKSegment* m_Child = nullptr;

	vec2f m_StartPos;
	vec2f m_EndPos;
	float m_Length;

	float m_WorldAngle = -1.57f;
	float m_LocalAngle = 0;

	float m_SwayStrength = 0.1f;
	float m_SwaySpeed = 1.0f;
	float m_SwayOffset= 0.0f;
	
};

