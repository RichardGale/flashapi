

    /**
     * The SpreadMethod class provides values for the <codeph class="+ topic/ph pr-d/codeph ">spreadMethod</codeph> parameter 
     * in the <codeph class="+ topic/ph pr-d/codeph ">beginGradientFill()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">lineGradientStyle()</codeph> methods of the Graphics class.
     * 
     *   <p class="- topic/p ">The following example shows the same gradient fill using various spread methods:</p><adobetable class="+ topic/table adobe-d/adobetable "><tgroup cols="3" class="- topic/tgroup "><tbody class="- topic/tbody "><row class="- topic/row "><entry align="center" class="- topic/entry "><adobeimage alt="linear gradient with SpreadMethod.PAD" href="../../images/beginGradientFill_spread_pad.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry align="center" class="- topic/entry "><adobeimage alt="linear gradient with SpreadMethod.REFLECT" href="../../images/beginGradientFill_spread_reflect.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry><entry align="center" class="- topic/entry "><adobeimage alt="linear gradient with SpreadMethod.REPEAT" href="../../images/beginGradientFill_spread_repeat.jpg" placement="inline" class="+ topic/image adobe-d/adobeimage " /></entry></row><row class="- topic/row "><entry align="center" class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SpreadMethod.PAD</codeph></entry><entry align="center" class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SpreadMethod.REFLECT</codeph></entry><entry align="center" class="- topic/entry "><codeph class="+ topic/ph pr-d/codeph ">SpreadMethod.REPEAT</codeph></entry></row></tbody></tgroup></adobetable>
     * @langversion 3.0
     * @playerversion   Flash 9
     */


namespace flash {
namespace display {


        /**
         * Specifies that the gradient use the pad spread method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string SpreadMethod::PAD="pad";

        /**
         * Specifies that the gradient use the reflect spread method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string SpreadMethod::REFLECT="reflect";

        /**
         * Specifies that the gradient use the repeat spread method.
         * @langversion 3.0
         * @playerversion   Flash 9
         */
        const std::string SpreadMethod::REPEAT="repeat";

        SpreadMethod::SpreadMethod();
}
}

