#if !defined(FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATIONCOMPLETEEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATIONCOMPLETEEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * The DRMManager dispatches a DRMAuthenticationCompleteEvent object when a call to the <codeph class="+ topic/ph pr-d/codeph ">authenticate()</codeph>
 * method of the DRMManager object succeeds.
 * @langversion 3.0
 * @playerversion   AIR 1.5
 * @playerversion   Flash 10.1
 */

using namespace flash::events;
using namespace flash::utils;

namespace flash
{
    namespace events
    {
        class DRMAuthenticationCompleteEvent : public flash::events::Event
        {
            /**
             * The string constant to use for the authentication complete event
             * in the type parameter when adding and removing event listeners.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            static const std::string AUTHENTICATION_COMPLETE;

            /**
             * The URL of the media rights server.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            std::string       serverURL();
        public:
            void         serverURL(std::string value);

            /**
             * The content domain of the media rights server. Here, domain is not a network or Internet domain name.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            std::string       domain();
        public:
            void         domain(std::string value);

            /**
             * The authentication token.
             *
             *   The authentication is automatically added to the DRMManager session cache. You
             * can save the token and use it to authenticate the user in a future session. Reuse a
             * token with the setAuthenticationToken() method of the DRMManager.
             * Token expiration and other properties are determined by the server generating the token.
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            flash::utils::ByteArray *token();
        public:
            void         token(ByteArray *value);

            /**
             * Duplicates an instance of an Event subclass.
             *
             *   Returns a new Event object that is a copy of the original instance of the Event object.
             * You do not normally call clone(); the EventDispatcher class calls it automatically
             * when you redispatch an event   that is, when you call dispatchEvent(event) from a handler
             * that is handling event.The new Event object includes all the properties of the original.When creating your own custom Event class, you must override the
             * inherited Event.clone() method in order for it to duplicate the
             * properties of your custom class. If you do not set all the properties that you add
             * in your event subclass, those properties will not have the correct values when listeners
             * handle the redispatched event.In this example, PingEvent is a subclass of Event
             * and therefore implements its own version of clone().
             * <codeblock>
             *
             *   class PingEvent extends Event {
             * var URL:String;
             *
             *   public override function clone():Event {
             * return new PingEvent(type, bubbles, cancelable, URL);
             * }
             * }
             *
             *   </codeblock>
             * @return  A new Event object that is identical to the original.
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates a new instance of a DRMAuthenticationCompleteEvent object.
             * @param   type    the event type string
             * @param   bubbles whether the event bubbles up the display list
             * @param   cancelable  whether the event can be canceled
             * @param   inServerURL the URL of the logged-in server
             * @param   inDomain    the authenticated domain on the logged-in server
             * @param   inToken the authentication token
             * @langversion 3.0
             * @playerversion   AIR 1.5
             * @playerversion   Flash 10.1
             */
        public:
            DRMAuthenticationCompleteEvent(std::string type, bool bubbles=false, bool cancelable=false, std::string inServerURL="", std::string inDomain="", ByteArray *inToken=NULL);
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATIONCOMPLETEEVENT_AS
#endif // __cplusplus

