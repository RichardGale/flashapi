#if !defined(FLEX11_6_NUMBER_AS)
#define FLEX11_6_NUMBER_AS
#if defined(__cplusplus)


/**
 * A data type representing an IEEE-754 double-precision floating-point number. You can manipulate primitive numeric
 * values by using the methods and properties associated with the Number class. This class is identical to the
 * JavaScript Number class.
 * <p class="- topic/p ">The properties of the Number class are static, which means you do not need an object to use them, so you
 * do not need to use the constructor.</p><p class="- topic/p ">The Number data type adheres to the double-precision IEEE-754 standard. </p><p class="- topic/p ">The Number data type is useful when you need to use floating-point values.
 * Flash runtimes handle int and uint data types more efficiently than Number, but Number is
 * useful in situations where the range of values required exceeds the valid range
 * of the int and uint data types. The Number class can be used to
 * represent integer values well beyond the valid range of the int and uint data types.
 * The Number data type can use up to 53 bits to represent integer values, compared to
 * the 32 bits available to int and uint. The default value of a variable typed as Number is <codeph class="+ topic/ph pr-d/codeph ">NaN</codeph> (Not a Number).</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how a number with six digits after the decimal place
 * is truncated (with rounding) to a number with two digits after the decimal point.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 *
 *   public class NumberExample extends Sprite {
 * public function NumberExample() {
 * var num:Number = new Number(10.456345);
 * var str:String = num.toFixed(2);
 * trace(num); // 10.456345
 * trace(str); // 10.46
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class Number: public Object
{
public:
    static const int length;

    /**
     * The IEEE-754 value representing Not a Number (NaN).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float NaN;

    /**
     * Specifies the IEEE-754 value representing negative infinity. The value of this property
     * is the same as that of the constant -Infinity.
     *
     *   Negative infinity is a special numeric value that is returned when a mathematical
     * operation or function returns a negative value larger than can be
     * represented.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float NEGATIVE_INFINITY;

    /**
     * Specifies the IEEE-754 value representing positive infinity. The value of this property
     * is the same as that of the constant Infinity.
     *
     *   Positive infinity is a special numeric value that is returned when a mathematical
     * operation or function returns a value larger than can be represented.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float POSITIVE_INFINITY;

    /**
     * The smallest representable non-negative, non-zero, number (double-precision IEEE-754). This number is
     * approximately 5e-324. The smallest representable number overall is actually -Number.MAX_VALUE.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float MIN_VALUE;

    /**
     * The largest representable number (double-precision IEEE-754). This number is
     * approximately 1.79e+308.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float MAX_VALUE;
public:
    static const float E;
public:
    static const float LN10;
public:
    static const float LN2;
public:
    static const float LOG10E;
public:
    static const float LOG2E;
public:
    static const float PI;
public:
    static const float SQRT1_2;
public:
    static const float SQRT2;

    /**
     * Creates a Number object with the specified value. This constructor has the same effect
     * as the Number() public native function that converts an object of a different type
     * to a primitive numeric value.
     * @param   num The numeric value of the Number instance being created or a value
     *   to be converted to a Number. The default value is 0 if num is
     *   not specified. Using the constructor without specifying a num parameter is not
     *   the same as declaring a variable of type Number with no value assigned (such as var myNumber:Number), which
     *   defaults to NaN. A number with no value assigned is undefined and the equivalent of
     *   new Number(undefined).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    Number(void *value);

public:
    static float    abs(float x);

public:
    static float    acos(float x);

public:
    static float    asin(float x);

public:
    static float    atan(float x);

public:
    static float    ceil(float x);

public:
    static float    cos(float x);

public:
    static float    exp(float x);

public:
    static float    floor(float x);

public:
    static float    log(float x);

public:
    static float    round(float x);

public:
    static float    sin(float x);

public:
    static float    sqrt(float x);

public:
    static float    tan(float x);

public:
    static float    atan2(float y, float x);

public:
    static float    pow(float x, float y);

public:
    static float    max(float x, float y, ...);

public:
    static float    min(float x, float y, ...);

public:
    static float    random();

    /**
     * Returns the string representation of the specified Number object (myNumber).
     * If the value of the Number object is a decimal number without a leading zero (such as .4),
     * Number.toString() adds a leading zero (0.4).
     * @param   radix   Specifies the numeric base (from 2 to 36) to use for the number-to-string
     *   conversion. If you do not specify the radix parameter, the default value
     *   is 10.
     * @return  The numeric representation of the Number object as a string.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    std::string toString(void *radix);

    /**
     * Returns the primitive value type of the specified Number object.
     * @return  The primitive type value of the Number object.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
    float    valueOf();

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

#endif // FLEX11_6_NUMBER_AS
#endif // __cplusplus

