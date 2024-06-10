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

#include "IEvent.hpp"

#include <functional>
#include <list>
#include <queue>
#include <unordered_map>

namespace mmt_gd
{
/**
 * \brief rudimentary event bus (implemented as Singleton)
 * for registering delegates that execute code, when event is triggered.
 * add ons for the future: abort events, timer to limit processing of
 * events, ...
 *
 * BE CAREFUL: the EventBus has not been thoroughly tested.
 */
class EventBus
{
public:
    using EventListener = std::function<void(IEvent::Ptr)>;
    using ListenerId    = unsigned long;

    static EventBus& getInstance();

    /**
     * \brief´Add/remove event listeners
     * Be careful:
     * Due to the usage of std::function, multiple additions of the
     * same function to the m_listener cannot be checked.
     * \param type Type of the event
     * \param listener event listener
     * \return ID of the Listener
     */
    ListenerId addListener(IEvent::EventType type, EventListener listener);
    void       removeListener(ListenerId id);

    /**
     * \brief immediately triggers the event
     * \param event event to be fired
     */
    void fireEvent(const IEvent::Ptr& event);

    /**
     * \brief queue event to be processed
     * \param event event to be queued
     */
    void queueEvent(const IEvent::Ptr& event);

    /**
     * \brief should called once per frame to process events
     */
    void processEvents(float deltaTime);

private:
    struct ListenerData
    {
        ListenerId    m_id;
        EventListener m_listener;
    };

    using ListenerList       = std::list<ListenerData>;
    using EventListenerMap   = std::unordered_map<IEvent::EventType, ListenerList>;
    using ListenerIdEventMap = std::unordered_map<ListenerId, IEvent::EventType>;
    using EventQueue         = std::queue<IEvent::Ptr>;

    static constexpr int NumMaxQueues = 2;
    static ListenerId    m_listenerIdCtr;

    int m_currentEventQueue = 0;

    /**
     * \brief buffering the events to avoid circles when new events are
     * queued each frame before the old ones are processed.
     */
    EventQueue m_eventQueueBuffer[NumMaxQueues];

    /**
     * \brief The map stores the registered listeners for each event.
     */
    EventListenerMap m_eventListenerMap;

    /**
     * \brief This map is used for faster lookups when removing listeners.
     */
    ListenerIdEventMap m_listenerIdEventMap;
};
} // namespace mmt_gd
