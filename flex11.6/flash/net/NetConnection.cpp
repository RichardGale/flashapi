

#include "NetConnection.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/Responder.h"

    /**
     * Dispatched when a NetConnection object is reporting its status or error condition.
     * @eventType   flash.events.NetStatusEvent.NET_STATUS
     */

using namespace flash::events;
using namespace flash::net;

namespace flash {
namespace net {


        /**
         * The default object encoding for NetConnection objects.
         * When an object is written to or read from binary data, the defaultObjectEncoding
         * property indicates which Action Message Format (AMF) version is used to serialize the data:
         * the ActionScript 3.0 format (ObjectEncoding.AMF3)
         * or the ActionScript 1.0 and ActionScript 2.0 format (ObjectEncoding.AMF0).
         * 
         *   The default value is ObjectEncoding.AMF3.
         * Changing NetConnection.defaultObjectEncoding
         * does not affect existing NetConnection instances; it affects only instances that
         * are created subsequently.To set an object's encoding separately (rather than setting object encoding for the entire
         * application), set the objectEncoding property of the NetConnection object instead.For more detailed information, see the description of the objectEncoding
         * property.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        unsigned int NetConnection::defaultObjectEncoding()       ;
        void NetConnection::defaultObjectEncoding(unsigned int version)       ;

        /**
         * Indicates whether the application is connected to a server through
         * a persistent RTMP connection (true) or not (false).
         * When connected through HTTP, this property is false, except
         * when connected to Flash Remoting services on an application server,
         * in which case it is true.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        bool NetConnection::connected()          ;

        /**
         * The URI passed to the NetConnection.connect() method.
         * If NetConnection.connect() hasn't been called or if no URI was passed,
         * this property is undefined.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    server-specific: Documented this method with server-specific info in span tags. The
         *   info is relevant for Flex servers, as well as Flash Media Server.
         */
        std::string NetConnection::uri()         ;

        /**
         * Indicates the object on which callback methods are invoked. The default is
         * this NetConnection instance. If you set the client property to another object,
         * callback methods will be invoked on that object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    Property documented; needs review.
         * @throws  TypeError The client property must be set to a non-null object.
         */
        Object* NetConnection::client()         ;
        void NetConnection::client(Object* object)       ;

        /**
         * The object encoding for this NetConnection instance.
         * 
         *   When an object is written to or read from binary data, the defaultObjectEncoding
         * property indicates which Action Message Format (AMF) version is used to serialize the data: the ActionScript 3.0 format (ObjectEncoding.AMF3)
         * or the ActionScript 1.0 and ActionScript 2.0 format (ObjectEncoding.AMF0).
         * Set the objectEncoding property to set an AMF version for a NetConnection instance.
         * It's important to understand this property if your application needs to
         * communicate with servers released prior to Flash Player 9. The following three scenarios are possible:
         * Connecting to a server that supports AMF3 (for example, Flex Data Services 2 or Flash Media Server 3).
         * The default value of defaultObjectEncoding is
         * ObjectEncoding.AMF3. All NetConnection instances created in this
         * file use AMF3 serialization, so you don't need to set the
         * objectEncoding property.Connecting to a server that doesn't support AMF3 (for example, Flash Media Server 2).
         * In this scenario, set the static NetConnection.defaultObjectEncoding property to
         * ObjectEncoding.AMF0. All NetConnection instances created in this
         * SWF file use AMF0 serialization. You don't need to set the
         * objectEncoding property. Connecting to multiple servers that use different encoding versions. Instead of
         * using defaultObjectEncoding, set the object encoding on a per-connection
         * basis using the objectEncoding property for each connection.
         * Set it to ObjectEncoding.AMF0 to connect to
         * servers that use AMF0 encoding, such as Flash Media Server 2,
         * and set it to ObjectEncoding.AMF3 to connect to
         * servers that use AMF3 encoding, such as Flex Data Services 2.Once a NetConnection instance is connected, its objectEncoding
         * property is read-only.If you use the wrong encoding to connect to a server, the NetConnection object
         * dispatches the netStatus event. The NetStatusEvent.info
         * property contains an information object with a code property value of
         * NetConnection.Connect.Failed, and a description explaining that the object
         * encoding is incorrect.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ReferenceError An attempt was made to set the value of the objectEncoding
         *   property while the NetConnection instance was connected.
         * @throws  ArgumentError This property was set to a value other than ObjectEncoding.AMF0
         *   or ObjectEncoding.AMF3.
         */
        unsigned int NetConnection::objectEncoding()       ;
        void NetConnection::objectEncoding(unsigned int version)       ;

