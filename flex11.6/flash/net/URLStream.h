#if !defined(FLEX11_6_FLASH_NET_URLSTREAM_AS)
#define FLEX11_6_FLASH_NET_URLSTREAM_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class URLRequest;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

/**
 * Dispatched when data is received as the download operation progresses.
 * @eventType   flash.events.ProgressEvent.PROGRESS
 */
//[Event(name="progress",type="flash.events.ProgressEvent")]

/**
 * Dispatched when a load operation starts.
 * @eventType   flash.events.Event.OPEN
 */
//[Event(name="open",type="flash.events.Event")]

/**
 * Dispatched when an input/output error occurs that causes a load operation to fail.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched if a call to the URLStream.load() method attempts to access data over HTTP
 * and Adobe AIR is able to detect and return the status code for the request.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_RESPONSE_STATUS
 */
//[Event(name="httpResponseStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched if a call to URLStream.load()
 * attempts to access data over HTTP, and Flash Player or  Adobe AIR
 * is able to detect and return the status code for the request.
 * @eventType   flash.events.HTTPStatusEvent.HTTP_STATUS
 */
//[Event(name="httpStatus",type="flash.events.HTTPStatusEvent")]

/**
 * Dispatched if a call to URLStream.load()
 * attempts to load data from a server outside the security sandbox.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched when data has loaded successfully.
 * @eventType   flash.events.Event.COMPLETE
 */
//[Event(name="complete",type="flash.events.Event")]

