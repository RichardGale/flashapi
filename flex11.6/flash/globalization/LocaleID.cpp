

    /**
     * The LocaleID class provides methods for parsing and using locale ID names. This class supports locale ID names
     * that use the syntax defined by the Unicode Technical Standard #35 
     * (<xref href="http://unicode.org/reports/tr35/" class="- topic/xref ">http://unicode.org/reports/tr35/</xref>).
     * 
     *   EXAMPLE:
     * 
     *   The following example shows how to retrieve and display information about LocaleID strings 
     * for different locales.
     * <p class="- topic/p ">
     * This example uses the following locales: Arabic (Saudi Arabia), English (US), English (US, POSIX variant), Chinese (PRC), 
     * Chinese (Taiwan),  Chinese (Simplified Han Script), Chinese (PRC with several keys and values)
     * </p><p class="- topic/p ">
     * The example does the following for each locale in the list:
     * </p><ol class="- topic/ol "><li class="- topic/li ">Creates a new LocaleID object.</li><li class="- topic/li ">Displays various properties of the LocaleID. The values shown will differ based on your operating system and user preferences.</li><li class="- topic/li ">Displays the full set of keys and values for the LocaleID.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * package 
     * {
     * import flash.display.Sprite;
     * import flash.globalization.LocaleID;
     * 
     *   public class LocaleIDExample extends Sprite
     * {
     * public function LocaleIDExample()
     * {
     * var localeNames:Array = ["ar-SA", "EN_us", "en-US-POSIX", "zh-CH", "zh-TW", "zh-Hans", "zh-CH@collation=pinyin;calendar=chinese;currency=RMB"];
     *   
     *     for ( var i:int = 0; i &lt; localeNames.length; i++ ) 
     *   {
     *   var locID:LocaleID = new LocaleID( localeNames[i] as String );
     *   
     *     trace('\n\n' + "LocaleID requested: " + locID.requestedLocaleIDName 
     *   + "; actual: " + locID.actualLocaleIDName);
     *   trace( "Last Operation Status after new LocaleID: " + locID.lastOperationStatus);
     *   
     *     trace("name:     " + locID.name);
     *   trace("language: " + locID.getLanguage() + "; status: "  + locID.lastOperationStatus);
     *   trace("script:   " + locID.getScript()  +  "; status: "  + locID.lastOperationStatus);
     *   trace("region:   " + locID.getRegion()  +  "; status: "  + locID.lastOperationStatus);
     *   trace("variant:  " + locID.getVariant()  + "; status: "  + locID.lastOperationStatus);
     *   trace("isRightToLeft: ", locID.isRightToLeft(), "; status: "  + locID.lastOperationStatus);
     *   
     *     var keysAndValues:Object = locID.getKeysAndValues();
     *   var key:String;
     *   for (key in keysAndValues)
     *   {
     *   trace("key: ", key + " value: " + keysAndValues[ key ]);
     *   }
     *   trace( "Last Operation Status after getKeysAndValues(): " + locID.lastOperationStatus);
     *   }
     *   }
     *   }
     *   }
     *   </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 10.1
     * @playerversion   AIR 2
     */


namespace flash {
namespace globalization {


