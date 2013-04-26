#if !defined(FLEX11_6_FLASH_NET_SECURESOCKET_AS)
#define FLEX11_6_FLASH_NET_SECURESOCKET_AS
#if defined(__cplusplus)


namespace flash
{
    namespace security
    {
        class X509Certificate;
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
 * Dispatched when a socket has received data.
 * @eventType   flash.events.ProgressEvent.SOCKET_DATA
 */
//[Event(name="socketData",type="flash.events.ProgressEvent")]

/**
 * Dispatched when an input or output error occurs that causes a send or receive operation to fail.
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
 * The SecureSocket class enables code to make socket connections utilizing the Secure Sockets Layer (SSL)
 * and Transport Layer Security (TLS) protocols.
 *
 *   <p class="- topic/p "><i class="+ topic/ph hi-d/i ">AIR profile support:</i> This feature is supported
 * on all desktop operating systems, but is not supported on all AIR for TV devices.
 * It is not supported on mobile devices. You can test
 * for support at run time using the <codeph class="+ topic/ph pr-d/codeph ">SecureSocket.isSupported</codeph> property. See
 * <xref href="http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html" class="- topic/xref ">
 * AIR Profile Support</xref> for more information regarding API support across multiple profiles.</p><p class="- topic/p ">The SSL/TLS protocols provide a mechanism by which the
 * identity of a host can be authenticated via its certificate, and  provides for encrypted communication
 * over the socket. SSLv3 and TLSv1 are supported. Validation of the server certificate is performed using
 * the trust store and certificate validation support of the client platform.</p><p class="- topic/p ">The SecureSocket class will only connect to servers with valid, trusted certificates. You cannot choose
 * to connect to a server in spite of a problem with it's certificate. For example, there is no way to connect
 * to a server with an expired certificate or a certificate that doesn't chain to a trusted root certificate
 * even though the certificate would be valid otherwise.</p><p class="- topic/p ">The SecureSocket class is useful for performing encrypted communication to a trusted server. In other respects
 * a SecureSocket object behaves like a regular Socket object.</p><p class="- topic/p ">To use the methods of the SecureSocket class, first use the constructor, <codeph class="+ topic/ph pr-d/codeph ">new SecureSocket()</codeph>,
 * to create a SecureSocket object. When you connect to a server, the server certificate is validated. If the
 * certificate is valid and trusted, the connection is established and the Socket dispatches a
 * <codeph class="+ topic/ph pr-d/codeph ">connect</codeph> event. If the certificate cannot be validated, the Socket dispatches an
 * <codeph class="+ topic/ph pr-d/codeph ">IOError</codeph> event.</p><p class="- topic/p "><b class="+ topic/ph hi-d/b ">Important:</b> The Online Certificate Status Protocol (OCSP) is not supported by all operating systems.
 * Users can also disable OCSP checking on individual computers. If OCSP is not supported or is disabled and
 * a certificate does not contain the information necessary to check revocation using a Certificate Revocation
 * List (CRL), then certificate revocation is not checked. The certificate is accepted if otherwise valid.
 * This could allow a server to use a revoked certificate.</p>
 *
 *   EXAMPLE:
 *
 *   The following example illustrates how to create and connect a
 * SecureSocket object.
 * <codeblock xml:space="preserve" class="+ topic/pre pr-d/codeblock ">package
 * {
 * import flash.display.Sprite;
 * import flash.errors.IOError;
 * import flash.events.Event;
 * import flash.events.IOErrorEvent;
 * import flash.net.SecureSocket;
 *
 *   public class SecureSocketExample extends Sprite
 * {
 * private var secureSocket:SecureSocket = new SecureSocket();
 *
 *   public function SecureSocketExample()
 * {
 * secureSocket.addEventListener( Event.CONNECT, onConnect )
 * secureSocket.addEventListener( IOErrorEvent.IO_ERROR, onError );
 *
 *   try
 * {
 * secureSocket.connect( "208.77.188.166", 443 );
 * }
 * catch ( error:Error )
 * {
 * trace ( error.toString() );
 * }
 * }
 *
 *   private function onConnect( event:Event ):void
 * {
 * trace("Connected.");
 * }
 *
 *   private function onError( error:IOErrorEvent ):void
 * {
 * trace( error.text + ", " + secureSocket.serverCertificateStatus );
 * }
 * }
 * }
 * </codeblock>
 * @langversion 3.0
 * @playerversion   AIR 2
 */
using namespace flash::security;
using namespace flash::utils;

namespace flash
{
    namespace net
    {
        class SecureSocket: public Socket
        {
            /**
             * Indicates whether the secure sockets are supported on the current system.
             *
             *   Secure sockets are not supported on all platforms. Check this property
             * before attempting to create a new SecureSocket instance.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static bool         isSupported();

            /**
             * The status of the server's certificate.
             *
             *   The status is CertificateStatus.UNKNOWN until the
             * socket attempts to connect to a server. After validation, the status will be one
             * of the strings enumerated by the CertificateStatus class. The connection only
             * succeeds when the certificate is valid and trusted. Thus, after a
             * connect event, the status is always trusted. Note: Once the certificate has been validated or rejected, the status
             * value is not updated until the next call to the connect() method.
             * Calling close() does not reset the status value to "unknown".
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            std::string  serverCertificateStatus();

        public:
            X509Certificate *serverCertificate();

            /**
             * Connects the socket to the specified host and port using SSL or TLS.
             *
             *   When you call the connect() method, the server certificate is validated. If the
             * SSL/TLS handshake succeeds and the certificate is valid and trusted, the connection is established,
             * the socket dispatches a connect event. If the handshake fails or the certificate cannot
             * be validated, the socket dispatches an IOError event. You can check the certificate
             * validation result by reading the serverCertificateStatus property after one of these
             * events has been dispatched. (When a connect event is dispatched, the certificate
             * status is always trusted.)If the socket is already connected, the existing connection is closed first.
             * @param   host    The name or IP address of the host to connect to.
             * @param   port    The port number to connect to.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @internal    BRS compare this entire description with XMLSocket.connect() and make consistent
             * @throws  IOError No host was specified and the connection failed.
             * @throws  SecurityError This error occurs if you specify a socket port less than
             *   zero or higher than 65535.
             */
        public:
            void     connect(std::string host, int port);

            /**
             * Creates a new SecureSocket object.
             *
             *   Check SecureSocket.isSupported before attempting to create a SecureSocket
             * instance. If SSLv3 or TLSv1 sockets are not supported, the runtime will throw an IllegalOperationError.
             * @langversion 3.0
             * @playerversion   AIR 2
             * @throws  IllegalOperationError This error occurs when SSLv3 or TLSv1 support is not available.
             */
        public:
            SecureSocket();

        public:
            void     addBinaryChainBuildingCertificate(ByteArray *certificate, bool trusted);
        };
    }
}

#endif // FLEX11_6_FLASH_NET_SECURESOCKET_AS
#endif // __cplusplus

