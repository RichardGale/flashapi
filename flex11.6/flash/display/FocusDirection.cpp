

    /**
     * The FocusDirection class enumerates values to be used for the 
     * <codeph class="+ topic/ph pr-d/codeph ">direction</codeph> parameter of the <codeph class="+ topic/ph pr-d/codeph ">assignFocus()</codeph> method
     * of a Stage object and for the <codeph class="+ topic/ph pr-d/codeph ">direction</codeph> property of a FocusEvent object.
     * @langversion 3.0
     * @playerversion   AIR 1.0
     */


namespace flash {
namespace display {


        /**
         * Indicates that focus should be given to the object at the beginning of the reading order.
         * @playerversion   AIR 1.0
         */
        const std::string FocusDirection::TOP   = "top";

        /**
         * Indicates that focus should be given to the object at the end of the reading order.
         * @playerversion   AIR 1.0
         */
        const std::string FocusDirection::BOTTOM   = "bottom";

        /**
         * Indicates that focus object within the interactive object should not change.
         * @playerversion   AIR 1.0
         */
        const std::string FocusDirection::NONE   = "none";

        FocusDirection::FocusDirection();
}
}

