

    /**
     * This class contains constants for use with the <codeph class="+ topic/ph pr-d/codeph ">IME.conversionMode</codeph>
     * property. Setting <codeph class="+ topic/ph pr-d/codeph ">conversionMode</codeph> to either 
     * <codeph class="+ topic/ph pr-d/codeph ">ALPHANUMERIC_FULL</codeph> or <codeph class="+ topic/ph pr-d/codeph ">JAPANESE_KATAKANA_FULL</codeph> causes the
     * player to use a full width font, whereas using <codeph class="+ topic/ph pr-d/codeph ">ALPHANUMERIC_HALF</codeph> or
     * <codeph class="+ topic/ph pr-d/codeph ">JAPANESE_KATAKANA_HALF</codeph> uses a half width font.
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace system {


        /**
         * The string "ALPHANUMERIC_FULL", for use with the  
         * IME.conversionMode property.
         * This constant is used with all IMEs.
         * Use the syntax IMEConversionMode.ALPHANUMERIC_FULL.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::ALPHANUMERIC_FULL="ALPHANUMERIC_FULL";

        /**
         * The string "ALPHANUMERIC_HALF", for use with the 
         * IME.conversionMode property.
         * This constant is used with all IMEs.
         * Use the syntax IMEConversionMode.ALPHANUMERIC_HALF.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::ALPHANUMERIC_HALF="ALPHANUMERIC_HALF";

        /**
         * The string "CHINESE", for use with the 
         * IME.conversionMode property.
         * This constant is used with simplified and traditional Chinese IMEs.
         * Use the syntax IMEConversionMode.CHINESE.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::CHINESE="CHINESE";

        /**
         * The string "JAPANESE_HIRAGANA", for use with the
         * IME.conversionMode property. 
         * This constant is used with Japanese IMEs.
         * Use the syntax IMEConversionMode.JAPANESE_HIRAGANA.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::JAPANESE_HIRAGANA="JAPANESE_HIRAGANA";

        /**
         * The string "JAPANESE_KATAKANA_FULL", for use with the 
         * IME.conversionMode property.
         * This constant is used with Japanese IMEs.
         * Use the syntax IMEConversionMode.JAPANESE_KATAKANA_FULL.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::JAPANESE_KATAKANA_FULL="JAPANESE_KATAKANA_FULL";

        /**
         * The string "JAPANESE_KATAKANA_HALF", for use with the 
         * IME.conversionMode property. 
         * This constant is used with Japanese IMEs.
         * Use the syntax IMEConversionMode.JAPANESE_KATAKANA_HALF.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::JAPANESE_KATAKANA_HALF="JAPANESE_KATAKANA_HALF";

        /**
         * The string "KOREAN", for use with the 
         * IME.conversionMode property.
         * This constant is used with Korean IMEs.
         * Use the syntax IMEConversionMode.KOREAN.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::KOREAN="KOREAN";

        /**
         * The string "UNKNOWN", which can be returned by a call to
         * the IME.conversionMode property. This value cannot be set, 
         * and is returned only if the player is unable to identify the currently 
         * active IME.
         * Use the syntax IMEConversionMode.UNKNOWN.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string IMEConversionMode::UNKNOWN="UNKNOWN";

        IMEConversionMode::IMEConversionMode();
}
}

