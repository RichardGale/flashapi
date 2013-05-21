#if !defined(FLEX11_6_FLASH_GLOBALIZATION_STRINGTOOLS_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_STRINGTOOLS_AS
#if defined(__cplusplus)


/**
 * The StringTools class provides locale-sensitive case conversion methods.
 *
 *   <p class="- topic/p ">In some situations the
 * conversion between uppercase and lowercase letters is not a simple mapping from one character
 * to another and instead requires language- or context-specific processing.  For example:</p><ul class="- topic/ul "><li class="- topic/li ">In Turkish and Azeri,
 * the uppercase of the dotted lowercase <b class="+ topic/ph hi-d/b ">i</b> is an uppercase dotted <b class="+ topic/ph hi-d/b ">  </b> (U+0130).
 * Similarly the lowercase of a
 * dotless uppercase <b class="+ topic/ph hi-d/b ">I</b>, is a lowercase dotless <b class="+ topic/ph hi-d/b ">  </b> (U+0131). </li><li class="- topic/li ">The lowercase sharp S, <b class="+ topic/ph hi-d/b ">  </b> (U+00DF), used in German
 * is converted to uppercase double SS.</li><li class="- topic/li ">In Greek there are two representations of the
 * lowercase sigma, <b class="+ topic/ph hi-d/b ">  </b> (U+03C3) and <b class="+ topic/ph hi-d/b ">  </b> (U+03C2), which both convert to the single
 * uppercase sigma <b class="+ topic/ph hi-d/b ">  </b> (U+03A3). </li></ul><p class="- topic/p ">
 * The <codeph class="+ topic/ph pr-d/codeph ">toLowerCase()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">toUpperCase()</codeph> methods of this
 * class provide this special case conversion logic.
 * </p><p class="- topic/p ">
 * Due to the use of the user's settings, the use of case conversion rules
 * provided by the operating system, and the use of a fallback locale when a requested locale is not supported,
 * different users can see different case conversion results even when using the same locale ID.
 * </p>
 *
 *   EXAMPLE:
 *
 *   This example shows how different strings
 * are converted to lower case and upper case in a lingustically correct manner.
 *
 *   <p class="- topic/p ">
 * This example takes the following steps:
 * </p><ol class="- topic/ol "><li class="- topic/li ">Creates a StringTools object.</li><li class="- topic/li ">Defines three strings with characters unique to the Turkish, Greek, and German languages.</li><li class="- topic/li ">Converts each string to upper case and lower case and displays the results. This example demonstrates interesting
 * locale-specific behavior for characters like the Turkish "    " and "    ", the German "    " and the Greek "             ".</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.globalization.LocaleID;
 * import flash.globalization.StringTools;
 * import flash.text.TextField;
 * import flash.text.TextFieldAutoSize;
 *
 *   public class StringToolsExample extends Sprite
 * {
 * public function StringToolsExample()
 * {
 * var localeName:String= LocaleID.DEFAULT;
 * var strTool:StringTools = new StringTools(localeName);
 *
 *   trace('\n\n' + "LocaleID requested: " + nf.requestedLocaleIDName
 * + "; actual: " + nf.actualLocaleIDName);
 * trace( "Last Operation Status:" + nf.lastOperationStatus );
 *
 *   var turkishStr:String = "iI         ";
 * var greekStr:String = "                              ";
 * var germanStr:String= "    ";
 *
 *   var tfTurInp:TextField = createTextField(10, 10);
 * tfTurInp.text="Turkish Input: \t " + turkishStr;
 *
 *   var tfdash:TextField = createTextField(10, 20);
 * tfdash.text="-------------------";
 *
 *   var tf1:TextField = createTextField(10, 30);
 * tf1.text="\t Upper case: \t " + strTool.toUpperCase(turkishStr);
 *
 *   var tf2:TextField = createTextField(10, 40);
 * tf2.text="\t Lower case: \t " + strTool.toLowerCase(turkishStr);
 *
 *   var tfgreekInp:TextField = createTextField(10, 60);
 * tfgreekInp.text="Greek Input: \t " + greekStr;
 *
 *   var tfdash1:TextField = createTextField(10, 70);
 * tfdash1.text="-------------------";
 *
 *   var tf3:TextField = createTextField(10, 80);
 * tf3.text="\t Upper case: \t " + strTool.toUpperCase(greekStr);
 *
 *   var tf4:TextField = createTextField(10, 90);
 * tf4.text="\t Lower case: \t " + strTool.toLowerCase(greekStr);
 *
 *   var tfgermanInp:TextField = createTextField(10, 110);
 * tfgermanInp.text="German Input: \t " + germanStr;
 *
 *   var tfdash2:TextField = createTextField(10, 120);
 * tfdash2.text="-------------------";
 *
 *   var tf5:TextField = createTextField(10, 130);
 * tf5.text="\t Upper case: \t " + strTool.toUpperCase(germanStr);
 *
 *   var tf6:TextField = createTextField(10, 140);
 * tf6.text="\t Lower case: \t " + strTool.toLowerCase(germanStr);
 * }
 *
 *   private function createTextField(x:Number, y:Number):TextField
 * {
 * var result:TextField = new TextField();
 * result.x = x;
 * result.y = y;
 * result.autoSize=TextFieldAutoSize.LEFT;
 * addChild(result);
 * return result;
 * }
 * }
 * }
 *
 *   </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */


