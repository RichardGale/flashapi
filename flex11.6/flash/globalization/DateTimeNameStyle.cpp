

    /**
     * The DateTimeNameStyle class enumerates constants that control the length of the month names and weekday names 
     * that are used when formatting dates. Use these constants for the <codeph class="+ topic/ph pr-d/codeph ">nameStyle</codeph> parameter 
     * of the DateTimeFormatter <codeph class="+ topic/ph pr-d/codeph ">getMonthNames()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">getWeekDayNames()</codeph> methods.
     * 
     *   <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">LONG_ABBREVIATION</codeph> and <codeph class="+ topic/ph pr-d/codeph ">SHORT_ABBREVIATION</codeph> may be the same or 
     * different depending on the operating system settings.</p>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * Specifies the full form or full name style for month names and weekday names.
         * 
         *   Examples: Tuesday, November.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeNameStyle::FULL="full";

        /**
         * Specifies the long abbreviation style for month names and weekday names.
         * 
         *   Examples: Tues for Tuesday, Nov for November.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeNameStyle::LONG_ABBREVIATION="longAbbreviation";

        /**
         * Specifies the short abbreviation style for month names and weekday names.
         * 
         *   Examples: T for Tuesday, N for November.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string DateTimeNameStyle::SHORT_ABBREVIATION="shortAbbreviation";

        DateTimeNameStyle::DateTimeNameStyle();
}
}

