#if !defined(FLEX11_6_FLASH_NET_XMLSOCKET_AS)
#define FLEX11_6_FLASH_NET_XMLSOCKET_AS
#if defined(__cplusplus)


#include "flash/events/EventDispatcher.h"
namespace flash
{
    namespace net
    {
        class Socket;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace events
    {
        class Event;
    }
}
namespace flash
{
    namespace events
    {
        class ProgressEvent;
    }
}

/**
 * Dispatched if a call to the XMLSocket.connect() method
 * attempts to connect either to a server outside the caller's security sandbox or to a port lower than 1024.
 * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
 */
//[Event(name="securityError",type="flash.events.SecurityErrorEvent")]

/**
 * Dispatched when an input/output error occurs that causes a send or receive operation to fail.
 * @eventType   flash.events.IOErrorEvent.IO_ERROR
 */
//[Event(name="ioError",type="flash.events.IOErrorEvent")]

/**
 * Dispatched after raw data is sent or received.
 * @eventType   flash.events.DataEvent.DATA
 */
//[Event(name="data",type="flash.events.DataEvent")]

/**
 * Dispatched after a successful call to the XMLSocket.connect() method.
 * @eventType   flash.events.Event.CONNECT
 */
//[Event(name="connect",type="flash.events.Event")]

/**
 * Dispatched when the server closes the socket connection.
 * @eventType   flash.events.Event.CLOSE
 */
//[Event(name="close",type="flash.events.Event")]

/**
 * The XMLSocket class implements client sockets that let the
 * <ph class="- topic/ph ">Flash Player or</ph> AIR application communicate
 * with a server computer identified by an IP address or domain name. The XMLSocket class is useful for
 * client-server applications that require low latency, such as real-time chat systems. A traditional
 * HTTP-based chat solution frequently polls the server and downloads new messages using an HTTP
 * request. In contrast, an XMLSocket chat solution maintains an open connection to the server, which
 * lets the server immediately send incoming messages without a request from the client.
 * To use the XMLSocket class, the server computer must run a daemon that understands the protocol used
 * by the XMLSocket class. The protocol is described in the following list:
 * <ul class="- topic/ul "><li class="- topic/li ">XML messages are sent over a full-duplex TCP/IP stream socket connection.</li><li class="- topic/li ">Each XML message is a complete XML document, terminated by a zero (0) byte.</li><li class="- topic/li ">An unlimited number of XML messages can be sent and received over a single XMLSocket
 * connection.</li></ul><p class="- topic/p ">Setting up a server to communicate with the XMLSocket object can be challenging. If your application
 * does not require real-time interactivity, use the URLLoader class instead of the XMLSocket class. </p><p class="- topic/p ">To use the methods of the XMLSocket class, first use the constructor, <codeph class="+ topic/ph pr-d/codeph ">new XMLSocket</codeph>,
 * to create an XMLSocket object.</p><p class="- topic/p ">SWF files in the local-with-filesystem sandbox may not use sockets.</p><p class="- topic/p "><i class="+ topic/ph hi-d/i ">Socket policy files</i> on the target host specify the hosts from which SWF files
 * can make socket connections, and the ports to which those connections can be made.
 * The security requirements with regard to socket policy files have become more stringent
 * in the last several releases of Flash Player.
 * In all versions of Flash Player, Adobe recommends the use of a socket policy file;
 * in some circumstances, a socket policy file is required. Therefore, if you
 * are using XMLSocket objects, make sure that the target host provides a socket policy file
 * if necessary. </p><p class="- topic/p ">The following list summarizes the requirements for socket policy files
 * in different versions of Flash Player:</p><ul class="- topic/ul "><li class="- topic/li "> In Flash Player 9.0.124.0 and later, a socket policy file is required for any XMLSocket connection.
 * That is, a socket policy file on the target host is required no matter what port
 * you are connecting to, and is required even if you are connecting
 * to a port on the same host that is serving the SWF file. </li><li class="- topic/li "> In Flash Player versions 9.0.115.0 and earlier, if you want to connect to a port number below 1024,
 * or if you want to connect to a host other than the one serving the SWF file,
 * a socket policy file on the target host is required. </li><li class="- topic/li "> In Flash Player 9.0.115.0, even if a socket policy file isn't required,
 * a warning is displayed when using the Flash Debug Player if the target host
 * doesn't serve a socket policy file. </li></ul><p class="- topic/p ">However, in Adobe AIR, content in the <codeph class="+ topic/ph pr-d/codeph ">application</codeph> security sandbox (content
 * installed with the AIR application) are not restricted by these security limitations.</p><p class="- topic/p ">For more information related to security, see the Flash Player Developer Center Topic:
 * <xref href="http://www.adobe.com/go/devnet_security_en" scope="external" class="- topic/xref ">Security</xref>.</p>
 *
 *   EXAMPLE:
 *
 *   The following example uses the class XMLSocketExample class to send data using
 * an XMLSocket and print information during XMLSocket events.  This is accomplished using
 * the following steps:
 * <ol class="- topic/ol "><li class="- topic/li ">The XMLSocketExample constructor creates a XMLSocket instance named <codeph class="+ topic/ph pr-d/codeph ">socket</codeph> and
 * passes <codeph class="+ topic/ph pr-d/codeph ">socket</codeph> to <codeph class="+ topic/ph pr-d/codeph ">ConfigureListeners()</codeph> (described below) and then calls the
 * <codeph class="+ topic/ph pr-d/codeph ">connect()</codeph> method of XMLSocket using the host name "localhost" and port
 * number of <codeph class="+ topic/ph pr-d/codeph ">8080</codeph>.</li><li class="- topic/li ">The <codeph class="+ topic/ph pr-d/codeph ">configureListeners()</codeph> method is then called, which adds listeners for each of the
 * supported XMLSocket events:
 * <ul class="- topic/ul "><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">closeHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">close</codeph> event, which is dispatched
 * after the network connection has been closed.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">connectHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">connect</codeph> event, dispatched when the network
 * connection has been established.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">dataHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">data</codeph> events, dispatched every time
 * the XMLSocket receives new data.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">progressHandler()</codeph>: listens for the <codeph class="+ topic/ph pr-d/codeph ">progress</codeph> events, dispatched when a call to
 * <codeph class="+ topic/ph pr-d/codeph ">send()</codeph> has been made and while the send is ongoing.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">securityErrorHandler()</codeph>: listens for <codeph class="+ topic/ph pr-d/codeph ">securityError</codeph> events, which would be
 * dispatched if an attempt was made to access the XMLSocket with the wrong local playback security setting or
 * using a port lower than 1024.</li><li class="- topic/li "><codeph class="+ topic/ph pr-d/codeph ">ioErrorHandler()</codeph>: listens for <codeph class="+ topic/ph pr-d/codeph ">ioError</codeph> events, which would happen only
 * if an operation to send or receive data failed.</li></ul></li></ol><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Notes:</b><ul class="- topic/ul "><li class="- topic/li ">You need to compile the SWF file with "Local playback security" set to "Access network only".</li><li class="- topic/li ">You need a server running on your domain using port 8080 for this example to work.</li><li class="- topic/li ">If you are running Flash Player 9.0.124.0 or later, you need to place a socket policy file on your server
 * that permits socket connections from your domain to port 8080. For information on serving socket policy files,
 * see the Flash Player Developer Center Topic:
 * <xref href="http://www.adobe.com/devnet/flashplayer/articles/socket_policy_files.html" scope="external" class="- topic/xref ">
 * Setting up a socket policy file server</xref>.</li></ul></p><codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">
 *
 *   package {
 * import flash.display.Sprite;
 * import flash.events.*;
 * import flash.net.XMLSocket;
 *
 *   public class XMLSocketExample extends Sprite {
 * private var hostName:String = "localhost";
 * private var port:uint = 8080;
 * private var socket:XMLSocket;
 *
 *   public function XMLSocketExample() {
 * socket = new XMLSocket();
 * configureListeners(socket);
 * if (hostName &amp;&amp; port) {
 * socket.connect(hostName, port);
 * }
 * }
 *
 *   public function send(data:Object):void {
 * socket.send(data);
 * }
 *
 *   private function configureListeners(dispatcher:IEventDispatcher):void {
 * dispatcher.addEventListener(Event.CLOSE, closeHandler);
 * dispatcher.addEventListener(Event.CONNECT, connectHandler);
 * dispatcher.addEventListener(DataEvent.DATA, dataHandler);
 * dispatcher.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
 * dispatcher.addEventListener(ProgressEvent.PROGRESS, progressHandler);
 * dispatcher.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
 * }
 *
 *   private function closeHandler(event:Event):void {
 * trace("closeHandler: " + event);
 * }
 *
 *   private function connectHandler(event:Event):void {
 * trace("connectHandler: " + event);
 * }
 *
 *   private function dataHandler(event:DataEvent):void {
 * trace("dataHandler: " + event);
 * }
 *
 *   private function ioErrorHandler(event:IOErrorEvent):void {
 * trace("ioErrorHandler: " + event);
 * }
 *
 *   private function progressHandler(event:ProgressEvent):void {
 * trace("progressHandler loaded:" + event.bytesLoaded + " total: " + event.bytesTotal);
 * }
 *
 *   private function securityErrorHandler(event:SecurityErrorEvent):void {
 * trace("securityErrorHandler: " + event);
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */
using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;
using namespace flash::events;
using namespace flash::events;

namespace flash
{
    namespace net
    {
        class XMLSocket: public EventDispatcher
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
            int          timeout();
        public:
            void         timeout(int value);

