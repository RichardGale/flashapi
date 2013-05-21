

    /**
     * The Date class represents date and time information. An instance of the Date class represents a particular point 
     * in time for which the properties such as month, day, hours, and seconds can be queried or modified. The Date 
     * class lets you retrieve date and time values relative to universal time (Greenwich mean time, now called universal 
     * time or UTC) or relative to local time, which is determined by the local time zone setting on the operating system 
     * that is running Flash Player. The methods of the Date class are not static but apply only to the individual Date 
     * object specified when the method is called. The <codeph class="+ topic/ph pr-d/codeph ">Date.UTC()</codeph> and <codeph class="+ topic/ph pr-d/codeph ">Date.parse()</codeph> methods are 
     * exceptions; they are static methods.
     * <p product="flash" class="- topic/p ">The Date class handles daylight saving time differently, depending on the operating system and 
     * runtime version. Flash Player 6 and later versions handle daylight saving time on the following operating 
     * systems in these ways:</p><ul product="flash" class="- topic/ul "><li class="- topic/li ">Windows - the Date object automatically adjusts its output for daylight saving time. The Date object detects 
     * whether daylight saving time is employed in the current locale, and if so, it detects the standard-to-daylight 
     * saving time transition date and times. However, the transition dates currently in effect are applied to dates in 
     * the past and the future, so the daylight saving time bias might calculate incorrectly for dates in the past when 
     * the locale had different transition dates.</li><li class="- topic/li ">Mac OS X - the Date object automatically adjusts its output for daylight saving time. The time zone information 
     * database in Mac OS X is used to determine whether any date or time in the present or past should have a daylight 
     * saving time bias applied.</li><li class="- topic/li ">Mac OS 9 - the operating system provides only enough information to determine whether the current date and 
     * time should have a daylight saving time bias applied. Accordingly, the date object assumes that the current 
     * daylight saving time bias applies to all dates and times in the past or future.</li></ul><p product="flash" class="- topic/p ">Flash Player 5 handles daylight saving time on the following operating systems as follows:</p><ul product="flash" class="- topic/ul "><li class="- topic/li ">Windows - the U.S. rules for daylight saving time are always applied, which leads to incorrect transitions 
     * in Europe and other areas that employ daylight saving time but have different transition times than the U.S. Flash 
     * correctly detects whether daylight saving time is used in the current locale.</li></ul><p class="- topic/p ">To use the Date class, construct a Date instance using the <codeph class="+ topic/ph pr-d/codeph ">new</codeph> operator.</p><p class="- topic/p ">ActionScript 3.0 adds several new accessor properties that can be used in place of many Date class methods 
     * that access or modify Date instances. ActionScript 3.0 also includes several new variations of the 
     * <codeph class="+ topic/ph pr-d/codeph ">toString()</codeph> method that are included for ECMA-262 3rd Edition compliance, including: 
     * <codeph class="+ topic/ph pr-d/codeph ">Date.toLocaleString()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Date.toTimeString()</codeph>, <codeph class="+ topic/ph pr-d/codeph ">Date.toLocaleTimeString()</codeph>, 
     * <codeph class="+ topic/ph pr-d/codeph ">Date.toDateString()</codeph>, and <codeph class="+ topic/ph pr-d/codeph ">Date.toLocaleDateString()</codeph>.</p><p class="- topic/p ">To compute relative time or time elapsed, see the <codeph class="+ topic/ph pr-d/codeph ">getTimer()</codeph> method in the flash.utils package.</p>
     * 
     *   EXAMPLE:
     * 
     *   The following example shows various uses of the <codeph class="+ topic/ph pr-d/codeph ">Date()</codeph> constructor to assign the
     * following variables:
     * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">myDate1</codeph> calls <codeph class="+ topic/ph pr-d/codeph ">Date()</codeph> with no parameters, which sets <codeph class="+ topic/ph pr-d/codeph ">myDate1</codeph> to the
     * current date and time (according to your current system's date and time). </li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">myDate2</codeph> calls <codeph class="+ topic/ph pr-d/codeph ">Date()</codeph> with the <codeph class="+ topic/ph pr-d/codeph ">year</codeph> (<codeph class="+ topic/ph pr-d/codeph ">2000</codeph>), month
     * (<codeph class="+ topic/ph pr-d/codeph ">0</codeph> = January), and <codeph class="+ topic/ph pr-d/codeph ">day</codeph> (<codeph class="+ topic/ph pr-d/codeph ">1</codeph>) parameters passed to it.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">myDate3</codeph> calls <codeph class="+ topic/ph pr-d/codeph ">Date()</codeph> with the <codeph class="+ topic/ph pr-d/codeph ">year</codeph> (<codeph class="+ topic/ph pr-d/codeph ">65</codeph> = 1965),
     * <codeph class="+ topic/ph pr-d/codeph ">month</codeph> (<codeph class="+ topic/ph pr-d/codeph ">2</codeph> = March), the <codeph class="+ topic/ph pr-d/codeph ">day</codeph> (<codeph class="+ topic/ph pr-d/codeph ">6</codeph>), the <codeph class="+ topic/ph pr-d/codeph ">hour</codeph>
     * (<codeph class="+ topic/ph pr-d/codeph ">9</codeph>), the <codeph class="+ topic/ph pr-d/codeph ">minute</codeph> (<codeph class="+ topic/ph pr-d/codeph ">30</codeph>), the <codeph class="+ topic/ph pr-d/codeph ">second</codeph> (<codeph class="+ topic/ph pr-d/codeph ">15</codeph>)
     * and the <codeph class="+ topic/ph pr-d/codeph ">millisecond</codeph>-+ (<codeph class="+ topic/ph pr-d/codeph ">0</codeph>) passed as parameters.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">myDate4</codeph> calls <codeph class="+ topic/ph pr-d/codeph ">Date()</codeph> with the time value representing the number of milliseconds
     * <b class="+ topic/ph hi-d/b ">before</b> (since the value is negative) 0:00:00 GMT January 1, 1970.</li></ul><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
     * 
     *   package {
     * import flash.display.Sprite;
     * 
     *   public class DateExample extends Sprite{
     * public function DateExample() {
     * var myDate1:Date = new Date();
     * trace(myDate1); // [NOW]
     * 
     *   var myDate2:Date = new Date(2000, 0, 1);
     * trace(myDate2); // Sat Jan 1 00:00:00 GMT-0800 2000
     * 
     *   var myDate3:Date = new Date(65, 2, 6, 9, 30, 15, 0);
     * trace(myDate3); // Sat Mar 6 09:30:15 GMT-0800 1965
     * 
     *   var myDate4:Date = new Date(-14159025000);
     * trace(myDate4); // Sun Jul 20 19:56:15 GMT-0700 1969
     * }        
     * }    
     * }
     * </codeblock>
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     */




        const int Date::length  ;

        float Date::fullYear()         ;
        void Date::fullYear(float value)       ;

        float Date::month()         ;
        void Date::month(float value)       ;

        float Date::date()         ;
        void Date::date(float value)       ;

        float Date::hours()         ;
        void Date::hours(float value)       ;

        float Date::minutes()         ;
        void Date::minutes(float value)       ;

        float Date::seconds()         ;
        void Date::seconds(float value)       ;

        float Date::milliseconds()         ;
        void Date::milliseconds(float value)       ;

        float Date::fullYearUTC()         ;
        void Date::fullYearUTC(float value)       ;

        float Date::monthUTC()         ;
        void Date::monthUTC(float value)       ;

        float Date::dateUTC()         ;
        void Date::dateUTC(float value)       ;

        float Date::hoursUTC()         ;
        void Date::hoursUTC(float value)       ;

        float Date::minutesUTC()         ;
        void Date::minutesUTC(float value)       ;

        float Date::secondsUTC()         ;
        void Date::secondsUTC(float value)       ;

        float Date::millisecondsUTC()         ;
        void Date::millisecondsUTC(float value)       ;

        float Date::time()         ;
        void Date::time(float value)       ;

        float Date::timezoneOffset()         ;

        float Date::day()         ;

        float Date::dayUTC()         ;

        /**
         * Constructs a new Date object that holds the specified date and time.
         * 
         *   The Date() constructor takes up to seven parameters (year, month,  
         * ..., millisecond) to specify a date and time to the millisecond. The date that
         * the newly constructed Date object contains depends on the number, and data type, of arguments passed. If you pass no arguments, the Date object is assigned the current date and time.If you pass one argument of data type Number, the Date object is assigned a time value based on the number of milliseconds since January 1, 1970 0:00:000 GMT, as specified by the lone argument.If you pass one argument of data type String, and the string contains a valid date, the Date object  contains a time value based on that date.If you pass two or more arguments, the Date object is assigned a time value based on the argument values passed, which represent the date's year, month, date, hour, minute, second, and milliseconds.If you pass a string to the Date class constructor, the date can be in a variety of formats, but must at least include the month, date, and year. For example, Feb 1 2005 is valid, but Feb 2005 is not. The following list indicates some of the valid formats:Day Month Date Hours:Minutes:Seconds GMT Year (for instance, "Tue Feb 1 00:00:00 GMT-0800 2005", which matches toString())Day Month Date Year Hours:Minutes:Seconds AM/PM (for instance, "Tue Feb 1 2005 12:00:00 AM", which matches toLocaleString())Day Month Date Year (for instance, "Tue Feb 1 2005", which matches toDateString())Month/Day/Year (for instance, "02/01/2005")Month/Year (for instance, "02/2005")
         * @param   yearOrTimevalue If other parameters are specified, this number represents a 
         *   year (such as 1965); otherwise, it represents a time value. If the number represents a year, a 
         *   value of 0 to 99 indicates 1900 through 1999; otherwise all four digits of the year must be 
         *   specified. If the number represents a time value (no other parameters are specified), it is the
         *   number of milliseconds before or after 0:00:00 GMT January 1, 1970; a negative values represents  
         *   a time before 0:00:00 GMT January 1, 1970, and a positive value represents a time after.
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   date    An integer from 1 to 31.
         * @param   hour    An integer from 0 (midnight) to 23 (11 p.m.).
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999 of milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        Date::Date(void* year, void* month, void* date, void* hours, void* minutes, void* seconds, void* ms);

        /**
         * Converts a string representing a date into a number equaling the number of milliseconds 
         * elapsed since January 1, 1970, UTC.
         * @param   date    A string representation of a date, which conforms to the format for the output of
         *   Date.toString(). The date format for the output of Date.toString() is:
         *   
         *     Day Mon DD HH:MM:SS TZD YYYY
         *   For example: 
         *   Wed Apr 12 15:30:17 GMT-0700 2006
         *   The Time Zone Designation (TZD) is always in the form GMT-HHMM or UTC-HHMM indicating the 
         *   hour and minute offset relative to Greenwich Mean Time (GMT), which is now also called universal time (UTC).
         *   The year month and day terms can be separated by a forward slash (/) or by spaces, but never by a
         *   dash (-). Other supported formats include the following (you can include partial representations of these 
         *   formats; that is, just the month, day, and year):
         *   MM/DD/YYYY HH:MM:SS TZD
         *   HH:MM:SS TZD Day Mon/DD/YYYY 
         *   Mon DD YYYY HH:MM:SS TZD
         *   Day Mon DD HH:MM:SS TZD YYYY
         *   Day DD Mon HH:MM:SS TZD YYYY
         *   Mon/DD/YYYY HH:MM:SS TZD
         *   YYYY/MM/DD HH:MM:SS TZD
         * @return  A number representing the milliseconds elapsed since January 1, 1970, UTC.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        float Date::parse(void* s)         ;

        /**
         * Returns the number of milliseconds between midnight on January 1, 1970, universal time, 
         * and the time specified in the parameters. This method uses universal time, whereas the 
         * Date constructor uses local time.
         * This method is useful if you want to pass a UTC date to the Date class constructor.
         * Because the Date class constructor accepts the millisecond offset as an argument, you
         * can use the Date.UTC() method to convert your UTC date into the corresponding millisecond 
         * offset, and send that offset as an argument to the Date class constructor:
         * @param   year    A four-digit integer that represents the year (for example, 2000).
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   date    An integer from 1 to 31.
         * @param   hour    An integer from 0 (midnight) to 23 (11 p.m.).
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The number of milliseconds since January 1, 1970 and the specified date and time.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */
        float Date::UTC(void* year, void* month, void* date, void* hours, void* minutes, void* seconds, void* ms, ...)         ;

        /**
         * Returns the number of milliseconds since midnight January 1, 1970, universal time, 
         * for a Date object.
         * @return  The number of milliseconds since January 1, 1970 that a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::valueOf()         ;

        /**
         * Sets the date in milliseconds since midnight on January 1, 1970, and returns the new 
         * time in milliseconds.
         * @param   millisecond An integer value where 0 is midnight on January 1, universal time (UTC).
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setTime(void* t)         ;

        /**
         * Returns a String representation of the day, date, time, and timezone.
         * The date format for the output is:
         * 
         *   Day Mon Date HH:MM:SS TZD YYYY
         * For example:
         * Wed Apr 12 15:30:17 GMT-0700 2006
         * @return  The string representation of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toString()         ;

        /**
         * Returns a string representation of the day and date only, and does not include the time or timezone.
         * Contrast with the following methods:
         * Date.toTimeString(), which returns only the time and timezoneDate.toString(), which returns not only the day and date, but also the time and timezone.
         * @return  The string representation of day and date only.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toDateString()         ;

        /**
         * Returns a String representation of the time and timezone only, and does not include the day and date.
         * Contrast with the Date.toDateString() method, which returns only the day and date.
         * @return  The string representation of time and timezone only.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toTimeString()         ;

        /**
         * Returns a String representation of the day, date, time, given in local time.
         * Contrast with the Date.toString() method, which returns the same information (plus the timezone)
         * with the year listed at the end of the string.
         * @return  A string representation of a Date object in the local timezone.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toLocaleString()         ;

        /**
         * Returns a String representation of the day and date only, and does not include the time or timezone.
         * This method returns the same value as Date.toDateString.
         * Contrast with the following methods:
         * Date.toTimeString(), which returns only the time and timezoneDate.toString(), which returns not only the day and date, but also the
         * time and timezone.
         * @return  The String representation of day and date only.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toLocaleDateString()         ;

        /**
         * Returns a String representation of the time only, and does not include the day, date, year, or timezone.
         * Contrast with the Date.toTimeString() method, which returns the time and timezone.
         * @return  The string representation of time and timezone only.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toLocaleTimeString()         ;

        /**
         * Returns a String representation of the day, date, and time in universal time (UTC).
         * For example, the date February 1, 2005 is returned as Tue Feb 1 00:00:00 2005 UTC.
         * @return  The string representation of a Date object in UTC time.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */std::string Date::toUTCString()         ;

        /**
         * Returns the four-digit year of a Date object according to universal time (UTC).
         * @return  The UTC four-digit year a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCFullYear()         ;

        /**
         * Returns the month (0 [January] to 11 [December]) portion of a Date object
         * according to universal time (UTC).
         * @return  The UTC month portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCMonth()         ;

        /**
         * Returns the day of the month (an integer from 1 to 31) of a Date object, 
         * according to universal time (UTC).
         * @return  The UTC day of the month (1 to 31) that a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCDate()         ;

        /**
         * Returns the day of the week (0 for Sunday, 1 for Monday, and so on) of this Date
         * according to universal time (UTC).
         * @return  The UTC day of the week (0 to 6) that a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCDay()         ;

        /**
         * Returns the hour (an integer from 0 to 23) of the day of a Date object
         * according to universal time (UTC).
         * @return  The UTC hour of the day (0 to 23) a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCHours()         ;

        /**
         * Returns the minutes (an integer from 0 to 59) portion of a Date object
         * according to universal time (UTC).
         * @return  The UTC minutes portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCMinutes()         ;

        /**
         * Returns the seconds (an integer from 0 to 59) portion of a Date object
         * according to universal time (UTC).
         * @return  The UTC seconds portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCSeconds()         ;

        /**
         * Returns the milliseconds (an integer from 0 to 999) portion of a Date object
         * according to universal time (UTC).
         * @return  The UTC milliseconds portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getUTCMilliseconds()         ;

        /**
         * Returns the full year (a four-digit number, such as 2000) of a Date object 
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The full year a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getFullYear()         ;

        /**
         * Returns the month (0 for January, 1 for February, and so on) portion of this 
         * Date according to local time. Local time is determined by the operating system 
         * on which the Flash runtimes are running.
         * @return  The month (0 - 11) portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getMonth()         ;

        /**
         * Returns the day of the month (an integer from 1 to 31) specified by a Date object
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The day of the month (1 - 31) a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getDate()         ;

        /**
         * Returns the day of the week (0 for Sunday, 1 for Monday, and so on) specified by this
         * Date according to local time. Local time is determined by the operating 
         * system on which the Flash runtimes are running.
         * @return  A numeric version of the day of the week (0 - 6) a Date object
         *   represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getDay()         ;

        /**
         * Returns the hour (an integer from 0 to 23) of the day portion of a Date object
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The hour (0 - 23) of the day a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getHours()         ;

        /**
         * Returns the minutes (an integer from 0 to 59) portion of a Date object
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The minutes portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getMinutes()         ;

        /**
         * Returns the seconds (an integer from 0 to 59) portion of a Date object
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The seconds (0 to 59) portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getSeconds()         ;

        /**
         * Returns the milliseconds (an integer from 0 to 999) portion of a Date object
         * according to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * @return  The milliseconds portion of a Date object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getMilliseconds()         ;

        /**
         * Returns the difference, in minutes, between universal 
         * time (UTC) and the computer's local time.
         * @return  The minutes you need to add to the computer's local time value to equal UTC. If
         *   your computer's time is set later than UTC, the return value will be negative.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getTimezoneOffset()         ;

        /**
         * Returns the number of milliseconds since midnight January 1, 1970, universal time, 
         * for a Date object. Use this method to represent a specific instant in time 
         * when comparing two or more Date objects.
         * @return  The number of milliseconds since Jan 1, 1970 that a Date object represents.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::getTime()         ;

        /**
         * Sets the year, according to local time, and returns the new time in milliseconds. If 
         * the month and day parameters are specified, 
         * they are set to local time. Local time is determined by the operating system on which 
         * the Flash runtimes are running.
         * 
         *   Calling this method does not modify the other fields of the Date but 
         * Date.getUTCDay() and Date.getDay() can report a new value 
         * if the day of the week changes as a result of calling this method.
         * @param   year    A four-digit number specifying a year. Two-digit numbers do not represent 
         *   four-digit years; for example, 99 is not the year 1999, but the year 99.
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   day A number from 1 to 31.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setFullYear(void* year, void* month, void* date)         ;

        /**
         * Sets the month and optionally the day of the month, according to local time, and 
         * returns the new time in milliseconds. Local time is determined by the operating 
         * system on which the Flash runtimes are running.
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   day An integer from 1 to 31.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setMonth(void* month, void* date)         ;

        /**
         * Sets the day of the month, according to local time, and returns the new time in 
         * milliseconds. Local time is determined by the operating system on which the Flash runtimes are
         * running.
         * @param   day An integer from 1 to 31.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setDate(void* date)         ;

        /**
         * Sets the hour, according to local time, and returns the new time in milliseconds. 
         * Local time is determined by the operating system on which the Flash runtimes are running.
         * @param   hour    An integer from 0 (midnight) to 23 (11 p.m.).
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setHours(void* hour, void* min, void* sec, void* ms)         ;

        /**
         * Sets the minutes, according to local time, and returns the new time in milliseconds. 
         * Local time is determined by the operating system on which the Flash runtimes are running.
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setMinutes(void* min, void* sec, void* ms)         ;

        /**
         * Sets the seconds, according to local time, and returns the new time in milliseconds. 
         * Local time is determined by the operating system on which the Flash runtimes are running.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setSeconds(void* sec, void* ms)         ;

        /**
         * Sets the milliseconds, according to local time, and returns the new time in 
         * milliseconds. Local time is determined by the operating system on which the Flash runtimes are 
         * running.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setMilliseconds(void* ms)         ;

        /**
         * Sets the year, in universal time (UTC), and returns the new time in milliseconds.
         * 
         *   Optionally, this method can also set the month and day of the month. Calling 
         * this method does not modify the other fields, but the Date.getUTCDay() and 
         * Date.getDay() methods can report a new value if the day of the week changes as a 
         * result of calling this method.
         * @param   year    An integer that represents the year specified as a full four-digit year, 
         *   such as 2000.
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   day An integer from 1 to 31.
         * @return  An integer.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCFullYear(void* year, void* month, void* date)         ;

        /**
         * Sets the month, and optionally the day, in universal time(UTC) and returns the new 
         * time in milliseconds. Calling this method does not modify the other fields, but the
         * Date.getUTCDay() and Date.getDay() methods might report a new 
         * value if the day of the week changes as a result of calling this method.
         * @param   month   An integer from 0 (January) to 11 (December).
         * @param   day An integer from 1 to 31.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCMonth(void* month, void* date)         ;

        /**
         * Sets the day of the month, in universal time (UTC), and returns the new time in 
         * milliseconds. Calling this method does not modify the other fields of a Date
         * object, but the Date.getUTCDay() and Date.getDay() methods can report 
         * a new value if the day of the week changes as a result of calling this method.
         * @param   day A number; an integer from 1 to 31.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCDate(void* date)         ;

        /**
         * Sets the hour, in universal time (UTC), and returns the new time in milliseconds. 
         * Optionally, the minutes, seconds, and milliseconds can be specified.
         * @param   hour    An integer from 0 (midnight) to 23 (11 p.m.).
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCHours(void* hour, void* min, void* sec, void* ms)         ;

        /**
         * Sets the minutes, in universal time (UTC), and returns the new time in milliseconds.
         * Optionally, you can specify the seconds and milliseconds.
         * @param   minute  An integer from 0 to 59.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCMinutes(void* min, void* sec, void* ms)         ;

        /**
         * Sets the seconds, and optionally the milliseconds, in universal time (UTC) and 
         * returns the new time in milliseconds.
         * @param   second  An integer from 0 to 59.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCSeconds(void* sec, void* ms)         ;

        /**
         * Sets the milliseconds, in universal time (UTC), and returns the new time in milliseconds.
         * @param   millisecond An integer from 0 to 999.
         * @return  The new time, in milliseconds.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   AIR 1.0
         * @playerversion   Lite 4
         */float Date::setUTCMilliseconds(void* ms)         ;

