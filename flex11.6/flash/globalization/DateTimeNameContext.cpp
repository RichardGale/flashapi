

    /**
     * The DateTimeNameContext class enumerates constant values representing the formatting context in which a month name 
     * or weekday name is used. These constants are used for the <codeph class="+ topic/ph pr-d/codeph ">context</codeph> parameters for the DateTimeFormatter's
     * <codeph class="+ topic/ph pr-d/codeph ">getMonthNames()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">getWeekDayNames()</codeph> methods.
     * 
     *   <p class="- topic/p ">The context parameter only changes the results of those methods for certain locales and operating systems. 
     * For most locales the lists of month names and weekday names do not differ by context.</p>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * Indicates that the date element name is used within a date format.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeNameContext::FORMAT   = "format";

        /**
         * Indicates that the date element name is used in a "stand alone" context, independent of other formats. 
         * For example, the name can be used to show only the month name in a calendar or the weekday name in a date chooser.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeNameContext::STANDALONE   = "standalone";

        DateTimeNameContext::DateTimeNameContext();
}
}

