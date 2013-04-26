#if !defined(FLEX11_6_MATH_AS)
#define FLEX11_6_MATH_AS
#if defined(__cplusplus)


/**
 * The Math class contains methods and constants that represent common mathematical
 * functions and values.
 * <p class="- topic/p ">Use the methods and properties of this class to access and manipulate mathematical constants and functions.
 * All the properties and methods of the Math class are static and must be called using the syntax
 * <codeph class="+ topic/ph pr-d/codeph ">Math.method(</codeph><codeph class="+ topic/ph pr-d/codeph "><i class="+ topic/ph hi-d/i ">parameter</i></codeph><codeph class="+ topic/ph pr-d/codeph ">)</codeph> or <codeph class="+ topic/ph pr-d/codeph ">Math.constant</codeph>.
 * In ActionScript, constants are defined with the maximum precision of double-precision IEEE-754 floating-point numbers.</p><p class="- topic/p ">Several Math class methods use the measure of an angle in radians as a parameter. You can use the following equation
 * to calculate radian values before calling the method and then provide the calculated value as the parameter, or you can
 * provide the entire right side of the equation (with the angle's measure in degrees in place of <codeph class="+ topic/ph pr-d/codeph ">degrees</codeph>) as
 * the radian parameter.</p><p class="- topic/p ">To calculate a radian value, use the following formula:</p><pre xml:space="preserve" class="- topic/pre ">
 * radians = degrees ~~ Math.PI/180
 * </pre><p class="- topic/p ">To calculate degrees from radians, use the following formula:</p><pre xml:space="preserve" class="- topic/pre ">
 * degrees = radians ~~ 180/Math.PI
 * </pre><p class="- topic/p ">The following is an example of passing the equation as a parameter to calculate the sine of a 45   angle:</p><p class="- topic/p "><codeph class="+ topic/ph pr-d/codeph ">Math.sin(45 ~~ Math.PI/180)</codeph> is the same as <codeph class="+ topic/ph pr-d/codeph ">Math.sin(.7854)</codeph></p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> The Math functions acos, asin, atan, atan2, cos, exp, log, pow, sin, and sqrt may
 * result in slightly different values depending on the algorithms
 * used by the CPU or operating system. Flash runtimes call on the CPU (or operating system if the CPU doesn't support
 * floating point calculations) when performing the calculations for the listed functions, and results have shown
 * slight variations depending upon the CPU or operating system in use.
 * </p>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

class Math: public Object
{
    /**
     * A mathematical constant for the base of natural logarithms, expressed as e.
     * The approximate value of eis 2.71828182845905.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float E;

    /**
     * A mathematical constant for the natural logarithm of 10, expressed as loge10,
     * with an approximate value of 2.302585092994046.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float LN10;

    /**
     * A mathematical constant for the natural logarithm of 2, expressed as loge2,
     * with an approximate value of 0.6931471805599453.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float LN2;

    /**
     * A mathematical constant for the base-10 logarithm of the constant e (Math.E),
     * expressed as log10e, with an approximate value of 0.4342944819032518.
     * The Math.log() method computes the natural logarithm of a number. Multiply the
     * result of Math.log() by Math.LOG10E to obtain the base-10 logarithm.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float LOG10E;

    /**
     * A mathematical constant for the base-2 logarithm of the constant e, expressed
     * as log2e, with an approximate value of 1.442695040888963387.
     *
     *   The Math.log method computes the natural logarithm of a number. Multiply the
     * result of Math.log() by Math.LOG2E to obtain the base-2 logarithm.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float LOG2E;

    /**
     * A mathematical constant for the ratio of the circumference of a circle to its diameter,
     * expressed as pi, with a value of 3.141592653589793.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float PI;

    /**
     * A mathematical constant for the square root of one-half, with an approximate
     * value of 0.7071067811865476.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float SQRT1_2;

    /**
     * A mathematical constant for the square root of 2, with an approximate
     * value of 1.4142135623730951.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static const float SQRT2;

public:
    Math();

    /**
     * Computes and returns an absolute value for the number specified by the
     * parameter val.
     * @param   val The number whose absolute value is returned.
     * @return  The absolute value of the specified paramater.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    abs(float val);

    /**
     * Computes and returns the arc cosine of the number specified in the
     * parameter val, in radians.
     * @param   val A number from -1.0 to 1.0.
     * @return  The arc cosine of the parameter val.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    acos(float val);

    /**
     * Computes and returns the arc sine for the number specified in the
     * parameter val, in radians.
     * @param   val A number from -1.0 to 1.0.
     * @return  A number between negative pi divided by 2 and positive pi
     *   divided by 2.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    asin(float val);

    /**
     * Computes and returns the value, in radians, of the angle whose tangent is
     * specified in the parameter val. The return value is between
     * negative pi divided by 2 and positive pi divided by 2.
     * @param   val A number that represents the tangent of an angle.
     * @return  A number between negative pi divided by 2 and positive
     *   pi divided by 2.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    atan(float val);

    /**
     * Returns the ceiling of the specified number or expression. The ceiling of a
     * number is the closest integer that is greater than or equal to the number.
     * @param   val A number or expression.
     * @return  An integer that is both closest to, and greater than or equal to, the parameter
     *   val.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    ceil(float val);

    /**
     * Computes and returns the cosine of the specified angle in radians. To
     * calculate a radian, see the overview of the Math class.
     * @param   angleRadians    A number that represents an angle measured in radians.
     * @return  A number from -1.0 to 1.0.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    cos(float angleRadians);

    /**
     * Returns the value of the base of the natural logarithm (e), to the
     * power of the exponent specified in the parameter x. The
     * constant Math.E can provide the value of e.
     * @param   val The exponent; a number or expression.
     * @return  e to the power of the parameter val.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    exp(float val);

    /**
     * Returns the floor of the number or expression specified in the parameter
     * val. The floor is the closest integer that is less than or equal
     * to the specified number or expression.
     * @param   val A number or expression.
     * @return  The integer that is both closest to, and less than or equal to, the parameter
     *   val.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    floor(float val);

    /**
     * Returns the natural logarithm of the parameter val.
     * @param   val A number or expression with a value greater than 0.
     * @return  The natural logarithm of parameter val.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    log(float val);

    /**
     * Rounds the value of the parameter val up or down to the nearest
     * integer and returns the value. If val is equidistant
     * from its two nearest integers (that is, if the number ends in .5), the value
     * is rounded up to the next higher integer.
     * @param   val The number to round.
     * @return  The parameter val rounded to the nearest whole number.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    round(float val);

    /**
     * Computes and returns the sine of the specified angle in radians. To
     * calculate a radian, see the overview of the Math class.
     * @param   angleRadians    A number that represents an angle measured in radians.
     * @return  A number; the sine of the specified angle (between -1.0 and 1.0).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    sin(float angleRadians);

    /**
     * Computes and returns the square root of the specified number.
     * @param   val A number or expression greater than or equal to 0.
     * @return  If the parameter val is greater than or equal to zero, a number; otherwise NaN (not a number).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    sqrt(float val);

    /**
     * Computes and returns the tangent of the specified angle. To calculate a
     * radian, see the overview of the Math class.
     * @param   angleRadians    A number that represents an angle measured in radians.
     * @return  The tangent of the parameter angleRadians.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    tan(float angleRadians);

    /**
     * Computes and returns the angle of the point y/x in
     * radians, when measured counterclockwise from a circle's x axis
     * (where 0,0 represents the center of the circle). The return value is between
     * positive pi and negative pi. Note that the first parameter to atan2 is always the y coordinate.
     * @param   y   The y coordinate of the point.
     * @param   x   The x coordinate of the point.
     * @return  A number.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    atan2(float y, float x);

    /**
     * Computes and returns base to the power of pow.
     * @param   base    A number to be raised by the power of the parameter pow.
     * @param   pow A number specifying the power that the parameter base is raised by.
     * @return  The value of base raised to the power of pow.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    pow(float base, float pow);

    /**
     * Evaluates val1 and val2 (or more values) and returns the largest value.
     * @param   val1    A number or expression.
     * @param   val2    A number or expression.
     * @param   rest    A number or expression. Math.max() can accept multiple arguments.
     * @return  The largest of the parameters val1 and val2 (or more values).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    max(float val1, float val2, ...);

    /**
     * Evaluates val1 and val2 (or more values) and returns the smallest value.
     * @param   val1    A number or expression.
     * @param   val2    A number or expression.
     * @param   rest    A number or expression. Math.min() can accept multiple arguments.
     * @return  The smallest of the parameters val1 and val2 (or more values).
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    min(float val1, float val2, ...);

    /**
     * Returns a pseudo-random number n, where 0 <= n < 1. The number returned is calculated in an undisclosed manner, and is "pseudo-random" because the calculation inevitably contains some element of non-randomness.
     * @return  A pseudo-random number.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    static float    random();
};

#endif // FLEX11_6_MATH_AS
#endif // __cplusplus

