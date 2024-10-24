#include "FKSegment.h"

FKSegment::FKSegment(float _length, vec2f _startPos = {0.0f,0.0f})
{
	m_Length = _length;
	m_StartPos = _startPos;

	m_SwayOffset = float(rand()) / RAND_MAX * 2;
}

FKSegment::~FKSegment()
{
	if (m_Child)
	{
		delete m_Child;
		m_Child = nullptr;
	}
}

void FKSegment::Update(Clock& _clock)
{
	m_LocalAngle = m_SwayStrength * sin((_clock.getElapsedTime().asSeconds() + m_SwayOffset) * m_SwaySpeed) ;

	m_WorldAngle = -1.57f + m_LocalAngle;

	if (m_Child) m_Child->Update(_clock);
}

void FKSegment::CalculateLocations()
{
	float LocationX = m_Length * cos(m_WorldAngle);
	float LocationY = m_Length * sin(m_WorldAngle);

	m_EndPos = vec2f(m_StartPos.x + LocationX, m_StartPos.y + LocationY);

	if (m_Child)
	{
		m_Child->SetStartPosition(m_EndPos);
		m_Child->AddParentAngle(m_WorldAngle);
		m_Child->CalculateLocations();
	}
}

void FKSegment::Draw(sf::RenderWindow& _window, Vert _line[2])
{
	_line[0].position = m_StartPos;
	_line[1].position = m_EndPos;

	_window.draw(_line, 2, sf::Lines);

	if (m_Child)
	{
		m_Child->Draw(_window, _line);
	}
}
void FKSegment::AddChild(float _length)
{
	if (m_Child) {
		m_Child->AddChild(_length);
	}
	else
	{
		m_Child = new FKSegment(_length);
	}
}

void FKSegment::SetStartPosition(vec2f _startPos)
{
	m_StartPos = _startPos;
}

void FKSegment::AddParentAngle(float _parentAngle)
{
	m_WorldAngle = m_LocalAngle + _parentAngle;
}
