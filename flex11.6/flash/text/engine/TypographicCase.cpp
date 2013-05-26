

    /**
     * The TypographicCase class is an enumeration of constant values for setting the <codeph class="+ topic/ph pr-d/codeph ">typographicCase</codeph> property 
     * of the ElementFormat class.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Specifies default typographic case. The results are font-dependent; characters use the settings specified by the font designer
         * without any features applied.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::DEFAULT   = "default";

        /**
         * Specifies that uppercase characters use title glyphs on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::TITLE   = "title";

        /**
         * Specifies that spacing is adjusted for uppercase characters on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::CAPS   = "caps";

        /**
         * Specifies that uppercase characters use small-caps glyphs on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::SMALL_CAPS   = "smallCaps";

        /**
         * Specifies that all characters use uppercase glyphs on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::UPPERCASE   = "uppercase";

        /**
         * Specifies that all characters use lowercase glyphs on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::LOWERCASE   = "lowercase";

        /**
         * Specifies that all lowercase characters use small-caps glyphs on output.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string TypographicCase::CAPS_AND_SMALL_CAPS   = "capsAndSmallCaps";

        TypographicCase::TypographicCase();
}
}
}

