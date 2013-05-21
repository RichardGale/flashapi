#if !defined(FLEX11_6_TYPEERROR_AS)
#define FLEX11_6_TYPEERROR_AS
#if defined(__cplusplus)


/**
 * A TypeError exception is thrown when the actual type of an operand is different
 * from the expected type.
 * <p class="- topic/p ">
 * In addition, this exception is thrown when:
 * <ul class="- topic/ul "><li class="- topic/li ">An actual parameter to a function or method could not be coerced to the formal
 * parameter type.</li><li class="- topic/li ">A value is assigned to a variable and cannot be coerced to the variable's type.</li><li class="- topic/li ">The right side of the <codeph class="+ topic/ph pr-d/codeph ">is</codeph> or <codeph class="+ topic/ph pr-d/codeph ">instanceof</codeph> operator is not a valid type.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">super</codeph> keyword is used illegally.</li><li class="- topic/li ">A property lookup results in more than one binding, and is therefore ambiguous.</li><li class="- topic/li ">A method is invoked on an incompatible object.  For example, a TypeError
 * exception is thrown if a RegExp class method is "grafted" onto a generic object
 * and then invoked.</li></ul></p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how a TypeError exception can
 * be generated and handled within a <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> statement.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.DisplayObject;
 * import flash.display.Sprite;
 *
 *   public class TypeErrorExample extends Sprite {
 * public function TypeErrorExample() {
 * try {
 * var child:Object = new Object();
 * addChild(DisplayObject(child));
 * }
 * catch(e:TypeError) {
 * trace(e);
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   AIR 1.0
 * @playerversion   Lite 4
 */


class TypeError : public Error
{
public:
    static const int length;

    /**
     * Creates a new TypeError object.
     * @param   message Contains the message associated with the TypeError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    TypeError(void *message=(void *)"", void *id=0);
};

#endif // FLEX11_6_TYPEERROR_AS
#endif // __cplusplus

