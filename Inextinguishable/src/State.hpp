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
#include "stdafx.h"
#include <memory>
namespace mmt_gd
{
class GameStateManager;
class Game;

class State
{
public:
    using Ptr = std::shared_ptr<State>;

    State(GameStateManager* gameStateManager, Game* game) : m_gameStateManager(gameStateManager), m_game(game)
    {
    }

    virtual ~State()                    = default;
    State(const State&)             = delete;
    State(const State&&)            = delete;
    State& operator=(const State&)  = delete;
    State& operator=(const State&&) = delete;

    virtual void init()
    {
    }

    virtual void exit()
    {
    }
    virtual void close()
    {

    }
    virtual void shutdown()
    {
    }

    virtual void update(float delta) = 0;
    virtual void draw()              = 0;

protected:
    GameStateManager* m_gameStateManager;
    Game*             m_game;
};
} // namespace mmt_gd