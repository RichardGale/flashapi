

#include "DRMAuthenticationErrorEvent.h"
#include "flash/events/Event.h"

    /**
     * The DRMManager dispatches a DRMAuthenticationErrorEvent object when a call to the <codeph class="+ topic/ph pr-d/codeph ">authenticate()</codeph>
     * method of the DRMManager object fails.
     * @langversion 3.0
     * @playerversion   AIR 1.5
     * @playerversion   Flash 10.1
     */

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * The string constant to use for the authentication error event 
         * in the type parameter when adding and removing event listeners.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string DRMAuthenticationErrorEvent::AUTHENTICATION_ERROR="authenticationError";

        /**
         * A more detailed error code.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        int DRMAuthenticationErrorEvent::subErrorID()      ;
        void DRMAuthenticationErrorEvent::subErrorID(int value)       ;

        /**
         * The URL of the media rights server that rejected the authentication attempt.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        std::string DRMAuthenticationErrorEvent::serverURL()         ;
        void DRMAuthenticationErrorEvent::serverURL(std::string value)       ;

        /**
         * The content domain of the media rights server. Here, domain is not a network or Internet domain name.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        std::string DRMAuthenticationErrorEvent::domain()         ;
        void DRMAuthenticationErrorEvent::domain(std::string value)       ;

        /**
         * Creates a copy of the ErrorEvent object and sets the value of each property to match that of the original.
         * @return  A new ErrorEvent object with property values that match those of the original.
         */
        flash::events::Event* DRMAuthenticationErrorEvent::clone()                     ;

        /**
         * Creates a new instance of a DRMAuthenticationErrorEvent object.
         * @param   type    the event type string
         * @param   bubbles whether the event bubbles up the display list
         * @param   cancelable  whether the event can be canceled
         * @param   inDetail    The error description
         * @param   inErrorID   The ID of the general type of error
         * @param   inSubErrorID    The ID indicating the specific error within its type
         * @param   inServerURL the URL of the logged-in server
         * @param   inDomain    the authenticated domain on the logged-in server
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        DRMAuthenticationErrorEvent::DRMAuthenticationErrorEvent(std::string type, bool bubbles, bool cancelable, std::string inDetail, int inErrorID, int inSubErrorID, std::string inServerURL, std::string inDomain);
}
}