        /**
         * Indicates that the user's default linguistic preferences should be used, as specified in the user's operating system settings.
         * For example, such preferences are typically set using the "Control Panel" for Windows, or the "System Preferences" in Mac OS X.
         * 
         *   Using the LocaleID.DEFAULT setting can result in the use of a different locale ID name for different 
         * kinds of operations. For example, one locale could be used for sorting and a different one for formatting.
         * This flexibility respects the user preferences, and the class behaves this way by design.This locale identifier is not always the most appropriate one to use.
         * For applications running in the browser, the browser's preferred locale could be a better choice.
         * It is often a good idea to let the user alter the preferred locale ID name setting and preserve that preference
         * in a user profile, cookie, or shared object.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        const std::string LocaleID::DEFAULT   = "i-default";

        /**
         * Returns a slightly more "canonical" locale identifier.
         * 
         *   This method performs the following conversion to the locale ID name to give it a more canonical form.Proper casing is applied to all of the components.Underscores are converted to dashes.No additional processing is performed. For example, aliases are not replaced, and no elements are added or removed.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::name()         ;

        /**
         * The status of the most recent operation that this LocaleID object performed. 
         * The lastOperationStatus property is set whenever the constructor or a method of 
         * this class is called or another property is set. For the possible values see the description for each method.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::lastOperationStatus()         ;

        /**
         * Returns a list of acceptable locales based on a list of desired locales and a list of the locales that are currently available.
         * 
         *   The resulting list is sorted according in order of preference.Here is a typical use case for this method:A user specifies a list of languages that she understands
         * (stored in a user profile, a browser setting, or a cookie). 
         * The user lists the languages that she understands best first, so the order of the languages in the list is relevant.
         * This list is the "want" list.The application is localized into a number of different languages.
         * This list is the "have" list.The determinePreferredLocales() method returns an intersection of the two lists, sorted so that the 
         * user's preferred languages come first.If this feature is not supported on the current operating system, this method returns a null value.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @param   want    A list of the user's preferred locales sorted in order of preference.
         * @param   have    A list of locales available to the application. The order of this list is not important.
         * @param   keyword A keyword to use to help determine the best fit.
         * @return  A subset of the available locales, sorted according to the user's preferences.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::vector<std::string> LocaleID::determinePreferredLocales(std::vector<std::string> want, std::vector<std::string> have, std::string keyword)                  ;

        /**
         * Returns the language code specified by the locale ID name.
         * 
         *   If the locale name cannot be properly parsed then the language code is the same as the full locale name.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  A two-character language code obtained by parsing the locale ID name.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::getLanguage()         ;

        /**
         * Returns the region code specified by the locale ID name.
         * 
         *   This method returns an empty string if the region code cannot be parsed or guessed
         * This could occur if an unknown or incomplete locale ID name like "xy" is used.
         * The region code is not validated against a fixed list. For example, the region code returned for a locale ID name of 
         * "xx-YY" is "YY".When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORIf the region is not part of the specified locale name, the most likely region code for the locale is "guessed" and
         * lastOperationStatus property is set to LastOperationStatus.USING_FALLBACK_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  A two-character region code, or an empty string if the region code cannot be parsed or otherwise 
         *   determined from the locale name.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::getRegion()         ;

        /**
         * Returns the script code specified by the locale ID name.
         * 
         *   This method returns an empty string if the script code cannot be parsed or guessed
         * This could occur if an unknown or incomplete locale ID name like "xy" is used.
         * The script code is not validated against a fixed list. For example, the script code returned for a locale ID name of 
         * "xx-Abcd-YY" is "Abcd".The region, as well as the language, can also affect the return value. For example, the script code for "mn-MN"
         * (Mongolian-Mongolia) is "Cyrl" (Cyrillic), while the script code for "mn-CN" (Mongolian-China) is
         * "Mong" (Mongolian).When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORIf the script code is not part of the specified locale name, the most likely script code is "guessed" and
         * lastOperationStatus property is set to LastOperationStatus.USING_FALLBACK_WARNING.Otherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  A four-character script code, or an empty string if the script code cannot be parsed or otherwise 
         *   determined from the locale name.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::getScript()         ;

        /**
         * Returns the language variant code specified by the locale ID name.
         * 
         *   This method returns an empty string if there is no language variant code in the given locale ID name.
         * (No guessing is necessary because few locales have or need a language variant.)When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  A language variant code, or an empty string if the locale ID name does not contain a language variant code.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        std::string LocaleID::getVariant()         ;

        /**
         * Constructs a new LocaleID object, given a locale name. The locale name
         * must conform to the syntax defined by the Unicode Technical Standard #35 
         * (http://unicode.org/reports/tr35/).
         * 
         *   When the constructor completes successfully the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORWhen the requested locale ID name is not available then the lastOperationStatus 
         * is set to one of the following:LastOperationStatus.USING_FALLBACK_WARNINGLastOperationStatus.USING_DEFAULT_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in 
         * the LastOperationStatus class.For details on the warnings listed above and other possible values of the lastOperationStatus property
         * see the descriptions in the LastOperationStatus class.
         * @param   name    A locale ID name, which can also include an optional collation string. 
         *   For example: "en-US" or "de-DE@collation=phonebook"
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         * @throws  ArgumentError if the name is null.
         */
        LocaleID::LocaleID(std::string name);

        /**
         * Returns an object containing all of the key and value pairs from the LocaleID object.
         * 
         *   The returned object is structured as a hash table or associative array, where each property name represents a key
         * and the value of the property is value for that key. For example, the following code lists all of the keys and values    
         * obtained from the LocaleID object using the getKeysAndValues() method:
         * <codeblock>
         * 
         *   var myLocale:LocaleID = new LocaleID("fr-CA");
         * var localeData:Object = myLocale.getKeysAndValues();
         * for (var propertyName:String in localeData)
         * {
         * trace(propertyName + " = " + localeData[propertyName]);
         * }
         * 
         *   </codeblock>
         * When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  An Object containing all the keys and values in the LocaleID object, structured as an associative array or hashtable.
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        Object* LocaleID::getKeysAndValues()         ;

        /**
         * Specifies whtehr the text direction for the specified locale is right to left.
         * 
         *   The result can be used to determine the direction of the text in the Flash text engine,
         * and to decide whether to mirror the user interface to support the current text direction.When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
         * LastOperationStatus class.
         * @return  true if the general text flows in a line of text should go from right to left; otherwise false;
         * @langversion 3.0
         * @playerversion   Flash 10.1
         * @playerversion   AIR 2
         */
        bool LocaleID::isRightToLeft()          ;
}
}

