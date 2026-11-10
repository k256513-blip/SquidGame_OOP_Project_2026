#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "MainMenu.h"
#include "GameSelection.h"

#include "RedLightGreenLight.h"
#include "Dalgona.h"

#include "HumanPlayer.h"
#include "CPUPlayer.h"
#include "Participant.h"

#include "GameState.h"

class Game
{
private:

    // WINDOW
    sf::RenderWindow window;

    // CONTESTANTS
    HumanPlayer player;

    CPUPlayer cpu1;
    CPUPlayer cpu2;
    CPUPlayer cpu3;
    CPUPlayer cpu4;
    CPUPlayer cpu5;
    CPUPlayer cpu6;
    CPUPlayer cpu7;
    CPUPlayer cpu8;
    CPUPlayer cpu9;
    CPUPlayer cpu10;
    CPUPlayer cpu11;
    CPUPlayer cpu12;
    CPUPlayer cpu13;
    CPUPlayer cpu14;
    CPUPlayer cpu15;

    CPUPlayer* cpuPlayers[15];

    // MENUS
    MainMenu mainMenu;
    GameSelection gameSelection;

    // MINIGAMES
    RedLightGreenLight redLightGreenLight;
    Dalgona dalgona;

    GameState currentState;

    // BOT SELECTION
    int selectedBotCount;
    sf::Text botCountText;
    std::vector<Participant*> activeParticipants;

    // COUNTDOWN
    sf::RectangleShape countdownBox;
    sf::Text countdownText;
    sf::Clock countdownClock;
    bool countdownActive;
    int countdownNumber;

    // PAUSE SYSTEM
    bool paused;
    sf::RectangleShape pauseOverlay;
    sf::RectangleShape resumeButtonBox;
    sf::RectangleShape mainMenuButtonBox;
    sf::Text resumeButton;
    sf::Text mainMenuButton;

    // RESULT SCREEN
    sf::RectangleShape resultBox;
    sf::Text resultText;
    sf::RectangleShape returnToMenuButtonBox;
    sf::Text returnToMenuButton;
    bool playerWon;

    // SHARED FONT
    sf::Font font;

    // HELPERS
    void prepareContestants();
    void deactivateUnusedRLGLBots();
    void startRedLightGreenLight();
    void startDalgona();
    void startCountdown();
    void finishCurrentGame();
    void returnToMainMenu();
    void drawPauseOverlay();
    void drawResultScreen();

public:
    Game();
    void run();
};