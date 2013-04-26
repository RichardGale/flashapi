#if !defined(FLEX11_6_FLASH_NET_SOCKET_AS)
#define FLEX11_6_FLASH_NET_SOCKET_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
#include "IDataInput.h"
#include "IDataOutput.h"
namespace flash
{
    namespace utils
    {
        class Timer;
    }
}
namespace flash
{
    namespace events
    {
        class SecurityErrorEvent;
    }
}
namespace flash
{
    namespace events
    {
        class TimerEvent;
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
 * Dispatched if a call to Socket.connect() attempts to connect to a server
 * prohibited by the caller's security sandbox or to a port lower than 1024 and no socket policy file
 * exists to permit such a connection.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched when a socket has received data.
 * @eventType   flash.events.ProgressEvent.SOCKET_DATA
 */
//[Event(name="socketData",type="flash.events.ProgressEvent")]

/**
 * Dispatched when an input/output error occurs that causes a send or load operation to fail.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched when a network connection has been established.
 * @eventType   flash.events.Event.CONNECT
 */
//[Event(name="connect",type="flash.events.Event")]

/**
 * Dispatched when the server closes the socket connection.
 * @eventType   flash.events.Event.CLOSE
 */
//[Event(name="close",type="flash.events.Event")]

/**
 * The Socket class enables code to establish Transport Control Protocol (TCP) socket
 * connections for sending and receiving binary data.
 *
 *   <p class="- topic/p ">The Socket class is useful for working with servers that use binary protocols.</p><p class="- topic/p ">To use the methods of the Socket class, first use the constructor, <codeph class="+ topic/ph pr-d/codeph ">new Socket</codeph>,
 * to create a Socket object.</p><p class="- topic/p ">A socket transmits and receives data asynchronously. </p><p class="- topic/p ">On some operating systems, flush() is called automatically between execution frames, but on other operating systems, such
 * as Windows, the data is never sent unless you call <codeph class="+ topic/ph pr-d/codeph ">flush()</codeph> explicitly. To ensure your application behaves reliably
 * across all operating systems, it is a good practice to call the <codeph class="+ topic/ph pr-d/codeph ">flush()</codeph> method after writing each message
 * (or related group of data) to the socket.</p><p class="- topic/p ">In Adobe AIR, Socket objects are also created when a listening ServerSocket receives a connection from an external process.
 * The Socket representing the connection is dispatched in a ServerSocketConnectEvent. Your application is responsible for
 * maintaining a reference to this Socket object. If you don't, the Socket object is eligible for garbage collection and may be
 * destroyed by the runtime without warning.</p><p class="- topic/p ">SWF content running in the local-with-filesystem security sandbox cannot use sockets.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">Socket policy files</i> on the target host specify the hosts from which SWF files
 * can make socket connections, and the ports to which those connections can be made.
 * The security requirements with regard to socket policy files have become more stringent
 * in the last several releases of Flash Player.
 * In all versions of Flash Player, Adobe recommends the use of a socket policy file;
 * in some circumstances, a socket policy file is required. Therefore, if you
 * are using Socket objects, make sure that the target host provides a socket policy file
 * if necessary. </p><p class="- topic/p ">The following list summarizes the requirements for socket policy files
 * in different versions of Flash Player:</p><ul class="- topic/ul "><li class="- topic/li "> In Flash Player 9.0.124.0 and later, a socket policy file is required for any socket connection.
 * That is, a socket policy file on the target host is required no matter what port
 * you are connecting to, and is required even if you are connecting
 * to a port on the same host that is serving the SWF file. </li><li class="- topic/li "> In Flash Player versions 9.0.115.0 and earlier, if you want to connect to a port number below 1024,
 * or if you want to connect to a host other than the one serving the SWF file,
 * a socket policy file on the target host is required. </li><li class="- topic/li "> In Flash Player 9.0.115.0, even if a socket policy file isn't required,
 * a warning is displayed when using the Flash Debug Player if the target host
 * doesn't serve a socket policy file. </li><li class="- topic/li ">In AIR, a socket policy file is not required for content running in the application
 * security sandbox. Socket policy files are required for any socket connection established
 * by content running outside the AIR application security sandbox.</li></ul><p class="- topic/p ">For more information related to security, see the Flash Player Developer Center Topic:
 * <xref href="http://www.adobe.com/go/devnet_security_en" scope="external" class="- topic/xref ">Security</xref></p>
 *
 *   EXAMPLE:
 *
 *   The following example reads from and writes to a socket and outputs information
 * transmitted during socket events. Highlights of the example follow:
 * <ol class="- topic/ol "><li class="- topic/li ">The constructor creates a <codeph class="+ topic/ph pr-d/codeph ">CustomSocket</codeph> instance named <codeph class="+ topic/ph pr-d/codeph ">socket</codeph> and passes the
 * host name <codeph class="+ topic/ph pr-d/codeph ">localhost</codeph> and port 80 as arguments. Since <codeph class="+ topic/ph pr-d/codeph ">CustomSocket</codeph> extends
 * Socket, a call to <codeph class="+ topic/ph pr-d/codeph ">super()</codeph> calls Socket's constructor.</li><li class="- topic/li ">The example then calls the <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method, which adds listeners for
 * Socket events.</li><li class="- topic/li ">Finally, the socket <codeph class="+ topic/ph pr-d/codeph ">connect()</codeph> method is called with <codeph class="+ topic/ph pr-d/codeph ">localhost</codeph> as the
 * host name and 80 as the port number.</li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Note:</b> To run the example, you need a server running on the same domain
 * where the SWF resides (in the example, <codeph class="+ topic/ph pr-d/codeph ">localhost</codeph>) and listening on port 80.</p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 *
 *   public class SocketExample extends Sprite {
 *
 *   public function SocketExample() {
 * var socket:CustomSocket = new CustomSocket("localhost", 80);
 * }
 * }
 * }
 *
 *   import flash.errors.*;
 * import flash.events.*;
 * import flash.net.Socket;
 *
 *   class CustomSocket extends Socket {
 * private var response:String;
 *
 *   public function CustomSocket(host:String = null, port:uint = 0) {
 * super();
 * configureListeners();
 * if (host &amp;&amp; port)  {
 * super.connect(host, port);
 * }
 * }
 *
 *   private function configureListeners():void {
 * addEventListener(Event.CLOSE, closeHandler);
 * addEventListener(Event.CONNECT, connectHandler);
 * addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
 * addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
 * addEventListener(ProgressEvent.SOCKET_DATA, socketDataHandler);
 * }
 *
 *   private function writeln(str:String):void {
 * str += "\n";
 * try {
 * writeUTFBytes(str);
 * }
 * catch(e:IOError) {
 * trace(e);
 * }
 * }
 *
 *   private function sendRequest():void {
 * trace("sendRequest");
 * response = "";
 * writeln("GET /");
 * flush();
 * }
 *
 *   private function readResponse():void {
 * var str:String = readUTFBytes(bytesAvailable);
 * response += str;
 * }
 *
 *   private function closeHandler(event:Event):void {
 * trace("closeHandler: " + event);
 * trace(response.toString());
 * }
 *
 *   private function connectHandler(event:Event):void {
 * trace("connectHandler: " + event);
 * sendRequest();
 * }
 *
 *   private function ioErrorHandler(event:IOErrorEvent):void {
 * trace("ioErrorHandler: " + event);
 * }
 *
 *   private function securityErrorHandler(event:SecurityErrorEvent):void {
 * trace("securityErrorHandler: " + event);
 * }
 *
 *   private function socketDataHandler(event:ProgressEvent):void {
 * trace("socketDataHandler: " + event);
 * readResponse();
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::events;
using namespace ;
using namespace ;
using namespace flash::utils;
using namespace flash::events;
using namespace flash::events;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        class Socket: public EventDispatcher, public IDataInput,, public IDataOutput
        {
            /**
             * Indicates the number of milliseconds to wait for a connection.
             *
             *   If the connection doesn't succeed within the specified time, the connection fails.
             * The default value is 20,000 (twenty seconds).
             * @langversion 3.0
             * @playerversion   Flash 10
             * @playerversion   AIR 1.5
             * @playerversion   Lite 4
             */
        public:
            unsigned int timeout();
        public:
            void         timeout(unsigned int value);

