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
class SpriteAnimationComponent final : public IRenderComponent
{
    public:
    using Ptr = std::shared_ptr<SpriteAnimationComponent>;

    //there are 2 constroctors here because you could also want to giva a animation something that hasent had an Physikscomponent
    SpriteAnimationComponent(GameObject& gameObject, sf::RenderWindow& renderWindow, std::string textureFile, std::string layerName, sf::Vector2i spriteRowsAndCollums,float animationSpeed);

    SpriteAnimationComponent(GameObject& gameObject, sf::RenderWindow& renderWindow, std::string textureFile, std::string layerName, sf::Vector2i spriteRowsAndCollums,float animationSpeed,sf::Vector2i hitBoxSize );

    ~SpriteAnimationComponent() override;

    bool init() override;

    void update(float deltaTime) override;

    void draw() override;
    /// <summary>
    /// changes row so that the animation can play in a different animation
    /// </summary>
    /// <param name="row"></param>
    void changeAnimation(int row);
    void changeAnimation(int row, int columAmount);


    sf::Sprite& getSprite()
    {
        return m_sprite;
    }

private:
    void setTextureRect();
    std::string m_textureFile;
    sf::Texture m_texture;
    sf::Sprite  m_sprite;
    std::string m_layerName;
    sf::Vector2i m_hitBoxSize = sf::Vector2i(0, 0);

    /// <summary>
    /// how many rows and collums the texture has
    /// </summary>
    sf::Vector2i m_spriteRowsAndCollums;
    float        m_animationSpeed;
    sf::Vector2f singleSquaresize;
    sf::Vector2f currentTextureRectPosition = sf::Vector2f(0.f,0.f);
    sf::IntRect  textureRect;
    float        time = 0;
    /// <summary>
    /// Can be changed when you switch animations
    /// </summary>
    int          ColumnSizeforthisRow;
    
};
} // namespace mmt_gd
