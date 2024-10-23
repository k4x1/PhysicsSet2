#include "Grass.h"


Grass::Grass(sf::RenderWindow& _window)
{
    m_Line[0].color = sf::Color::Green;
    m_Line[1].color = sf::Color::Green;

    int NumGrassBlades = 200;
    float SegmentLength = 20.0f;
    float AddedLength = 30.0f ;

    // Creates root grass objects
    for (int i = 0; i < NumGrassBlades; i++) {
        float RandomAddedLength = fmod(rand(), AddedLength);

        vec2f SegmentPos(_window.getSize().x / NumGrassBlades * i, _window.getSize().y);

        FKSegment* NewRootSegment = new FKSegment(SegmentLength + RandomAddedLength, SegmentPos);
        m_RootSegments.push_back(NewRootSegment);

        // Adds children to root segments
        for (int j = 0; j < 10; j++)
        {
            RandomAddedLength = fmod(rand(), AddedLength);
            NewRootSegment->AddChild(RandomAddedLength);
        }
    }
}

void Grass::Update(Clock& _clock)
{
    for (auto CurrentSegment : m_RootSegments)
    {
        CurrentSegment->Update(_clock);
        CurrentSegment->CalculateLocations();
    }
    
}

void Grass::Draw(sf::RenderWindow& _window)
{
    for (auto CurrentSegment : m_RootSegments)
    {
        CurrentSegment->Draw(_window, m_Line);
    }
}
