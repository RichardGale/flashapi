#if !defined(FLEX11_6_FLASH_GLOBALIZATION_LASTOPERATIONSTATUS_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_LASTOPERATIONSTATUS_AS
#if defined(__cplusplus)


/**
 * The LastOperationStatus class enumerates constant values that represent the status of the most recent globalization service operation.
 * These values can be retrieved through the read-only property <codeph class="+ topic/ph pr-d/codeph ">lastOperationStatus</codeph> available in most globalization
 * classes.
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace globalization
    {
        class LastOperationStatus : public Object
        {
            /**
             * Indicates that the last operation succeeded without any errors. This status can be returned
             * by all constructors, non-static methods, static methods and read/write properties.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NO_ERROR;

            /**
             * Indicates that a fallback value was set during the most recent operation.
             * This status can be returned by constructors and methods like DateTimeFormatter.setDateTimeStyles(),
             * and when retrieving properties like CurrencyFormatter.groupingPattern.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string USING_FALLBACK_WARNING;

            /**
             * Indicates that an operating system default value was used during the most recent operation.
             * Class constructors can return this status.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string USING_DEFAULT_WARNING;

            /**
             * Indicates that the parsing of a number failed.
             * This status can be returned by parsing methods of the formatter classes, such as
             * CurrencyFormatter.parse() and NumberFormatter.parseNumber(). For example, if the value "12abc34" is passed
             * as the parameter to the CurrencyFormatter.parse() method, the method returns "NaN" and sets the
             * lastOperationStatus value to LastOperationStatus.PARSE_ERROR.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string PARSE_ERROR;

            /**
             * Indicates that the requested operation or option is not supported. This status can be returned by methods like
             * DateTimeFormatter.setDateTimePattern() and when retrieving properties like
             * Collator.ignoreCase.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string UNSUPPORTED_ERROR;

            /**
             * Indicates that the return error code is not known.
             *
             *   Any non-static method or read/write properties can return this error when the operation is not successful
             * and the return error code is not known.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string ERROR_CODE_UNKNOWN;

            /**
             * Indicates that the pattern for formatting a number, date, or time is invalid.
             *
             *   This status is set when the user's operating system does not support the given pattern.
             *
             *   For example, the following code shows the value of the lastOperationStatus property after
             * an invalid "xx" pattern is used for date formatting:
             * <codeblock>
             *
             *   var df:DateTimeFormatter = new DateTimeFormatter("en-US");
             * df.setDateTimePattern("xx");
             * trace(df.lastOperationStatus); // "patternSyntaxError"
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string PATTERN_SYNTAX_ERROR;

            /**
             * Indicates that memory allocation has failed.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string MEMORY_ALLOCATION_ERROR;

            /**
             * Indicates that an argument passed to a method was illegal.
             *
             *   For example, the following code shows that an invalid argument error status is set
             * when CurrencyFormatter.grouping property is set to the invalid value "3;".
             * <codeblock>
             *
             *   var cf:CurrencyFormatter = new CurrencyFormatter("en-US");
             * cf.groupingPattern = "3;";
             * trace(cf.lastOperationStatus); // "illegalArgumentError"
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string ILLEGAL_ARGUMENT_ERROR;

            /**
             * Indicates that given buffer is not enough to hold the result.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string BUFFER_OVERFLOW_ERROR;

            /**
             * Indicates that a given attribute value is out of the expected range.
             *
             *   The following example shows that setting the NumberFormatter.negativeNumberFormat
             * property to an out-of-range value results in an invalid attribute value status.
             *
             *   <codeblock>
             *
             *   var nf:NumberFormatter = new NumberFormatter(LocaleID.DEFAULT);
             * nf.negativeNumberFormat = 9;
             * nf.lastOperationStatus; // "invalidAttrValue"
             *
             *   </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string INVALID_ATTR_VALUE;

            /**
             * Indicates that an operation resulted a value that exceeds a specified numeric type.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string NUMBER_OVERFLOW_ERROR;

            /**
             * Indicates that invalid Unicode value was found.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string INVALID_CHAR_FOUND;

            /**
             * Indicates that a truncated Unicode character value was found.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string TRUNCATED_CHAR_FOUND;

            /**
             * Indicates that an iterator went out of range or an invalid parameter was specified for month, day, or time.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string INDEX_OUT_OF_BOUNDS_ERROR;

            /**
             * Indicates that an underlying platform API failed for an operation.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string PLATFORM_API_FAILED;

            /**
             * Indicates that an unexpected token was detected in a Locale ID string.
             *
             *   For example, the following code shows the value of the lastOperationStatus property after
             * an incomplete string is used when requesting a locale ID. As a result the lastOperationStatus
             * property is set to the value UNEXPECTED_TOKEN after a call to the
             * LocaleID.getKeysAndValues() method.
             *
             *   <codeblock>
             *
             *   var locale:LocaleID = new LocaleID("en-US@Collation");
             *   var kav:Object = locale.getKeysAndValues();
             *   trace(locale.lastOperationStatus); // "unexpectedToken"
             *
             *     </codeblock>
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static const std::string UNEXPECTED_TOKEN;

        public:
            LastOperationStatus();
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_LASTOPERATIONSTATUS_AS
#endif // __cplusplus