        /**
         * Determines which fallback methods are tried if an
         * initial connection attempt to Flash Media Server fails. Set the proxyType property before
         * calling the NetConnection.connect() method.
         * 
         *   Acceptable values are "none", "HTTP", "CONNECT",
         * and "best".The default value is "none".To use native SSL, set the property to "best". If the player cannot make a direct connection
         * to the server (over the default port of 443 or over another port that you specify)
         * and a proxy server is in place, the player tries to use the CONNECT method. If that attempt fails, the player tunnels over HTTPS.
         * If the property is set to "HTTP" and a direct connection fails, HTTP tunneling is used.
         * If the property is set to "CONNECT" and a direct connection fails,
         * the CONNECT method of tunneling is used. If that fails, the connection does
         * not fall back to HTTP tunneling.This property is applicable only when using RTMP, RTMPS, or RTMPT. The CONNECT
         * method is applicable only to users who are connected to the network by a proxy server.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    This property is used in Breeze 5.5. In the Breeze Add-in, the default value is <code>"best"</code>; if this value
         *   is not changed, native SSL sockets are used by default, and a fallback
         *   to other methods is used if necessary.
         */
        std::string NetConnection::proxyType()         ;
        void NetConnection::proxyType(std::string ptype)       ;

        /**
         * The proxy type used to make a successful connection to Flash Media Server. Possible values are:
         * "none", "HTTP", "HTTPS", or "CONNECT".
         * 
         *   The value is "none" if the connection is not tunneled or is a native SSL connection.The value is "HTTP" if the connection is tunneled over HTTP.The value is "HTTPS" if the connection is tunneled over HTTPS,The value is "CONNECT" if the connection is tunneled using the CONNECT method through a proxy server.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    This property is used in Breeze 5.5.
         * @throws  ArgumentError An attempt was made to access this property when the NetConnection instance
         *   was not connected.
         */
        std::string NetConnection::connectedProxyType()         ;

        /**
         * Indicates whether a secure connection was made using native Transport Layer Security (TLS)
         * rather than HTTPS. This property is valid only when a NetConnection object is connected.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ArgumentError An attempt was made to access this property when the NetConnection instance
         *   was not connected.
         */
        bool NetConnection::usingTLS()          ;

        /**
         * The protocol used to establish the connection. This property is relevant when using
         * Flash Media Server. Possible values are as follows:
         * "rtmp": Real-Time Messaging Protocol (RTMP)"rtmpe": Encrypted RTMP"rtmpt": HTTP tunneling RTMP"rtmpte": HTTP tunneling encrypted RTMP"rtmps": HTTPS-based RTMP"rtmfp": Real-Time Media Flow Protocol (RTMFP)
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         * @throws  ArgumentError An attempt was made to access this property when the NetConnection instance
         *   was not connected.
         */
        std::string NetConnection::protocol()         ;

        /**
         * The total number of inbound and outbound peer connections that this instance of Flash Player or Adobe AIR allows.
         * The default value is 8.
         * This value does not distinguish between publisher and subscriber connections. If this value is reduced while
         * peer connections are present, the new value affects new incoming connections only. Existing connections are not dropped.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        unsigned int NetConnection::maxPeerConnections()       ;
        void NetConnection::maxPeerConnections(unsigned int maxPeers)       ;

        /**
         * The identifier of this Flash Player or Adobe AIR instance for this NetConnection instance. This property is meaningful only for RTMFP connections.
         * 
         *   Every NetConnection instance has a unique nearID property. No Flash Player or Adobe AIR instance
         * or NetConnection instance has the same identifier.Other Flash Player or Adobe AIR instances
         * use this identifier as the peerID for new NetStream connections to this client.
         * Subsequently, this identifier is the farID in any peer NetStream that connects to this instance.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string NetConnection::nearID()         ;

        /**
         * The identifier of the Flash Media Server instance to which this Flash Player or Adobe AIR instance is connected.
         * This property is meaningful only for RTMFP connections. The value of this property is available only after an RTMFP connection is established.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string NetConnection::farID()         ;

        /**
         * A value chosen substantially by this Flash Player or Adobe AIR instance, unique to this connection. This value appears to the server
         * as its client.farNonce value. This value is defined only for RTMFP, RTMPE, and RTMPTE connections.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string NetConnection::nearNonce()         ;

        /**
         * A value chosen substantially by Flash Media Server, unique to this connection. This value appears to the server
         * as its client.nearNonce value. This value is defined only for RTMFP, RTMPE, and RTMPTE connections.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::string NetConnection::farNonce()         ;

        /**
         * An object that holds all of the peer subscriber NetStream objects that are not associated with publishing NetStream objects.
         * Subscriber NetStream objects that are associated with publishing NetStream objects are in the NetStream.peerStreams
         * array.
         * @langversion 3.0
         * @playerversion   Flash 10
         * @playerversion   AIR 1.5
         */
        std::vector<void*> NetConnection::unconnectedPeerStreams()        ;

