#include "Arm.h"

Arm::Arm(vec2f _startPos) {
	m_Line[0].color = sf::Color::Green;
	m_Line[1].color = sf::Color::Green;

	for (int i = 0; i < 10; i++) {
		IKSegment* NewSegment = new IKSegment(50, _startPos);
		m_Segments.push_back(NewSegment);

		_startPos.y += 50; 
	}
}

Arm::~Arm()
{
	for (auto iter : m_Segments)
	{
		delete iter;
	}
}

void Arm::Update(sf::RenderWindow& _window) {
    if (m_Segments.size() == 0) return;

    vec2f MousePos = _window.mapPixelToCoords(sf::Mouse::getPosition(_window));

    m_Segments[0]->SetEndPos(MousePos);

    for (size_t i = 0; i < m_Segments.size() - 1; ++i) {
        m_Segments[i + 1]->SetEndPos(m_Segments[i]->GetStartPos());
    }

    sf::Vector2u windowSize = _window.getSize();
    vec2f basePosition(windowSize.x / 2.f, windowSize.y / 2.f);

    m_Segments.back()->SetStartPos(basePosition);

    for (int i = m_Segments.size() - 1; i > 0; --i) {
        m_Segments[i - 1]->SetStartPos(m_Segments[i]->GetEndPos());
    }
}

void Arm::Draw(sf::RenderWindow& _window)
{
	for (auto iter : m_Segments)
	{
		iter->Draw(_window, m_Line);
	}
}
