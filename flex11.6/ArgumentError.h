#if !defined(FLEX11_6_ARGUMENTERROR_AS)
#define FLEX11_6_ARGUMENTERROR_AS
#if defined(__cplusplus)


/**
 * The ArgumentError class represents an error that occurs when the arguments
 * supplied in a function do not match the arguments defined for
 * that function. This error occurs, for example, when a function is called with
 * the wrong number of arguments, an argument of the incorrect type, or an invalid argument.
 *
 *   EXAMPLE:
 *
 *   The following example shows how an <codeph class="+ topic/ph pr-d/codeph ">ArgumentError</codeph> error is
 * generated and handled within a <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> statement. The
 * <codeph class="+ topic/ph pr-d/codeph ">println()</codeph> function takes one argument, a single string, but because two strings are supplied,
 * the error is thrown.
 * Typically, the compiler might catch such an error, but the <codeph class="+ topic/ph pr-d/codeph ">this[]</codeph> syntax in the <codeph class="+ topic/ph pr-d/codeph ">try</codeph>
 * statement bypasses the compiler's syntax checking for the function.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class ArgumentErrorExample extends Sprite {
 * public function ArgumentErrorExample() {
 * println("Hello World");
 *
 *   try {
 * this["println"]("Hello", "World");
 * }
 * catch(e:ArgumentError) {
 * trace(e);
 * }
 * }
 *
 *   public function println(str:String):void {
 * trace(str);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */

#include "flex11.6.h"



class ArgumentError : public Error
{
public:
    static const int length;

    /**
     * Creates an ArgumentError object.
     * @param   message A string associated with the error.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    ArgumentError(std::string message="", void *id=0);
};

#endif // FLEX11_6_ARGUMENTERROR_AS
#endif // __cplusplus

