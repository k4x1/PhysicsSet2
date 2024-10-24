#include "Arm.h"

Arm::Arm(vec2f _startPos)
{
	m_Line[0].color = sf::Color::Green;
	m_Line[1].color = sf::Color::Green;

	for (int i = 0; i < 20; i++)
	{
		IKSegment* NewSegment = new IKSegment(50, vec2f(_startPos.x + (i*50), _startPos.y ));
		m_Segments.push_back(NewSegment);
	}
}

Arm::~Arm()
{
	for (auto iter : m_Segments)
	{
		delete iter;
	}
}

void Arm::Update(sf::RenderWindow& _window)
{
	if (m_Segments.size() == 0) return;
	vec2f MousePos = vec2f(sf::Mouse::getPosition(_window));

	m_Segments[0]->Follow(MousePos);

	for (int i = 1; i < m_Segments.size(); i++)
	{
		m_Segments[i]->Follow(m_Segments[i - 1]->GetStartPos());
	}

}

void Arm::Draw(sf::RenderWindow& _window)
{
	for (auto iter : m_Segments)
	{
		iter->Draw(_window, m_Line);
	}
}
