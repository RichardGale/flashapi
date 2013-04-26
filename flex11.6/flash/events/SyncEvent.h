#if !defined(FLEX11_6_FLASH_EVENTS_SYNCEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_SYNCEVENT_AS
#if defined(__cplusplus)


#include "flash/events/Event.h"

/// @eventType  flash.events.SyncEvent.SYNC
//[Event(name="sync",type="flash.events.SyncEvent")]

/**
 * An SharedObject object representing a remote shared object dispatches a SyncEvent object when the remote
 * shared object has been updated by the server. There is only one type of <codeph class="+ topic/ph pr-d/codeph ">sync</codeph> event:
 * <codeph class="+ topic/ph pr-d/codeph ">SyncEvent.SYNC</codeph>.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 * @internal    includeExample examples\SyncEventExample.as -noswf
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class SyncEvent: public Event
        {
            /**
             * Defines the value of the type property of a sync event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.changeListAn array with properties that describe the array's status.targetThe SharedObject instance that has been updated by the server.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string SYNC;

            /**
             * An array of objects; each object contains properties that describe the changed members of a remote shared object.
             * The properties of each object are code, name, and oldValue.
             * When you initially connect to a remote shared object that is persistent locally and/or on the server, all the
             * properties of this object are set to empty strings.Otherwise, Flash sets code to "clear",
             * "success", "reject", "change", or "delete". A value of "clear" means either that you have successfully connected to a remote shared object
             * that is not persistent on the server or the client, or that all the properties of the object have been deleted--for
             * example, when the client and server copies of the object are so far out of sync that Flash Player resynchronizes the client
             * object with the server object. In the latter case, SyncEvent.SYNC is dispatched and the "code" value
             * is set to "change". A value of "success" means the client changed the shared object. A value of "reject" means the client tried unsuccessfully to change the object; instead, another client changed the object. A value of "change" means another client changed the object or the server resynchronized the object. A value of "delete" means the attribute was deleted. The name property contains the name of the property that has been changed.The oldValue property contains the former value of the changed property. This parameter is
             * null unless code has a value of "reject" or "change".
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::vector<void *> changeList();
        public:
            void         changeList(std::vector<void *> value);

            /**
             * Creates a copy of the SyncEvent object and sets the value of each property to match that of the original.
             * @return  A new SyncEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about sync events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of sync event: SyncEvent.SYNC.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   changeList  An array of objects that describe the synchronization with the remote SharedObject. Event listeners can access this object through the changeList property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            SyncEvent(std::string type, bool bubbles, bool cancelable, std::vector<void *> changeList);

            /**
             * Returns a string that contains all the properties of the SyncEvent object. The string is in the following format:
             * [SyncEvent type=value bubbles=value cancelable=value list=value]
             * @return  A string that contains all the properties of the SyncEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_SYNCEVENT_AS
#endif // __cplusplus

