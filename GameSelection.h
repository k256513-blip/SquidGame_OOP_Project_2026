
#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"

class GameSelection
{
private:

    sf::Font font;

    sf::Texture backgroundTexture;
    sf::Sprite background;

    sf::Text title;

    sf::Text redLightGreenLight;
    sf::Text dalgona;

    sf::Text continueButton;

    sf::RectangleShape redLightButton;
    sf::RectangleShape dalgonaButton;
    sf::RectangleShape continueButtonBox;

    bool redLightSelected;
    bool dalgonaSelected;


public:

    GameSelection();

    GameState handleInput(sf::Event& event);

    void draw(sf::RenderWindow& window);

    bool isRedLightSelected();
    bool isDalgonaSelected();
    void resetSelection();
    
};
