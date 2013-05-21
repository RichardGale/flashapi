#if !defined(FLEX11_6_FLASH_GLOBALIZATION_CURRENCYFORMATTER_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_CURRENCYFORMATTER_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace globalization
    {
        class CurrencyParseResult;
    }
}

/**
 * The CurrencyFormatter class provides locale-sensitive formatting and parsing of currency values.
 *
 *   <p class="- topic/p ">The CurrencyFormatter class uses the data and functionality provided by the operating system
 * and is designed to format currency values according to the conventions
 * of a specific locale and type of currency.  The position of the currency symbol,
 * the negative symbol, the decimal separator, the grouping separator, the grouping pattern
 * decimal separator, and other elements can vary depending on the locale.</p><p class="- topic/p ">If the operating system supports the requested locale, the properties and
 * currency type are set according to the conventions and defaults of the requested locale.
 * If the requested locale is not available, then the properties are set according to
 * a fallback or default system locale, which can be retrieved using the <codeph class="+ topic/ph pr-d/codeph ">actualLocaleIDName</codeph> property.
 * </p><p class="- topic/p ">
 * Due to the use of the user's settings, the use of formatting patterns
 * provided by the operating system, and the use of a fallback locale when a requested locale is not supported,
 * different users can see different formatting results, even when using the same locale ID.
 * </p>
 *
 *   EXAMPLE:
 *
 *   The following shows how a currency amount is formatted
 * differently based on different locales and currencies.
 *
 *   The results from this example will differ based on your operating system and user preferences.
 * <p class="- topic/p ">
 * This example uses the following locales:
 * </p><ul class="- topic/ul "><li class="- topic/li ">The default operating system locale for currency formatting (<codeph class="+ topic/ph pr-d/codeph ">LocaleID.DEFAULT</codeph>)</li><li class="- topic/li ">Japanese (Japan)</li><li class="- topic/li ">English (US)</li><li class="- topic/li ">French (France)</li></ul><p class="- topic/p ">The example does the following for each locale in the list:</p><ol class="- topic/ol "><li class="- topic/li ">Creates a CurrencyFormatter object</li><li class="- topic/li ">Uses the <codeph class="+ topic/ph pr-d/codeph ">formattingWithCurrencySymbolIsSafe()</codeph> method to check whether the default currency for the locale is Euros ("EUR")
 * and if so it formats the string using the currency symbol. Otherwise it formats the string using the ISO code.
 * </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.globalization.CurrencyFormatter;
 * import flash.globalization.LocaleID;
 *
 *   public class CurrencyFormatterExample1 extends Sprite
 * {
 * public function CurrencyFormatterExample1():void
 * {
 * var cf:CurrencyFormatter;
 * var amountWithSymbol:String;
 * var amountWithISOCode:String
 *
 *   var localeNames:Array = [LocaleID.DEFAULT, "ja-JP", "en-US", "fr-FR"];
 *
 *   for each (var localeName:String in localeNames)
 * {
 * cf = new CurrencyFormatter(localeName);
 *
 *   trace('\n' + "LocaleID requested=" + cf.requestedLocaleIDName
 * + "; actual=" + cf.actualLocaleIDName);
 *
 *   trace("Last Operation Status: " + cf.lastOperationStatus );
 *
 *   trace("Currency ISO Code: " + cf.currencyISOCode);
 *
 *   if (cf.formattingWithCurrencySymbolIsSafe("EUR"))
 * {
 * amountWithSymbol = cf.format(123456789.19, true);
 * trace("Format using Symbol: "+ amountWithSymbol);
 * }
 * else
 * {
 * amountWithISOCode = cf.format(123456789.19);
 * trace("Format using ISO Code: " + amountWithISOCode);
 * }
 * }
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example parses a currency amount using the rules for a given locale.
 * The results from this example may differ based on your operating system and user preferences.
 * <p class="- topic/p ">This example takes the following steps:</p><ol class="- topic/ol "><li class="- topic/li ">Creates a CurrencyFormatter object for the English (US) locale.</li><li class="- topic/li ">Uses the <codeph class="+ topic/ph pr-d/codeph ">parse()</codeph> method to parse the input string.</li><li class="- topic/li ">Displays the amount and currency string values from the resulting CurrencyParseResult object.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.globalization.CurrencyFormatter;
 * import flash.globalization.CurrencyParseResult;
 * import flash.globalization.LastOperationStatus;
 * import flash.globalization.LocaleID;
 *
 *   public class CurrencyFormatterParseExample extends Sprite
 * {
 * public function CurrencyFormatterParseExample()
 * {
 * var cf:CurrencyFormatter = new CurrencyFormatter( "en_US" );
 *
 *   trace("LocaleID requested=" + cf.requestedLocaleIDName
 * + "; actual=" + cf.actualLocaleIDName);
 * trace("Last Operation Status: " + cf.lastOperationStatus );
 *
 *   var inputString:String = "Dollar 123,567,89,0.254";
 *
 *   var result:CurrencyParseResult = cf.parse(inputString);
 *
 *   if (cf.lastOperationStatus == LastOperationStatus.NO_ERROR ) {
 * trace("Amount value: " + result.value);
 * trace("Currency string: " + result.currencyString);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

using namespace flash::globalization;

namespace flash
{
    namespace globalization
    {
        class CurrencyFormatter : public Object
        {
            /**
             * The three letter ISO 4217 currency code for the actual locale being used.
             *
             *   This code is used to determine the currency symbol or string when formatting currency amounts
             * using the format() method with the withCurrencySymbol parameter set to false.This property is initialized by the constructor based on the actual locale that is used. When a fallback
             * locale is used this property reflects the preferred, default currency code for the fallback locale.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  currencyISOCode();

            /**
             * The currency symbol or string for the actual locale being used.
             *
             *   This property is used as the currency symbol when formatting currency amounts
             * using the format() method with the withCurrencySymbol parameter set to true.This property is initialized by the constructor based on the actual locale that is used. When a fallback
             * locale is used this property reflects the preferred, default currency symbol for the fallback locale.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  currencySymbol();

            /**
             * The status of the most recent operation that this CurrencyFormatter object performed.
             * The lastOperationStatus property is set whenever the constructor or a method of
             * this class is called or another property is set. For the possible values see the description for each method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  lastOperationStatus();

            /**
             * The name of the requested locale ID that was passed to the constructor of this CurrencyFormatter object.
             *
             *   If the LocaleID.DEFAULT value was used then the name returned is "i-default".
             * The actual locale used can differ from the requested locale when a fallback locale is applied.
             * The name of the actual locale can be retrieved using the actualLocaleIDName property.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  requestedLocaleIDName();

            /**
             * The name of the actual locale ID used by this CurrencyFormatter object.
             *
             *   There are three possibilities for the value of the name, depending on operating system and the
             * value of the requestedLocaleIDName parameter passed to the CurrencyFormatter() constructor.If the requested locale was not LocaleID.DEFAULT and
             * the operating system provides support for the requested locale,
             * then the name returned is the same as the requestedLocaleIDName property.
             * If LocaleID.DEFAULT was used as the value for the requestedLocaleIDName
             * parameter to the constructor, then the name of the current locale specified by the user's operating system
             * is used. The LocaleID.DEFAULT value preserves user's customized setting in the OS.
             * Passing an explicit value as the requestedLocaleIDName parameter does not necessarily give the
             * same result as using the LocaleID.DEFAULT even if the two locale ID names are the same.
             * The user might have customized the locale settings on their machine, and by requesting an
             * explicit locale ID name rather than using LocaleID.DEFAULT your application would not
             * retrieve those customized settings.
             * For example:
             * <codeblock>
             *
             *   var fmt:CurrencyFormatter = new CurrencyFormatter(LocaleID.DEFAULT);
             * var aliName:String = fmt.actualLocaleIDName;
             *
             *   </codeblock>
             * In the above example, aliName is the name of the locale corresponding to
             * the user's current operating systems settings (for example, "it-IT" if the user's locale is set to Italian-Italy),
             * and not "i-default" (the name of the LocaleID.DEFAULT locale).If the system does not support the requestedLocaleIDName specified in the constructor
             * then a fallback locale ID name is provided.
             * For Example:
             * <codeblock>
             *
             *   var fmt:CurrencyFormatter = new CurrencyFormatter("fr-CA");
             * var aliName:String = fmt.actualLocaleIDName;
             *
             *   </codeblock>
             * Assuming that the operating system in the example above does not support the "fr-CA" (French-Canada) locale ID,
             * a fallback is used. In this case the fallback locale ID is "fr-FR" (French-France).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  actualLocaleIDName();

            /**
             * The maximum number of digits that can appear after the decimal separator.
             *
             *   Numbers are rounded to the number of digits specified by this property. The rounding scheme
             * varies depending on the user's operating system.When the trailingZeros property is set to true, the fractional portion of the
             * number (after the decimal point) is padded with trailing zeros until its length matches the value of this
             * fractionalDigits property.When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            int          fractionalDigits();
        public:
            void         fractionalDigits(int value);

            /**
             * Enables the use of the grouping separator when formatting currency amounts.
             *
             *   When the useGrouping property is set to true, digits are grouped and
             * delimited by the grouping separator character.
             * For example: $123,456,789When the useGrouping property is set to false, digits are not grouped or separated.
             * For example: $123456789The groupingSeparator property defines the symbol to be used as a grouping separator. The
             * groupingPattern property defines the number of digits between grouping separators.When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         useGrouping();
        public:
            void         useGrouping(bool value);

            /**
             * Describes the placement of grouping separators within the formatted currency amount string.
             *
             *   When the useGrouping property is set to true, the groupingPattern property is used
             * to define the placement and pattern used for the grouping separator.The grouping pattern is defined as a string containing numbers separated by semicolons and optionally may end
             * with an asterisk. For example: "3;2;*". Each number in the string represents the number of digits
             * in a group. The grouping separator is placed before each group of digits. An asterisk at the end of the string
             * indicates that groups with that number of digits should be repeated for the rest of the formatted string.
             * If there is no asterisk then there are no additional groups or separators for the rest of the formatted string. The first number in the string corresponds to the first group of digits to the left of the decimal separator.
             * Subsequent numbers define the number of digits in subsequent groups to the left. Thus the string "3;2;*"
             * indicates that a grouping separator is placed after the first group of 3 digits, followed by groups of 2 digits.
             * For example: 98,76,54,321The following table shows examples of formatting the currency amount 123456789.12 with various grouping patterns.
             * The grouping separator is a comma, the decimal separator is a period, and a dollar sign ($) is the currency symbol.
             * Grouping PatternSample Format3;* $123,456,789.123;2;*$12,34,56,789.123$123456,789.12Only a limited number of grouping sizes can be defined. On some operating systems, grouping patterns can only contain
             * two numbers plus an asterisk. Other operating systems can support up to four numbers and an asterisk.
             * For patterns without an asterisk, some operating systems only support one number while others support up to three numbers.
             * If the maximum number of grouping pattern elements is exceeded, then additional elements
             * are ignored, and the lastOperationStatus property is set as described below.
             * When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            std::string  groupingPattern();
        public:
            void         groupingPattern(std::string value);

            /**
             * Defines the set of digit characters used when formatting currency amounts.
             *
             *   Different languages and regions use different sets of characters to represent the
             * digits 0 through 9.  This property defines the set of digits to be used.The value of this property represents the Unicode value for the zero digit of a decimal digit set.
             * The valid values for this property are defined in the NationalDigitsType class.When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            unsigned int digitsType();
        public:
            void         digitsType(unsigned int value);

            /**
             * The decimal separator character used for formatting or parsing currency amounts that have a decimal part.
             *
             *   This property is initially set based on the locale that is selected when the formatter object
             * is constructed.When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            std::string  decimalSeparator();
        public:
            void         decimalSeparator(std::string value);

            /**
             * The character or string used for the grouping separator.
             *
             *   The value of this property is used as the grouping separator when formatting currency amounts when the
             * useGrouping property is set to true. This
             * property is initially set based on the locale that is selected when the formatter object
             * is constructed.When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            std::string  groupingSeparator();
        public:
            void         groupingSeparator(std::string value);

            /**
             * The negative symbol used when formatting negative currency amounts.
             *
             *   This symbol is used with the negative currency
             * format when formatting a currency amount that is less than zero. It is not used in negative currency formats that do not include
             * a negative sign (for example, when negative currency amounts are enclosed in parentheses). When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            std::string  negativeSymbol();
        public:
            void         negativeSymbol(std::string value);

            /**
             * A numeric value that indicates a formatting pattern for negative currency amounts.
             * This pattern defines the location of the currency symbol and the negative symbol
             * or parentheses in relation to the numeric portion of the currency amount.
             *
             *   The value of this property must be one of the constants defined in the table below.
             * The table below summarizes the possible formatting patterns for negative currency amounts.
             * When a currency amount is formatted with the format() method:The '  ' symbol is replaced with the value of the currencyISOCode or
             * the currencySymbol property, depending on the value of the withCurrencySymbol parameter
             * passed to the format() method;The '-' character is replaced with the value of the negativeNumberSymbol property;The 'n' character is replaced with the currency amount value that is passed to the format() method.Negative currency format typeFormatting pattern0(  n)1-  n2  -n3  n-4(n  )5-n  6n-  7n  -8-n   9-   n10n   -11   n-12   -n13n-   14(   n)15(n   )When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError if the assigned value is not between 0 and 15.
             */
        public:
            unsigned int negativeCurrencyFormat();
        public:
            void         negativeCurrencyFormat(unsigned int value);

            /**
             * A numeric value that indicates a formatting pattern for positive currency amounts.
             * This format defines the location of currency symbol
             * relative to the numeric portion of the currency amount.
             *
             *   The value of this property must be one of the constants defined in the table below.
             * The table below summarizes the possible formatting patterns for positive currency amounts.
             * When a currency amount is formatted with the format() method:The '  ' symbol is replaced with the value of the currencyISOCode or
             * the currencySymbol property, depending on the value of the withCurrencySymbol parameter
             * passed to the format() method;The 'n' character is replaced with the currency amount value that is passed to the format() method.Positive currency format typeFormatting pattern0  n1n  2   n3n   When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError if the assigned value is not between 0 and 3.
             */
        public:
            unsigned int positiveCurrencyFormat();
        public:
            void         positiveCurrencyFormat(unsigned int value);

            /**
             * Specifies whether a leading zero is included in a formatted currency amount when there are no integer digits
             * to the left of the decimal separator.
             *
             *   When this property is set to true a leading zero is included to the left of the decimal separator
             * when formatting numeric values between -1.0 and 1.0.
             * When this property is set to false a leading zero is not included.For example if the currency amount is 0.321 and this property is set true, then the leading
             * zero is included in the formatted string. If the property is set to false, the leading zero
             * is not included. In that case the string would just include the decimal separator followed by the decimal digits,
             * like $.321. The following table shows examples of how currency amounts are formatted based on the values of this property and
             * the related fractionalDigits and trailingZeros properties.
             * trailingZerosleadingZerofractionalDigits0.120truetrue3$0.120$0.000falsetrue3$0.12$0truefalse3$.120$.000falsefalse3$.12$0When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            bool         leadingZero();
        public:
            void         leadingZero(bool value);

            /**
             * Specifies whether trailing zeros are included in the formatted currency amount.
             *
             *   When this property is set to true, trailing zeros are included in the fractional part
             * of the formatted number up the limit specified by the fractionalDigits property.
             * When this property is set to false then no trailing zeros are shown.For example if the currency amount is 123.4, and this property is set true, and the fractionalDigits property
             * is set to 3, the formatted string would show trailing zeros, like $123.400 .
             * If this property is false, trailing zeros are not included, and the string shows just the decimal
             * separator followed by the non-zero decimal digits, like $123.4 .The following table shows examples of how currency amounts are formatted based on the values of this property and
             * the related fractionalDigits and leadingZero properties.
             * trailingZerosleadingZerofractionalDigits0.120truetrue3$0.120$0.000falsetrue3$0.12$0truefalse3$.120$.000falsefalse3$.12$0When this property is assigned a value and there are no errors or warnings, the lastOperationStatus property
             * is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if this property is assigned a null value.
             */
        public:
            bool         trailingZeros();
        public:
            void         trailingZeros(bool value);

            /**
             * Constructs a new CurrencyFormatter object to format numbers representing currency amounts according to
             * the conventions of a given locale.
             *
             *   This constructor determines if the current operating system supports the requested locale ID name.
             * If it is not supported then a fallback locale is used instead.
             * If a fallback locale is used then the lastOperationStatus property
             * indicates the type of fallback, and the actualLocaleIDName property contains
             * the name of the fallback locale ID. Certain properties such as the currencySymbol and currencyISOCode properties are set
             * automatically based on the locale.NOTE: When a fallback locale is used the currency properties are set to default values,
             * and therefore the currencySymbol or
             * currencyISOCode properties might be given unexpected values. It is a good idea to examine the
             * currencySymbol and currencyISOCode property values before formatting a currency amount.
             * To format based on the user's current operating system preferences, pass the value LocaleID.DEFAULT
             * in the requestedLocaleIDName parameter to the constructor.
             * When the constructor is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORWhen the requested locale ID name is not available then the lastOperationStatus
             * is set to one of the following:LastOperationStatus.USING_FALLBACK_WARNINGLastOperationStatus.USING_DEFAULT_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in
             * the LastOperationStatus class.For details on the warnings listed above and other possible values of the
             * lastOperationStatus property, see the descriptions in the LastOperationStatus class.
             * @param   requestedLocaleIDName   The preferred locale ID name to use when determining date or time formats.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the requestedLocaleIDName parameter is null.
             */
        public:
            CurrencyFormatter(std::string requestedLocaleIDName);

            /**
             * Lists all of the locale ID names supported by this class.
             *
             *   If this class is not supported on the current operating system, this method returns a null value.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @return  A vector of strings containing all of the locale ID names supported by this class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static std::vector<std::string> getAvailableLocaleIDNames();

            /**
             * Sets the currencyISOCode and currencySymbol properties of the CurrencyFormatter object.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the the currencyISOCode and the currencySymbol properties are not modified and the
             * lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   currencyISOCode The three letter ISO 4217 currency code (for example, USD for US dollars, EUR for Euros).
             *   Must contain three uppercase letters from A to Z.
             * @param   currencySymbol  The currency symbol or string to be used when formatting currency values. This can be an empty string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the currencyISOCode or currencySymbol parameter is null.
             */
        public:
            void     setCurrency(std::string currencyISOCode, std::string currencySymbol);

            /**
             * Creates a string representing a currency amount formatted according to the current properties of this CurrencyFormatter object,
             * including the locale, currency symbol, and currency ISO code.
             *
             *   By default this method uses the currencyISOCode property to determine the currency symbol and other
             * settings used when formatting.Many countries and regions use the same currency symbols for different currencies.
             * For example the United States, Australia, New Zealand, Canada,
             * and Mexico all use the same dollar sign symbol ($) for local currency values. When the formatting currency differs
             * from the user's local currency it is best to use the ISO code as the currency string.
             * You can use the formattingWithCurrencySymbolIsSafe() method to test whether the ISO code of the
             * currency to be formatted matches the currencyISOCode property of the formatter.
             * This method can format numbers of very large and very small magnitudes. However the
             * number of significant digits is limited to the precision provided by the Number data type.
             * @param   value   The numeric value to be formatted into a currency string.
             * @param   withCurrencySymbol  When set to false the currencyISOCode property determines which
             *   currency string or symbol to use in the output string. When set to true, the current value of the
             *   currencySymbol property is used in the output string.
             * @return  A string containing the formatted currency value.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string format(float value, bool withCurrencySymbol   =false);

            /**
             * Determines whether the currently specified currency symbol can be used when formatting currency amounts.
             *
             *   Many regions and countries use the same currency symbols. This method can be used to
             * safeguard against the use of an ambiguous currency symbol, or a currency symbol or ISO code that
             * is different than expected due to the use of a fallback locale.A common use case for this method is to determine whether to show a local currency symbol (if the amount is formatted in
             * the user's default currency), or a more specific ISO code string (if the amount is formatted in a currency
             * different from the user's default).This method compares the requestedISOCode parameter against the current currencyISOCode property,
             * returning true if the strings are equal and false if they are not.
             * When the strings are equal, using the format() method with the
             * withCurrencySymbol parameter set to true results in a formatted currency value string
             * with a unique currency symbol for the locale.
             * If this method returns false, then using the format() method with the withCurrencySymbol
             * parameter set to true could result in the use of an ambiguous or incorrect currency symbol.
             * When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   requestedISOCode    A three letter ISO 4217 currency code (for example, USD for US dollars, EUR for Euros).
             *   Must contain three uppercase letters from A to Z.
             * @return  true if the currencyISOCode property matches the requestedISOCode parameter;
             *   otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the requestedISOCode parameter is null.
             */
        public:
            bool     formattingWithCurrencySymbolIsSafe(std::string requestedISOCode);

            /**
             * Parses a string into a currency amount and a currency symbol.
             *
             *   The parsing algorithm uses the value of the decimalSeparator property to determine the integral and fractional
             * portion of the number. It uses the values of the negativeCurrencyFormat and positiveCurrencyFormat
             * properties to determine the location of the currency symbol or string relative to the currency amount.
             * For negative amounts the value of the negativeCurrencyFormat property determines the location of the
             * negative symbol and whether parentheses are used.If the order of the currency symbol, minus sign, and number in the input string does not match the pattern identified by the
             * negativeCurrencyFormat and positiveCurrencyFormat properties, then:The value property of the returned CurrencyParseResult object is set to NaN.The currencyString property of the returned CurrencyParseResult object is set to null.The lastOperationStatus property is set to indicate that parsing failed.The input string may include space characters, which are ignored during the parsing.Parsing can succeed even if there is no currency symbol. No validation is done of the portion of the string
             * corresponding to the currency symbol. If there is no currency symbol or string, the currencyString property in the
             * returned CurrencyParseResult object is set to an empty string.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   inputString The input string to parse.
             * @return  A CurrencyParseResult object containing the numeric value and the currency symbol or string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the inputString parameter is null.
             */
        public:
            flash::globalization::CurrencyParseResult *parse(std::string inputString);
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_CURRENCYFORMATTER_AS
#endif // __cplusplus

