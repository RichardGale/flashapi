#if !defined(FLEX11_6_FLASH_GLOBALIZATION_CURRENCYPARSERESULT_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_CURRENCYPARSERESULT_AS
#if defined(__cplusplus)


/**
 * A data structure that represents a currency amount and currency symbol or string that were extracted by parsing a currency value.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */


namespace flash
{
    namespace globalization
    {
        class CurrencyParseResult : public Object
        {
            /**
             * The currency amount value that was extracted from the input string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float        value();

            /**
             * The portion of the input string that corresponds to the currency symbol or currency string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  currencyString();

            /**
             * Constructs a currency parse result object.
             * @param   value   A number representing the currency amount value.
             * @param   symbol  A string representing the currency symbol.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            CurrencyParseResult(float value =NaN, std::string symbol="");
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_CURRENCYPARSERESULT_AS
#endif // __cplusplus

