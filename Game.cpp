
#include "Game.h"

#include <string>


// =============================================================
// CONSTRUCTOR
// =============================================================

Game::Game()

    : player("Player 1", sf::Color::Blue),

    cpu1("Player 2", 70, sf::Color::Red),
    cpu2("Player 3", 80, sf::Color::Green),
    cpu3("Player 4", 60, sf::Color::Yellow),
    cpu4("Player 5", 90, sf::Color::Magenta),
    cpu5("Player 6", 50, sf::Color::Cyan),

    cpu6("Player 7", 75, sf::Color(255, 128, 0)),
    cpu7("Player 8", 65, sf::Color(128, 0, 255)),
    cpu8("Player 9", 85, sf::Color(255, 105, 180)),
    cpu9("Player 10", 55, sf::Color(128, 128, 128)),
    cpu10("Player 11", 95, sf::Color(255, 255, 255)),

    cpu11("Player 12", 68, sf::Color(139, 69, 19)),
    cpu12("Player 13", 72, sf::Color(0, 128, 128)),
    cpu13("Player 14", 88, sf::Color(255, 215, 0)),
    cpu14("Player 15", 62, sf::Color(0, 191, 255)),
    cpu15("Player 16", 78, sf::Color(160, 32, 240)),

    redLightGreenLight(
        player,
        cpu1,
        cpu2,
        cpu3,
        cpu4,
        cpu5,
        cpu6,
        cpu7,
        cpu8,
        cpu9,
        cpu10,
        cpu11,
        cpu12,
        cpu13,
        cpu14,
        cpu15
    ),

    dalgona(
        &player,
        &cpu1,
        &cpu2,
        &cpu3,
        &cpu4,
        &cpu5
    )

