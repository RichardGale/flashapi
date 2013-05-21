

#include "SecureSocket.h"
#include "flash/security/X509Certificate.h"
#include "flash/utils/ByteArray.h"

    /**
     * Dispatched when a socket has received data.
     * @eventType   flash.events.ProgressEvent.SOCKET_DATA
     */

using namespace flash::security;
using namespace flash::utils;

namespace flash {
namespace net {


        /**
         * Indicates whether the secure sockets are supported on the current system.
         * 
         *   Secure sockets are not supported on all platforms. Check this property 
         * before attempting to create a new SecureSocket instance.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        bool SecureSocket::isSupported()          ;

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
        std::string SecureSocket::serverCertificateStatus()         ;

        X509Certificate* SecureSocket::serverCertificate()                  ;

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
        void SecureSocket::connect(std::string host, int port)       ;

        /**
         * Creates a new SecureSocket object.
         * 
         *   Check SecureSocket.isSupported before attempting to create a SecureSocket 
         * instance. If SSLv3 or TLSv1 sockets are not supported, the runtime will throw an IllegalOperationError.
         * @langversion 3.0
         * @playerversion   AIR 2
         * @throws  IllegalOperationError This error occurs when SSLv3 or TLSv1 support is not available.
         */
        SecureSocket::SecureSocket();

        void SecureSocket::addBinaryChainBuildingCertificate(ByteArray* certificate, bool trusted)       ;
}
}

