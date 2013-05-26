

    /**
     * The BreakOpportunity class is an enumeration of constant values that you can use to set the <codeph class="+ topic/ph pr-d/codeph ">breakOpportunity</codeph> property 
     * of the ElementFormat class. 
     * This property determines which characters can be used for breaking when wrapping text is broken into multiple lines.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Bases line break opportunities on Unicode character properties. This setting implements 
         * the Unicode line breaking properties defined by the Unicode Standard Annex #14.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string BreakOpportunity::AUTO   = "auto";

        /**
         * Treats any character in the ContentElement object as a line break opportunity.
         * This value is typically used when Roman text is embedded in Asian text and it is desirable for breaks to happen
         * in the middle of words.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string BreakOpportunity::ANY   = "any";

        /**
         * Treats no characters in the ContentElement object as line break opportunities.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string BreakOpportunity::NONE   = "none";

        /**
         * Treats all characters in the ContentElement object as line break opportunities, meaning that a line break will occur
         * afer each character. You can use this option to generate the shortest possible lines, 
         * which you can use to create text on a line or similar effects.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string BreakOpportunity::ALL   = "all";

        BreakOpportunity::BreakOpportunity();
}
}
}

