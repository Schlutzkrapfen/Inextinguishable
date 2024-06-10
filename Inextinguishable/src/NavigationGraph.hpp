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

#include <SFML/System/Vector2.hpp>
#include <unordered_map>
#include <vector>
// Hash function for NodeId
namespace std
{using NodeId = sf::Vector2i;

template <>
struct hash<NodeId>
{
    size_t operator()(const NodeId& id) const
    {
        // A simple hash function combining x and y
        return hash<int>()(id.x) ^ hash<int>()(id.y);
    }
};
} // namespace std
namespace mmt_gd
{
using NodeId = sf::Vector2i;

struct NavigationNode
{
    bool                m_walkable;
    std::vector<NodeId> neighbors;

    const std::vector<NodeId>& getNeighbors() const
    {
        return neighbors;
    }
};

// Equality comparison function for NodeId
bool operator==(const NodeId& lhs, const NodeId& rhs);

class NavigationGraph
{
public:
    static NavigationGraph& getInstance()
    {

        static NavigationGraph instance;

        return instance;
    }

    void init(int width, int height);

    NavigationGraph(const NavigationGraph&)            = delete;
    NavigationGraph& operator=(const NavigationGraph&) = delete;

    void                  addNode(const NodeId& nodeId, const NavigationNode& node);
    NavigationNode& getNode(const NodeId& nodeId);
    void                  setWalkable(const NodeId& nodeId, bool walkable);
    float                 distanceBetween(const NodeId& a, const NodeId& b) const;
    std::deque<NodeId>   findPath(const NodeId& start, const NodeId& goal);
    bool                  isValidNode(const NodeId& nodeId) const;
     sf::Vector2f&   getPlayerPosition() ;
    void                  setPlayerPosition(const sf::Vector2f& position);
    const std::unordered_map<NodeId, NavigationNode> getWalkableNodes() const;


private:
    NavigationGraph();
    ~NavigationGraph() = default;

    std::unordered_map<NodeId, NavigationNode> nodes;
    std::unordered_map<NodeId, NodeId>         cameFrom;
    int                                      m_width;
    int                                      m_height;
    sf::Vector2f                              playerPosition;
};

} // namespace mmt_gd
