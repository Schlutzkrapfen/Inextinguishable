/**************************************************************************/
/*                         This file is part of:                          */
/*                             Inextinguishable                           */
/*                                                                        */
/**************************************************************************/
/* Authors:  Eleni Kuretsidis, David Messner                              */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/
#pragma once
#include "stdafx.h"

#include <filesystem>

namespace mmt_gd
{
class ConfigurationManager
{
public:
    static ConfigurationManager& Instance()
    {
        static ConfigurationManager instance;
        return instance;
    }

    struct Config
    {
        //General Configs
        sf::Vector2i m_resolution{1280, 720};
        std::string  m_windowName = "Inextinguishable";
        const std::filesystem::path m_resourcePath{"../assets"}; //Path for TileManager
        const std::string           m_path{"../assets"}; //Path for AssetManager

       //PlayerConfigs
        const float m_playerBaseAcceleration = 1000.0F;    // pixels / second
        const float m_speedDampening = 0.97f;      //factor that smooths movement
        const float   m_MaxPlayerSpeed    = 150;
        
        //Enemy Config
        const float m_AIBaseSpeed = 100.0F;
        const int   m_MaxEnemyNumber = 100;
        const int   m_initSpawnInterval = 6;
        const float   m_testSpawnInterval = 0.2;
        const sf::Vector2f m_despawnLocation{-10000, -10000};

        // Enemy & Player 
        const float m_baseHealth = 100.0f;  // default value, is used if nothing is defined in Tiled
    };

    Config& getConfig()
    {
        return m_config;
    }

private:
    ConfigurationManager() = default;

    Config m_config;
};
} // namespace mmt_gd
