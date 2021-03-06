#if !defined(FLEX11_6_FLASH_SECURITY_CERTIFICATESTATUS_AS)
#define FLEX11_6_FLASH_SECURITY_CERTIFICATESTATUS_AS
#if defined(__cplusplus)


/**
 * The CertificateStatus class defines constants used to report the
 * results of certificate validation processing by a SecureSocket object.
 * @langversion 3.0
 * @playerversion   AIR 2
 */

#include "flex11.6.h"



namespace flash
{
    namespace security
    {
        class CertificateStatus : public Object
        {
            /**
             * A valid, trusted certificate.
             *
             *   Indicates that a certificate has not expired, has not
             * failed a revocation check, and chains to a trusted root certificate.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string TRUSTED;

            /**
             * The validity of the certificate is not known.
             *
             *   Indicates that certificate validation processing
             * has not been performed yet on a certificate.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string UNKNOWN;

            /**
             * An invalid certificate.
             *
             *   Indicates that certificate validation processing
             * was attempted, but failed. This is the generic faliure status that
             * is reported when a more specific certificate status cannot be
             * determined.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string INVALID;

            /**
             * The certificate is outside its valid period.
             *
             *   Indicates that certificate validation processing
             * was attempted, but failed because the validity period of the certificate is either before or
             * after the current date. On some operating systems, the notYetValid status is reported
             * when the current date is before the validity period of the cerificate. On other operating systems,
             * the expired status is reported in both cases.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string EXPIRED;

            /**
             * The certificate is not yet valid.
             *
             *   Indicates that a certificate is not yet valid.
             * The current date is before the notBefore date/time of the certificate
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string NOT_YET_VALID;

            /**
             * The certificate common name does not match the expected host name.
             *
             *   Indicates that certificate validation
             * processing was attempted, but failed because the certificate's
             * common name does not match the fully qualified domain name of the host.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string PRINCIPAL_MISMATCH;

            /**
             * The certificate does not chain to a trusted root certificate.
             *
             *   Indicates that certificate validation
             * processing was attempted, but that the certificate does not chain
             * to any of the root certificates in the client trust store. On
             * some operating systems, the untrustedSigners is also
             * reported if the certificate is in the list of untrusted certificates
             * on the client computer.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string UNTRUSTED_SIGNERS;

            /**
             * The certificate has been revoked.
             *
             *   Indicates that certificate validation processing
             * was attempted, but failed because the certificate has been revoked. On
             * some operating systems, the revoked status is also reported
             * when the certificate (or its root certificate) has been added to the
             * list of untrusted certificates on the client computer.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string REVOKED;

            /**
             * A root or intermediate certificate in this certificate's chain is invalid.
             *
             *   Indicates that certificate validation processing
             * was attempted, but failed because the certificate's trust chain was
             * invalid.
             * @langversion 3.0
             * @playerversion   AIR 2
             */
        public:
            static const std::string INVALID_CHAIN;

        public:
            CertificateStatus();
        };
    }
}

#endif // FLEX11_6_FLASH_SECURITY_CERTIFICATESTATUS_AS
#endif // __cplusplus

