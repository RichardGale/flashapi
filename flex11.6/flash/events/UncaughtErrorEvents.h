#if !defined(FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENTS_AS)
#define FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENTS_AS
#if defined(__cplusplus)


/**
 * Dispatched when an error occurs and developer code doesn't detect and handle
 * the error.
 * @eventType   flash.events.UncaughtErrorEvent.UNCAUGHT_ERROR
 */
//[Event(name="uncaughtError",type="flash.events.UncaughtErrorEvent")]





















#include "flex11.6.h"



namespace flash
{
    namespace events
    {
        /**
         * The UncaughtErrorEvents class provides a way to receive uncaught
         * error events. An instance of this class dispatches an
         * <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event when a runtime error occurs and the
         * error isn't detected and handled in your code.
         *
         *   <p class="- topic/p ">Use the following properties to access an UncaughtErrorEvents instance:</p><ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">LoaderInfo.uncaughtErrorEvents</codeph>: to
         * detect uncaught errors in code defined in the same SWF.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">Loader.uncaughtErrorEvents</codeph>: to detect uncaught
         * errors in code defined in the SWF loaded by a Loader object.</li></ul><p class="- topic/p ">To catch an error directly and prevent an uncaught error event,
         * do the following:</p><ul class="- topic/ul "><li class="- topic/li ">Use a <codeph class="+ topic/ph pr-d/codeph "><xref href="../../statements.html#try..catch..finally" class="- topic/xref ">try..catch</xref></codeph>
         * block to isolate code that potentially throws a synchronous error</li><li class="- topic/li ">When performing an operation that dispatches an event when an error occurs,
         * register a listener for that error event</li></ul><p class="- topic/p ">If the content loaded by a Loader object is an AVM1 (ActionScript 2) SWF file,
         * uncaught errors in the AVM1 SWF file do not result in an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph>
         * event. In addition, JavaScript errors in HTML content loaded in an HTMLLoader object
         * (including a Flex HTML control) do not result in an <codeph class="+ topic/ph pr-d/codeph ">uncaughtError</codeph> event.</p>
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        class UncaughtErrorEvents : public EventDispatcher
        {
            /**
             * Creates an UncaughtErrorEvents instance. Developer code shouldn't create
             * UncaughtErrorEvents instances directly. To access an UncaughtErrorEvents
             * object, use one of the following properties:
             *
             *   LoaderInfo.uncaughtErrorEvents: to
             * detect uncaught errors in code defined in the same SWF.Loader.uncaughtErrorEvents: to detect uncaught
             * errors in code defined in the SWF loaded by a Loader object.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            UncaughtErrorEvents();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_UNCAUGHTERROREVENTS_AS
#endif // __cplusplus

