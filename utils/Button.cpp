#include "./button.hpp"

#include <iostream>
#include <cmath>

Button::Button(const std::string& path) {
    if(!m_font.loadFromFile(path)) {
        std::cerr << "Error loading font file!! No text will be rendered on button!" << std::endl;
        return;
    }

    m_text.setFont(m_font);
}

void Button::draw(sf::RenderWindow& surface, const sf::Event& event) {
    m_button.setPosition(pos);
    m_button.setSize(size);
    m_button.setFillColor(filledColor);
    m_button.setOutlineColor(outlineColor);
    m_button.setOutlineThickness(outlineThickness);

    m_text.setString(string);
    m_text.setFillColor(fontColor);
    m_text.setCharacterSize(std::max(size.x/string.size(), size.y/2));
    m_text.setPosition(sf::Vector2f(pos.x + size.x/2 - m_text.getLocalBounds().width/2, pos.y + size.y/2 - m_text.getLocalBounds().height/2 - m_text.getLocalBounds().top));

    if(buttonPressed) { m_button.setFillColor(ClickColor); }

    surface.draw(m_button);
    surface.draw(m_text);
}

bool Button::buttonClicked(const sf::Event& event, const sf::Vector2f& mousePos) {
    if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && !buttonPressed) {
        if(mousePos.x >= pos.x && mousePos.x <= pos.x + size.x) {
            if(mousePos.y >= pos.y && mousePos.y <= pos.y + size.y) {
                buttonPressed = true;
                return true;
            }
        }  
    }
    else if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && buttonPressed) {
        buttonPressed = false;
    }
    return false;
}