            /**
             * Indicates whether this XMLSocket object is currently connected. You can also check
             * whether the connection succeeded by registering for the connect
             * event and ioError event.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            bool         connected();

            /**
             * Establishes a connection to the specified Internet host using the specified TCP port.
             *
             *   If you specify null for the host parameter, the host
             * contacted is the one where the file calling XMLSocket.connect() resides.
             * For example, if the calling file was downloaded from www.adobe.com, specifying null
             * for the host parameter means you are connecting to www.adobe.com.You can prevent a file from using this method by setting the
             * allowNetworking parameter of the the object and embed
             * tags in the HTML page that contains the SWF content.For more information, see the Flash Player Developer Center Topic:
             * Security.
             * @param   host    A fully qualified DNS domain name or an IP address in the form
             *   111.222.333.444. You can also specify null to connect to the host server
             *   on which the SWF file resides. If the calling file is a SWF file running in a web browser,
             *   host must be in the same domain as the file.
             * @param   port    The TCP port number on the target host used to establish a connection.
             *   In Flash Player 9.0.124.0 and later, the target host must serve a socket policy file
             *   specifying that socket connections are permitted from the host serving the SWF file
             *   to the specified port. In earlier versions of Flash Player, a socket policy file is required
             *   only if you want to connect to a port number below 1024,
             *   or if you want to connect to a host other than the one serving the SWF file.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  SecurityError Local untrusted files may not communicate with
             *   the Internet. Work around this limitation by reclassifying the file
             *   as local-with-networking or trusted.
             * @throws  SecurityError You may not specify a socket port higher than
             *   65535.
             */
        public:
            void     connect(std::string host, int port);

