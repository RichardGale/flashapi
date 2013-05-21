

    /**
     * A data structure that represents a currency amount and currency symbol or string that were extracted by parsing a currency value.
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * The currency amount value that was extracted from the input string.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        float CurrencyParseResult::value()         ;

        /**
         * The portion of the input string that corresponds to the currency symbol or currency string.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string CurrencyParseResult::currencyString()         ;

        /**
         * Constructs a currency parse result object.
         * @param   value   A number representing the currency amount value.
         * @param   symbol  A string representing the currency symbol.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        CurrencyParseResult::CurrencyParseResult(float value, std::string symbol);
}
}

