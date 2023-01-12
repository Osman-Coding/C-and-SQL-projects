#include <SFML/Graphics.hpp>
#include <deque>

const int WIDTH = 800;
const int HEIGHT = 600;
const int BLOCK_SIZE = 20;

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Snake Game");

    // Create the snake
    std::deque<sf::RectangleShape> snake;
    for (int i = 0; i < 5; i++) {
        sf::RectangleShape block;
        block.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
        block.setFillColor(sf::Color::Green);
        block.setPosition(WIDTH / 2 - BLOCK_SIZE / 2, HEIGHT / 2 - BLOCK_SIZE / 2);
        snake.push_back(block);
    }

    // Create the food
    sf::RectangleShape food;
    food.setSize(sf::Vector2f(BLOCK_SIZE, BLOCK_SIZE));
    food.setFillColor(sf::Color::Red);
    food.setPosition(WIDTH / 2 - BLOCK_SIZE / 2, HEIGHT / 2 - BLOCK_SIZE / 2);

    // Create the clock for measuring time
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen()) {
        // Handle events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Move the snake
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        for (int i = 0; i < snake.size(); i++) {
            sf::Vector2f position = snake[i].getPosition();
            position.x += BLOCK_SIZE * time;
            snake[i].setPosition(position);
        }

        // Clear the window
        window.clear();

        // Draw the snake
        for (int i = 0; i < snake.size(); i++) {
            window.draw(snake[i]);
        }

        // Draw the food
        window.draw(food);

        // Display the window
        window.display();
    }

    return 0;
}
