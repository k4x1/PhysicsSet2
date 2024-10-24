#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using vec2f = sf::Vector2f;
using vec2i = sf::Vector2i;
using Clock = sf::Clock;
using Vert = sf::Vertex;

class Debug {
public:

    template<typename T>
    static void Log(const T& message) {
        std::cout << message << std::endl;
    }


    static void Log(const vec2f& vector) {
        std::cout << "(" << vector.x << ", " << vector.y << ")" << std::endl;
    }

   
    static void Log(const vec2i& vector) {
        std::cout << "(" << vector.x << ", " << vector.y << ")" << std::endl;
    }

    template<typename First, typename... Args>
    static void Log(const First& first, const Args&... args) {
        Log(first); 
        Log(args...); 
        
    }
};
