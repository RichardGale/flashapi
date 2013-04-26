#if !defined(FLEX11_6_FLASH_ERRORS_IOERROR_AS)
#define FLEX11_6_FLASH_ERRORS_IOERROR_AS
#if defined(__cplusplus)


/**
 * The IOError exception is thrown when some type of input or output failure occurs.
 * For example, an IOError exception is thrown if a read/write operation is attempted on
 * a socket that has not connected or that has become disconnected.
 *
 *   EXAMPLE:
 *
 *   The following example throws an IOError exception when it attempts to close
 * a Sound stream that has never been loaded.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 * package {
 * import flash.display.Sprite;
 * import flash.errors.IOError;
 * import flash.media.Sound;
 *
 *   public class IOErrorExample extends Sprite
 * {
 * public function IOErrorExample()
 * {
 * var music:Sound = new Sound();
 * try {
 * music.close();
 * trace("Stream closed.");
 * } catch (error:IOError) {
 * trace("The stream could not be closed, or the stream was not open.");
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
        class IOError: public Error
        {
        public:
            IOError(std::string message, int id);
        };
    }
}

#endif // FLEX11_6_FLASH_ERRORS_IOERROR_AS
#endif // __cplusplus

