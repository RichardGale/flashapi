

#include "UncaughtErrorEvent.h"
#include "flash/events/Event.h"

    /// @eventType  flash.events.UncaughtErrorEvent.UNCAUGHT_ERROR

using namespace flash::events;

namespace flash {
namespace events {


        /**
         * Defines the value of the type property of an uncaughtError event object.
         * This event has the following properties:PropertyValuebubblestruecancelabletrue; cancelling the event prevents the uncaught error dialog from appearing in debugger runtime versionscurrentTargetThe object that is actively processing the Event object with an event listener.errorThe uncaught error.targetThe LoaderInfo object associated with the SWF where the error happened.textText error message.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string UncaughtErrorEvent::UNCAUGHT_ERROR   = "uncaughtError";

        /**
         * The error object associated with the uncaught error. Typically, this 
         * object's data type is one of the following:
         * 
         *   An Error instance (or one of its subclasses), if the uncaught error is
         * a synchronous error created by a throw statement, such as an 
         * error that could have been caught using a try..catch blockAn ErrorEvent instance (or one of its subclasses), if the uncaught error
         * is an asynchronous error that dispatches an error event when the error happensHowever, the error property can potentially be an object of any
         * data type. ActionScript does not require a throw
         * statement to be used only with Error objects. For example, the following
         * code is legal both at compile time and run time:
         * <codeblock>
         * throw new Sprite()
         * </codeblock>
         * If that throw statement is not caught by a 
         * try..catch block, the throw statement 
         * triggers an uncaughtError event. In that case, the 
         * error property of the UncaughtErrorEvent object that's dispatched
         * is the Sprite object that's constructed in the throw statement.Consequently, in your uncaughtError listener, you should check
         * the data type of the error property. The following example 
         * demonstrates this check:
         * <codeblock>
         * 
         *   function uncaughtErrorHandler(event:UncaughtErrorEvent):void
         * {
         * var message:String;
         * 
         *   if (event.error is Error)
         * {
         * message = Error(event.error).message;
         * }
         * else if (event.error is ErrorEvent)
         * {
         * message = ErrorEvent(event.error).text;
         * }
         * else
         * {
         * message = event.error.toString();
         * }
         * }
         * </codeblock>
         * If the error property contains an Error instance (or Error subclass),  
         * the available error information varies depending on the version of the runtime
         * in which the content is running. The following functionality is only available 
         * when content is running in a debugger version of the runtime, such as the 
         * debugger version of Flash Player or the AIR Debug Launcher (ADL):Error.getStackTrace() to get the call stack that led to 
         * the error. In non-debugger runtime versions, this method returns 
         * null. Note that call stack information is never available 
         * when the error property is an ErrorEvent instance.Complete Error.message text. In non-debugger runtime versions,
         * this property contains a short version of the error message, which is often a 
         * combination of the Error.errorID and Error.name properties.All other properties and methods of the Error class are available in all 
         * runtime versions.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        void* UncaughtErrorEvent::error()    ;

        /**
         * Creates a copy of the UncaughtErrorEvent object and sets the value of 
         * each property to match that of the original.
         * @return  A new UncaughtErrorEvent object with property values that match those 
         *   of the original.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        flash::events::Event* UncaughtErrorEvent::clone()                     ;

        /**
         * Returns a string that contains all the properties of the UncaughtErrorEvent object.
         * @return  A string that contains all the properties of the UncaughtErrorEvent object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string UncaughtErrorEvent::toString()         ;

        /**
         * Creates an UncaughtErrorEvent object that contains information about an 
         * uncaughtError event.
         * @param   type    The type of the event.
         * @param   bubbles Determines whether the Event object participates in the bubbling stage of the event flow. Event listeners can access this information through the inherited bubbles property.
         * @param   cancelable  Determines whether the Event object can be canceled. Event listeners can access this information through the inherited cancelable property.
         * @param   error_in    The object associated with the error that was not caught or handled (an Error or ErrorEvent object under normal circumstances).
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        UncaughtErrorEvent::UncaughtErrorEvent(std::string type, bool bubbles, bool cancelable, void* error_in);
}
}

