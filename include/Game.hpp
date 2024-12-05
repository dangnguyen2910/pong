#ifndef Game_H
#define Game_H

#include <SFML/Graphics.hpp>

class Game
{
    public: 
        Game();
        void run();

    private: 
        void processEvents();
        void update();
        void render();

    private: 
        sf::RenderWindow window; 
        sf::RectangleShape player1; 
        sf::RectangleShape player2;
};

#endif