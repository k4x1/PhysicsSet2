
#include "Utils.h"
#include "Grass.h"

int main()
{
    //Create the window with a set resolution:
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML Project");
    
    // Sine function clock
    Clock clock;

    Grass* GrassManager = new Grass(window);

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
        GrassManager->Update(clock);
        GrassManager->Draw(window);
        

        //////////////////////////////////
        window.display();
    }

    return 0;
}