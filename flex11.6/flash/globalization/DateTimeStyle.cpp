

    /**
     * Enumerates constants that determine a locale-specific date and time formatting pattern. These constants are used when  
     * constructing a DateTimeFormatter object or when calling the <codeph class="+ topic/ph pr-d/codeph ">DateTimeFormatter.setDateTimeStyles()</codeph> method.
     * 
     *   <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">CUSTOM</codeph> constant cannot be used in the DateTimeFormatter constructor or the 
     * <codeph class="+ topic/ph pr-d/codeph ">DateFormatter.setDateTimeStyles()</codeph> method. 
     * This constant is instead set as the <codeph class="+ topic/ph pr-d/codeph ">timeStyle</codeph> and <codeph class="+ topic/ph pr-d/codeph ">dateStyle</codeph> property as a side effect of
     * calling the <codeph class="+ topic/ph pr-d/codeph ">DateTimeFormatter.setDateTimePattern()</codeph> method.
     * </p>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * Specifies that a custom pattern string is used to specify the date or time style.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeStyle::CUSTOM   = "custom";

        /**
         * Specifies the long style of a date or time.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeStyle::LONG   = "long";

        /**
         * Specifies the medium style of a date or time.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeStyle::MEDIUM   = "medium";

        /**
         * Specifies the short style of a date or time.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeStyle::SHORT   = "short";

        /**
         * Specifies that the date or time should not be included in the formatted string.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeStyle::NONE   = "none";

        DateTimeStyle::DateTimeStyle();
}
}

