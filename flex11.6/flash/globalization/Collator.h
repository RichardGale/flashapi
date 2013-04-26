#if !defined(FLEX11_6_FLASH_GLOBALIZATION_COLLATOR_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_COLLATOR_AS
#if defined(__cplusplus)


/**
 * The Collator class provides locale-sensitive string comparison capabilities.
 *
 *   <p class="- topic/p ">This class uses the string comparison services provided by the operating system.
 * The comparisons differ according to the locale identifier that is provided when the class instance is created.
 * ActionScript stores strings using the Unicode character set.  The Boolean string comparison
 * operators (==, !=, &lt;, &lt;=, &gt;, &gt;=) use Unicode code points for comparison. In most cases the resulting
 * sort order doesn't match the conventions of a particular language and region, and thus
 * should not be used to sort strings that are presented in a user interface.  In contrast the comparison methods in this class
 * provide an order that adheres to these conventions.
 * </p><p class="- topic/p ">Here are some examples where the sort order differs depending on the language:
 * </p><ul class="- topic/ul "><li class="- topic/li "> In English, lowercase a is before uppercase A and uppercase A is before lowercase b.</li><li class="- topic/li ">    is after z in Swedish, whereas in German    is after o</li><li class="- topic/li "> ch is sorted as one character between c-d in traditional Spanish</li><li class="- topic/li "> accented characters in French are sorted according to the last accent difference instead of the first accent
 * difference: for example, cote &lt; c  te &lt; cot   &lt; c  t   instead of cote &lt;  cot   &lt; c  te &lt; c  t  </li></ul><p class="- topic/p ">
 * Sort orders can even differ within the same language and region depending on the usage. For example, in German there
 * is a different sort order used for names in a phone book versus words in a dictionary. In Chinese and Japanese
 * there are different ways of sorting the ideographic characters: by pronunciation or by the ideographic radical and the
 * number of strokes uses in the glyph. In Spanish and Georgian, there is a difference between modern and traditional sorting.
 * </p><p class="- topic/p ">
 * The comparison methods in this class provide two main usage modes. The <codeph class="+ topic/ph pr-d/codeph ">initialMode</codeph>
 * parameter of the <codeph class="+ topic/ph pr-d/codeph ">Collator()</codeph> constructor controls these modes. The default "sorting" mode is for sorting items that are displayed to an end user.
 * In this mode, comparison is more strict to ensure that items that are otherwise the same are sorted in a
 * consistent manner.  For example, uppercase letters and lowercase letters do not compare as equal.
 * In the "matching" mode the comparison is more lenient. For example in this mode uppercase and
 * lowercase letters are treated equally.  Here's an example that demonstrates both of these modes:
 * </p><codeblock rev="3.0" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var sortingCollator:Collator = new Collator("en-US", CollatorMode.SORTING);
 * var words:Array = new  Array("Airplane" , "airplane", "boat", "Boat");
 * words.sort(sortingCollator.compare);
 * trace(words);
 *
 *   var matchingCollator:Collator = new Collator("en-US", CollatorMode.MATCHING);
 * if (matchingCollator.equals("Car", "car")) {
 * trace("The words match!");
 * }
 * </codeblock><p class="- topic/p ">
 * Even when providing a locale ID parameter to the constructor as shown above, collation behavior can differ by user
 * based on the user's operating system settings and whether a fallback locale is used when the
 * requested locale is not supported.
 * </p>
 *
 *   EXAMPLE:
 *
 *   The following example shows sorting results that differ based on the locale.
 *
 *   The example takes the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Iterates through an array of locale ID names, including the default locale ID for the operating system
 * (as specified by <codeph class="+ topic/ph pr-d/codeph ">LocaleID.DEFAULT</codeph>)</li><li class="- topic/li ">Creates a Collator object for each locale ID name using "sorting" mode (the default). </li><li class="- topic/li ">Displays the requested and actual locale ID names and the value of the <codeph class="+ topic/ph pr-d/codeph ">lastOperationStatus</codeph> property
 * so you can see if a fallback locale was used.</li><li class="- topic/li ">Sorts a data array using each collator and displays the results. The resulting order is different for each locale.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.globalization.Collator;
 * import flash.globalization.LocaleID;
 *
 *   public class CollatorExample1
 * {
 * public var col:Collator;
 *
 *   public function CollatorExample1():void
 * {
 * var localeNames:Array = [LocaleID.DEFAULT,
 * "de-DE", "sv-SE",
 * "fr-FR", "lt-LT",
 * "es-ES"];
 *
 *   var testSortData:Array = [
 * "y ", "i ", "k ", // Latvian
 * "acxa ", "acha ", "adxa ", // es_traditional
 * "n ", "   ", "o ", "z ", "vu ", "wo ", // sw
 * "d  d ", "daed ", // de
 * "  f ", "of ", // de_dictionary
 * "c  te ", "cot   " // fr
 * ];
 *
 *   for each (var localeName:String in localeNames) {
 *
 *   col = new Collator(localeName);
 *
 *   trace("LocaleID requested: " + col.requestedLocaleIDName
 * + "; actual: " + col.actualLocaleIDName);
 *
 *   trace("Last Operation Status: " + col.lastOperationStatus );
 *
 *   var result:Array = testSortData.sort(col.compare);
 *
 *   trace ("sorted data: " + result);
 * }
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following examples shows uses a Collator object to control the behavior of string comparisons.
 *
 *   The example takes the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">Creates a Collator object for the user's default locale using "matching" mode. </li><li class="- topic/li ">Alternately sets the <codeph class="+ topic/ph pr-d/codeph ">Collator.ignoreDiacritics</codeph> property to <codeph class="+ topic/ph pr-d/codeph ">false</codeph> and <codeph class="+ topic/ph pr-d/codeph ">true</codeph></li><li class="- topic/li ">Compares sets of strings that contain diacritics and upper case and lower case characters. </li><li class="- topic/li ">Shows how the comparisons change when the
 * <codeph class="+ topic/ph pr-d/codeph ">Collator.ignoreDiacritics</codeph> and <codeph class="+ topic/ph pr-d/codeph ">Collator.ignoreCase</codeph> properties change.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.globalization.Collator;
 * import flash.globalization.CollatorMode;
 * import flash.globalization.LocaleID;
 *
 *   public class CollatorExample2 extends Sprite
 * {
 * public var col:Collator;
 * public var testMatchData:Array = ["cote", "Cote", "c    te", "cot    "];
 * public var wordToMatch:String = "Cote";
 *
 *   public function CollatorExample2()
 * {
 * col = new Collator( LocaleID.DEFAULT, CollatorMode.MATCHING );
 *
 *   trace("LocaleID requested: " + col.requestedLocaleIDName
 * + "; actual: " + col.actualLocaleIDName);
 *
 *   trace("Last Operation Status: " + col.lastOperationStatus );
 *
 *   trace('\n' + "ignoreCase = " + col.ignoreCase);
 * trace("ignoreDiacritics = " + col.ignoreDiacritics);
 *
 *   compareString(testMatchData, wordToMatch) // All variations of the word cote match
 *
 *   col.ignoreDiacritics = false;
 * trace('\n' + "ignoreDiacritics = false");
 *
 *   compareString(testMatchData, wordToMatch) // Variations with different diacritics will not match
 *
 *   col.ignoreCase = false;
 * trace('\n' + "ignoreCase = false");
 *
 *   compareString(testMatchData, wordToMatch) // Variations with different case will not match
 * }
 *
 *   private function compareString(stringArray:Array, keyword:String):void
 * {
 * for each(var s:String in stringArray)
 * {
 * if(col.equals(s, keyword))
 * {
 * trace(keyword + " = " + s);
 * }
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

namespace flash
{
    namespace globalization
    {
        class Collator: public Object
        {
            /**
             * When this property is set to true, identical strings and strings that differ only in the case of the letters
             * are evaluated as equal.
             * For example, compare("ABC", "abc") returns true when the
             * ignoreCase property is set to true.
             *
             *   The case conversion of the string follows the rules for the specified locale.
             *
             *   When the ignoreCase property is false then upper- and lowercase characters are not equal to one another.
             *
             *   When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROR
             * Otherwise, the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ignoreCase();
        public:
            void         ignoreCase(bool value);

            /**
             * When this property is set to true, strings that use the same base characters but
             * different accents or other diacritic marks are evaluated as equal.
             * For example compare("cot  ", "c  te") returns true when the
             * ignoreDiacritics property is set to true.
             *
             *   When the ignoreDiacritics is set to false then base characters with
             * diacritic marks or accents are not considered equal to one another.When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ignoreDiacritics();
        public:
            void         ignoreDiacritics(bool value);

            /**
             * When this property is set to true, strings that differ only by the type of kana character being used are
             * treated as equal.
             * For example, compare("      ", "      ")  returns true when the
             * ignoreKanaType property is set to true.
             *
             *   If the ignoreKanaType is set to false then hiragana and katakana characters that refer to the same
             * syllable are not equal to one another.
             * When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ignoreKanaType();
        public:
            void         ignoreKanaType(bool value);

            /**
             * When this property is set to is true, symbol characters such as spaces, currency symbols, math symbols,
             * and other types of symbols are ignored when sorting or matching.
             * For example the strings "OBrian", "O'Brian", and "O Brian" would all be treated as equal when the
             * ignoreSymbols property is set to true.
             *
             *   If the ignoreSymbols property is false then symbol characters are considered in string comparisons.
             * When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROR
             * Otherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ignoreSymbols();
        public:
            void         ignoreSymbols(bool value);

            /**
             * When this property is true, full-width and half-width forms of some Chinese and Japanese characters are evaluated as equal.
             *
             *   For compatibility with existing standards for Chinese and Japanese character sets, Unicode provides character codes
             * for both full-width and half width-forms of some characters.
             * For example, when the ignoreCharacterWidth property is set to true,
             * compare("      ", "A   ") returns true.
             * If the ignoreCharacterWidth property is set to false, then full-width and half-width forms
             * are not equal to one another.
             * When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROR
             * Otherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         ignoreCharacterWidth();
        public:
            void         ignoreCharacterWidth(bool value);

            /**
             * Controls how numeric values embedded in strings are handled during string comparison.
             *
             *   When the numericComparison property is set to true, the compare method
             * converts numbers that appear in strings to numerical values for comparison.When this property is set to false, the comparison treats numbers as character codes and
             * sort them according to the rules for sorting characters in the specified locale.For example, when this property is true for the locale ID "en-US", then the strings
             * "version1", "version10", and "version2"
             * are sorted into the following order: version1 < version2 < version10.When this property is false for "en-US", those same strings
             * are sorted into the following order: version1 < version10 < version2.When this property is assigned a value and there are no errors or warnings,
             * the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROR
             * Otherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            bool         numericComparison();
        public:
            void         numericComparison(bool value);

            /**
             * The status of the most recent operation that this Collator object performed.
             * The lastOperationStatus is set whenever the constructor or a method of
             * this class is called, or when a property is set. For the possible values see the description under each method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  lastOperationStatus();

            /**
             * The name of the actual locale ID used by this Collator object.
             *
             *   There are three possibilities for the value of the name, depending on operating system and the
             * value of the requestedLocaleIDName parameter passed to the Collator() constructor.If the requested locale was not LocaleID.DEFAULT and
             * the operating system provides support for the requested locale,
             * then the name returned is the same as the requestedLocaleIDName property.
             * If LocaleID.DEFAULT was used as the value for the requestedLocaleIDName
             * parameter to the constructor, then the name of the current locale specified by the user's operating system
             * is used. The LocaleID.DEFAULT value preserves user's customized setting in the OS. Passing
             * an explicit value as the requestedLocaleIDName parameter does not necessarily give the
             * same result as using the LocaleID.DEFAULT even if the two locale ID names are the same.
             * The user might have customized the locale settings on their machine, and by requesting an
             * explicit locale ID name rather than using LocaleID.DEFAULT your application would not
             * retrieve those customized settings.
             * For example:
             * <codeblock>
             *
             *   var fmt:Collator = new Collator(LocaleID.DEFAULT);
             * var aliName:String = fmt.actualLocaleIDName;
             *
             *   </codeblock>
             * In the above example, aliName is the name of the locale corresponding to
             * the user's current operating systems settings (e.g. "it-IT" if the user's locale is set to Italian-Italy),
             * and not "i-default" (the name of the LocaleID.DEFAULT locale).If the system does not support the requestedLocaleIDName specified in the constructor
             * then a fallback locale ID name is provided.
             * For Example:
             * <codeblock>
             *
             *   var fmt:Collator = new Collator("fr-CA");
             * var aliName:String = fmt.actualLocaleIDName;
             *
             *   </codeblock>
             * Assuming that the operating system in the example above does not support the "fr-CA" (French-Canada) locale ID,
             * a fallback is used. In that case the aliName variable contains the fallback locale ID
             * "fr-FR" (French-France).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  actualLocaleIDName();

            /**
             * The name of the requested locale ID that was passed to the constructor of this Collator object.
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
             * Constructs a new Collator object to provide string comparisons according to the conventions of a specified locale.
             *
             *   If the current operating system does not support the locale ID that is passed in the requestedLocaleIDName
             * parameter, then a fallback locale is determined.
             * If a fallback is used then the lastOperationStatus property is set to indicate the type of fallback.
             *
             *   The initialMode parameter sets various collation options for general uses.
             * It can be set to one of the following values:
             * CollatorMode.SORTING: sets collation options for general linguistic sorting usages such as
             * sorting a list of text strings that are displayed to an end user.
             * In this mode, differences in uppercase and lowercase letters, accented characters, and other differences
             * specific to the locale are considered when doing string comparisons.CollatorMode.MATCHING: sets collation options for general usages such as
             * determining if two strings are equivalent. In this mode, differences in uppercase and lower
             * case letters, accented characters, and so on are ignored when doing string comparisons.
             * Here is an example of a sorted list created using a Collator with the locale ID "en-US" (English in US)
             * and the CollatorMode.SORTING option:
             * Aa          AEae    Bb      Cc
             * As shown above, all characters are treated as if they have different values, but in linguistic order.
             *
             *   Here is an example of a sorted list created using Collator with the locale ID "en-US" (English in US) and the CollatorMode.MATCHING option:
             * A    a                  AE   ae        B b          C    c              Legend: Characters in a same row are treated as equivalent characters during comparison/sorting. For example, "a" (U+0040 = LATIN SMALL LETTER A) and "  " (U+00C4 = LATIN CAPITAL LETTER A WITH DIAERESIS) are considered to be equal.
             * As shown above, some characters are in linguistic order and are treated as if they have the same character value.
             *
             *   For finer control over sorting order, you can change collator properties such as
             * Collator.ignoreCase or Collator.ignoreDiacritics.
             *
             *   For reference, here is a corresponding sorting example done using the standard Array.sort(),
             * which is not locale-aware:
             * AAEBCaaebc
             * As you can see above, all characters are sorted simply in Unicode numeric value order.
             * It does not make much sense linguistically.
             *
             *   To use the user's current operating system preferences, pass the static value LocaleID.DEFAULT
             * in the requestedLocaleIDName parameter to the constructor.
             *
             *   Some locales have several sort order variants. For example, in German
             * one sort order is used for phone books and another sort order is used for dictionaries.
             * In Chinese, words are commonly supported by transliteration of the characters
             * into the pinyin.  These different sort orders can be selected by including the "collation" keyword
             * in the string that is passed in the requestedLocaleIDName parameter to the constructor.
             *
             *   <codeblock>
             *
             *   var germanPhonebook:LocaleID = new LocaleID("de-DE@collation=phonebook");
             *   var chinesePinyin:LocaleID = new LocaleID("zh-Hant@collation=pinyin");
             *
             *     </codeblock>
             *
             *     Possible values for the collation string are as follows, with the affected
             *   languages shown in parentheses:
             *   Collation stringDescriptionstandardThe default ordering for each language. phonebookFor a phonebook-style ordering (used in German).pinyinPinyin ordering for Latin and for CJK characters; that is, an ordering for
             *   CJK characters based on a character-by-character transliteration into a pinyin. (used in Chinese)traditionalFor a traditional-style sort (used in Spanish) strokePinyin ordering for Latin, stroke order for CJK characters (used in Chinese)direct(used in Hindi) big5hanPinyin ordering for Latin, big5 character set ordering for CJK characters. (used in Chinese) gb2312hanPinyin ordering for Latin, gb2312han character set ordering for CJK characters.
             *   (used in Chinese) unihanPinyin ordering for Latin, Unihan radical-stroke ordering for CJK characters. (used in Chinese)
             *   If the host platform does not support the requested collation type, then a fallback is used
             *   and the lastOperationStatus property is set to indicate that a fallback was selected.
             *   You can use the actualLocaleIDName property to determine the value that was used as a fallback,
             *   as shown in the following example:
             *
             *     <codeblock>
             *
             *     var collator:Collator = new Collator("fr-FR");
             *   if (collator.lastOperationStatus == LastOperationStatus.USING_FALLBACK_WARNING)
             *   {
             *   trace ("Using fallback locale: " + collator.actualLocaleIDName);
             *   }
             *
             *     </codeblock>
             *   When the constructor completes successfully, then
             *   the lastOperationStatus property is set to:  LastOperationStatus.NO_ERRORWhen the requested locale ID is not available, then the lastOperationStatus property is set to one of the following:LastOperationStatus.USING_FALLBACK_WARNINGLastOperationStatus.USING_DEFAULT_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in the LastOperationStatus class.For details on the  warnings listed above and other possible values of lastOperationStatus,  see
             *   the descriptions in the LastOperationStatus class.
             * @param   requestedLocaleIDName   String to be used by this Collator object.
             * @param   initialMode A string value to specify the initial collation mode. The default value is
             *   CollatorMode.SORTING. See the CollatorMode class
             *   for a list of available modes.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError when the requestedLocaleIDName parameter is null.
             * @throws  ArgumentError when the requestedLocaleIDName parameter contains an invalid value.
             */
        public:
            Collator(std::string requestedLocaleIDName, std::string initialMode);

            /**
             * Lists all of the locale ID names supported by this class.
             *
             *   If this class is not supported at all on the current operating system, this method returns a null value.
             * @return  A vector of strings containing all of the locale ID names supported by this class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            static std::vector<std::string> *getAvailableLocaleIDNames();

            /**
             * Compares two strings and returns an integer value indicating whether the first string is
             * less than, equal to, or greater than the second string. The comparison
             * uses the sort order rules for the locale ID that was specified in the Collator() constructor.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @param   string1 First comparison string.
             * @param   string2 Second comparison string.
             * @return  An integer value indicating whether the first string is
             *   less than, equal to, or greater than the second string.
             *   If the return value is negative, string1 is less than string2.If the return value is zero, string1 is equal to string2. If the return value is positive, string1 is larger than string2.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError when a required parameter is null.
             * @throws  ArgumentError when a parameter contains an invalid value.
             */
        public:
            int      compare(std::string string1, std::string string2);

            /**
             * Compares two strings and returns a Boolean value indicating whether the strings are equal.
             * The comparison uses the sort order rules for the locale ID that was specified in the Collator() constructor.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:  LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants
             * defined in the LastOperationStatus class.
             * @param   string1 First comparison string.
             * @param   string2 Second comparison string.
             * @return  A Boolean value indicating whether the strings are equal (true) or unequal (false).
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError when a required parameter is null.
             * @throws  ArgumentError when a parameter contains an invalid value.
             */
        public:
            bool     equals(std::string string1, std::string string2);
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_COLLATOR_AS
#endif // __cplusplus

