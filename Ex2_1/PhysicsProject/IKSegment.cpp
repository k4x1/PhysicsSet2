#include "IKSegment.h"

IKSegment::IKSegment(float _length, vec2f _starPos)
{
	m_Length = _length;
	m_StartPos = _starPos;

	UpdateEndLocation();
}

void IKSegment::UpdateEndLocation()
{
	float LocationX = m_Length * cos(m_Angle);
	float LocationY = m_Length * sin(m_Angle);
	
	m_EndPos = vec2f(m_StartPos.x + LocationX, m_StartPos.y + LocationY);
}

void IKSegment::Draw(sf::RenderWindow& _window, Vert _lines[2])
{
	_lines[0].position = m_StartPos;
	_lines[1].position = m_EndPos;

	_window.draw(_lines, 2, sf::Lines);
}

void IKSegment::Follow(vec2f _targetPos)
{
	vec2f TargetDir = _targetPos - m_StartPos;

	m_Angle = atan2(TargetDir.y, TargetDir.x);

	TargetDir = Physics::Normalize(TargetDir);
	TargetDir *= -m_Length;

	m_StartPos = _targetPos + TargetDir;

	UpdateEndLocation();
}

vec2f IKSegment::GetStartPos()
{
	return m_StartPos;
}
