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
// GameObjectManager.hpp

#pragma once

#include "EventBus.hpp"
#include "GameObject.hpp"

#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>

namespace mmt_gd
{
class GameObjectManager
{
public:
    using GameObjectMap = std::unordered_map<std::string, GameObject::Ptr>;

    static GameObjectManager& getInstance()
    {
        static GameObjectManager instance;
        return instance;
    }

    void init();
    void shutdown();
    void update(float deltaTime);

    void            addGameObject(const GameObject::Ptr& gameObject);
    GameObject::Ptr getGameObject(const std::string& id) const;

    GameObjectMap& getGameObjects()
    {
        return m_gameObjects;
    }

    void removeGameObject(const std::shared_ptr<GameObject>& go);

private:
    GameObjectManager();                                             
    ~GameObjectManager();                                            
    GameObjectManager(const GameObjectManager&)            = delete; 
    GameObjectManager& operator=(const GameObjectManager&) = delete; 

    GameObjectMap m_gameObjects;

    std::list<EventBus::ListenerId> m_listeners;
};
} // namespace mmt_gd
