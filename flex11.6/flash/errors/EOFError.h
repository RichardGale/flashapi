#if !defined(FLEX11_6_FLASH_ERRORS_EOFERROR_AS)
#define FLEX11_6_FLASH_ERRORS_EOFERROR_AS
#if defined(__cplusplus)


/**
 * An EOFError exception is thrown when you attempt to read past the end of the available data. For example, an
 * EOFError is thrown when one of the read methods in the IDataInput interface is
 * called and there is insufficient data to satisfy the read request.
 *
 *   EXAMPLE:
 *
 *   The following example uses the <codeph class="+ topic/ph pr-d/codeph ">EOFErrorExample</codeph> class to show
 * the error generated if an attempt is made to read past the end of the available
 * data.  This is accomplished with the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The constructor creates a ByteArray object <codeph class="+ topic/ph pr-d/codeph ">byteArr</codeph> and writes a Boolean
 * value of <codeph class="+ topic/ph pr-d/codeph ">false</codeph> into the byte stream using <codeph class="+ topic/ph pr-d/codeph ">writeBoolean()</codeph>.  </li><li class="- topic/li ">The position of <codeph class="+ topic/ph pr-d/codeph ">byteArr</codeph> is reset to <codeph class="+ topic/ph pr-d/codeph ">0</codeph> (start of the data stream).</li><li class="- topic/li ">A single byte is removed from the data stream using <codeph class="+ topic/ph pr-d/codeph ">readBoolean()</codeph>.  The
 * data stream now contains no data.</li><li class="- topic/li ">Within an error handling code segment set to catch EOFError objects, <codeph class="+ topic/ph pr-d/codeph ">readBoolean()</codeph>
 * is called a second time and the EOFError is caught and passed to a <codeph class="+ topic/ph pr-d/codeph ">trace()</codeph>
 * statement, which outputs the error message associated with EOFError objects. </li></ol><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.errors.EOFError;
 * import flash.utils.ByteArray;
 *
 *   public class EOFErrorExample extends Sprite {
 * public function EOFErrorExample() {
 * var byteArr:ByteArray = new ByteArray();
 *
 *   byteArr.writeBoolean(false);
 * trace(byteArr.length);        // 1
 *
 *   byteArr.position = 0;
 * try {
 * trace(byteArr.readBoolean());    // false
 * }
 * catch(e:EOFError) {
 * trace(e);
 * }
 * try {
 * trace(byteArr.readBoolean());
 * }
 * catch(e:EOFError) {
 * trace(e);        // EOFError: Error #2030: End of file was encountered.
 * }
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */

namespace flash
{
    namespace errors
    {
        class EOFError: public IOError
        {
        public:
            EOFError(std::string message, int id);
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_EOFERROR_AS
#endif // __cplusplus

