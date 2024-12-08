#include "Game.hpp"

Game::Game():
window(sf::VideoMode(1000,700), "Pong"),
player1(sf::Vector2f{120.f,10.f}),
player2(sf::Vector2f(120.f,10.f))
{
    window.setMouseCursorVisible(false);

    player1.rotate(90.f);
    player2.rotate(90.f);

    player1.setPosition(sf::Vector2f(100.f, 300.f));
    player2.setPosition(sf::Vector2f(900.f, 300.f));

}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (window.isOpen())
    {  
        sf::Time timePerFrame = clock.restart();
        processEvents();
        update(timePerFrame);
        render(); 
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased: 
            handlePlayerInput(event.key.code, false);
            break;

        }
    }
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{ 
    if (key == sf::Keyboard::W)
        player1IsMovingUp = isPressed;
    else if (key == sf::Keyboard::S)
        player1IsMovingDown = isPressed;

    if (key == sf::Keyboard::Up)
        player2IsMovingUp = isPressed;
    else if (key == sf::Keyboard::Down)
        player2IsMovingDown = isPressed;
}


void Game::update(sf::Time deltaTime)
{
    sf::Vector2f player1Movement; 
    sf::Vector2f player2Movement;
    float playerSpeed = 300.f;

    if (player1IsMovingUp)
        player1Movement.y -= playerSpeed * deltaTime.asSeconds();
    if (player1IsMovingDown)
        player1Movement.y += playerSpeed * deltaTime.asSeconds(); 
    if (player2IsMovingUp)
        player2Movement.y -= playerSpeed * deltaTime.asSeconds();
    if (player2IsMovingDown)
        player2Movement.y += playerSpeed * deltaTime.asSeconds();

    player1.move(player1Movement);
    player2.move(player2Movement);
}


void Game::render()
{
    window.clear();
    window.draw(player1);
    window.draw(player2);
    window.display();
}