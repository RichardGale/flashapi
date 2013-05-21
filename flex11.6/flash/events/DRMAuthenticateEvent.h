#if !defined(FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATEEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATEEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace net
    {
        class NetStream;
    }
}
#include "flash/events/Event.h"

/// @eventType  flash.events.DRMAuthenticateEvent.AUTHENTICATION_TYPE_DRM
//[Event(name="drmAuthenticate",type="flash.events.DRMAuthenticateEvent")]

/// @eventType  flash.events.DRMAuthenticateEvent.AUTHENTICATION_TYPE_PROXY
//[Event(name="drmAuthenticate",type="flash.events.DRMAuthenticateEvent")]


//[Event(name="drmAuthenticate",type="flash.events.DRMAuthenticateEvent")]

using namespace flash::events;
using namespace flash::net;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.DRMAuthenticateEvent.DRM_AUTHENTICATE


        /**
         * A NetStream object dispatchs a DRMAuthenticateEvent object when attempting to play digital rights management (DRM) encrypted
         * content that requires a user credential for authentication.
         * <p class="- topic/p ">
         * The DRMAuthenticateEvent handler is responsible for gathering the required credentials
         * (such as the user name, password, and type) and passing the values to the
         * <codeph class="+ topic/ph pr-d/codeph ">NetStream.setDRMAuthenticationCredentials()</codeph> method for authentication. Each
         * AIR application must provide some mechanism for obtaining user credentials.
         * For example, the application could provide a user with a simple user interface to enter the
         * username and password values, and optionally the type value as well.
         * </p><p class="- topic/p ">
         * If user authentication failed, the application will retry
         * authentication and dispatch a new DRMAuthenticateEvent event for the NetStream object.
         * </p>
         *
         *   EXAMPLE:
         *
         *   <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">package
         * {
         * import flash.display.Sprite;
         * import flash.events.AsyncErrorEvent;
         * import flash.events.NetStatusEvent;
         * import flash.events.DRMAuthenticateEvent;
         * import flash.media.Video;
         * import flash.net.NetConnection;
         * import flash.net.NetStream;
         *
         *   public class DRMAuthenticateEventExample extends Sprite
         * {
         * var videoURL:String = "Video.flv";
         * var videoConnection:NetConnection;
         * var videoStream:NetStream;
         * var video:Video = new Video();
         *
         *   public function DRMAuthenticateEventExample()
         * {
         * videoConnection = new NetConnection();
         * videoConnection.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler);
         * videoConnection.connect(null);
         * }
         *
         *   private function connectStream():void {
         * videoStream = new NetStream(videoConnection);
         * videoStream.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler);
         * videoStream.addEventListener(AsyncErrorEvent.ASYNC_ERROR, asyncErrorHandler);
         * videoStream.addEventListener(DRMAuthenticateEvent.DRM_AUTHENTICATE, drmAuthenticateEventHandler);
         * video.attachNetStream(videoStream);
         * videoStream.play(videoURL);
         * addChild(video);
         * }
         *
         *   private function netStatusHandler(event:NetStatusEvent):void {
         * switch (event.info.code) {
         * case "NetConnection.Connect.Success":
         * connectStream();
         * break;
         * case "NetStream.Play.StreamNotFound":
         * trace("Unable to locate video: " + videoURL);
         * break;
         * }
         * }
         *
         *   private function asyncErrorHandler(event:AsyncErrorEvent):void {
         * // ignore AsyncErrorEvent events.
         * }
         *
         *   private function drmAuthenticateEventHandler(event:DRMAuthenticateEvent):void {
         * videoStream.setDRMAuthenticationCredentials("User", "password", "drm");
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   AIR 1.0
         */
        class DRMAuthenticateEvent : public flash::events::Event
        {
            /**
             * The DRMAuthenticateEvent.DRM_AUTHENTICATE constant defines the value of the
             * type property of a DRMAuthenticateEvent object.
             *
             *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for
             * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string DRM_AUTHENTICATE;

            /**
             * The DRMAuthenticateEvent.AUTHENTICATION_TYPE_DRM constant defines the value of the
             * authenticationType property of a DRMAuthenticateEvent object.
             *
             *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for
             * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse; there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string AUTHENTICATION_TYPE_DRM;

            /**
             * The DRMAuthenticateEvent.AUTHENTICATION_TYPE_PROXY constant defines the value of the
             * authenticationType property of a DRMAuthenticateEvent object.
             *
             *   This event has the following properties:PropertyValueauthenticationTypeIndicates whether the supplied credentials are for
             * authenticating against the Flash Media Rights Management Server (FMRMS) or a proxy server.bubblesfalsecancelablefalse; there is no default behavior to cancel.headerThe encrypted content file header provided by the server.netstreamThe NetStream object that initiated this event.passwordPromptA prompt for a password credential, provided by the server.targetThe NetStream object.urlPromptA prompt for a URL to display, provided by the server.usernamePromptA prompt for a user name credential, provided by the server.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            static const std::string AUTHENTICATION_TYPE_PROXY;

            /**
             * The encrypted content file header provided by the server.
             * It contains information about the context of the encrypted content.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            std::string  header();

            /**
             * A prompt for a user name credential, provided by the server.
             * The string can include instruction for the type of user name required.
             * For example, a content provider may require an e-mail address as the user name.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            std::string  usernamePrompt();

            /**
             * A prompt for a password credential, provided by the server.
             * The string can include instruction for the type of password required.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            std::string  passwordPrompt();

            /**
             * A prompt for a URL string, provided by the server.
             * The string can provide the location where the username and password will be sent.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            std::string  urlPrompt();

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
        public:
            std::string  authenticationType();

            /**
             * The NetStream object that initiated this event.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            flash::net::NetStream *netstream();

            /**
             * Creates a copy of the DRMAuthenticateEvent object and sets the value of each property to match
             * that of the original.
             * @return  A new DRMAuthenticateEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             */
        public:
            flash::events::Event *clone();

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
        public:
            DRMAuthenticateEvent(std::string type, bool bubbles   =false, bool cancelable   =false, std::string header="", std::string userPrompt="", std::string passPrompt="", std::string urlPrompt="", std::string authenticationType="", NetStream *netstream=NULL);

            /**
             * Returns a string that contains all the properties of the DRMAuthenticateEvent object.
             * The string is in the following format:
             * [DRMAuthenticateEvent type=value bubbles=value cancelable=value
             * eventPhase=value header=value usernamePrompt=value passwordPrompt=value
             * urlPrompt=value] authenticationType=value
             * @return  A string that contains all the properties of the DRMAuthenticateEvent object.
             * @playerversion   AIR 1.0
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_DRMAUTHENTICATEEVENT_AS
#endif // __cplusplus

