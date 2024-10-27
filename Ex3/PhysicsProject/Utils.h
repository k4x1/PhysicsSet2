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
class Physics {
public:
    static float GetVectorLength(const vec2f& _vector)
    {
        return sqrt((_vector.x * _vector.x) + (_vector.y * _vector.y));
    }
    static vec2f Normalize(vec2f& _vector)
    {
        float Magnitude = GetVectorLength(_vector);
        return _vector /= Magnitude;
    }
};
