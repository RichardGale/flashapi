

    /**
     * The LineJustification class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">lineJustfication</codeph> property 
     * of the TextJustifier subclasses.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Do not justify lines.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LineJustification::UNJUSTIFIED   = "unjustified";

        /**
         * Justify all but the last line.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LineJustification::ALL_BUT_LAST   = "allButLast";

        /**
         * Justify all lines.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LineJustification::ALL_INCLUDING_LAST   = "allIncludingLast";
        const std::string LineJustification::ALL_BUT_MANDATORY_BREAK  ;

        LineJustification::LineJustification();
}
}
}

