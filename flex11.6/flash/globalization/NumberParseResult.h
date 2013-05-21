#if !defined(FLEX11_6_FLASH_GLOBALIZATION_NUMBERPARSERESULT_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_NUMBERPARSERESULT_AS
#if defined(__cplusplus)


/**
 * A data structure that holds information about a number that was extracted by parsing a string.
 *
 *   <p class="- topic/p ">The number string can contain a prefix and suffix surrounding a number. In such
 * cases the <codeph class="+ topic/ph pr-d/codeph ">startIndex</codeph> property is set to the first character of the number.
 * Also, the <codeph class="+ topic/ph pr-d/codeph ">endIndex</codeph> property
 * is set to the index of the character that follows the last character of the number.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */


namespace flash
{
    namespace globalization
    {
        class NumberParseResult : public Object
        {
            /**
             * The value of the numeric portion of the input string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            float        value();

            /**
             * The index of the first character of the numeric portion of the input string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            int          startIndex();

            /**
             * The index of the character after the last character of the numeric portion of the input string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            int          endIndex();

            /**
             * Constructs a number parse result object.  NumberParseResult objects are usually created by the
             * NumberFormatter.parse() and NumberFormatter.parseNumber() methods, rather
             * than by calling this constructor directly.
             * @param   value   The value of the numeric portion of the input string.
             * @param   startIndex  The index of the first character of the number in the input string.
             * @param   endIndex    The index of the character after the last character of the number in the input string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            NumberParseResult(float value =NaN, int startIndex=2147483647, int endIndex=2147483647);
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_NUMBERPARSERESULT_AS
#endif // __cplusplus

