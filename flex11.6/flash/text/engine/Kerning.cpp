

    /**
     * The Kerning class is an enumeration of constant values used with <codeph class="+ topic/ph pr-d/codeph ">ElementFormat.kerning</codeph>.
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Used to indicate kerning is enabled.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string Kerning::ON   = "on";

        /**
         * Used to indicate kerning is disabled.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string Kerning::OFF   = "off";

        /**
         * Used to indicate that kerning is enabled except where inappropriate in Asian typography. Kerning is 
         * applied between two characters if neither is Kanji, Hiragana, or Katakana.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string Kerning::AUTO   = "auto";

        Kerning::Kerning();
}
}
}

