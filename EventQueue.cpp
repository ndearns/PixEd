#include <algorithm>
#include "EventQueue.h"

static EventQueue default_event_queue;

EventQueue* EventQueue::defaultEQ()
{
    return &default_event_queue;
}

void EventQueue::add( Event* e )
{
    events.push_back( new EQEntry{ e } );
}

void EventQueue::service_queue()
{
    if ( !events.empty() )
    {
        EQEntry* e = events.front();
        e->event->despatch();
        events.pop_front();
        delete e->event;
    }
}

void EventQueue::receiver_deleted( EventReceiver* erx )
/*
		erasing an element may invalidate the iterator
		so repeat operation until we get through it 
		without deleting anything
	*/
{
    events.erase(
        std::remove_if( events.begin(), events.end(),
            [ = ]( EQEntry* e ) {
                if ( e->event->receiver == erx )
                    return true;
                else
                    return false;
            } ) );
}
