#pragma once

#include <SFML/Graphics.hpp>

class Button {
private:
    sf::RectangleShape m_button;
    sf::Font m_font;
    sf::Text m_text;

public:
    sf::Vector2f pos  = { 10.0f, 10.0f };
    sf::Vector2f size = { 120.0f, 40.0f };

    sf::Color filledColor  = sf::Color(20, 25, 30);
    sf::Color ClickColor   = sf::Color(146, 134, 148);
    sf::Color outlineColor = sf::Color::White;
    sf::Color fontColor    = sf::Color::White;

    float outlineThickness = 2.0f;
    std::string string = "";
    bool buttonPressed = false;

public:
    Button(const std::string& path="");
    void draw(sf::RenderWindow& surface, const sf::Event& event);

    bool buttonClicked(const sf::Event& event, const sf::Vector2f& mousePos);
};