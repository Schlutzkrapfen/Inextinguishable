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

#include "EventBus.hpp"

#include <SFML/Graphics.hpp>
#include <unordered_map>

namespace mmt_gd
{
class IRenderComponent;

class SpriteManager
{
public:
    using TileSetMap = std::unordered_map<std::string, std::shared_ptr<sf::Texture>>;

    explicit SpriteManager(sf::RenderWindow& renderWindow) : m_renderWindow(renderWindow)
    {
    }

    void init();
    void shutdown();

    void setCamera(IRenderComponent* cameraComp)
    {
        m_camera = cameraComp;
    }

    IRenderComponent* getCamera() const
    {
        return m_camera;
    }

    /**
     * \brief Add component to the named layer. If the component is already in a layer
     * it is removed from this layer and put in this layer.
     */
    void addCompToLayer(const std::string& layer, IRenderComponent* comp);
    void removeComp(IRenderComponent* comp);

    /**
     * \brief Get current layer of the given component.
     */
    std::string getLayer(const IRenderComponent* comp);

    /**
     * \brief Set up the order of layers by providing their names in order
     * from back to front.
     */
    void setLayerOrder(const std::vector<std::string>& layerOrder)
    {
        m_layerOrder = layerOrder;
    }

    void setTileSize(const sf::Vector2i& tileSize)
    {
        m_tileSize = tileSize;
    }

    sf::Vector2i getTileSize() const
    {
        return m_tileSize;
    }

    void setTileSets(const TileSetMap& tileSets)
    {
        m_tileSets = tileSets;
    }

    const TileSetMap& getTileSets() const
    {
        return m_tileSets;
    }

    sf::RenderWindow& getWindow() const
    {
        return m_renderWindow;
    }

    void draw();

private:
    sf::RenderWindow& m_renderWindow;
    sf::Image m_floorImage;
    sf::Texture m_floorTexture;
    sf::Sprite m_floorSprite;
    sf::Vector2i m_tileSize{};
    TileSetMap   m_tileSets;

    IRenderComponent* m_camera = nullptr;

    std::map<std::string, std::list<IRenderComponent*>> m_layerToComp;
    std::map<const IRenderComponent*, std::string>      m_compToLayer;

    std::vector<std::string> m_layerOrder;

    /**
     * \brief maintain a list of listeners that the manager is subscribed to,
     * so that he can unsubscribe
     */
    std::list<EventBus::ListenerId> m_listeners;
};
} // namespace mmt_gd
