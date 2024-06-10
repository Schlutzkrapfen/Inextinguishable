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

#include "IRenderComponent.hpp"

#include <SFML/Graphics.hpp>
#include <string>

namespace mmt_gd
{
struct Tile
{
    /**
     * \brief original tile index
     */
    int                         m_idx;
    std::shared_ptr<sf::Sprite> m_sprite;
};

struct TileLayer
{
    std::string       m_name;
    sf::Vector2i      m_dimension;
    sf::Vector2i      m_tileSize;
    std::vector<Tile> m_tiles;
};

class TileLayerRenderComponent final : public IRenderComponent
{
public:
    using Ptr = std::shared_ptr<TileLayerRenderComponent>;

    TileLayerRenderComponent(GameObject& gameObject, sf::RenderWindow& renderWindow, TileLayer layer);
    ~TileLayerRenderComponent() override;

    bool init() override;
    void update(float deltaTime) override;
    void draw() override;

    const TileLayer& getLayer() const
    {
        return m_layer;
    }

private:
    TileLayer m_layer;

    std::list<Tile> m_visibleTiles;
};
} // namespace mmt_gd
