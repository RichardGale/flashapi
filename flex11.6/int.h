#if !defined(FLEX11_6_INT_AS)
#define FLEX11_6_INT_AS
#if defined(__cplusplus)


/**
 * The int class lets you work with the data type representing a 32-bit signed integer.
 * The range of values represented by the int class is -2,147,483,648 (-2^31) to 2,147,483,647 (2^31-1).
 * <p class="- topic/p ">The constant properties of the int class, <codeph class="+ topic/ph pr-d/codeph ">MAX_VALUE</codeph> and <codeph class="+ topic/ph pr-d/codeph ">MIN_VALUE</codeph>, are static, which means that you don't need an object to use them, so you don't need to use the constructor. The methods, however, are not static, which means that you do need an object to use them. You can create an int object by using the int class constructor or by declaring a variable of type int and assigning the variable a literal value.</p><p class="- topic/p ">The int data type is useful for loop counters and other situations where a floating point number is not needed, and is similar to the int data type in Java and C++. The default value of a variable typed as int is <codeph class="+ topic/ph pr-d/codeph ">0</codeph></p><p class="- topic/p ">If you are working with numbers that exceed <codeph class="+ topic/ph pr-d/codeph ">int.MAX_VALUE</codeph>, consider using Number.  </p><p class="- topic/p ">The following example calls the <codeph class="+ topic/ph pr-d/codeph ">toString()</codeph> method of the int class, which returns the string <codeph class="+ topic/ph pr-d/codeph ">1234</codeph>: </p><codeblock rev="3.0" xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * var myint:int = 1234;
 * myint.toString();
 * </codeblock><p class="- topic/p ">The following example assigns the value of the <codeph class="+ topic/ph pr-d/codeph ">MIN_VALUE</codeph> property to a variable declared without the use of the constructor:</p><pre xml:space="preserve" class="- topic/pre ">
 * var smallest:int = int.MIN_VALUE;
 * </pre>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">IntExample</codeph> class to show how
 * to work with and check the validity of int data types:
 * <ol class="- topic/ol "><li class="- topic/li ">Two int variables <codeph class="+ topic/ph pr-d/codeph ">a</codeph> and <codeph class="+ topic/ph pr-d/codeph ">b</codeph> are declared in the constructor.</li><li class="- topic/li ">The two ints are added using the method <codeph class="+ topic/ph pr-d/codeph ">addIntegers()</codeph>.</li><li class="- topic/li ">A third int variable <codeph class="+ topic/ph pr-d/codeph ">c</codeph> is assigned the outcome of <codeph class="+ topic/ph pr-d/codeph ">parseInteger()</codeph>,
 * which checks the validity of the string passed to it to ensure that it is an integer value
 * in the acceptable range for int data types and returns an int equal to the integer value
 * of the string if it is valid.</li><li class="- topic/li ">The int variables <codeph class="+ topic/ph pr-d/codeph ">a</codeph> and <codeph class="+ topic/ph pr-d/codeph ">c</codeph> are added together using <codeph class="+ topic/ph pr-d/codeph ">addIntegers()</codeph>.</li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class IntExample extends Sprite {
 * public function IntExample() {
 * var a:int = 512;
 * var b:int = -128;
 *
 *   trace(addIntegers(a, b)); // 384
 *
 *   var c:int = parseInteger("32");
 *
 *   trace(addIntegers(a, c)); // 544
 * }
 *
 *   public function addIntegers(a:int, b:int):int {
 * return a + b;
 * }
 *
 *   public function parseInteger(str:String):int {
 * var num:Number = parseInt(str);
 * if(!isNaN(num) &amp;&amp; num &lt;= int.MAX_VALUE &amp;&amp; num &gt;= int.MIN_VALUE) {
 * return int(num);
 * }
 *
 *   return 0;
 * }
 *
 *   }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class int: public Object
{
    /**
     * The smallest representable 32-bit signed integer, which is -2,147,483,648.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const int MIN_VALUE;

    /**
     * The largest representable 32-bit signed integer, which is 2,147,483,647.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const int MAX_VALUE;
public:
    static const int length;

    /**
     * Constructor; creates a new int object. You must use the int constructor when using int.toString() and int.valueOf(). You do not use a constructor when using the properties of an int object. The new int constructor is primarily used as a placeholder. An int object is not the same as the int() function that converts a parameter to a primitive value.
     * @param   num The numeric value of the int object being created or a value to be converted to a  number. The default value is 0 if value is not provided.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    int(void *value);

    /**
     * Returns the string representation of an int object.
     * @param   radix   Specifies the numeric base (from 2 to 36) to use for the number-to-string conversion. If you do not specify the radix parameter, the default value is 10.
     * @return  A string.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string toString(void *radix);

    /**
     * Returns the primitive value of the specified int object.
     * @return  An int value.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    int      valueOf();

    /**
     * Returns a string representation of the number in exponential notation. The string contains
     * one digit before the decimal point and up to 20 digits after the decimal point, as
     * specified by the fractionDigits parameter.
     * @param   fractionDigits  An integer between 0 and 20, inclusive, that represents the desired number of decimal places.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     * @throws  RangeError Throws an exception if the fractionDigits argument is outside the range 0 to 20.
     */
    std::string toExponential(void *p);

    /**
     * Returns a string representation of the number either in exponential notation or in
     * fixed-point notation. The string will contain the number of digits specified in the
     * precision parameter.
     * @param   precision   An integer between 1 and 21, inclusive, that represents the desired number of digits to represent in the resulting string.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     * @throws  RangeError Throws an exception if the precision argument is outside the range 1 to 21.
     */
    std::string toPrecision(void *p);

    /**
     * Returns a string representation of the number in fixed-point notation.
     * Fixed-point notation means that the string will contain a specific number of digits
     * after the decimal point, as specified in the fractionDigits parameter.
     * The valid range for the fractionDigits parameter is from 0 to 20.
     * Specifying a value outside this range throws an exception.
     * @param   fractionDigits  An integer between 0 and 20, inclusive, that represents the desired number of decimal places.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     * @playerversion   Lite 4
     * @throws  RangeError Throws an exception if the fractionDigits argument is outside the range 0 to 20.
     */
    std::string toFixed(void *p);
};

#endif // FLEX11_6_INT_AS
#endif // __cplusplus

