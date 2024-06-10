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

#include <Box2D/box2d.h>

namespace mmt_gd
{


class RigidBodyComponent : public IComponent
{
public:
    RigidBodyComponent(GameObject& gameObject, b2BodyType type);
    ~RigidBodyComponent() override;


    void addVelocity(const sf::Vector2f& velocity) const;
    void setVelocity(const sf::Vector2f& velocity) const;
    void setTorque(float torque) const;

    bool init() override
    {
        return true;
    }

    void update(float deltaTime) override{};

    void physicsUpdate(float deltaTime);


    b2Body* getB2Body() const;


private:
    b2Body* m_body;
};
} // namespace mmt_gd
