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

    m_Angle = std::atan2(TargetDir.y, TargetDir.x);

    TargetDir = Physics::Normalize(TargetDir) * -m_Length;
    m_StartPos = _targetPos + TargetDir;

    UpdateEndLocation();
}


void IKSegment::SetStartPos(vec2f _startPos)
{
    m_StartPos = _startPos;

    vec2f dir = m_EndPos - m_StartPos;

    dir = Physics::Normalize(dir) * m_Length;

    m_EndPos = m_StartPos + dir;

    m_Angle = std::atan2(dir.y, dir.x);
}

void IKSegment::SetEndPos(vec2f _endPos)
{
    m_EndPos = _endPos;

    vec2f dir = m_StartPos - m_EndPos;

    dir = Physics::Normalize(dir) * m_Length;

    m_StartPos = m_EndPos + dir;

    m_Angle = std::atan2(m_EndPos.y - m_StartPos.y, m_EndPos.x - m_StartPos.x);
}

vec2f IKSegment::GetStartPos()
{
    return m_StartPos;
}


vec2f IKSegment::GetEndPos()
{
    return m_EndPos;
}

