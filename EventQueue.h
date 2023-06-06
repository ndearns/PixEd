#pragma once

#include <deque>

class Event;
class EventReceiver;
class EQEntry;
class EventQueue;


class EventReceiver
{
};

class Event
{
public:
    virtual ~Event() = default;
    EventReceiver* receiver;
    virtual void despatch() = 0;
};

class EQEntry
{
public:
    Event* event;
    ~EQEntry() { delete this->event; };
};

class EventQueue
{

public:
    std::deque< EQEntry* > events;
    /*
			the actual queue of events
			nb: as is the way with c++, queue doesn't 
			work the way you expect it to.  need to use
			deque so we can iterate over contents when 
			we want to remove a deleted receiver's events 
			from the queue
			You need a 'front' AND a 'pop_front' to both 
			process AND remove an element
		*/

    static EventQueue* defaultEQ();
    /*
			 returns a global default instance
			 you can still create individual queues
			 this is not a singleton
		 */

    void add( Event* e );
    /*
			push e onto the back of the queue
			passed by value as we're assuming that
			events are very small packets.
			If you are sending huge chunks of data
			then revisit this assumption
		*/

    void service_queue();
    /*
			main loop needs to call this.
			pop an event off the queue and
			deliver it to the receiver
		*/

    void receiver_deleted( EventReceiver* erx );
    /*
			an event receiver has been deleted.
			we need to remove any events targeted
			at them, so we don't try to deliver 
			them to a deleted instance
		*/
};
