#if !defined(FLEX11_6_REFERENCEERROR_AS)
#define FLEX11_6_REFERENCEERROR_AS
#if defined(__cplusplus)


/**
 * A ReferenceError exception is thrown when a reference to an undefined property is
 * attempted on a sealed (nondynamic) object. References to undefined variables will
 * result in ReferenceError exceptions to inform you of potential bugs and help you troubleshoot
 * application code.
 * <p class="- topic/p ">However, you can refer to undefined properties of a dynamic class without causing a ReferenceError exception
 * to be thrown. For more information, see the <codeph class="+ topic/ph pr-d/codeph ">dynamic</codeph> keyword.</p>
 *
 *   EXAMPLE:
 *
 *   The following example shows how a <codeph class="+ topic/ph pr-d/codeph ">ReferenceError</codeph> exception can
 * be generated and handled within a <codeph class="+ topic/ph pr-d/codeph ">try..catch</codeph> statement.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 *
 *   public class ReferenceErrorExample extends Sprite {
 *
 *   public function ReferenceErrorExample() {
 * try {
 * this["someMember"] = true;
 * }
 * catch(e:ReferenceError) {
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


class ReferenceError : public Error
{
public:
    static const int length;

    /**
     * Creates a new ReferenceError object.
     * @param   message Contains the message associated with the ReferenceError object.
     * @playerversion   Lite 4
     * @playerversion   Flash 9
     * @playerversion   AIR 1.0
     */
public:
    ReferenceError(void *message=(void *)"", void *id=0);
};

#endif // FLEX11_6_REFERENCEERROR_AS
#endif // __cplusplus

