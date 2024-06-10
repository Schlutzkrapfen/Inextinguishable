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

#include "SpriteManager.hpp"
#include "TileLayerRenderComponent.hpp"
#include "Tileson.hpp"
#include "NavigationGraph.hpp"

namespace mmt_gd
{
class TileMapLoader
{
public:
    static void loadTileSetTextures(const std::unique_ptr<tson::Map>& map,
                                    const fs::path&                   resourcePath,
                                    SpriteManager&                    spriteManager,
                                    SpriteManager::TileSetMap&        tileSets);

    static void createTileSprite(const std::unique_ptr<tson::Map>& map,
                                 SpriteManager::TileSetMap&        tileSets,
                                 std::vector<TileLayer>&           tileLayers,
                                 int                               layerIdx,
                                 const tson::Layer&                layer,
                                 int                               i,
                                 unsigned                          gid);

    static void loadTileLayers(const std::unique_ptr<tson::Map>& map,
                               const fs::path&                   resourcePath,
                               SpriteManager&                    spriteManager);

    static void loadObjectLayers(const std::unique_ptr<tson::Map>& map,
                                 const fs::path&                   resourcePath,
                                 const SpriteManager&              spriteManager);


};
} // namespace mmt_gd
