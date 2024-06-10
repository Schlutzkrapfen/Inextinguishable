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
#include "IComponent.hpp"
#include "RigidBodyComponent.hpp"

#include <Box2D/Box2D.h>
#include <functional>
#include <list>

namespace mmt_gd
{


class ColliderComponent : public IComponent
{
public:
    /// \param collider1 the collider for which OnCollision was called.
    /// \param collider2 the collider with which the collision happened.
    using OnCollisionFunction = std::function<void(ColliderComponent&, ColliderComponent&)>;

    /// \param body the rigid body the collider is attached to.
    /// \param rect the size of the AABB in pixel
    ColliderComponent(GameObject& gameObject, RigidBodyComponent& body, b2FixtureDef& def);

    bool init() override
    {
        return true;
    }
    virtual void update(float fDeltaTime) override;
    /// Add delegate function to be executed when collision is detected.
    /// Signature: void func(ColliderComponent&)
    void registerOnCollisionFunction(const OnCollisionFunction& func);

    void applyDeferredChanges();

    /// Method called when collision occured. Method calls all subscribed
    /// OnCollisionFunctions
    ///
    /// \param collider collision occured with this collider
    void                onCollision(ColliderComponent& collider);
    RigidBodyComponent& getBody() const
    {
        return m_body;
    }

private:
    RigidBodyComponent&            m_body;
    b2Fixture*                     m_fixture;
    int                                bulletDamage = 10;
    int                                enemyDamage = 1;
    std::list<OnCollisionFunction> m_onCollisionFunctions;
    std::vector<std::function<void()>> deferredChanges;
    sf::Sound                          m_EnemyHit;
   int                          EnemyHitVolume = 30;
    sf::Sound                          m_PlayerHit;
   int                                 PlayerHitVolume = 100;
};
} // namespace mmt_gd
