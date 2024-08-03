#include "SliderFloat.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>


static float mapValue(float value, float inMin, float inMax, float outMin, float outMax) {
    return outMin + (value - inMin) * (outMax - outMin) / (inMax - inMin);
}

std::string to_string_with_precision(double value, int precision) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision) << value;
    return out.str();
}

SliderFloat::SliderFloat(const std::string& path) 
    : m_track(path), m_handle(path) {

}

bool SliderFloat::mouseHover(const sf::Vector2f& mousePos) {
    if(mousePos.x >= m_track.pos.x && mousePos.x <= m_track.pos.x + m_track.size.x) {
        if(mousePos.y >= m_track.pos.y && mousePos.y <= m_track.pos.y + m_track.size.y) {
            return true;
        }
    }
    return false;
}

void SliderFloat::moveHandle(const sf::Event& event, const sf::Vector2f& mousePos) {
    if(mouseHover(mousePos) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        if(mousePos.x >= m_track.pos.x && mousePos.x <= m_track.pos.x + m_track.size.x - m_handle.size.x) {
            m_handle.pos.x = mousePos.x;
        }
    }
}

void SliderFloat::setRange(int start, int end) {
    m_start = start;
    m_end = end;
}

void SliderFloat::setPositionAndSize(const sf::Vector2f& pos, const sf::Vector2f& size) {
    m_track.pos   = pos;
    m_track.size  = size;

    // m_handle.pos  = { pos.x, pos.y - (size.y * 0.3f) };
    // m_handle.size = { size.x / 5.0f, size.y + (size.y * 0.6f) };

    // m_handle.pos  = { pos.x, pos.y };
    // m_handle.size = { size.x / 5.0f, size.y };

    m_handle.pos  = { pos.x, pos.y + (size.y * 0.1f) };
    m_handle.size = { size.x / 5.0f, size.y - (size.y * 0.2f) };
}

void SliderFloat::setColors(const sf::Color& fillColor, const sf::Color& clickColor, const sf::Color& fontColor, const sf::Color& outlineColor) {
    m_track.filledColor  = fillColor;
    m_track.ClickColor   = clickColor;
    m_track.fontColor    = fontColor;
    m_track.outlineColor = outlineColor;

    m_handle.filledColor  = sf::Color(0, 0, 0, 127); // transparent
    m_handle.ClickColor   = clickColor;
    m_handle.fontColor    = fontColor;
    m_handle.outlineColor = outlineColor;
}

void SliderFloat::setOutlineThickness(float outlineThickness) {
    m_track.outlineThickness  = outlineThickness;
    m_handle.outlineThickness = outlineThickness;
}


float SliderFloat::getCurrentValue() const {
    return m_current;
}

void SliderFloat::draw(sf::RenderWindow& surface, const sf::Event& event) {

    sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(surface);
    moveHandle(event, mousePos);

    m_current = mapValue(m_handle.pos.x, m_track.pos.x, m_track.pos.x + m_track.size.x - m_handle.size.x, m_start, m_end);    
    m_handle.string = to_string_with_precision(m_current, 1);

    m_track.draw(surface, event);
    m_handle.draw(surface, event);
}