        /**
         * Creates a NetConnection object. Call the connect() method to make a connection.
         * 
         *   If an application needs to communicate with servers released prior
         * to Flash Player 9, set the NetConnection object's
         * objectEncoding property.The following code creates a NetConnection object:
         * var nc:NetConnection = new NetConnection();
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @oldexample  See the example for <code>connect()</code>.
         */
        NetConnection::NetConnection();

        /**
         * Closes the connection that was opened locally or to the server and dispatches
         * a netStatus event
         * with a code property of NetConnection.Connect.Closed.
         * 
         *   This method disconnects all NetStream objects running over the connection.
         * Any queued data that has not been sent is discarded. (To terminate
         * local or server streams without closing the connection, use NetStream.close().)
         * If you close the connection and then want to create a new one,
         * you must create a new NetConnection object and call the connect() method again.
         * The close() method also disconnects all remote shared objects running
         * over this connection.
         * However, you don't need to recreate the shared object to reconnect. Instead, you can just
         * call SharedObject.connect() to reestablish the connection to the shared object.
         * Also, any data in the shared object that was queued when you issued
         * NetConnection.close() is sent after you reestablish a connection
         * to the shared object.
         * With Flash Media Server, the best development practice is to call close()
         * when the client no longer needs the connection to the server. Calling close()
         * is the fastest way to clean up unused connections. You can configure the server to close idle connections
         * automatically as a back-up measure. For more information, see
         * the Flash Media Server Configuration and Administration Guide.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    server-specific: Documented this method with server-specific info in span tags. The
         *   info is relevant for Flex servers, as well as Flash Media Server.
         */
        void NetConnection::close()       ;

        /**
         * Adds a context header to the Action Message Format (AMF) packet structure. This header is sent with
         * every future AMF packet. If you call NetConnection.addHeader()
         * using the same name, the new header replaces the existing header, and the new header
         * persists for the duration of the NetConnection object. You can remove a header by
         * calling NetConnection.addHeader() with the name of the header to remove
         * an undefined object.
         * @param   operation   Identifies the header and the ActionScript object data associated with it.
         * @param   mustUnderstand  A value of true indicates that the server must understand
         *   and process this header before it handles any of the following headers or messages.
         * @param   param   Any ActionScript object.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @internal    IMD: This method can be used in the client Flash Player for Flash Remoting
         *   and Flex apps. It is also a server side method used by Flash Media Server apps.
         */
        void NetConnection::addHeader(std::string operation, bool mustUnderstand, Object* param)       ;

