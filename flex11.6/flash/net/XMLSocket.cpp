

#include "XMLSocket.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/Socket.h"
#include "flash/utils/ByteArray.h"
#include "flash/events/Event.h"
#include "flash/events/ProgressEvent.h"

    /**
     * Dispatched if a call to the XMLSocket.connect() method
     * attempts to connect either to a server outside the caller's security sandbox or to a port lower than 1024.
     * @eventType   flash.events.SecurityErrorEvent.SECURITY_ERROR
     */

using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;

namespace flash {
namespace net {


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
        int XMLSocket::timeout()      ;
        void XMLSocket::timeout(int value)       ;

        /**
         * Indicates whether this XMLSocket object is currently connected. You can also check 
         * whether the connection succeeded by registering for the connect 
         * event and ioError event.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool XMLSocket::connected()          ;

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
        void XMLSocket::connect(std::string host, int port)       ;

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
        void XMLSocket::send(void* object)       ;

        /**
         * Closes the connection specified by the XMLSocket object. 
         * The close event is dispatched only when the server
         * closes the connection; it is not dispatched when you call the close() method.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void XMLSocket::close()       ;

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
        XMLSocket::XMLSocket(std::string host, int port);
}
}

