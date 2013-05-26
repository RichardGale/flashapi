

    /**
     * The SoftKeyboardTrigger class defines the possible values for the <codeph class="+ topic/ph pr-d/codeph ">triggerType</codeph> property 
     * of the SoftKeyboardEvent class. These values indicate what type of action triggered a SoftKeyboard 
     * activation event.
     * @langversion 3.0
     * @playerversion   AIR 2.6
     * @playerversion   Flash 10.2
     */


namespace flash {
namespace events {


        /**
         * A function call triggered the event.
         * @langversion 3.0
         * @playerversion   AIR 2.6
         * @playerversion   Flash 10.2
         */
        const std::string SoftKeyboardTrigger::CONTENT_TRIGGERED   = "contentTriggered";

        /**
         * A user action triggered the event. Typical user actions that can trigger this event include 
         * explicitly closing the keyboard, or pressing the Back key.
         * @langversion 3.0
         * @playerversion   AIR 2.6
         * @playerversion   Flash 10.2
         */
        const std::string SoftKeyboardTrigger::USER_TRIGGERED   = "userTriggered";

        SoftKeyboardTrigger::SoftKeyboardTrigger();
}
}

