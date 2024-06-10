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

#include <SFML/Graphics.hpp>
#include <list>
#include <string>
#include <utility>

namespace mmt_gd
{
class GameObject final : public sf::Transformable
{
public:
    using Ptr = std::shared_ptr<GameObject>;

    static Ptr create(const std::string& id)
    {
        return std::make_shared<GameObject>(id);
    }

    explicit GameObject(std::string id) : m_id(std::move(id))
    {
    }

    /**
     * \brief Add a component to the game object.
     */
    template <typename T, typename... Args>
    std::shared_ptr<T> addComponent(Args&&... args)
    {
        auto obj = std::make_shared<T>(std::forward<Args>(args)...);
        if (auto cmp = std::dynamic_pointer_cast<IComponent>(obj))
        {
            m_componentList.push_back(cmp);
            return obj;
        }
        return {};
    }


    /**
     * \brief Remove a component from the game object.
     */
    void removeComponent(const IComponent::Ptr& component);

    /**
     * \brief Get a component of the game object by it's type.
     * \return nullptr if no component of the given type was found.
     */
    template <typename TComponent>
    std::shared_ptr<TComponent> getComponent()
    {
        for (auto& component : m_componentList)
        {
            if (auto cmp = std::dynamic_pointer_cast<TComponent>(component))
                return cmp;
        }
        return nullptr;
    }

    /**
     * \brief Get a component of the game object by it's type.
     * \return nullptr if no component of the given type was found.
     */
    template <typename TComponent>
    std::vector<std::shared_ptr<TComponent>> getComponents()
    {
        std::vector<std::shared_ptr<TComponent>> result{};
        for (auto& component : m_componentList)
        {
            std::dynamic_pointer_cast<TComponent>(component);
            if (std::shared_ptr<TComponent> cmp = std::dynamic_pointer_cast<TComponent>(component))
            {
                result.push_back(cmp);
            }
        }
        return result;
    }

    /**
     * \brief Initialize all added components
     * \return true if all components were initialized successfully
     */
    bool init() const;

    void update(float deltaTime) const;

    bool isMarkedForDelete() const
    {
        return m_wantToDie;
    }

    void markForDelete()
    {
        m_wantToDie = true;
    }

    bool isActive() const
    {
        return m_isActive;
    }

    void setActive(const bool isActive)
    {
        m_isActive = isActive;
    }

    std::string getId() const
    {
        return m_id;
    }

    void setId(const std::string& id)
    {
        m_id = id;
    }

protected:
    std::string m_id        = "unnamed"; ///< unique name of object, e.g. player
    bool        m_wantToDie = false;
    bool        m_isActive  = true;

    std::list<IComponent::Ptr> m_componentList;
};
} // namespace mmt_gd