{
    window.create(
        sf::VideoMode(1280, 720),
        "Squid Games"
    );

    window.setFramerateLimit(60);


    // =========================================================
    // INITIAL GAME STATE
    // =========================================================

    currentState = GameState::MainMenu;

    selectedBotCount = 15;

    paused = false;

    countdownActive = false;
    countdownNumber = 3;

    playerWon = false;


    // =========================================================
    // CPU POINTER ARRAY
    // =========================================================

    cpuPlayers[0] = &cpu1;
    cpuPlayers[1] = &cpu2;
    cpuPlayers[2] = &cpu3;
    cpuPlayers[3] = &cpu4;
    cpuPlayers[4] = &cpu5;

    cpuPlayers[5] = &cpu6;
    cpuPlayers[6] = &cpu7;
    cpuPlayers[7] = &cpu8;
    cpuPlayers[8] = &cpu9;
    cpuPlayers[9] = &cpu10;

    cpuPlayers[10] = &cpu11;
    cpuPlayers[11] = &cpu12;
    cpuPlayers[12] = &cpu13;
    cpuPlayers[13] = &cpu14;
    cpuPlayers[14] = &cpu15;


    // =========================================================
    // FONT
    // =========================================================

    font.loadFromFile("arial.ttf");


    // =========================================================
    // BOT COUNT DISPLAY
    // =========================================================

    botCountText.setFont(font);

    botCountText.setCharacterSize(24);

    botCountText.setFillColor(
        sf::Color::White
    );

    botCountText.setPosition(
        950.0f,
        620.0f
    );

    botCountText.setString(
        "Bots: 15   [ / ]"
    );


    // =========================================================
    // COUNTDOWN BOX
    // =========================================================

    countdownBox.setSize(
        sf::Vector2f(300, 140)
    );

    countdownBox.setPosition(
        490, 290
    );

    countdownBox.setFillColor(
        sf::Color(60, 60, 60, 230)
    );

    countdownBox.setOutlineColor(
        sf::Color::White
    );

    countdownBox.setOutlineThickness(3.0f);


    countdownText.setFont(font);

    countdownText.setCharacterSize(72);

    countdownText.setFillColor(
        sf::Color::White
    );

    countdownText.setString("3");

    countdownText.setPosition(
        625, 315
    );


    // =========================================================
    // PAUSE OVERLAY
    // =========================================================

    pauseOverlay.setSize(
        sf::Vector2f(1280, 720)
    );

    pauseOverlay.setFillColor(
        sf::Color(255, 255, 255, 70)
    );


    resumeButtonBox.setSize(
        sf::Vector2f(220, 60)
    );

    resumeButtonBox.setPosition(
        530, 280
    );

    resumeButtonBox.setFillColor(
        sf::Color(60, 60, 60)
    );

    resumeButtonBox.setOutlineColor(
        sf::Color::White
    );

    resumeButtonBox.setOutlineThickness(2.0f);


    mainMenuButtonBox.setSize(
        sf::Vector2f(220, 60)
    );

    mainMenuButtonBox.setPosition(
        530, 370
    );

    mainMenuButtonBox.setFillColor(
        sf::Color(60, 60, 60)
    );

    mainMenuButtonBox.setOutlineColor(
        sf::Color::White
    );

    mainMenuButtonBox.setOutlineThickness(2.0f);


    resumeButton.setFont(font);

    resumeButton.setString("Resume");

    resumeButton.setCharacterSize(28);

    resumeButton.setFillColor(
        sf::Color::White
    );

    resumeButton.setPosition(
        585, 293
    );


    mainMenuButton.setFont(font);

    mainMenuButton.setString("Main Menu");

    mainMenuButton.setCharacterSize(28);

    mainMenuButton.setFillColor(
        sf::Color::White
    );

    mainMenuButton.setPosition(
        565, 383
    );


    // =========================================================
    // RESULT BOX
    // =========================================================

    resultBox.setSize(
        sf::Vector2f(620, 280)
    );

    resultBox.setPosition(
        330, 220
    );

    resultBox.setFillColor(
        sf::Color(30, 30, 30, 230)
    );

    resultBox.setOutlineColor(
        sf::Color::White
    );

    resultBox.setOutlineThickness(3.0f);


    resultText.setFont(font);

    resultText.setCharacterSize(52);

    resultText.setFillColor(
        sf::Color::Red
    );


    returnToMenuButtonBox.setSize(
        sf::Vector2f(280, 60)
    );

    returnToMenuButtonBox.setPosition(
        500, 405
    );

    returnToMenuButtonBox.setFillColor(
        sf::Color(60, 60, 60)
    );

    returnToMenuButtonBox.setOutlineColor(
        sf::Color::White
    );

    returnToMenuButtonBox.setOutlineThickness(2.0f);


    returnToMenuButton.setFont(font);

    returnToMenuButton.setString(
        "Return to Main Menu"
    );

    returnToMenuButton.setCharacterSize(24);

    returnToMenuButton.setFillColor(
        sf::Color::White
    );

    returnToMenuButton.setPosition(
        520, 420
    );
}


// =============================================================
// PREPARE CONTESTANTS
// =============================================================

void Game::prepareContestants()
{
    player.revive();
    player.resetForNextGame();


    for (int i = 0; i < 15; i++)
    {
        cpuPlayers[i]->revive();

        cpuPlayers[i]->resetForNextGame();
    }
}


// =============================================================
// REMOVE UNUSED RLGL BOTS
// =============================================================

void Game::deactivateUnusedRLGLBots()
{
    for (
        int i = selectedBotCount;
        i < 15;
        i++
        )
    {
        cpuPlayers[i]->eliminate();
    }
}


// =============================================================
// START RLGL
// =============================================================

void Game::startRedLightGreenLight()
{
    prepareContestants();

    mainMenu.stopMusic();

    redLightGreenLight.reset();

    deactivateUnusedRLGLBots();

    currentState = GameState::Playing;

    paused = false;

    startCountdown();
}


// =============================================================
// START DALGONA
// =============================================================

void Game::startDalgona()
{
    prepareContestants();

    mainMenu.stopMusic();


    activeParticipants.clear();

    activeParticipants.push_back(
        &player
    );


    for (
        int i = 0;
        i < selectedBotCount;
        i++
        )
    {
        activeParticipants.push_back(
            cpuPlayers[i]
        );
    }


    dalgona.reset();

    dalgona.setParticipants(
        activeParticipants
    );


    currentState = GameState::Dalgona;

    paused = false;

    startCountdown();
}


// =============================================================
// START COUNTDOWN
// =============================================================

void Game::startCountdown()
{
    countdownActive = true;

    countdownNumber = 3;

    countdownText.setString("3");

    countdownClock.restart();
}