            /**
             * The number of bytes of data available for reading in the input buffer.
             *
             *   Your code must access bytesAvailable to ensure
             * that sufficient data is available before trying to read
             * it with one of the read methods.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            unsigned int bytesAvailable();

            /**
             * Indicates whether this Socket object is currently connected.
             * A call to this property returns a value of true if the socket
             * is currently connected, or false otherwise.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         connected();

            /**
             * Controls the version of AMF used when writing or reading an object.
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
             * constants from the flash.utils.Endian class,
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
            unsigned int bytesPending();

            /**
             * Connects the socket to the specified host and port.
             *
             *   If the connection fails immediately, either an event is dispatched
             * or an exception is thrown: an error event is dispatched if a host was
             * specified, and an exception is thrown if no host was specified.
             * Otherwise, the status of the connection is reported by an event.
             * If the socket is already connected, the existing connection is closed first.
             * @param   host    The name or IP address of the host to connect to. If no host is specified,
             *   the host that is contacted is the host where the calling file
             *   resides. If you do not specify a host, use an event listener to
             *   determine whether the connection was successful.
             * @param   port    The port number to connect to.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    BRS compare this entire description with XMLSocket.connect() and make consistent
             * @throws  IOError No host was specified and the connection failed.
             * @throws  SecurityError This error occurs in SWF content
             *   for the following reasons:Local untrusted SWF files may not communicate with
             *   the Internet. You can work around this limitation by reclassifying the
             *   file as local-with-networking or as trusted.You cannot specify a socket port higher than 65535.In the HTML page that contains the SWF content, the
             *   allowNetworking parameter of the object
             *   and embed tags is set to "none".
             */
        public:
            void     connect(std::string host, int port);

