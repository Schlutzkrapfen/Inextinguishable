#pragma once

#include "FPS.hpp"
#include "GameStateManager.h"

#include <TGUI/Backend/SFML-Graphics.hpp>

namespace mmt_gd
{
    class InputManager;
    class DebugDraw;
    class AssetManager;
    class GameStateManager;
    class ConfigurationManager;

    class Game
    {
    public:
        Game();
        static Game& Instance();

        sf::RenderWindow& getWindow()
        {
            return m_window;
        }
        static tgui::Gui& getGui();

        void run();
        sf::String score;

    private:
        bool init();
        void update();
        void draw();
        void bindKeys();
        void shutdown() const;

        sf::RenderWindow      m_window;
        GameStateManager      m_gameStateManager;
        InputManager* m_inputManager = nullptr;
        DebugDraw* m_debugDraw = nullptr;
        ConfigurationManager* m_configurationmanager = nullptr;
        AssetManager*         m_assetManager         = nullptr;
        Fps           m_fps;
        static tgui::Gui m_gui;
    };
} // namespace mmt_gd
