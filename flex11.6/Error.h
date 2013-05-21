#if !defined(FLEX11_6_ERROR_AS)
#define FLEX11_6_ERROR_AS
#if defined(__cplusplus)


/**
 * The Error class contains information about an error that occurred in a script. In developing ActionScript 3.0 applications,
 * when you run your compiled code in the debugger version of a Flash runtime, a dialog box displays exceptions of type Error,
 * or of a subclass, to help you troubleshoot the code.
 * You create an Error object by using the <codeph class="+ topic/ph pr-d/codeph ">Error</codeph> constructor function.
 * Typically, you throw a new Error object from within a <codeph class="+ topic/ph pr-d/codeph ">try</codeph>
 * code block that is caught by a <codeph class="+ topic/ph pr-d/codeph ">catch</codeph> or <codeph class="+ topic/ph pr-d/codeph ">finally</codeph> code block.
 * <p class="- topic/p ">You can also create a subclass of the Error class and throw instances of that subclass.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">ErrorExample</codeph> class to show
 * how a custom error can be generated.  This is accomplished with the following
 * steps:
 * <ol class="- topic/ol "><li class="- topic/li ">A local variable <codeph class="+ topic/ph pr-d/codeph ">nullArray</codeph> of Array type is declared, but notice
 * that a new Array object is never created.</li><li class="- topic/li ">The constructor attempts to load a value into the uninitialized array by using
 * the <codeph class="+ topic/ph pr-d/codeph ">push()</codeph> method within an error handling code segment that catches a
 * custom error by using the <codeph class="+ topic/ph pr-d/codeph ">CustomError</codeph> class, which extends <codeph class="+ topic/ph pr-d/codeph ">Error</codeph>.</li><li class="- topic/li ">When the CustomError is thrown, the constructor catches it and then outputs an
 * error message by using the <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph> statement. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package
 * {
 * import flash.display.Sprite;
 * public class ErrorExample extends Sprite
 * {
 * private var nullArray:Array;
 * public function ErrorExample()
 * {
 * try
 * {
 * nullArray.push("item");
 * }
 * catch(e:Error)
 * {
 * throw new CustomError("nullArray is null");
 * }
 * }
 * }
 * }
 *
 *   class CustomError extends Error
 * {
 * public function CustomError(message:String)
 * {
 * super(message);
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


class Error : public Object
{
public:
    static const int length;

    /**
     * Contains the message associated with the Error object. By default, the value of this property
     * is "Error". You can specify a message property when you create an
     * Error object by passing the error string to the Error constructor function.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    std::string message;

    /**
     * Contains the name of the Error object. By default, the value of this property is "Error".
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    std::string name;

    /**
     * Contains the reference number associated with the specific error message. For a custom Error object,
     * this number is the value from the id parameter supplied in the constructor.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    int          errorID();

    /**
     * Creates a new Error object. If message is specified, its value is assigned
     * to the object's Error.message property.
     * @param   message A string associated with the Error object; this parameter
     *   is optional.
     * @param   id  A reference number to associate with the specific error message.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    Error(void *message=(void *)"", void *id=0);

public:
    static std::string getErrorMessage(int index);

public:
    static void    *throwError(Class *type, unsigned int index, ...);

    /**
     * Returns the call stack for an error as a string at the time of the error's construction (for the debugger version
     * of Flash Player and the AIR Debug Launcher (ADL) only; returns null if not using the debugger version
     * of Flash Player or the ADL. As shown in the following example, the first line of the return value is the
     * string representation of the exception object, followed by the stack trace elements:
     *
     *   <codeblock>
     *
     *   TypeError: null cannot be converted to an object
     * at com.xyz.OrderEntry.retrieveData(OrderEntry.as:995)
     * at com.xyz.OrderEntry.init(OrderEntry.as:200)
     * at com.xyz.OrderEntry.$construct(OrderEntry.as:148)
     *
     *   </codeblock>
     * @return  A string representation of the call stack.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */
public:
    std::string getStackTrace();
};

#endif // FLEX11_6_ERROR_AS
#endif // __cplusplus