            /**
             * Creates a new Socket object. If no parameters are specified, an initially disconnected socket
             * is created. If parameters are specified, a connection is attempted to the specified host and port.
             *
             *   Note: It is strongly advised to use the constructor form without parameters, then
             * add any event listeners, then call the connect method with host
             * and port parameters. This sequence guarantees that all event listeners will work
             * properly.
             * @param   host    A fully qualified DNS domain name or an IP address. IPv4 addresses are specified in
             *   dot-decimal notation, such as 192.0.2.0. In Flash Player 9.0.115.0 and AIR 1.0 and later,
             *   you can specify IPv6 addresses using hexadecimal-colon notation, such as 2001:db8:ccc3:ffff:0:444d:555e:666f.
             *   You can also specify null to connect to the host server
             *   on which the SWF file resides.  If the SWF file issuing this call is running in a web browser,
             *   host must be in the domain from which the SWF file originated.
             * @param   port    The TCP port number on the target host used to establish a connection.
             *   In Flash Player 9.0.124.0 and later, the target host must serve a socket policy file
             *   specifying that socket connections are permitted from the host serving the SWF file
             *   to the specified port. In earlier versions of Flash Player, a socket policy file is required
             *   only if you want to connect to a port number below 1024,
             *   or if you want to connect to a host other than the one serving the SWF file.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @internal    BRS determine if all above events are accurate, and which ones also apply
             * @throws  SecurityError This error occurs in SWF content
             *   for the following reasons:Local-with-filesystem files cannot communicate with the Internet. You can
             *   work around this problem by reclassifying this SWF file as local-with-networking or trusted.
             *   This limitation is not set for AIR application content in the application security sandbox.You cannot specify a socket port higher than 65535.
             */
        public:
            Socket(std::string host, int port);

            /**
             * Reads the number of data bytes specified by the length
             * parameter from the socket. The bytes are read into the specified byte
             * array, starting at the position indicated by offset.
             * @param   bytes   The ByteArray object to read data into.
             * @param   offset  The offset at which data reading should begin in the byte
             *   array.
             * @param   length  The number of bytes to read. The default value of 0 causes
             *   all available data to be read.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is
             *   not open.
             */
        public:
            void     readBytes(ByteArray *bytes, unsigned int offset, unsigned int length);

            /**
             * Writes a sequence of bytes from the specified byte array. The write
             * operation starts at the position specified by offset.
             *
             *   If you omit the length parameter the default
             * length of 0 causes the method to write the entire buffer starting at
             * offset.If you also omit the offset parameter, the entire buffer is written.
             * @param   bytes   The ByteArray object to write data from.
             * @param   offset  The zero-based offset into the bytes ByteArray
             *   object at which data writing should begin.
             * @param   length  The number of bytes to write.  The default value of 0 causes
             *   the entire buffer to be written, starting at the value specified by
             *   the offset parameter.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             * @throws  RangeError If offset is greater than the length of the ByteArray specified in
             *   bytes or if the amount of data specified to be written by offset plus
             *   length exceeds the data available.
             */
        public:
            void     writeBytes(ByteArray *bytes, unsigned int offset, unsigned int length);

