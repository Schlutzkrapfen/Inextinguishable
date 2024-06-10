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

#include "IEvent.hpp"
#include "SpriteRenderComponent.hpp"
#include "TileLayerRenderComponent.hpp"

#include <utility>

namespace mmt_gd
{
class RenderableCreateEvent final : public BasicDataEvent<IRenderComponent&>
{
public:
    RenderableCreateEvent(std::string layer, IRenderComponent& comp) : BasicDataEvent(comp), m_layer(std::move(layer))
    {
    }

    static const EventType Type;

    EventType getEventType() override
    {
        return Type;
    }

    std::string getLayer() const
    {
        return m_layer;
    }

private:
    std::string m_layer;
};

class RenderableDestroyEvent final : public BasicDataEvent<IRenderComponent&>
{
public:
    RenderableDestroyEvent(std::string layer, IRenderComponent& comp) : BasicDataEvent(comp), m_layer(std::move(layer))
    {
    }

    static const EventType Type;

    EventType getEventType() override
    {
        return Type;
    }

    std::string getLayer() const
    {
        return m_layer;
    }

private:
    std::string m_layer;
};
} // namespace mmt_gd
