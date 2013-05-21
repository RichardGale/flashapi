#if !defined(FLEX11_6_FLASH_EVENTS_IMEEVENT_AS)
#define FLEX11_6_FLASH_EVENTS_IMEEVENT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace text
    {
        namespace ime
        {
            class IIMEClient;
        }
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}

/// @eventType  flash.events.IMEEvent.IME_COMPOSITION
//[Event(name="imeComposition",type="flash.events.IMEEvent")]


//[Event(name="imeComposition",type="flash.events.IMEEvent")]

using namespace flash::events;
using namespace flash::text::ime;

namespace flash
{
    namespace events
    {
        /// @eventType  flash.events.IMEEvent.IME_START_COMPOSITION


        /**
         * An IMEEvent object is dispatched when the user enters text using an input method editor
         * (IME). IMEs are generally used to enter text from languages that have ideographs instead of
         * letters, such as Japanese, Chinese, and Korean. There are two IME events:
         * <codeph class="+ topic/ph pr-d/codeph ">IMEEvent.IME_COMPOSITION</codeph> and <codeph class="+ topic/ph pr-d/codeph ">IMEEvent.IME_START_COMPOSITION</codeph>.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    includeExample examples\IMEEventExample.as -noswf
         */
        class IMEEvent : public TextEvent
        {
            /**
             * Defines the value of the type property of an imeComposition event object.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe IME object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static const std::string IME_COMPOSITION;

            /**
             * To handle IME text input, the receiver must set the imeClient field of the event to an object
             * that implements the IIMEClient interface. If imeClient is unset, the runtime uses out-of-line
             * IME composition instead, and sends the final composition as a TEXT_INPUT event.
             * This event has the following properties:PropertyValuebubblesfalsecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event
             * object with an event listener.targetThe IME object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @airversion  AIR 2
             */
        public:
            static const std::string IME_START_COMPOSITION;

            /**
             * Specifies an object that implements the IMEClient interface. Components based on the flash.text.engine
             * package must implement this interface to support editing text inline using an IME.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @airversion  AIR 2
             */
        public:
            flash::text::ime::IIMEClient *imeClient();
        public:
            void         imeClient(IIMEClient *value);

            /**
             * Creates a copy of the IMEEvent object and sets the value of each property to match that of the original.
             * @return  A new IMEEvent object with property values that match those of the original.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            flash::events::Event *clone();

            /**
             * Creates an Event object with specific information relevant to IME events.
             * Event objects are passed as parameters to event listeners.
             * @param   type    The type of the event. Event listeners can access this information through the inherited type property. There is only one IME event: IMEEvent.IME_COMPOSITION.
             * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
             * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
             * @param   text    The reading string from the IME. This is the initial string as typed by the user, before selection of any candidates. The final composition string is delivered to the object with keyboard focus in a TextEvent.TEXT_INPUT event. Event listeners can access this information through the text property.
             * @param   imeClient   A set of callbacks used by the text engine to communicate with the IME. Useful if your code has its own text engine and is rendering lines of text itself, rather than using TextField objects or the TextLayoutFramework.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            IMEEvent(std::string type, bool bubbles   =false, bool cancelable   =false, std::string text="", IIMEClient *imeClient=NULL);

            /**
             * Returns a string that contains all the properties of the IMEEvent object. The string is in the following format:
             * [IMEEvent type=value bubbles=value cancelable=value text=value]
             * @return  A string that contains all the properties of the IMEEvent object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string toString();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_IMEEVENT_AS
#endif // __cplusplus

