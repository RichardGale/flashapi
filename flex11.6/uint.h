#if !defined(FLEX11_6_UINT_AS)
#define FLEX11_6_UINT_AS
#if defined(__cplusplus)


/**
 * The uint class provides methods for working with a data type representing a 32-bit unsigned integer. Because an unsigned integer can only be
 * positive, its maximum value is twice that of the int class.
 * <p class="- topic/p ">The range of values represented by the uint class is 0 to 4,294,967,295 (2^32-1).</p><p class="- topic/p ">You can create a uint object by declaring a variable of type uint and assigning the variable a literal value. The default value of a variable of type uint is <codeph class="+ topic/ph pr-d/codeph ">0</codeph>.</p><p class="- topic/p ">The uint class is primarily useful for pixel color values (ARGB and RGBA) and other situations where
 * the int data type does not work well. For example, the number 0xFFFFFFFF, which
 * represents the color value white with an alpha value of 255, can't be represented
 * using the int data type because it is not within the valid range of the int values.</p><p class="- topic/p ">The following example creates a uint object and calls the <codeph class="+ topic/ph pr-d/codeph ">
 * toString()</codeph> method:</p><pre xml:space="preserve" class="- topic/pre ">
 * var myuint:uint = 1234;
 * trace(myuint.toString()); // 1234
 * </pre><p class="- topic/p ">The following example assigns the value of the <codeph class="+ topic/ph pr-d/codeph ">MIN_VALUE</codeph>
 * property to a variable without the use of the constructor:</p><pre xml:space="preserve" class="- topic/pre ">
 * var smallest:uint = uint.MIN_VALUE;
 * trace(smallest.toString()); // 0
 * </pre>
 *
 *   EXAMPLE:
 *
 *   The following example declares a uint <codeph class="+ topic/ph pr-d/codeph ">i</codeph> within a <codeph class="+ topic/ph pr-d/codeph ">for</codeph> loop,
 * which prints out the digits 0 to 9 (since uint defaults to 0).
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 *
 *   public class UintExample extends Sprite {
 * public function UintExample() {
 * for(var i:uint; i &lt; 10; i++) {
 * trace(i);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class uint: public Object
{
    /**
     * The smallest representable unsigned integer, which is 0.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int MIN_VALUE;

    /**
     * The largest representable 32-bit unsigned integer, which is 4,294,967,295.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const unsigned int MAX_VALUE;
public:
    static const int length;

    /**
     * Returns the string representation of a uint object.
     * @param   radix   Specifies the numeric base (from 2 to 36) to use for the
     *   number-to-string conversion. If you do not specify the radix
     *   parameter, the default value is 10.
     * @return  The string representation of the uint object.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string toString(void *radix);

    /**
     * Creates a new uint object. You can create a variable of uint type and assign it a literal value. The new uint() constructor is primarily used
     * as a placeholder. A uint object is not the same as the
     * uint() function, which converts a parameter to a primitive value.
     * @param   num The numeric value of the uint object being created,
     *   or a value to be converted to a number. If num is not provided,
     *   the default value is 0.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    uint(void *value);

    /**
     * Returns the primitive uint type value of the specified
     * uint object.
     * @return  The primitive uint type value of this uint
     *   object.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    unsigned int valueOf();

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

#endif // FLEX11_6_UINT_AS
#endif // __cplusplus

