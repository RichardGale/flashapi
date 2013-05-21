

    /**
     * The LigatureLevel class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">ligatureLevel</codeph> property 
     * of the ElementFormat class. A ligature occurs where two or more letter-forms are joined as a single glyph. Ligatures 
     * usually replace consecutive characters sharing common components, such as the letter pairs 'fi', 'fl', or 'ae'.
     * They are used with both Latin and Non-Latin character sets.
     * <p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> When working with Arabic or Syriac fonts, <codeph class="+ topic/ph pr-d/codeph ">ligatureLevel</codeph> must be set to MINIMUM or above.</p>
     * @langversion 3.0
     * @playerversion   Flash 10
     * @playerversion   AIR 1.5
     * @playerversion   Lite 4
     */


namespace flash {
namespace text {
namespace engine {


        /**
         * Used to specify no ligatures.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LigatureLevel::NONE="none";

        /**
         * Used to specify minimum ligatures.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LigatureLevel::MINIMUM="minimum";

        /**
         * Used to specify common ligatures.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LigatureLevel::COMMON="common";

        /**
         * Used to specify uncommon ligatures.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LigatureLevel::UNCOMMON="uncommon";

        /**
         * Used to specify exotic ligatures.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string LigatureLevel::EXOTIC="exotic";

        LigatureLevel::LigatureLevel();
}
}
}

