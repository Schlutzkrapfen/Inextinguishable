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
#include "Tileson.hpp"

#include <Box2D/box2d.h>
#include <list>

namespace mmt_gd
{

class ColliderComponent;
class RigidBodyComponent;

class PhysicsManager : public b2ContactListener
{
public:
    struct Manifold
    {
        sf::Vector2f       normal;
        float              penetration{};
        ColliderComponent* colliderA{};
        ColliderComponent* colliderB{};
    };

    // Box2D Callbacks
    void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
    void BeginContact(b2Contact* contact) override;
    void EndContact(b2Contact* contact) override;
    void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;

    void init();
    void shutdown();
    void update(float fDeltaTime);

    //Physic Globals
    static std::shared_ptr<b2World> get_b2_world();
    static b2Body*                  createB2Body(b2BodyDef& def);
    static void                     destroyB2Body(b2Body& def);


    static b2Vec2         s2b(const sf::Vector2f& vec, bool scale = true);
    static sf::Vector2f   b2s(const b2Vec2& vec, bool scale = true);
    static b2Vec2         t2b(const tson::Vector2i& vec, bool scale = true);
    static b2Vec2         t2b(const tson::Vector2f& vec, bool scale = true);
    static tson::Vector2f b2t(const b2Vec2& vec, bool scale = true);
    static sf::Color      b2s(const b2Color& color, int alpha = 255);
    static b2Color        s2b(const sf::Color& color, int alpha = 255);


    // 1 meter (box2d) is more or less 64 pixels (sfml) == pixels per meter
    static const float RATIO;

    // 64 pixels (sfml) are more or less 1 meter (box2d) == meters per pixel
    static const float UNRATIO;

    //formula to convert radians to degrees = (radians * (pi/180))
    static const float RADTODEG;

private:
    // maintain a list of listeners that the manager is subscribed to,
    // so that he can unsubscribe
    std::list<mmt_gd::EventBus::ListenerId> m_listeners;

    static std::shared_ptr<b2World> m_world;

    std::vector<RigidBodyComponent*> m_rbodies;
};
} // namespace mmt_gd
