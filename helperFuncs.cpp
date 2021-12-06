// Helper Functions
// Built by: Brian Horner
//
// Edit History:
// 12/6/2021

// --- SFML Includes ---
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>

// -- Consts --
const int APP_WIDTH{800};
const int APP_HEIGHT{800};
const float rotationSpeed{0.3};

void movePlayer(sf::RenderWindow& window, sf::Event& event, sf::CircleShape
player){
    while (window.isOpen()){
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
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
            player.rotate(0.05 *rotationSpeed);

            if (player.getPosition().x > 775.0){
                player.setPosition(-25.0, player.getPosition().y);
            }

        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            player.move((-0.05), 0.0);
            player.rotate(-0.05 *rotationSpeed);
            if (player.getPosition().x < -25.0){
                player.setPosition(825.0, player.getPosition().y);
            }

        }

    }
}