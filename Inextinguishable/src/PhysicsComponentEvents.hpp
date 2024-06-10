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

#pragma once

#include "ColliderComponent.hpp"
#include "IEvent.hpp"
#include "RigidBodyComponent.hpp"

namespace mmt_gd
{


// RigidBodyComponent is a reference, because components are managed by
// game objects
class RigidBodyCreateEvent : public BasicDataEvent<RigidBodyComponent&>
{
public:
    using BasicDataEvent::BasicDataEvent;

    // EventType defined using GUID functionality of VS 2015.
    // Tools->Create GUID -> DEFINE_GUID -> take longest value in the beginning.
    // output:
    //
    // {DEC71435-8D92-4CA7-A3D5-FD17F9D5CC34}
    // DEFINE_GUID(<< name >> ,
    //	0xdec71435, 0x8d92, 0x4ca7, 0xa3, 0xd5, 0xfd, 0x17, 0xf9, 0xd5, 0xcc, 0x34);
    //
    // m_EventType identifies event, when we want to add it to the event bus
    static const EventType m_eventType;
    EventType              getEventType() override
    {
        return m_eventType;
    }
};

// RigidBodyComponent is a reference, because components are managed by
// game objects
class RigidBodyDestroyEvent : public BasicDataEvent<RigidBodyComponent&>
{
public:
    using BasicDataEvent::BasicDataEvent;

    // EventType defined using GUID functionality of VS 2015.
    // Tools->Create GUID -> DEFINE_GUID -> take longest value in the beginning.
    // output:
    //
    // {DEC71435-8D92-4CA7-A3D5-FD17F9D5CC34}
    // DEFINE_GUID(<< name >> ,
    //	0xdec71435, 0x8d92, 0x4ca7, 0xa3, 0xd5, 0xfd, 0x17, 0xf9, 0xd5, 0xcc, 0x34);
    //
    // m_EventType identifies event, when we want to add it to the event bus
    static const EventType m_eventType;
    EventType              getEventType() override
    {
        return m_eventType;
    }
};


} // namespace mmt_gd