// =============================================================
// FINISH CURRENT GAME
// =============================================================

void Game::finishCurrentGame()
{
    if (currentState == GameState::Playing)
    {
        playerWon =
            redLightGreenLight.didPlayerWin();
    }

    else if (currentState == GameState::Dalgona)
    {
        playerWon =
            dalgona.didPlayerWin();
    }


    if (playerWon)
    {
        resultText.setString(
            "YOU SURVIVED!"
        );

        resultText.setFillColor(
            sf::Color::Green
        );
    }

    else
    {
        resultText.setString(
            "GAME OVER"
        );

        resultText.setFillColor(
            sf::Color::Red
        );
    }


    sf::FloatRect textBounds =
        resultText.getLocalBounds();


    resultText.setOrigin(
        textBounds.left +
        textBounds.width / 2.0f,

        textBounds.top +
        textBounds.height / 2.0f
    );


    resultText.setPosition(
        640.0f,
        300.0f
    );


    currentState = GameState::GameResult;

    countdownActive = false;

    paused = false;
}


// =============================================================
// RETURN TO MAIN MENU
// =============================================================

void Game::returnToMainMenu()
{
    currentState = GameState::MainMenu;

    paused = false;

    countdownActive = false;

    gameSelection.resetSelection();
}


// =============================================================
// DRAW PAUSE OVERLAY
// =============================================================

void Game::drawPauseOverlay()
{
    window.draw(pauseOverlay);

    window.draw(resumeButtonBox);
    window.draw(resumeButton);

    window.draw(mainMenuButtonBox);
    window.draw(mainMenuButton);
}


// =============================================================
// DRAW RESULT SCREEN
// =============================================================

void Game::drawResultScreen()
{
    window.draw(resultBox);

    window.draw(resultText);

    window.draw(returnToMenuButtonBox);

    window.draw(returnToMenuButton);
}


