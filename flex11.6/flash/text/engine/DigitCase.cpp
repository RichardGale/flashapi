

    /**
     * The DigitCase class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">digitCase</codeph> property 
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
         * Used to specify default digit case. The results are font-dependent; characters use the settings specified by the font designer
         * without any features applied.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitCase::DEFAULT   = "default";

        /**
         * Used to specify lining digit case.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitCase::LINING   = "lining";

        /**
         * Used to specify old style digit case.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitCase::OLD_STYLE   = "oldStyle";

        DigitCase::DigitCase();
}
}
}

