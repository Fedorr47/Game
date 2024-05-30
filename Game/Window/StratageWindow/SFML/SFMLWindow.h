#pragma once

import InterfaceWindow;
#include <SFML/Graphics.hpp>

class SFMLWindow : public IWindow {
private:
    sf::RenderWindow window_;

public:
    SFMLWindow() = default;
    ~SFMLWindow() override = default;

    void create();
    void close() { window_.close(); }
    void clear() { window_.clear(); }
    void begin_draw() { window_.clear(sf::Color::Black); }
    void end_draw() { window_.display(); }
    void update();

    bool is_open() const { return window_.isOpen(); }
    bool is_done();
    bool is_fullscreen();
    bool is_focused();

    void handle_events() override 
    {
        sf::Event event;
        while (window_.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window_.close();
            }
        }
    }
    sf::RenderWindow& get_window() { return window_; }
};
