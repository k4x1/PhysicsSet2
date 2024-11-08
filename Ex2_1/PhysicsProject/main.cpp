
#include "Utils.h"
#include "Arm.h"

int main()
{
    //Create the window with a set resolution:
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Project");
    
    // Sine function clock
    Clock clock;

    Arm* WormArm = new Arm(vec2f(640, 360));

    while (window.isOpen())
    {
        //Receive and deal with events here (mouse clicks, key events, window buttons etc).
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseButtonPressed:
             
              
                break;
            }

        }
        window.clear();
        WormArm->Update(window);
        WormArm->Draw(window);

        //////////////////////////////////
        window.display();
    }

    delete WormArm;

    return 0;
}