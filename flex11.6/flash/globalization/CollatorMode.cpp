

    /**
     * The CollatorMode class enumerates constant values that govern the behavior of string comparisons
     * performed by a Collator object.
     * These constants represent the values that can be passed in the <codeph class="+ topic/ph pr-d/codeph ">initialMode</codeph> parameter 
     * of the <codeph class="+ topic/ph pr-d/codeph ">Collator()</codeph> constructor.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * Initializes a Collator object so that the compare method is optimized for
         * sorting a list of text strings to be displayed to an end user.
         * In this mode, string comparisons consider 
         * differences in uppercase and lowercase letters, accented characters, and so on, 
         * according to the language and sorting rules required by the locale.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string CollatorMode::SORTING="sorting";

        /**
         * Initializes a Collator object so that the compare method is optimized for
         * determining whether two strings are equivalent.
         * In this mode, string comparisons ignore differences in uppercase and lower
         * case letters, accented characters, etc.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string CollatorMode::MATCHING="matching";

        CollatorMode::CollatorMode();
}
}

