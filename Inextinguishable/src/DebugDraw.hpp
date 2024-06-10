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
#include "GameObject.hpp"

namespace mmt_gd
{
/**
 * \brief Simple debug draw functionality.
 * Use the relevant draw* method to render debug stuff in the current frame
 */
class DebugDraw final : b2Draw
{
public:
    static DebugDraw& getInstance()
    {
        static DebugDraw instance;
        return instance;
    }

    void drawLine(const sf::Vector2f& p1, const sf::Vector2f& p2, const sf::Color& color, float thickness = 1.0f);
    void drawArrow(const sf::Vector2f& origin, const sf::Vector2f& direction, const sf::Color& color, float thickness = 1.0f);
    void drawCircle(const sf::Vector2f& center,
                    float               radius,
                    const sf::Color&    outlineColor,
                    const sf::Color&    fillColor = sf::Color::Transparent);
    void drawText(const std::string& str, const sf::Vector2f& center, const sf::Color& color);
    void drawRectangle(const sf::Vector2f& position,
                       const sf::Vector2f& size,
                       const sf::Color&    outlineColor,
                       const sf::Color&    fillColor = sf::Color::Transparent);

    // Box2D Debug Draw
    void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color) override;
    void DrawCircle(const b2Vec2& center, float radius, const b2Color& color) override;
    void DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color) override;
    void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color) override;
    void DrawTransform(const b2Transform& xf) override;
    void drawPolygonShape(const b2PolygonShape& b2Shape, const GameObject& trans, const b2Color& color);
    void DrawPoint(const b2Vec2& p, float size, const b2Color& color) override;
    void drawAabb(const b2AABB* aabb, const sf::Color& color);
    // end Box2D Debug Draw

    bool is_enabled() const
    {
        return m_enabled;
    }

    void setEnabled(bool enabled)
    {
        m_enabled = enabled;
    }

    void update(float deltaTime);

    void draw(sf::RenderWindow& renderWindow);

private:
    DebugDraw();

    DebugDraw(DebugDraw const&)
    {
    }

    void operator=(DebugDraw const&) const
    {
    }

    ~DebugDraw() override;

    bool                                    m_enabled;
    std::vector<std::shared_ptr<sf::Drawable>> m_shapes;
    sf::Font                                   m_font;
};
} // namespace mmt_gd
