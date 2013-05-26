

#include "DRMAuthenticateEvent.h"
#include "flash/net/NetStream.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.DRMAuthenticateEvent.AUTHENTICATION_TYPE_DRM

using namespace flash::events;
using namespace flash::net;

namespace flash {
namespace events {


        /**
         * The DRMAuthenticateEvent.DRM_AUTHENTICATE constant defines the value of the 
         * type property of a DRMAuthenticateEvent object.
         * 
         *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for 
         * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        const std::string DRMAuthenticateEvent::DRM_AUTHENTICATE   = "drmAuthenticate";

        /**
         * The DRMAuthenticateEvent.AUTHENTICATION_TYPE_DRM constant defines the value of the 
         * authenticationType property of a DRMAuthenticateEvent object.
         * 
         *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for 
         * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse; there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        const std::string DRMAuthenticateEvent::AUTHENTICATION_TYPE_DRM   = "drm";

        /**
         * The DRMAuthenticateEvent.AUTHENTICATION_TYPE_PROXY constant defines the value of the 
         * authenticationType property of a DRMAuthenticateEvent object.
         * 
         *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for 
         * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse; there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        const std::string DRMAuthenticateEvent::AUTHENTICATION_TYPE_PROXY   = "proxy";

        /**
         * The encrypted content file header provided by the server. 
         * It contains information about the context of the encrypted content.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::header()         ;

        /**
         * A prompt for a user name credential, provided by the server. 
         * The string can include instruction for the type of user name required.
         * For example, a content provider may require an e-mail address as the user name.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::usernamePrompt()         ;

        /**
         * A prompt for a password credential, provided by the server.  
         * The string can include instruction for the type of password required.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::passwordPrompt()         ;

        /**
         * A prompt for a URL string, provided by the server. 
         * The string can provide the location where the username and password will be sent.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::urlPrompt()         ;

        /**
         * Indicates whether the supplied credentials are for authenticating against Flash Media Rights Management Server (FMRMS)
         * or a proxy server. For example, the "proxy" option allows the application to authenticate against a proxy server 
         * if an enterprise requires such a step before the user can access the Internet. Unless anonymous authentication is used, 
         * after the proxy authentication, the user still needs to authenticate against FMRMS in order to obtain the voucher 
         * and play the content. You can use setDRMAuthenticationcredentials() a second time, with "drm" 
         * option, to authenticate against FMRMS.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::authenticationType()         ;

        /**
         * The NetStream object that initiated this event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        flash::net::NetStream* DRMAuthenticateEvent::netstream()                      ;

        /**
         * Creates a copy of the DRMAuthenticateEvent object and sets the value of each property to match
         * that of the original.
         * @return  A new DRMAuthenticateEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        flash::events::Event* DRMAuthenticateEvent::clone()                     ;

        /**
         * Creates an Event object that contains specific information about DRM authentication events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of DRMAuthenticate event: DRMAuthenticateEvent.DRM_AUTHENTICATE.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   header  The encrypted content file header provided by the server.
         * @param   userPrompt  A prompt for a user name credential, provided by the server.
         * @param   passPrompt  A prompt for a password credential, provided by the server.
         * @param   urlPrompt   A prompt for a URL to display, provided by the server.
         * @param   authenticationType  Indicates whether the supplied credentials are for authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.
         * @param   netstream   The NetStream object that initiated this event.
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        DRMAuthenticateEvent::DRMAuthenticateEvent(std::string type, bool bubbles, bool cancelable, std::string header, std::string userPrompt, std::string passPrompt, std::string urlPrompt, std::string authenticationType, NetStream* netstream);

        /**
         * Returns a string that contains all the properties of the DRMAuthenticateEvent object. 
         * The string is in the following format: 
         * [DRMAuthenticateEvent type=value bubbles=value cancelable=value
         * eventPhase=value header=value usernamePrompt=value passwordPrompt=value
         * urlPrompt=value] authenticationType=value
         * @return  A string that contains all the properties of the DRMAuthenticateEvent object.
         * @playerversion   AIR 1.0
         */
        std::string DRMAuthenticateEvent::toString()         ;
}
}

