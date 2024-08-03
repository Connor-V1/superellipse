#include <SFML/Graphics.hpp>
#include <cmath>

#include "utils/SliderFloat.hpp"

const float WINDOW_WIDTH = 800.0f;
const float WINDOW_HEIGHT = 600.0f;

const float TWO_PI = 6.28318530718f;

void drawPoint(sf::RenderWindow& surface, const sf::Vector2f& pos, const sf::Color& color=sf::Color::White) {
    sf::Vertex point(pos, color);
    surface.draw(&point, 1, sf::Points);
}

int signum(float value) {
    if(value > 0) return 1;
    else if(value < 0) return -1;
    return 0;
}

int main() {

    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "", sf::Style::Close | sf::Style::Titlebar);

    SliderFloat nSlider("./fonts/apercuMedium.ttf");
    nSlider.setRange(-6, 6);
    nSlider.setPositionAndSize(sf::Vector2f(10, 10), sf::Vector2f(300, 30));

    SliderFloat aSlider("./fonts/apercuMedium.ttf");
    aSlider.setRange(-400, 400);
    aSlider.setPositionAndSize(sf::Vector2f(10, 50), sf::Vector2f(300, 30));

    SliderFloat bSlider("./fonts/apercuMedium.ttf");
    bSlider.setRange(100, 400);
    bSlider.setPositionAndSize(sf::Vector2f(10, 90), sf::Vector2f(300, 30));

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        window.clear();

        sf::Vector2f pos = { WINDOW_WIDTH / 2.0f, WINDOW_HEIGHT / 2.0f };

        float n = nSlider.getCurrentValue();
        float a = aSlider.getCurrentValue();
        float b = bSlider.getCurrentValue();
        for(float angle = 0; angle <= TWO_PI; angle += 0.01) {
            float x = pos.x + std::pow(std::abs(std::cos(angle)), 2/n) * a * signum(std::cos(angle));
            float y = pos.y + std::pow(std::abs(std::sin(angle)), 2/n) * b * signum(std::sin(angle));

            drawPoint(window, sf::Vector2f(x, y));
        }

        nSlider.draw(window, event);
        aSlider.draw(window, event);
        bSlider.draw(window, event);

        window.display();
    }

    return 0;
}