            /**
             * Writes a Boolean value to the socket. This method writes a single byte,
             * with either a value of 1 (true) or 0 (false).
             * @param   value   The value to write to the socket: 1 (true) or 0 (false).
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeBoolean(bool value);

            /**
             * Writes a byte to the socket.
             * @param   value   The value to write to the socket. The low 8 bits of the
             *   value are used; the high 24 bits are ignored.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeByte(int value);

            /**
             * Writes a 16-bit integer to the socket. The bytes written are as follows:
             *
             *   (v >> 8) & 0xff v & 0xffThe low 16 bits of the parameter are used; the high 16 bits
             * are ignored.
             * @param   value   The value to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeShort(int value);

            /**
             * Writes a 32-bit signed integer to the socket.
             * @param   value   The value to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeInt(int value);

            /**
             * Writes a 32-bit unsigned integer to the socket.
             * @param   value   The value to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeUnsignedInt(unsigned int value);

            /**
             * Writes an IEEE 754 single-precision floating-point number to the socket.
             * @param   value   The value to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeFloat(float value);

            /**
             * Writes an IEEE 754 double-precision floating-point number to the socket.
             * @param   value   The value to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeDouble(float value);

            /**
             * Writes a multibyte string from the byte stream, using the specified character set.
             * @param   value   The string value to be written.
             * @param   charSet The string denoting the character set to use to interpret the bytes.
             *   Possible character set strings include "shift_jis", "CN-GB",
             *   and "iso-8859-1". For a complete list, see
             *   Supported Character Sets.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     writeMultiByte(std::string value, std::string charSet);

            /**
             * Writes the following data to the socket: a 16-bit unsigned integer, which
             * indicates the length of the specified UTF-8 string in bytes, followed by
             * the string itself.
             *
             *   Before writing the string, the method calculates the number of bytes
             * that are needed to represent all characters of the string.
             * @param   value   The string to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  RangeError The length is larger than 65535.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeUTF(std::string value);

            /**
             * Writes a UTF-8 string to the socket.
             * @param   value   The string to write to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeUTFBytes(std::string value);

            /**
             * Reads a Boolean value from the socket. After reading a single byte, the
             * method returns true if the byte is nonzero, and
             * false otherwise.
             * @return  A value of true if the byte read is nonzero,
             *   otherwise false.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            bool     readBoolean();

            /**
             * Reads a signed byte from the socket.
             * @return  A value from -128 to 127.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            int      readByte();

            /**
             * Reads an unsigned byte from the socket.
             * @return  A value from 0 to 255.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            unsigned int readUnsignedByte();

            /**
             * Reads a signed 16-bit integer from the socket.
             * @return  A value from -32768 to 32767.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            int      readShort();

            /**
             * Reads an unsigned 16-bit integer from the socket.
             * @return  A value from 0 to 65535.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            unsigned int readUnsignedShort();

            /**
             * Reads a signed 32-bit integer from the socket.
             * @return  A value from -2147483648 to 2147483647.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            int      readInt();

            /**
             * Reads an unsigned 32-bit integer from the socket.
             * @return  A value from 0 to 4294967295.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            unsigned int readUnsignedInt();

            /**
             * Reads an IEEE 754 single-precision floating-point number from the socket.
             * @return  An IEEE 754 single-precision floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            float    readFloat();

            /**
             * Reads an IEEE 754 double-precision floating-point number from the socket.
             * @return  An IEEE 754 double-precision floating-point number.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            float    readDouble();

            /**
             * Reads a multibyte string from the byte stream, using the specified character set.
             * @param   length  The number of bytes from the byte stream to read.
             * @param   charSet The string denoting the character set to use to interpret the bytes.
             *   Possible character set strings include "shift_jis", "CN-GB", and
             *   "iso-8859-1".
             *   For a complete list, see Supported Character Sets.
             *
             *     Note: If the value for the charSet parameter is not recognized
             *   by the current system, then the application uses the system's default code page as the character set.
             *   For example, a value for the charSet parameter, as in myTest.readMultiByte(22, "iso-8859-01")
             *   that uses 01 instead of 1 might work on your development machine, but not on another machine.
             *   On the other machine, the application will use the system's default code page.
             * @return  A UTF-8 encoded string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             */
        public:
            std::string readMultiByte(unsigned int length, std::string charSet);

            /**
             * Reads a UTF-8 string from the socket.  The string is assumed to be prefixed
             * with an unsigned short integer that indicates the length in bytes.
             * @return  A UTF-8 string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            std::string readUTF();

            /**
             * Reads the number of UTF-8 data bytes specified by the length
             * parameter from the socket, and returns a string.
             * @param   length  The number of bytes to read.
             * @return  A UTF-8 string.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            std::string readUTFBytes(unsigned int length);

            /**
             * Closes the socket. You cannot read or write any data after the close() method
             * has been called.
             *
             *   The close event is dispatched only when the server
             * closes the connection; it is not dispatched when you call the close() method.You can reuse the Socket object by calling the connect() method on it again.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError The socket could not be closed, or the socket was not open.
             */
        public:
            void     close();

            /**
             * Flushes any accumulated data in the socket's output buffer.
             *
             *   On some operating systems, flush() is called automatically between execution frames, but on other operating systems, such
             * as Windows, the data is never sent unless you call flush() explicitly. To ensure your application behaves reliably
             * across all operating systems, it is a good practice to call the flush() method after writing each message
             * (or related group of data) to the socket.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     flush();

            /**
             * Write an object to the socket in AMF serialized format.
             * @param   object  The object to be serialized.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void     writeObject(void *object);

            /**
             * Reads an object from the socket, encoded in AMF serialized format.
             * @return  The deserialized object
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  EOFError There is insufficient data available to read.
             * @throws  IOError An I/O error occurred on the socket, or the socket is not open.
             */
        public:
            void    *readObject();
        };
    }
}

#endif // FLEX11_6_FLASH_NET_SOCKET_AS
#endif // __cplusplus

