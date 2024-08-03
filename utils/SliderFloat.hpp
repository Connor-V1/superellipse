#pragma once

#include <SFML/Graphics.hpp>

#include "Button.hpp"

class SliderFloat {
private:
    Button m_track;
    Button m_handle;

    float m_start = 1;
    float m_end = 10;
    float m_current = m_start;

    std::string m_text = "";

public:
    SliderFloat(const std::string& path);
    void draw(sf::RenderWindow& surface, const sf::Event& event);

    bool mouseHover(const sf::Vector2f& mousePos);
    void moveHandle(const sf::Event& event, const sf::Vector2f& mousePos);

    void setRange(int start, int end);
    void setPositionAndSize(const sf::Vector2f& pos, const sf::Vector2f& size);
    void setColors(const sf::Color& fillColor, const sf::Color& clickColor, const sf::Color& fontColor, const sf::Color& outlineColor);
    void setOutlineThickness(float outlineThickness); 

    float getCurrentValue() const;
};