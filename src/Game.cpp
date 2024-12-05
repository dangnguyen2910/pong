#include "Game.hpp"

Game::Game():
window(sf::VideoMode(1000,700), "Pong"),
player1(sf::Vector2f(120.f,50.f)),
player2(sf::Vector2f(120.f,50.f))
{
    player1.rotate(90.f);
    player2.rotate(90.f);

    player1.setPosition(sf::Vector2f(100.f, 100.f));
    player2.setPosition(sf::Vector2f(300.f, 300.f));

}

void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        update();
        render(); 
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
    }
}


void Game::update()
{

}


void Game::render()
{
    window.clear();
    window.draw(player1);
    window.draw(player2);
    window.display();
}