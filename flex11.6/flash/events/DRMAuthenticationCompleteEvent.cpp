

#include "DRMAuthenticationCompleteEvent.h"
#include "flash/events/Event.h"
#include "flash/utils/ByteArray.h"

    /**
     * The DRMManager dispatches a DRMAuthenticationCompleteEvent object when a call to the <codeph class="+ topic/ph pr-d/codeph ">authenticate()</codeph>
     * method of the DRMManager object succeeds.
     * @langversion 3.0
     * @playerversion   AIR 1.5
     * @playerversion   Flash 10.1
     */

using namespace flash::events;
using namespace flash::utils;

namespace flash {
namespace events {


        /**
         * The string constant to use for the authentication complete event 
         * in the type parameter when adding and removing event listeners.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string DRMAuthenticationCompleteEvent::AUTHENTICATION_COMPLETE="authenticationComplete";

        /**
         * The URL of the media rights server.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        std::string DRMAuthenticationCompleteEvent::serverURL()         ;
        void DRMAuthenticationCompleteEvent::serverURL(std::string value)       ;

        /**
         * The content domain of the media rights server. Here, domain is not a network or Internet domain name.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        std::string DRMAuthenticationCompleteEvent::domain()         ;
        void DRMAuthenticationCompleteEvent::domain(std::string value)       ;

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
        flash::utils::ByteArray* DRMAuthenticationCompleteEvent::token()                        ;
        void DRMAuthenticationCompleteEvent::token(ByteArray* value)       ;

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
        flash::events::Event* DRMAuthenticationCompleteEvent::clone()                     ;

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
        DRMAuthenticationCompleteEvent::DRMAuthenticationCompleteEvent(std::string type, bool bubbles, bool cancelable, std::string inServerURL, std::string inDomain, ByteArray* inToken);
}
}