// =============================================================
// MAIN GAME LOOP
// =============================================================

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;


        // =====================================================
        // EVENT PROCESSING
        // =====================================================

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                continue;
            }


            // =================================================
            // RETURN TO MAIN MENU FROM RESULT SCREEN
            // =================================================

            if (
                currentState == GameState::GameResult &&
                event.type == sf::Event::MouseButtonPressed &&
                event.mouseButton.button == sf::Mouse::Left
                )
            {
                float mouseX =
                    static_cast<float>(
                        event.mouseButton.x
                        );

                float mouseY =
                    static_cast<float>(
                        event.mouseButton.y
                        );


                if (
                    returnToMenuButtonBox
                    .getGlobalBounds()
                    .contains(mouseX, mouseY)
                    )
                {
                    returnToMainMenu();
                }

                continue;
            }


            // =================================================
            // ESCAPE = PAUSE
            // =================================================

            if (
                event.type == sf::Event::KeyPressed &&
                event.key.code == sf::Keyboard::Escape
                )
            {
                if (
                    currentState == GameState::Playing ||
                    currentState == GameState::Dalgona
                    )
                {
                    paused = !paused;
                }

                continue;
            }


            // =================================================
            // PAUSE MENU INPUT
            // =================================================

            if (paused)
            {
                if (
                    event.type == sf::Event::MouseButtonPressed &&
                    event.mouseButton.button == sf::Mouse::Left
                    )
                {
                    float mouseX =
                        static_cast<float>(
                            event.mouseButton.x
                            );

                    float mouseY =
                        static_cast<float>(
                            event.mouseButton.y
                            );


                    // RESUME

                    if (
                        resumeButtonBox
                        .getGlobalBounds()
                        .contains(mouseX, mouseY)
                        )
                    {
                        paused = false;
                    }


                    // MAIN MENU

                    else if (
                        mainMenuButtonBox
                        .getGlobalBounds()
                        .contains(mouseX, mouseY)
                        )
                    {
                        returnToMainMenu();
                    }
                }

                continue;
            }


            // =================================================
            // GAME SELECTION
            // =================================================

            if (currentState == GameState::GameSelection)
            {
                // DECREASE BOT COUNT

                if (
                    event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::LBracket
                    )
                {
                    if (selectedBotCount > 1)
                    {
                        selectedBotCount--;
                    }

                    botCountText.setString(
                        "Bots: " +
                        std::to_string(selectedBotCount) +
                        "   [ / ]"
                    );

                    continue;
                }


                // INCREASE BOT COUNT

                if (
                    event.type == sf::Event::KeyPressed &&
                    event.key.code == sf::Keyboard::RBracket
                    )
                {
                    if (selectedBotCount < 15)
                    {
                        selectedBotCount++;
                    }

                    botCountText.setString(
                        "Bots: " +
                        std::to_string(selectedBotCount) +
                        "   [ / ]"
                    );

                    continue;
                }


                GameState newState =
                    gameSelection.handleInput(event);


                if (newState == GameState::Playing)
                {
                    if (
                        gameSelection.isRedLightSelected() &&
                        !gameSelection.isDalgonaSelected()
                        )
                    {
                        startRedLightGreenLight();
                    }

                    else if (
                        gameSelection.isDalgonaSelected() &&
                        !gameSelection.isRedLightSelected()
                        )
                    {
                        startDalgona();
                    }
                }

                continue;
            }


            // =================================================
            // RED LIGHT, GREEN LIGHT INPUT
            // =================================================

            if (
                currentState == GameState::Playing &&
                !countdownActive &&
                !redLightGreenLight.isFinished()
                )
            {
                redLightGreenLight.handleInput(event);
            }


            // =================================================
            // DALGONA INPUT
            // =================================================

            else if (
                currentState == GameState::Dalgona &&
                !countdownActive &&
                !dalgona.isFinished()
                )
            {
                dalgona.handleInput(event);
            }
        }


        // =====================================================
        // MAIN MENU
        // =====================================================

        if (currentState == GameState::MainMenu)
        {
            mainMenu.playMusic();

            currentState =
                mainMenu.handleInput(window);

            if (currentState == GameState::GameSelection)
            {
                gameSelection.resetSelection();
            }
        }


        // =====================================================
        // COUNTDOWN
        // =====================================================

        if (countdownActive && !paused)
        {
            if (
                countdownClock.getElapsedTime().asSeconds()
                >= 1.0f
                )
            {
                countdownClock.restart();

                countdownNumber--;


                if (countdownNumber == 0)
                {
                    countdownText.setString("GO!");
                }

                else if (countdownNumber < 0)
                {
                    countdownActive = false;


                    // Reset RLGL clocks after countdown.

                    if (currentState == GameState::Playing)
                    {
                        redLightGreenLight.reset();

                        deactivateUnusedRLGLBots();
                    }


                    // Start Dalgona after countdown.

                    else if (currentState == GameState::Dalgona)
                    {
                        dalgona.startGame();
                    }
                }

                else
                {
                    countdownText.setString(
                        std::to_string(countdownNumber)
                    );
                }
            }
        }


        // =====================================================
        // GAME UPDATE
        // =====================================================

        if (!paused && !countdownActive)
        {
            if (currentState == GameState::Playing)
            {
                redLightGreenLight.update();

                if (redLightGreenLight.isFinished())
                {
                    finishCurrentGame();
                }
            }


            else if (currentState == GameState::Dalgona)
            {
                dalgona.update();

                if (dalgona.isFinished())
                {
                    finishCurrentGame();
                }
            }
        }


        // =====================================================
        // DRAWING
        // =====================================================

        window.clear();


        if (currentState == GameState::MainMenu)
        {
            mainMenu.draw(window);
        }


        else if (currentState == GameState::GameSelection)
        {
            gameSelection.draw(window);

            window.draw(botCountText);
        }


        else if (currentState == GameState::Playing)
        {
            redLightGreenLight.draw(window);
        }


        else if (currentState == GameState::Dalgona)
        {
            dalgona.draw(window);
        }


        else if (currentState == GameState::GameResult)
        {
            drawResultScreen();
        }


        // =====================================================
        // PAUSE OVERLAY
        // =====================================================

        if (paused)
        {
            drawPauseOverlay();
        }


        // =====================================================
        // COUNTDOWN OVERLAY
        // =====================================================

        if (countdownActive)
        {
            window.draw(countdownBox);

            window.draw(countdownText);
        }


        window.display();
    }
}
