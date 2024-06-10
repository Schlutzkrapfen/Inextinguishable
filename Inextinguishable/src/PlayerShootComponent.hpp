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
#include "BulletPool.hpp"
#include "IComponent.hpp"
#include "GameObjectManager.hpp"
#include "EnemySpawner.hpp"


namespace mmt_gd
{
class PlayerShootComponent final : public IComponent
{
public:
    PlayerShootComponent(GameObject&                            gameObject,
                         int                                    poolSize,
                         sf::RenderWindow&                      renderWindow,
                         const std::string&                     textureFile,
                         sf::IntRect                            textureRect,
                         sf::IntRect                            colliderRect,
                         float                                  bulletMass,
                         float                                  bulletspeed,
                         const std::string& layerName,
                         int _playerID
                         );


    void shoot(const sf::Vector2f directionSpeed, const sf::Vector2f bulletSpawnOffset, const float radius );
    bool init() override;
    void update(float deltaTime) override;
    sf::Vector2f normalize(const sf::Vector2f& vector);

    BulletPool m_pool;
    float      m_timeSinceLastShot{};
  private:
   int      m_bulletspeed;
   float        bulletSpawnOffset = 0.05f;
   const int playerID;
   sf::Vector2f enemyPosition = sf::Vector2f(1000, 100);
   sf::Sound         m_shootSound;
   int                          shootSoundVolume = 40;
   std::vector<GameObject::Ptr> enemyList;
};
} // namespace mmt_gd
