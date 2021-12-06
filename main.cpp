// Game Build - Main
// Built by: Brian Horner
//

// --- Prebuilt Includes ---
#include <iostream>



// --- SFML Includes ---
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>


// --- User Built Includes ---


// -- Function templates --
void movePlayer(sf::Event& event, sf::CircleShape player);
float DeltaTime();
const int APP_WIDTH{800};
const int APP_HEIGHT{800};
const float rotationSpeed{0.5};


// --- Bullet Class ---
// Was not able to implement this
class Bullet{
    sf::RectangleShape bulletshape;
    Bullet(){
        sf::RectangleShape bulletshape(sf::Vector2f(20,20));
        Draw();
    }
    sf::RectangleShape Draw(){
        bulletshape.setPosition(250, 250);
        bulletshape.setSize(sf::Vector2f(20,20));
        bulletshape.setFillColor(sf::Color::White);
    }
};

int main(){

    // Creating window
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 800),
                  "Astroids", sf::Style::Titlebar|sf::Style::Close);

    // Creating player
    sf::CircleShape player;
    player.setOutlineColor(sf::Color::White);
    player.setFillColor(sf::Color::Black);
    player.setOutlineThickness(1);
    player.setRadius(12);
    player.setPointCount(3);
    player.setPosition(400,400);





    // --- Game loop ---
    while(window.isOpen()){
        // Event handling
        sf::Event event;
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::Closed:
                    window.close();
                    break;


            }
        }


        /// --- Player movement and rotation ---
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)){
            player.move(0.0, -0.05);
            if(player.getPosition().y <-25.0){
                player.setPosition(player.getPosition().x, 825.00);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)){
            player.move(0.0, 0.05);
            if(player.getPosition().y >775.00){
                player.setPosition(player.getPosition().x, -25.0);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            player.move((0.05), 0.0);
            player.rotate(0.05 *rotationSpeed+DeltaTime());

            if (player.getPosition().x > 775.0){
                player.setPosition(-25.0, player.getPosition().y);
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move((-0.05), 0.0);
            player.rotate(-0.05 *rotationSpeed+DeltaTime());
            if (player.getPosition().x < -25.0){
                player.setPosition(825.0, player.getPosition().y);
            }

        }


        // Display
        window.display();
        window.clear(sf::Color::Black);
        window.draw(player);

    }
    return 0;

}


float DeltaTime(){
    sf::Clock dtClock;
    std::cout << static_cast<int>(dtClock.restart().asSeconds()) <<std::endl;
    return dtClock.restart().asSeconds();
}