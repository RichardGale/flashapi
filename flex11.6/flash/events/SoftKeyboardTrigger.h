#if !defined(FLEX11_6_FLASH_EVENTS_SOFTKEYBOARDTRIGGER_AS)
#define FLEX11_6_FLASH_EVENTS_SOFTKEYBOARDTRIGGER_AS
#if defined(__cplusplus)


/**
 * The SoftKeyboardTrigger class defines the possible values for the <codeph class="+ topic/ph pr-d/codeph ">triggerType</codeph> property
 * of the SoftKeyboardEvent class. These values indicate what type of action triggered a SoftKeyboard
 * activation event.
 * @langversion 3.0
 * @playerversion   AIR 2.6
 * @playerversion   Flash 10.2
 */

#include "flex11.6.h"



namespace flash
{
    namespace events
    {
        class SoftKeyboardTrigger : public Object
        {
            /**
             * A function call triggered the event.
             * @langversion 3.0
             * @playerversion   AIR 2.6
             * @playerversion   Flash 10.2
             */
        public:
            static const std::string CONTENT_TRIGGERED;

            /**
             * A user action triggered the event. Typical user actions that can trigger this event include
             * explicitly closing the keyboard, or pressing the Back key.
             * @langversion 3.0
             * @playerversion   AIR 2.6
             * @playerversion   Flash 10.2
             */
        public:
            static const std::string USER_TRIGGERED;

        public:
            SoftKeyboardTrigger();
        };
    }
}

#endif // FLEX11_6_FLASH_EVENTS_SOFTKEYBOARDTRIGGER_AS
#endif // __cplusplus

