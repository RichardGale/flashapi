

#include "TextEvent.h"
#include "flash/events/Event.h"
#include "flash/events/TextEvent.h"

    /// @eventType  flash.events.TextEvent.LINK

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of a link event object.
         * 
         *   This event has the following properties:PropertyValuebubblestruecancelablefalse; there is no default behavior to cancel.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe text field containing the hyperlink that has been clicked. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.textThe remainder of the URL after "event:"
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextEvent::LINK="link";

        /**
         * Defines the value of the type property of a textInput event object. 
         * Note: This event is not dispatched for the Delete or Backspace keys.This event has the following properties:PropertyValuebubblestruecancelabletrue; call the preventDefault() method 
         * to cancel default behavior.currentTargetThe object that is actively processing the Event 
         * object with an event listener.targetThe text field into which characters are being entered. 
         * The target is not always the object in the display list 
         * that registered the event listener. Use the currentTarget 
         * property to access the object in the display list that is currently processing the event.textThe character or sequence of characters entered by the user.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        const std::string TextEvent::TEXT_INPUT="textInput";

        /**
         * For a textInput event, the character or sequence of characters 
         * entered by the user. For a link event, the text 
         * of the event attribute of the href attribute of the 
         * <a> tag.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string TextEvent::text()         ;
        void TextEvent::text(std::string value)       ;

        /**
         * Creates a copy of the TextEvent object and sets the value of each property to match that of the original.
         * @return  A new TextEvent object with property values that match those of the original.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::events::Event* TextEvent::clone()                     ;

        /**
         * Creates an Event object that contains information about text events.
         * Event objects are passed as parameters to event listeners.
         * @param   type    The type of the event. Event listeners can access this information through the inherited type property. Possible values are:
         *   TextEvent.LINK and TextEvent.TEXT_INPUT.
         * @param   bubbles Determines whether the Event object participates in the bubbling phase of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   text    One or more characters of text entered by the user. Event listeners can access this information through the text property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        TextEvent::TextEvent(std::string type, bool bubbles, bool cancelable, std::string text);

        /**
         * Returns a string that contains all the properties of the TextEvent object. The string is in the following format:
         * [TextEvent type=value bubbles=value cancelable=value text=value]
         * @return  A string that contains all the properties of the TextEvent object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        std::string TextEvent::toString()         ;
}
}

