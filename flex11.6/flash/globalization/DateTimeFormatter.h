#if !defined(FLEX11_6_FLASH_GLOBALIZATION_DATETIMEFORMATTER_AS)
#define FLEX11_6_FLASH_GLOBALIZATION_DATETIMEFORMATTER_AS
#if defined(__cplusplus)


/**
 * The DateTimeFormatter class provides locale-sensitive formatting for Date objects and access to localized
 * date field names. The methods of this class use functions and settings provided by the operating system.
 *
 *   <p class="- topic/p ">There are two ways to select a date time format: using a predefined pattern
 * or a custom pattern. For most applications the predefined styles specified by the
 * DateTimeStyle constants (<codeph class="+ topic/ph pr-d/codeph ">LONG</codeph>, <codeph class="+ topic/ph pr-d/codeph ">MEDIUM</codeph>, <codeph class="+ topic/ph pr-d/codeph ">NONE</codeph>, or <codeph class="+ topic/ph pr-d/codeph ">SHORT</codeph>
 * should be used.  These constants
 * specify the default patterns for the requested locale or the default patterns based on the
 * user's operating system settings.
 * </p><p class="- topic/p ">
 * For example the following code creates a date string using the default short date format:
 * </p><codeblock rev="3.0" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var df:DateTimeFormatter = new DateTimeFormatter(LocaleID.DEFAULT, DateTimeStyle.SHORT, DateTimeStyle.NONE);
 * var currentDate:Date = new Date();
 * var shortDate:String = df.format(currentDate);
 * </codeblock><p class="- topic/p ">When an instance of this class is created, if the requested locale is supported by the
 * operating system then the properties of the instance are set according to the conventions and
 * defaults of the requested locale and the constructor's <codeph class="+ topic/ph pr-d/codeph ">dateStyle</codeph> and <codeph class="+ topic/ph pr-d/codeph ">timeStyle</codeph> parameters.
 * If the requested locale is not available, then the properties are set according to a fallback or
 * default system locale, which can be retrieved using the <codeph class="+ topic/ph pr-d/codeph ">actualLocaleIDName</codeph> property.
 * </p><p class="- topic/p ">
 * This class contains additional methods to get localized strings for month names and
 * weekday names, and to retrieve the first day of the week that can be used in a calendar picker
 * or other similar application.
 * </p><p class="- topic/p ">
 * Due to the use of the user's settings, the use of formatting patterns
 * provided by the operating system, and the use of a fallback locale when a requested locale is not supported,
 * different users can see different formatting results even when using the same locale ID.
 * </p>
 *
 *   EXAMPLE:
 *
 *   The following examples shows how strings that represent date and time values can be formatted
 * differently based on the locale.
 *
 *   The output from this example will differ based on the operating system and user preferences.
 * <p class="- topic/p ">
 * This example uses the following locales: English (US), French (France), Spanish (Spain).
 * </p><p class="- topic/p ">
 * The example does the following for each locale in the list:
 * </p><ol class="- topic/ol "><li class="- topic/li ">Creates a DateTimeFormatter object using the default style (long dateStyle, long timeStyle)</li><li class="- topic/li ">Formats the current date and time using the default long date style.</li><li class="- topic/li ">Change to a time-only short date style using the <codeph class="+ topic/ph pr-d/codeph ">DateTimeStyle.NONE</codeph> and <codeph class="+ topic/ph pr-d/codeph ">DateTimeStyle.SHORT</codeph>
 * constants.</li><li class="- topic/li ">Formats the current date and time using the time-only short date style.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.globalization.DateTimeFormatter;
 * import flash.globalization.DateTimeStyle;
 *
 *   public class DateTimeFormatterExample extends Sprite
 * {
 * private var localeList:Array = new Array("en-US", "fr-FR", "es-ES");
 *
 *   public function DateTimeFormatterExample()
 * {
 * var date:Date = new Date();
 *
 *   for each (var locale:String in localeList) {
 * var dtf:DateTimeFormatter = new DateTimeFormatter(locale);
 * trace('\n' + "LocaleID requested=" + dtf.requestedLocaleIDName
 * + "; actual=" + dtf.actualLocaleIDName);
 *
 *   var longDate:String = dtf.format(date);
 * trace(longDate + " (" + dtf.getDateTimePattern() + ")");
 *
 *   dtf.setDateTimeStyles(DateTimeStyle.NONE, DateTimeStyle.SHORT);
 * var shortDate:String = dtf.format(date);
 * trace(shortDate + " (" + dtf.getDateTimePattern() + ")");
 * }
 * }
 * }
 * }
 * </codeblock>
 *
 *   EXAMPLE:
 *
 *   The following example shows how an application can format a date based on a pattern selected by the user.
 *
 *   The output from this example will differ based on the operating system and user preferences.
 * <p class="- topic/p ">
 * The example does the following for each locale in the list:
 * </p><ol class="- topic/ol "><li class="- topic/li ">Creates three input and output text fields.</li><li class="- topic/li ">Creates a DateTimeFormatter object using the American English locale.</li><li class="- topic/li ">Calls the <codeph class="+ topic/ph pr-d/codeph ">configureTextField()</codeph> function which sets the position and size of the text fields
 * and adds an event listener to the <codeph class="+ topic/ph pr-d/codeph ">patternField</codeph> object.</li><li class="- topic/li ">When the user enters pattern in the <codeph class="+ topic/ph pr-d/codeph ">patternField</codeph> text field, the <codeph class="+ topic/ph pr-d/codeph ">textInputHandler</codeph> function
 * formats the current date and time using the pattern, and displays the result and the <codeph class="+ topic/ph pr-d/codeph ">lastOperationStatus</codeph>
 * value the in output text fields.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.Event;
 * import flash.globalization.DateTimeFormatter;
 * import flash.text.*;
 *
 *   public class DateTimePatternExample extends Sprite
 * {
 * private var patternField:TextField = new TextField();
 * private var resultField:TextField = new TextField();
 * private var statusField:TextField = new TextField();
 * private var date:Date = new Date();
 * private var dtf:DateTimeFormatter = new DateTimeFormatter("en-US");
 *
 *   private function configureTextField():void
 * {
 * patternField.type = TextFieldType.INPUT;
 * patternField.width = 300;
 * patternField.height = 20;
 * patternField.background = true;
 * patternField.border = true;
 *
 *   resultField.y = 40;
 * resultField.width = 300;
 * resultField.height = 20;
 *
 *   statusField.y = 80;
 * statusField.width = 300;
 * statusField.height = 20;
 *
 *   addChild(patternField);
 * addChild(resultField);
 * addChild(statusField);
 * patternField.addEventListener(Event.CHANGE,textInputHandler);
 * }
 *
 *   private function textInputHandler(event:Event):void
 * {
 * dtf.setDateTimePattern(patternField.text);
 * statusField.text = dtf.lastOperationStatus;
 * resultField.text = dtf.format(date);
 * }
 *
 *   public function DateTimePatternExample()
 * {
 * configureTextField();
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 10.1
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace globalization
    {
        class DateTimeFormatter : public Object
        {
            /**
             * The status of previous operation that this DateTimeFormatter object performed.
             * The lastOperationStatus property is set whenever the constructor or a method of
             * this class is called, or another property is set. For the possible values see the description for each method.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       lastOperationStatus();

            /**
             * The name of the requested locale ID that was passed to the constructor of this DateTimeFormatter object.
             *
             *   If the LocaleID.DEFAULT value was used then the name returned is "i-default".
             * The actual locale used can differ from the requested locale when a fallback locale is applied.
             * The name of the actual locale can be retrieved using the actualLocaleIDName property.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string       requestedLocaleIDName();

            /**
             * The name of the actual locale ID used by this DateTimeFormatter object.
             *
             *   There are three possibilities for the value of the name, depending on operating system and the
             * value of the requestedLocaleIDName parameter passed to the Collator() constructor.If the requested locale was not LocaleID.DEFAULT and
             * the operating system provides support for the requested locale,
             * then the name returned is the same as the requestedLocaleIDName property.
             * If LocaleID.DEFAULT was used as the value for the requestedLocaleIDName
             * parameter to the constructor, then the name of the current locale specified by the user's operating system is
             * used. The LocaleID.DEFAULT value preserves user's customized setting in the OS.
             * Passing an explicit value as the requestedLocaleIDName parameter does not necessarily give the
             * same result as using the LocaleID.DEFAULT even if the two locale ID names are the same.
             * The user might have customized the locale settings on their machine, and by requesting an
             * explicit locale ID name rather than using LocaleID.DEFAULT your application would not
             * retrieve those customized settings.
             * For example:
             * <codeblock>
             *
             *   var fmt:DateTimeFormatter = new DateTimeFormatter(LocaleID.DEFAULT);
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
             *   var fmt:DateTimeFormatter = new DateTimeFormatter("fr-CA");
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
            std::string       actualLocaleIDName();

            /**
             * Constructs a new DateTimeFormatter object to format dates and times according to the conventions of the
             * specified locale and the provided date and time formatting styles. Date and time styles are used to set
             * date and time formatting patterns to predefined, locale dependent patterns from the operating system.
             *
             *   This constructor determines if the current operating system supports the requested locale ID name.
             * If it is not supported then a fallback locale is used instead.
             * The name of the fallback locale ID can be determined from the actualLocaleIDName property.
             *
             *   If a fallback is used for any of the requestedLocaleIDName, dateStyle or
             * timeStyle parameters then the lastOperationStatus property is set
             * to indicate the type of fallback.
             * To format based on the user's current operating system preferences, pass the value LocaleID.DEFAULT
             * in the requestedLocaleIDName parameter to the constructor.
             * When the constructor is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERRORWhen the requested locale ID name is not available then the lastOperationStatus
             * is set to one of the following:LastOperationStatus.USING_FALLBACK_WARNINGLastOperationStatus.USING_DEFAULT_WARNINGOtherwise the lastOperationStatus property is set to one of the constants defined in
             * the LastOperationStatus class.For details on the warnings listed above and other possible values of the
             * lastOperationStatus property see the descriptions in the LastOperationStatus class.
             * @param   requestedLocaleIDName   The preferred locale ID name to use when determining date or time formats.
             * @param   dateStyle   Specifies the style to use when formatting dates.
             *   The value corresponds to one of the values enumerated by the DateTimeStyle class:
             *   DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORTDateTimeStyle.NONE
             * @param   timeStyle   Specifies the style to use when formatting times.
             *   The value corresponds to one of the values enumerated by the DateTimeStyle class:
             *   DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORTDateTimeStyle.NONE
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError if the dateStyle or timeStyle parameter is not a valid DateTimeStyle constant.
             * @throws  TypeError if the dateStyle or timeStyle parameter is null.
             */
        public:
            DateTimeFormatter(std::string requestedLocaleIDName, std::string dateStyle="long", std::string timeStyle="long");

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
             * Sets the date and time styles for this instance of the DateTimeFormatter. Date and time styles are used to set
             * date and time formatting patterns to predefined, locale-dependent patterns from the operating system.
             *
             *   This method replaces the styles that were set using the DateTimeFormatter() constructor or
             * using the setDateTimePattern() method. The date and time pattern is
             * also updated based on the styles that are set.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   dateStyle   Specifies the style to use when formatting dates.
             *   The value corresponds to one of the values enumerated by the DateTimeStyle class:
             *   DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORTDateTimeStyle.NONE
             * @param   timeStyle   Specifies the style to use when formatting times.
             *   The value corresponds to one of the values enumerated by the DateTimeStyle class:
             *   DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORTDateTimeStyle.NONE
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  ArgumentError if the dateStyle or timeStyle parameter is not a valid DateTimeStyle constant.
             * @throws  TypeError if the dateStyle or timeStyle parameter is null.
             */
        public:
            void     setDateTimeStyles(std::string dateStyle, std::string timeStyle);

            /**
             * Gets the time style for this instance of the DateTimeFormatter. The time style is used to retrieve a
             * predefined time formatting pattern from the operating system.
             *
             *   The time style value can be set by the DateTimeFormatter() constructor, the setDateTimeStyles()
             * method or the setDateTimePattern() method.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @return  The time style string for this formatter.
             *   Possible values: DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORT DateTimeStyle.NONE DateTimeStyle.CUSTOM
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   getTimeStyle();

            /**
             * Gets the date style for this instance of the DateTimeFormatter. The date style is used to retrieve a
             * predefined date formatting pattern from the operating system.
             *
             *   The date style value can be set by the DateTimeFormatter() constructor, the setDateTimeStyles()
             * method or the setDateTimePattern() method.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @return  The date style string for this formatter.
             *   Possible values: DateTimeStyle.LONGDateTimeStyle.MEDIUMDateTimeStyle.SHORT DateTimeStyle.NONE DateTimeStyle.CUSTOM
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   getDateStyle();

            /**
             * Formats a display string for a Date object that is interpreted as being in the user's local time
             * (using the local time components of the Date object such as: date, day, fullYear, hours, minutes, month, and seconds).
             * The formatting is done using the conventions of the locale ID
             * and the date style and time style, or customized date pattern and time pattern,
             * specified for this DateTimeFormatter instance.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   dateTime    A Date value to be formatted.
             * @return  A formatted string representing the date or time value.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   format(Date *dateTime);

            /**
             * Formats a display string for a Date object that is interpreted as being in UTC time
             * (using the UTC components of the Date object such as: dateUTC, dayUTC, fullYearUTC, hoursUTC, minutesUTC, monthUTC,
             * and secondsUTC), according to the dateStyle, timeStyle or date time pattern.
             * The formatting is done using the conventions of the locale ID
             * and the date style and time style, or customized date pattern and time pattern,
             * specified for this DateTimeFormatter instance.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   dateTime    A Date value to be formatted.
             * @return  A formatted string representing the date or time value.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   formatUTC(Date *dateTime);

            /**
             * Retrieves a list of localized strings containing the month names for the current calendar system.
             * The first element in the list is the name for the first month of the year.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   nameStyle   Indicates the style of name string to be used.  Valid values are:
             *   DateTimeNameStyle.FULLDateTimeNameStyle.LONG_ABBREVIATIONDateTimeNameStyle.SHORT_ABBREVIATION
             * @param   context A code indicating the context in which the formatted string is used.
             *   This context makes a difference only for certain locales. Valid values are:
             *   DateTimeNameContext.FORMATDateTimeNameContext.STANDALONE
             * @return  A vector of localized strings containing the month names for the specified locale, name style, and context.
             *   The first element in the vector, at index 0, is the name for the first month of the year; the next element is
             *   the name for the second month of the year; and so on.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the nameStyle or context parameter is null.
             */
        public:
            std::vector<std::string> getMonthNames(std::string nameStyle="full", std::string context="standalone");

            /**
             * Retrieves a list of localized strings containing the names of weekdays for the current calendar system.
             * The first element in the list represents the name for Sunday.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @param   nameStyle   Indicates the style of name string to be used.  Valid values are:
             *   DateTimeNameStyle.FULLDateTimeNameStyle.LONG_ABBREVIATIONDateTimeNameStyle.SHORT_ABBREVIATION
             * @param   context A code indicating the context in which the formatted string is used.
             *   This context only applies for certain locales where the name of a month changes depending on the context.
             *   For example, in Greek the month names are different if they are displayed alone versus displayed along with a day.
             *   Valid values are:
             *   DateTimeNameContext.FORMATDateTimeNameContext.STANDALONE
             * @return  A vector of localized strings containing the month names for the specified locale, name style, and context.
             *   The first element in the vector, at index 0, is the name for Sunday; the next element is the name
             *   for Monday; and so on.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the nameStyle or context parameter is null.
             */
        public:
            std::vector<std::string> getWeekdayNames(std::string nameStyle="full", std::string context="standalone");

            /**
             * Returns an integer corresponding to the first day of the week for this locale and calendar system.
             * A value of 0 corresponds to Sunday, 1 corresponds to Monday, and so on, with 6 corresponding to Saturday.
             *
             *   When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @return  An integer corresponding to the first day of the week for this locale and calendar system.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            int      getFirstWeekday();

            /**
             * Returns the pattern string used by this DateTimeFormatter object to format dates and times.
             *
             *   This pattern can be set in one of three ways:By the dateStyle and timeStyle parameters used in the constructorBy the setDateTimeStyles() methodBy the setDateTimePattern() method.For a description of the pattern syntax, see the
             * setDateTimePattern() method.
             * When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @return  A string containing the pattern used by this DateTimeFormatter object to format dates and times.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             */
        public:
            std::string   getDateTimePattern();

            /**
             * Sets the pattern string used by this DateTimeFormatter object to format dates and times.
             *
             *   The pattern used to format dates can be set in one of three ways:By the dateStyle and timeStyle parameters used in the constructorBy the setDateTimeStyles() methodBy this setDateTimePattern() method.
             * As a side effect this method overrides the current time and date styles for this DateTimeFormatter object and set them
             * to the value DateTimeStyle.CUSTOM.
             * A pattern string defines how date and times are formatted. The pattern contains sequences of letters that are replaced
             * with date and time values in the formatted string.
             * For example, in the pattern "yyyy/MM" the characters "yyyy" are replaced with a four-digit year, followed by a
             * "/" character, and the characters "MM" are replaced with a two-digit month.
             * Many of the letters used in patterns can be repeated more than once to produce different outputs,
             * as described in the table below.
             *
             *   If a sequence exceeds the maximum number of letters supported by a pattern,
             * it is mapped back to the longest supported sequence for that pattern letter.
             * For example:
             * MMMMMM is replaced with MMMM dddd is replaced with dd EEEEEEE is replaced with EEEE aa is replaced with a hhh is replaced with hh mmmm is replaced with mmIn theory a pattern can contain up to 255 characters, but some platforms have stricter limit.
             * If the pattern exceeds the pattern character limit, the lastOperationStatus property is set to the value
             * LastOperationStatus.PATTERN_SYNTAX_ERROR.
             * Not all possible patterns are supported on each operating system. If a pattern is not supported on the platform
             * then a fallback pattern is used
             * and the lastOperationStatus property is set to indicate the use of a fallback.
             * If no reasonable fallback pattern can be provided, an empty string is used
             * and the lastOperationStatus property is set to indicate that the pattern was unsupported.
             * The following table describes the valid pattern letters and their meaning.
             * Pattern letterDescriptionGEra. Replaced by the Era string for the current date and calendar. This pattern is not supported on all
             * operating systems. On operating systems that do not support the era, the letters of the input pattern
             * are replaced by an empty string.
             * There can be one to five letters in era patterns that are interpreted as follows: If the number of pattern letters is one to three, the abbreviated form is used.  If the number of pattern letters is four, the format is interpreted as the full form.  If the number of pattern letters is five, the format is interpreted as the short abbreviation. Examples with the Gregorian Calendar(for operating systems that support this pattern): G, GG, GGG = AD  GGGG = Anno Domini GGGGG = AyYear. If the number of pattern letters is two, the last two digits of the year are displayed; otherwise the number of letters determines
             * the number of digits. If the year value requires more digits than provided by the number of letters, then the full
             * year value is provided. If there are more letters than required by the value, then the year values are padded with zeros.
             * The following list shows the results for the years 1 and 2005.
             * Examples: y = 1 y = 2005  yy = 01 yy = 05 yyyy = 0001 or 01, Depending on the operating system. yyyy = 2005 yyyyy = 01 or  0001, Depending on the operating system. More than four y's fall back to the maximum number of digits supported on the operating system. yyyyy = 2005M Month in year. There can be one to five letters in month patterns that are interpreted as follows:
             * If the number of pattern letters is one, the format is interpreted as numeric in one or two digits.  If the number of pattern letters is two, the format is interpreted as numeric in two digits.  If the number of pattern letters is three, the format is interpreted as the long abbreviation.  If the number of pattern letters is four, the format is interpreted as the full name.  If the number of pattern letters is five, the format is interpreted as the short abbreviation. This format is not supported
             * on all operating systems and falls back to the long abbreviation. Examples: M = 7  MM = 07 MMM = Jul, 7    MMMM = July, 7    MMMMM = J  or Jul, 7 or 7    depending on the operating system.d Day of the month.  There can be one or two letters in day of the month patterns that are interpreted as follows:
             * If the number of pattern letters is one, the format is interpreted as numeric in one or two digits.  If the number of pattern letters is two, the format is interpreted as numeric in two digits. Examples: d = 4  dd = 04 dd = 14EDay in week.  There can be one to five letters in day of the week patterns that are interpreted as follows:
             * If the number of pattern letters is one to three, the format is interpreted as the long abbreviation.  If the number of pattern letters is four, the format is interpreted as the full name.  If the number of pattern letters is five, the format is interpreted as the short abbreviation. This format is not supported
             * on all operating systems and falls back to the long abbreviation. Examples: E, EE, EEE = Tues EEEE = Tuesday EEEEE = T or Tues depending on the operating system.QQuarter. Some platforms do not support this pattern. There can be one to four letters in quarter patterns that are interpreted as follows:
             * If the number of pattern letters is one, the format is interpreted as numeric in one digit.  If the number of pattern letters is two, the format is interpreted as numeric in two digits.  If the number of pattern letters is three, the format is interpreted as the abbreviation.  If the number of pattern letters is four, the format is interpreted as the full name. Examples (for operating systems that support this pattern): Q = 2  QQ = 02 QQQ = Q2 QQQQ = second quarterwWeek of the year.  Some platforms do not support this pattern. There can be one to two letters in this pattern that are interpreted as follows.
             * If the number of pattern letters is one, the format is interpreted as numeric in one or two digits.  If the number of pattern letters is two, the format is interpreted as numeric in two digits. Examples for the second week of the year (for operating systems that support this pattern): w = 2  ww = 02WWeek of the month. Some platforms do not support this pattern. This pattern allows one letter only.
             * Examples for the second week of July (for operating systems that support this pattern): W = 2 DDay of the year. Some platforms do not support this pattern. There can be one to three letters in this pattern.
             * Examples for the second day of the year (for operating systems that support this pattern): D = 2  DD = 02 DDD = 002FOccurrence of a day of the week within a calendar month. For example, this element displays "3"
             * if used to format the date for the third Monday in October.  This pattern allows one letter only.
             * Examples for the second Wednesday in July (for operating systems that support this pattern): F = 2aAM/PM indicator.  This pattern allows one letter only, a or p.
             * Examples: a = AM,        p = PM,       hHour of the day in a 12-hour format [1 - 12]. This pattern must be one or two letters.
             * Examples: h = 1 h = 12 hh = 01HHour of the day in a 24-hour format [0 - 23]. This pattern must be one or two letters.
             * Examples: H = 0 H = 23 HH = 00KHour in the day in a 12-hour format [0 - 11]. This pattern must be one or two letters.
             * This pattern is not supported on all operating systems.
             * Examples (for operating systems that support this pattern): K = 0 K = 11 KK = 00kHour of the day in a 24-hour format [1 - 24]. This pattern must be one or two letters.
             * This pattern is not supported on all operating systems.
             * Examples (for operating systems that support this pattern): k = 1 k = 24 kk = 01mMinute of the hour [0 - 59]. This pattern must be one or two letters.
             * Examples: m = 2 m = 59 mm = 02sSeconds in the minute [0 - 59]. This pattern must be one or two letters.
             * Examples: s = 2 s = 59 ss = 02SMilliseconds. This pattern must be one to five letters. The value is rounded according to the
             * number of letters used. When five characters are used (SSSSS) it denotes fractional milliseconds.
             * Examples: S = 2 SS = 24 SSS = 235 SSSS = 2350 SSSSS = 23500zTime Zone. Represents the time zone as a string that respects   standard or daylight time, without referring to a specific
             * location. This pattern is not supported on all operating systems. On operating systems that do not support
             * time zone patterns, the letters of the input pattern are replaced by an empty string.  On operating
             * systems that do support this pattern, not all locales have a defined string. Those locales fall back
             * to a localized GMT format such as GMT-08:00 or GW-08:00
             * There must be one to four letters in this time zone pattern, interpreted as follows: If the number of pattern letters is one to three, the format is interpreted as abbreviated form.  If the number of pattern letters is four, the format is interpreted as the full name. Examples for operating systems that support this format: z, zz, zzz = PDT z, zz, zzz = PST z, zz, zzz = GMT-0800 zzzz = Pacific Daylight Time zzzz = Pacific Standard TimeZTime Zone. Represents the time zone as an offset from GMT.  This pattern is not supported on all operating systems. On operating systems that do not support
             * time zone patterns, the letters of the input pattern are replaced by an empty string.
             * There must be one to four letters in this time zone pattern,  interpreted as follows: If the number of pattern letters is one to three, the format uses the RFC 822 format.  If the number of pattern letters is four, the format uses the localized GMT format.  This
             * falls back to the non-localized GMT format for locales that do not have a localized GMT format. Examples for operating systems that support this format: Z, ZZ, ZZZ = -0800 ZZZZ = GMT-08:00, GW-08:00vTime Zone. A string reflecting the generic time zone that does not refer to a specific
             * location or distinguish between daylight savings time or standard time. This pattern is not supported on all operating systems. On operating systems that do not support
             * time zone patterns the letters of the input pattern are replaced by an empty string. On operating
             * systems that support this pattern, fallback strings are provided if a localized name is not
             * available.
             * There must be one or four letters in this time zone pattern, interpreted as follows: If the number of pattern letters is one, the format uses the abbreviated form.  If the number of pattern letters is four, the format uses the full form. Examples for operating systems that support this format: v = PT vvvv = Pacific Time'Other text'Text and punctuation may be included in the pattern string. However the characters from a to z and A to Z, are reserved as
             * syntax characters and must be enclosed in single quotes to be included in
             * the formatted string.  To include a single quote in the result string, two single quotes must be used in the
             * pattern string. The two single quotes may appear inside or outside a quoted portion of the pattern string.
             * An unmatched pair of single quotes is terminated at the end of the string.
             * Examples: EEEE, MMM. d, yyyy 'at' h 'o''clock' a= Tuesday, Sept. 8, 2005 at 1 o'clock PM yyyy   M   d    =  2005   9   8    mm''ss'' =  43'01'When this method is called and it completes successfully, the lastOperationStatus property is set to:LastOperationStatus.NO_ERROROtherwise the lastOperationStatus property is set to one of the constants defined in the
             * LastOperationStatus class.
             * @langversion 3.0
             * @playerversion   Flash 10.1
             * @playerversion   AIR 2
             * @throws  TypeError if the pattern parameter is null.
             */
        public:
            void     setDateTimePattern(std::string pattern);
        };
    }
}

#endif // FLEX11_6_FLASH_GLOBALIZATION_DATETIMEFORMATTER_AS
#endif // __cplusplus

