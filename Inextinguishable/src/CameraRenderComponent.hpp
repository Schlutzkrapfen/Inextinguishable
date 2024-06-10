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

namespace mmt_gd
{
/**
 * \brief Updates the camera/view of the render window. This new camera
 * will be used until another CameraRenderComponent changes it.
 * For positioning the translation component of the game object
 * transform is used.
 * Currently does not support rotation.
 */
class CameraRenderComponent final : public IRenderComponent
{
public:
    using Ptr = std::shared_ptr<CameraRenderComponent>;

    CameraRenderComponent(GameObject& gameObject, sf::RenderWindow& renderWindow, sf::View view);

    bool init() override;
    void update(float deltaTime) override;
    void draw() override;
    void shutdown();

private:
    float    Zoom = 0.6;
    sf::View m_view;
};
} // namespace mmt_gd
