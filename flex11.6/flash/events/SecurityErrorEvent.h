#if !defined(FLEX11_6_FLASH_EVENTS_SECURITYERROREVENT_AS)
#define FLEX11_6_FLASH_EVENTS_SECURITYERROREVENT_AS
#if defined(__cplusplus)


namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.SecurityErrorEvent.SECURITY_ERROR
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * An object dispatches a SecurityErrorEvent object to report the occurrence of a
 * security error. Security errors reported through this class are generally from asynchronous
 * operations, such as loading data, in which security violations may not manifest immediately.
 * Your event listener can access the object's <codeph class="+ topic/ph pr-d/codeph ">text</codeph> property to determine what operation was
 * attempted and any URLs that were involved. If there are no event listeners, <ph class="- topic/ph ">the
 * debugger version of Flash Player</ph> or the AIR Debug Launcher (ADL) application
 * automatically displays an error message that contains the contents of the <codeph class="+ topic/ph pr-d/codeph ">text</codeph>
 * property. There is one type of security error event: <codeph class="+ topic/ph pr-d/codeph ">SecurityErrorEvent.SECURITY_ERROR</codeph>.
 *
 *   <p class="- topic/p ">Security error events are the final events dispatched for any target object.
 * This means that any other events, including generic error events, are not dispatched for a target object
 * that experiences a security error.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">SecurityErrorEventExample</codeph> class to show how a
 * listener method <codeph class="+ topic/ph pr-d/codeph ">securityErrorHandler()</codeph> can be instantiated and set to listen for <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph>
 * events to be dispatched. This event will occur when a <codeph class="+ topic/ph pr-d/codeph ">URLRequest</codeph> location is not in exactly
 * the same domain as the calling SWF, and the requested domain has not authorized cross-domain access by way of
 * a cross-domain policy file.
 * <p class="- topic/p ">To create a <codeph class="+ topic/ph pr-d/codeph ">SecurityErrorEvent</codeph>, replace <codeph class="+ topic/ph pr-d/codeph ">http://www.[yourdomain].com</codeph> with a path that has not been authorized for
 * cross domain access.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.net.URLLoader;
 * import flash.net.URLRequest;
 * import flash.events.SecurityErrorEvent;
 *
 *   public class SecurityErrorEventExample extends Sprite {
 * public function SecurityErrorEventExample() {
 * var loader:URLLoader = new URLLoader();
 * loader.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
 *
 *   var request:URLRequest = new URLRequest("http://www.[yourDomain].com");
 * loader.load(request);
 * }
 *
 *   private function securityErrorHandler(event:SecurityErrorEvent):void {
 * trace("securityErrorHandler: " + event);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::events;

namespace flash
{
    namespace events
    {
        class SecurityErrorEvent: public ErrorEvent
        {
            /**
             * The SecurityErrorEvent.SECURITY_ERROR constant defines the value of the type property of a securityError event object.
             *
             *   This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe network object reporting the security error.textText to be displayed as an error message.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    (at)see flash.display.LoaderInfo#event:securityError
             */
        public:
            static const std::string SECURITY_ERROR;

            /**
             * Creates a copy of the SecurityErrorEvent object and sets the value of each property to match that of the original.
             * @return  A new securityErrorEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object that contains information about security error events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one type of error event: SecurityErrorEvent.SECURITY_ERROR.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   text    Text to be displayed as an error message. Event listeners can access this information through the text property.
             * @param   id  A reference number to associate with the specific error.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            SecurityErrorEvent(std::string type, bool bubbles, bool cancelable, std::string text, int id);

            /**
             * Returns a string that contains all the properties of the SecurityErrorEvent object. The string is in the following format:
             * [securityErrorEvent type=value bubbles=value cancelable=value text=value errorID=value]
             * The errorId is only available in Adobe AIR
             * @return  A string that contains all the properties of the SecurityErrorEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_SECURITYERROREVENT_AS
#endif // __cplusplus

