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

#include <vector>

namespace mmt_gd
{
class BulletPool
{
public:
    explicit BulletPool(size_t                                                                size,
                        const std::string&                                                    textureFile,
                        sf::IntRect                                                           textureRect,
                        const std::string&                                                    layerName,
                        sf::RenderWindow&                                                     renderWindow,
                       
                        float                                                                 mass/*,
                        std::function<void(BoxColliderComponent& a, BoxColliderComponent& b)> collisionCallback*/);


    std::vector<GameObject::Ptr> m_pool;
    GameObject::Ptr              get();

private:
    size_t            m_counter{};
    inline static int m_globalBulletIdx{0};
    //std::function<void(BoxColliderComponent& a, BoxColliderComponent& b)> m_collisionCallback;
};
}; // namespace mmt_gd
