

    /**
     * The DigitWidth class is an enumeration of constant values used in setting the <codeph class="+ topic/ph pr-d/codeph ">digitWidth</codeph> property 
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
         * Used to specify default digit width. The results are font-dependent; characters use the settings specified by the font designer
         * without any features applied.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitWidth::DEFAULT="default";

        /**
         * Used to specify proportional digit width.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitWidth::PROPORTIONAL="proportional";

        /**
         * Used to specify tabular digit width.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @playerversion   Lite 4
         */
        const std::string DigitWidth::TABULAR="tabular";

        DigitWidth::DigitWidth();
}
}
}