namespace flash
{
    namespace globalization
    {
        class StringTools : public Object
        {
            /**
             * The status of the most recent operation that this StringTools object performed.
             * The lastOperationStatus property is set whenever the constructor or a method of
             * this class is called or another property is set. For the possible values see the description for each method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string  lastOperationStatus();

            /**
             * The name of the requested locale ID that was passed to the constructor of this StringTools object.
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
             * The name of the actual locale ID used by this StringTools object.
             *
             *   There are three possibilities for the value of the name, depending on operating system and the
             * value of the requestedLocaleIDName parameter passed to the StringTools() constructor.If the requested locale was not LocaleID.DEFAULT and
             * the operating system provides support for the requested locale,
             * then the name returned is the same as the requestedLocaleIDName property.
             * If LocaleID.DEFAULT was used as the value for the requestedLocaleIDName
             * parameter to the constructor, then the name of the current locale specified by the user's operating system is
             * used. The LocaleID.DEFAULT value preserves user's customized setting in the OS.
             * Passing an explicit value as the requestedLocaleIDName parameter does not necessarily give the
             * same result as using the LocaleID.DEFAULT even if the two locale ID names are the same.
             * The user could have customized the locale settings on the machine, and by requesting an
             * explicit locale ID name rather than using LocaleID.DEFAULT your application would not
             * retrieve those customized settings.
             * For example:
             * <codeblock>
             *
             *   var tools:StringTools = new StringTools(LocaleID.DEFAULT);
             * var aliName:String = tools.actualLocaleIDName;
             *
             *   </codeblock>
             * In the above example, aliName is the name of the locale corresponding to
             * the user's current operating systems settings (e.g. "it-IT" if the user's locale is set to Italian-Italy),
             * and not "i-default" (the name of the LocaleID.DEFAULT locale).If the system does not support the requestedLocaleIDName specified in the constructor
             * then a fallback locale ID name is provided.
             * For Example:
             * <codeblock>
             *
             *   var tools:StringTools = new StringTools("fr-CA");
             * var aliName:String = tools.actualLocaleIDName;
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
             * Constructs a new StringTools object that provides case conversion and other utilities according to
             * the conventions of a given locale.
             *
             *   This constructor determines if the current operating system supports the requested locale ID name.
             * If it is not supported then a fallback locale is used instead.
             * If a fallback locale is used then the lastOperationStatus property
             * indicates the type of fallback, and the actualLocaleIDName property contains
             * the name of the fallback locale ID. When this constructor completes successfully the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORWhen the requested locale ID name is not available then the lastOperationStatus
             * is set to one of the following:LastOperationStatus.USING_FALLBACK_WARNINGLastOperationStatus.USING_DEFAULT_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in
             * the LastOperationStatus class.
             * @param   requestedLocaleIDName   The preferred locale ID name to use when determining date or time formats.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError when the requestedLocaleIDName parameter is null
             */
        public:
            StringTools(std::string requestedLocaleIDName);

            /**
             * Converts a string to lowercase according to language conventions.
             * Depending on the locale, the output string length can differ from the input string length.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   s   A string to convert to lowercase.
             * @return  The converted lowercase string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError when  the s parameter is null.
             */
        public:
            std::string toLowerCase(std::string s);

            /**
             * Converts a string to uppercase according to language conventions.
             * Depending on the locale, the output string length can differ from the input string length.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   s   A string to convert to uppercase.
             * @return  The converted uppercase string.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError when the s parameter is null.
             */
        public:
            std::string toUpperCase(std::string s);
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_STRINGTOOLS_AS
#endif // __cplusplus