            /**
             * Converts the XML object or data specified in the object parameter
             * to a string and transmits it to the server, followed by a zero (0) byte. If object
             * is an XML object, the string is the XML textual representation of the XML object. The
             * send operation is asynchronous; it returns immediately, but the data may be transmitted at a
             * later time. The XMLSocket.send() method does not return a value indicating whether
             * the data was successfully transmitted.
             *
             *   If you do not connect the XMLSocket object to the server using
             * XMLSocket.connect()), the XMLSocket.send()
             * operation fails.
             * @param   object  An XML object or other data to transmit to the server.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             * @throws  IOError The XMLSocket object is not connected to the server.
             */
        public:
            void     send(void *object);

            /**
             * Closes the connection specified by the XMLSocket object.
             * The close event is dispatched only when the server
             * closes the connection; it is not dispatched when you call the close() method.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            void     close();

            /**
             * Creates a new XMLSocket object. If no parameters are specified, an initially disconnected socket
             * is created. If parameters are specified, a connection is attempted to the specified host and port.
             *
             *   Note: It is strongly advised to use the constructor form without parameters, then
             * add any event listeners, then call the connect method with host
             * and port parameters. This sequence guarantees that all event listeners will work
             * properly.
             * @param   host    A fully qualified DNS domain name or an IP address in the form
             *   .222.333.444. In Flash Player 9.0.115.0 and AIR 1.0 and later,
             *   you can specify IPv6 addresses, such as rtmp://[2001:db8:ccc3:ffff:0:444d:555e:666f].
             *   You can also specify null to connect to the host server
             *   on which the SWF file resides.  If the SWF file issuing this call is running in a web browser,
             *   host must be in the same domain as the SWF file.
             * @param   port    The TCP port number on the target host used to establish a connection.
             *   In Flash Player 9.0.124.0 and later, the target host must serve a socket policy file
             *   specifying that socket connections are permitted from the host serving the SWF file
             *   to the specified port. In earlier versions of Flash Player, a socket policy file is required
             *   only if you want to connect to a port number below 1024,
             *   or if you want to connect to a host other than the one serving the SWF file.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            XMLSocket(std::string host, int port);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_XMLSOCKET_AS
#endif // __cplusplus

