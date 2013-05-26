#if !defined(FLEX11_6_FLASH_EVENTS_HTTPSTATUSEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_HTTPSTATUSEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/Event.h"

/// @eventType  flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
//[Event(name="httpResponseStatus",type="flash.events.HTTPStatusEvent")]


//[Event(name="httpStatus",type="flash.events.HTTPStatusEvent")]

using namespace flash::events;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.HTTPStatusEvent.HTTP_STATUS


        /**
         * The application dispatches HTTPStatusEvent objects when a network request returns an HTTP
         * status code.
         *
         *   <p class="- topic/p ">HTTPStatusEvent objects are always sent before error or completion events. An
         * HTTPStatusEvent object does not necessarily indicate an error condition; it simply reflects
         * the HTTP status code (if any) that is provided by the networking stack. <ph class="- topic/ph ">Some Flash
         * Player environments may be unable to detect HTTP status codes; a status code of 0 is always
         * reported in these cases.</ph></p><p class="- topic/p "><ph class="- topic/ph ">In Flash Player, there is only one type of HTTPStatus event:
         * <codeph class="+ topic/ph pr-d/codeph ">httpStatus</codeph>.</ph> In the AIR runtime, a FileReference, URLLoader, or URLStream
         * can register to listen for an <codeph class="+ topic/ph pr-d/codeph ">httpResponseStatus</codeph>, which includes <codeph class="+ topic/ph pr-d/codeph ">responseURL</codeph>
         * and <codeph class="+ topic/ph pr-d/codeph ">responseHeaders</codeph> properties. These properties are undefined in a <codeph class="+ topic/ph pr-d/codeph ">httpStatus</codeph>
         * event.</p>
         *
         *   EXAMPLE:
         *
         *   The following example attempts to load a nonexistent file from the root web directory
         * at http://www.[yourDomain].com, which should dispatch an <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler</codeph> event with a status of 404, indicating that
         * the file was not found.  The <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler</codeph> event is handled by <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler()</codeph>,
         * which simply prints two lines of information about the event.
         *
         *   <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ol class="- topic/ol "><li class="- topic/li ">You need to compile the SWF file with "Local Playback Security" set
         * to "Access Network Only" to generate a <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph> event in this example.</li><li class="- topic/li ">You need a server running on http://www.[yourDomain].com and listening on port 80 or you will receive
         * an <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler</codeph> event with status code 0 instead of 404.</li><li class="- topic/li ">You must not have a file named MissingFile.html at the root web directory
         * of http://www.[yourDomain].com or you will not receive the correct <codeph class="+ topic/ph pr-d/codeph ">httpStatusHandler</codeph> event.</li></ol></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         * package {
         * import flash.display.Sprite;
         * import flash.net.URLLoader;
         * import flash.net.URLRequest;
         * import flash.events.HTTPStatusEvent;
         *
         *   public class HTTPStatusEventExample extends Sprite {
         *
         *   public function HTTPStatusEventExample() {
         * var loader:URLLoader = new URLLoader();
         * loader.addEventListener(HTTPStatusEvent.HTTP_STATUS, httpStatusHandler);
         *
         *   var request:URLRequest = new URLRequest("http://www.[yourDomain].com/MissingFile.html");
         * loader.load(request);
         * }
         *
         *   private function httpStatusHandler(event:HTTPStatusEvent):void {
         * trace("httpStatusHandler: " + event);
         * trace("status: " + event.status);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class HTTPStatusEvent : public flash::events::Event
        {
            /**
             * The HTTPStatusEvent.HTTP_STATUS constant defines the value of the
             * type property of a httpStatus event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.statusThe HTTP status code returned by the server.targetThe network object receiving an HTTP status code.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string HTTP_STATUS;

            /**
             * Unlike the httpStatus event, the httpResponseStatus event is
             * delivered before any response data. Also, the httpResponseStatus event includes
             * values for the responseHeaders and responseURL properties (which are
             * undefined for an httpStatus event. Note that the httpResponseStatus event
             * (if any) will be sent before (and in addition to) any complete or error
             * event.
             *
             *   The HTTPStatusEvent.HTTP_RESPONSE_STATUS constant defines the value of the
             * type property of a httpResponseStatus event object. This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.responseURLThe URL from which the response was returned.responseHeadersThe response headers that the response returned,
             * as an array of URLRequestHeader objects.statusThe HTTP status code returned by the server.targetThe network object receiving an HTTP status code.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            static const std::string HTTP_RESPONSE_STATUS;

            /**
             * The HTTP status code returned by the server. For example, a value of 404 indicates that the server
             * has not found a match for the requested URI. HTTP status codes can be found in sections 10.4 and 10.5
             * of the HTTP specification at
             * http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html.
             *
             *   If Flash Player or AIR cannot get a status code from the
             * server, or if it cannot communicate with the server, the default value of 0 is passed to your code.
             * A value of 0 can be generated in any player (for example,
             * if a malformed URL is requested), and a value of 0 is always generated by the Flash Player plug-in
             * when it is run in the following browsers, which do not pass HTTP status codes to the player:
             * Netscape, Mozilla, Safari, Opera, and Internet Explorer for the Macintosh.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            int          status();

            /**
             * The URL that the response was returned from. In the case of redirects, this will be different
             * from the request URL.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            std::string       responseURL();
        public:
            void         responseURL(std::string value);

            /**
             * The response headers that the response returned, as an array of URLRequestHeader objects.
             * @langversion 3.0
             * @playerversion   AIR 1.0
             * @playerversion   Lite 4
             */
        public:
            std::vector<void *>        responseHeaders();
        public:
            void         responseHeaders(std::vector<void *> value);

            /**
             * Creates a copy of the HTTPStatusEvent object and sets the value of each property to match that of the original.
             * @return  A new HTTPStatusEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains specific information about HTTP status events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of HTTPStatus event: HTTPStatusEvent.HTTP_STATUS.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   status  Numeric status. Event listeners can access this information through the status property.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            HTTPStatusEvent(std::string type, bool bubbles=false, bool cancelable=false, int status=0);

            /**
             * Returns a string that contains all the properties of the HTTPStatusEvent object. The string is in the following format:
             * [HTTPStatusEvent type=value bubbles=value cancelable=value status=value]
             * @return  A string that contains all the properties of the HTTPStatusEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string   toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_HTTPSTATUSEVENT_AS
#endif // __cplusplus

