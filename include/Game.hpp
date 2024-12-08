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
        void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
        void update(sf::Time deltaTime);
        void render();

    private: 
        sf::RenderWindow window; 
        sf::RectangleShape player1; 
        sf::RectangleShape player2;

        bool player1IsMovingUp = false; 
        bool player1IsMovingDown = false; 
        bool player2IsMovingUp = false; 
        bool player2IsMovingDown = false; 
};

#endif