        /**
         * Calls a command or method on Flash Media Server or on an application server running Flash Remoting.
         * 
         *   Before calling NetConnection.call() you must call NetConnection.connect()
         * to connect to the server. You must create a server-side function to pass to this method.
         * 
         *   You cannot connect to commonly reserved ports.
         * For a complete list of blocked ports, see "Restricting Networking APIs" in the
         * ActionScript 3.0 Developer's Guide.
         * @param   command A method specified in the form [objectPath/]method. For example,
         *   the someObject/doSomething command tells the remote server
         *   to call the clientObject.someObject.doSomething() method, with all the optional
         *   ... arguments parameters. If the object path is missing,
         *   clientObject.doSomething() is invoked on the remote server.
         *   
         *     With Flash Media Server, command is the name of a function
         *   defined in an application's server-side script.
         *   You do not need to use an object path before command
         *   if the server-side script is placed at the root level of
         *   the application directory.
         * @param   responder   An optional object that is used to handle return values from the server.
         *   The Responder object can have two defined methods to handle the returned result:
         *   result and status. If an error is returned as the result,
         *   status is invoked; otherwise, result is invoked. The Responder object
         *   can process errors related to specific operations, while the NetConnection object responds to
         *   errors related to the connection status.
         * @param   arguments   Optional arguments that can be of any ActionScript type,
         *   including a reference to another ActionScript object. These arguments are passed
         *   to the method specified in the command parameter when the method is executed on the
         *   remote application server.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        void NetConnection::call(std::string command, Responder* responder, ...)       ;

        /**
         * Creates a two-way connection to an application on Flash Media Server or to Flash Remoting, or creates a two-way network
         * endpoint for RTMFP peer-to-peer group communication. To report its status or an error condition, a
         * call to NetConnection.connect() dispatches a netStatus event.
         * 
         *   Call NetConnection.connect() to do the following:Pass "null" to play video and mp3 files from a local file system or from a web server.Pass an "http" URL to connect to an application server running Flash Remoting. Use the NetServices class to call functions on and
         * return results from application servers over a NetConnection object.
         * For more information, see the Flash Remoting documentation. Pass an "rtmp/e/s" URL to connect to a Flash Media Server application.Pass an "rtmfp" URL to create a two-way network endpoint for RTMFP client-server, peer-to-peer, and IP multicast communication.Pass the string "rtmfp:" to create a serverless two-way network endpoint for RTMFP IP multicast communication.Consider the following security model:By default, Flash Player or AIR denies access between sandboxes.
         * A website can enable access to a resource by using a URL policy file. Your application can deny access to a resource on the server.
         * In a Flash Media Server application, use Server-Side ActionScript code to deny access.
         * See the Flash Media Server documentation.You cannot call NetConnection.connect() if the calling file is in the
         * local-with-file-system sandbox. You cannot connect to commonly reserved ports.
         * For a complete list of blocked ports, see "Restricting Networking APIs" in the
         * ActionScript 3.0 Developer's Guide.To prevent a SWF file from calling this method, set the allowNetworking
         * parameter of the the object and embed tags in the HTML
         * page that contains the SWF content.However, in Adobe AIR, content in the application security sandbox (content
         * installed with the AIR application) are not restricted by these security limitations.For more information about security, see the Adobe Flash Player Developer Center:
         * Security.
         * @param   command Use one of the following values for the command parameter:
         *   To play video and mp3 files from a local file system or from a web server, pass null.To connect to an application server running Flash Remoting, pass a URL that uses the http protocol.(Flash Player 10.1 or AIR 2 or later) To create a serverless network endpoint for RTMFP IP multicast communication,
         *   pass the string "rtmfp:". Use this connection type to receive an IP multicast stream from a publisher without using a server.
         *   You can also use this connection type to use IP multicast to discover peers on the same local area network (LAN).This connection type has the following limitations:Only peers on the same LAN can discover each other.Using IP multicast, Flash Player can receive streams, it cannot send them.Flash Player and AIR can send and receive streams in a peer-to-peer group, but the peers
         *   must be discovered on the same LAN using IP multicast.This technique cannot be used for one-to-one communication.To connect to Flash Media Server, pass the URI of the
         *   application on the server. Use the following
         *   syntax (items in brackets are optional):
         *   
         *     protocol:[//host][:port]/appname[/instanceName]Use one of the following protocols: rtmp,
         *   rtmpe, rtmps, rtmpt, rtmpte, or rtmfp.
         *   If the connection is successful, a
         *   netStatus event with a code property of
         *   NetConnection.Connect.Success is returned.
         *   See the NetStatusEvent.info property for a list of
         *   all event codes returned in response to calling connect(). If the file is served from the same host where the server is installed,
         *   you can omit the //host parameter. If you omit the /instanceName parameter,
         *   Flash Player or AIR connects to the application's default instance.(Flash Player 10.1 or AIR 2 or later)To create peer-to-peer applications, use the rtmfp protocol.
         * @param   arguments   Optional parameters of any type passed to the application
         *   specified in command.
         *   With Flash Media Server, the additional arguments are passed to the
         *   application.onConnect() event handler in the application's server-side
         *   code. You must define and handle the arguments in onConnect().
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         * @throws  ArgumentError The URI passed to the command parameter is
         *   improperly formatted.
         * @throws  IOError The connection failed. This can happen if you call connect()
         *   from within a netStatus event handler, which is not allowed.
         * @throws  SecurityError Local-with-filesystem SWF files cannot communicate with the Internet.
         *   You can avoid this problem by reclassifying the SWF file as local-with-networking or trusted.
         * @throws  SecurityError You cannot connect to commonly reserved ports.
         *   For a complete list of blocked ports, see "Restricting Networking APIs" in the
         *   ActionScript 3.0 Developer's Guide.
         */
        void NetConnection::connect(std::string command, ...)       ;
}
}