using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        /**
         * The URLStream class provides low-level access to
         * downloading URLs. Data is made available to application code
         * immediately as it is downloaded, instead of waiting until
         * the entire file is complete as with URLLoader.
         * The URLStream class also lets you close a stream
         * before it finishes downloading.
         * The contents of the downloaded file are made available as raw binary data.
         *
         *   <p class="- topic/p ">The read operations in URLStream are nonblocking.
         * This means that you must use the <codeph class="+ topic/ph pr-d/codeph ">bytesAvailable</codeph> property to determine
         * whether sufficient data is available before reading it.  An
         * <codeph class="+ topic/ph pr-d/codeph ">EOFError</codeph> exception is thrown if insufficient
         * data is available.</p><p class="- topic/p ">All binary data is encoded by default in big-endian format, with the
         * most significant byte first.</p><p class="- topic/p ">The security rules that apply to URL downloading with the URLStream class are identical
         * to the rules applied to URLLoader objects.
         * Policy files may be downloaded as needed. Local file security rules are enforced,
         * and security warnings are raised as needed.</p>
         *
         *   EXAMPLE:
         *
         *   The following example loads a SWF file and parses the beginning of its header to indicate
         * compression and version number information.
         * <p class="- topic/p ">To run the example, place a file named URLStreamExample.swf in the same directory as your SWF file.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
         *
         *   package {
         * import flash.display.Sprite;
         * import flash.errors.*;
         * import flash.events.*;
         * import flash.net.URLRequest;
         * import flash.net.URLStream;
         *
         *   public class URLStreamExample extends Sprite {
         * private static const ZLIB_CODE:String = "CWS";
         * private var stream:URLStream;
         *
         *   public function URLStreamExample() {
         * stream = new URLStream();
         * var request:URLRequest = new URLRequest("URLStreamExample.swf");
         * configureListeners(stream);
         * try {
         * stream.load(request);
         * } catch (error:Error) {
         * trace("Unable to load requested URL.");
         * }
         * }
         *
         *   private function configureListeners(dispatcher:EventDispatcher):void {
         * dispatcher.addEventListener(Event.COMPLETE, completeHandler);
         * dispatcher.addEventListener(HTTPStatusEvent.HTTP_STATUS, httpStatusHandler);
         * dispatcher.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
         * dispatcher.addEventListener(Event.OPEN, openHandler);
         * dispatcher.addEventListener(ProgressEvent.PROGRESS, progressHandler);
         * dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
         * }
         *
         *   private function parseHeader():void {
         * trace("parseHeader");
         * trace("isCompressed: " + isCompressed());
         * trace("version: " + stream.readByte());
         * }
         *
         *   private function isCompressed():Boolean {
         * return (stream.readUTFBytes(3) == ZLIB_CODE);
         * }
         *
         *   private function completeHandler(event:Event):void {
         * trace("completeHandler: " + event);
         * parseHeader();
         * }
         *
         *   private function openHandler(event:Event):void {
         * trace("openHandler: " + event);
         * }
         *
         *   private function progressHandler(event:Event):void {
         * trace("progressHandler: " + event);
         * }
         *
         *   private function securityErrorHandler(event:SecurityErrorEvent):void {
         * trace("securityErrorHandler: " + event);
         * }
         *
         *   private function httpStatusHandler(event:HTTPStatusEvent):void {
         * trace("httpStatusHandler: " + event);
         * }
         *
         *   private function ioErrorHandler(event:IOErrorEvent):void {
         * trace("ioErrorHandler: " + event);
         * }
         * }
         * }
         * </codeblock>
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        class URLStream : public flash::events::EventDispatcher, public IDataInput
        {
            /**
             * Indicates whether this URLStream object is
             * currently connected. A call to this property returns a value of true
             * if the URLStream object is connected, or false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         connected();

            /**
             * Returns the number of bytes of data available for reading
             * in the input buffer.
             * Your code must call the bytesAvailable property to ensure
             * that sufficient data is available before you try to read
             * it with one of the read methods.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int bytesAvailable();

            /**
             * Controls the version of Action Message Format (AMF) used when writing or reading an object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    Property documented; needs review
             */
        public:
            unsigned int objectEncoding();
        public:
            void         objectEncoding(unsigned int version);

            /**
             * Indicates the byte order for the data. Possible values are
             * Endian.BIG_ENDIAN or Endian.LITTLE_ENDIAN.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            std::string  endian();
        public:
            void         endian(std::string type);

        public:
            bool         diskCacheEnabled();

        public:
            float        position();
        public:
            void         position(float offset);

        public:
            float        length();

            /**
             * Begins downloading the URL specified in the request parameter.
             *
             *   Note: If a file being loaded contains non-ASCII characters
             * (as found in many non-English languages), it is recommended that you save the file
             * with UTF-8 or UTF-16 encoding, as opposed to a non-Unicode format like ASCII.If the loading operation fails immediately, an IOError or SecurityError
             * (including the local file security error) exception is thrown describing the failure.
             * Otherwise, an open event is dispatched if the URL download
             * starts downloading successfully, or an error event is dispatched if an error occurs.By default, the calling SWF file and the URL you load must be in exactly the same domain.
             * For example, a SWF file at www.adobe.com can load data only from sources that are also at www.adobe.com.
             * To load data from a different domain, place a URL policy file on the server hosting the data.In Flash Player, you cannot connect to commonly reserved ports.
             * For a complete list of blocked ports, see "Restricting Networking APIs" in the
             * ActionScript 3.0 Developer's Guide.In Flash Player, you can prevent a SWF file from using this method by setting the
             * allowNetworking parameter of the the object and embed
             * tags in the HTML page that contains the SWF content. In Flash Player 10 and later, and in AIR 1.5 and later, if you use a multipart
             * Content-Type (for example "multipart/form-data")
             * that contains an upload (indicated by a "filename" parameter in a "content-disposition" header within the POST body),
             * the POST operation is subject to the security rules applied to uploads:The POST operation must be performed in response to a user-initiated action, such as a mouse click or key press.If the POST operation is cross-domain (the POST target is not on the same server as the SWF file
             * that is sending the POST request),
             * the target server must provide a URL policy file that permits cross-domain access.Also, for any multipart Content-Type, the syntax must be valid (according to the RFC2046 standards).
             * If the syntax appears to be invalid, the POST operation is subject to the security rules applied to uploads.These rules also apply to AIR content in non-application sandboxes.
             * However, in Adobe AIR, content in the application sandbox (content installed with the AIR application)
             * are not restricted by these security limitations.For more information related to security, see The Flash Player Developer Center Topic:
             * Security.In AIR, a URLRequest object can register for the httpResponse status event.
             * Unlike the httpStatus event, the httpResponseStatus event is
             * delivered before any response data. Also, the httpResponseStatus event includes
             * values for the responseHeaders and responseURL properties (which are
             * undefined for an httpStatus event. Note that the httpResponseStatus event
             * (if any) will be sent before (and in addition to) any complete or error
             * event.
             * If there is an httpResponseStatus event listener, the body of the response
             * message is always sent; and HTTP status code responses always results in a complete event.
             * This is true in spite of whether the HTTP response status code indicates a success or an error.In AIR, if there is
             * nohttpResponseStatus event listener, the behavior differs
             * based on the SWF version:For SWF 9 content, the body of
             * the HTTP response message is sent only if the HTTP response status code indicates success.
             * Otherwise (if there is an error), no body is sent and the URLRequest object dispatches an IOError event.For SWF 10 content, the body of
             * the HTTP response message is always sent. If there is an error, the URLRequest object dispatches
             * an IOError event.
             * @param   request A URLRequest object specifying the URL to download. If the value of
             *   this parameter or the URLRequest.url property of the URLRequest object
             *   passed are null, the application throws a null pointer error.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  ArgumentError URLRequest.requestHeader objects may not contain
             *   certain prohibited HTTP request headers. For more information, see the URLRequestHeader class
             *   description.
             * @throws  MemoryError This error can occur for the following reasons:
             *
             *     Flash Player or Adobe AIR cannot convert the URLRequest.data parameter from UTF8 to MBCS. This error is
             *   applicable if the URLRequest object passed to load() is set to perform a GET operation
             *   and if System.useCodePage is set to true.Flash Player or Adobe AIR cannot allocate memory for
             *   the POST data. This error is applicable if the URLRequest object passed to load is set
             *   to perform a POST operation.
             * @throws  SecurityError Local untrusted SWF files may not communicate with
             *   the Internet. This may be worked around by reclassifying this SWF file
             *   as local-with-networking or trusted.
             * @throws  SecurityError You are trying to connect to a commonly reserved port.
             *   For a complete list of blocked ports, see "Restricting Networking APIs" in the
             *   ActionScript 3.0 Developer's Guide.
             */
        public:
            void     load(URLRequest *request);

            /**
             * Reads length bytes of data from the stream.
             * The bytes are read into the ByteArray object specified
             * by bytes, starting offset bytes into
             * the ByteArray object.
             * @param   bytes   The ByteArray object to read
             *   data into.
             * @param   offset  The offset into bytes at which data
             *   read should begin.  Defaults to 0.
             * @param   length  The number of bytes to read.  The default value
             *   of 0 will cause all available data to be read.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream, or the stream is not open.
             */
        public:
            void     readBytes(ByteArray *bytes, unsigned int offset=0, unsigned int length=0);

            /**
             * Reads a Boolean value from the stream. A single byte is read,
             * and true is returned if the byte is nonzero,
             * false otherwise.
             * @return  True is returned if the byte is nonzero, false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            bool     readBoolean();

            /**
             * Reads a signed byte from the stream.
             * The returned value is in the range -128...127.
             * @return  Value in the range -128...127.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            int      readByte();

            /**
             * Reads an unsigned byte from the stream.
             * The returned value is in the range 0...255.
             * @return  Value in the range 0...255.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            unsigned int readUnsignedByte();

            /**
             * Reads a signed 16-bit integer from the stream.
             * The returned value is in the range -32768...32767.
             * @return  Value in the range -32768...32767.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            int      readShort();

            /**
             * Reads an unsigned 16-bit integer from the stream.
             * The returned value is in the range 0...65535.
             * @return  Value in the range 0...65535.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            unsigned int readUnsignedShort();

            /**
             * Reads an unsigned 32-bit integer from the stream.
             * The returned value is in the range 0...4294967295.
             * @return  Value in the range 0...4294967295.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            unsigned int readUnsignedInt();

            /**
             * Reads a signed 32-bit integer from the stream.
             * The returned value is in the range -2147483648...2147483647.
             * @return  Value in the range -2147483648...2147483647.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            int      readInt();

            /**
             * Reads an IEEE 754 single-precision floating-point number from the stream.
             * @return  An IEEE 754 single-precision floating-point number from the stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            float    readFloat();

            /**
             * Reads an IEEE 754 double-precision floating-point number from the stream.
             * @return  An IEEE 754 double-precision floating-point number from the stream.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            float    readDouble();

            /**
             * Reads a multibyte string of specified length from the byte stream using the
             * specified character set.
             * @param   length  The number of bytes from the byte stream to read.
             * @param   charSet The string denoting the character set to use to interpret the bytes.
             *   Possible character set strings include "shift_jis", "CN-GB",
             *   "iso-8859-1", and others.
             *   For a complete list, see Supported Character Sets.
             *
             *     Note: If the value for the charSet parameter is not recognized
             *   by the current system, the application uses the system's default code page as the character set.
             *   For example, a value for the charSet parameter, as in
             *   myTest.readMultiByte(22, "iso-8859-01") that uses 01 instead of 1
             *   might work on your development machine, but not on another machine. On the other machine,
             *   the application will use the system's default code page.
             * @return  UTF-8 encoded string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             */
        public:
            std::string readMultiByte(unsigned int length, std::string charSet);

            /**
             * Reads a UTF-8 string from the stream.  The string
             * is assumed to be prefixed with an unsigned short indicating
             * the length in bytes.
             * @return  A UTF-8 string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            std::string readUTF();

            /**
             * Reads a sequence of length UTF-8
             * bytes from the stream, and returns a string.
             * @param   length  A sequence of UTF-8 bytes.
             * @return  A UTF-8 string produced by the byte representation of characters of specified length.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient
             *   data available to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            std::string readUTFBytes(unsigned int length);

            /**
             * Immediately closes the stream and
             * cancels the download operation.
             * No data can be read from the stream after the close() method is called.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError The stream could not be closed, or the stream was not open.
             */
        public:
            void     close();

            /**
             * Reads an object from the socket, encoded in Action Message Format (AMF).
             * @return  The deserialized object.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available
             *   to read. If a local SWF file triggers a security warning,
             *   Flash Player prevents the URLStream data from being available to ActionScript.
             *   When this happens, the bytesAvailable property returns 0 even if data has been
             *   received, and any of the read methods throws an EOFError exception.
             * @throws  IOError An I/O error occurred on the stream,
             *   or the stream is not open.
             */
        public:
            void    *readObject();

        public:
            void     stop();

        public:
            URLStream();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_URLSTREAM_AS
#endif // __cplusplus

