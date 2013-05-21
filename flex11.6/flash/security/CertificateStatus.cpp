

    /**
     * The CertificateStatus class defines constants used to report the
     * results of certificate validation processing by a SecureSocket object.
     * @langversion 3.0
     * @playerversion   AIR 2
     */


namespace flash {
namespace security {


        /**
         * A valid, trusted certificate.
         * 
         *   Indicates that a certificate has not expired, has not
         * failed a revocation check, and chains to a trusted root certificate.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        const std::string CertificateStatus::TRUSTED="trusted";

        /**
         * The validity of the certificate is not known.
         * 
         *   Indicates that certificate validation processing
         * has not been performed yet on a certificate.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        const std::string CertificateStatus::UNKNOWN="unknown";

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
        const std::string CertificateStatus::INVALID="invalid";

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
        const std::string CertificateStatus::EXPIRED="expired";

        /**
         * The certificate is not yet valid.
         * 
         *   Indicates that a certificate is not yet valid. 
         * The current date is before the notBefore date/time of the certificate
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        const std::string CertificateStatus::NOT_YET_VALID="notYetValid";

        /**
         * The certificate common name does not match the expected host name.
         * 
         *   Indicates that certificate validation
         * processing was attempted, but failed because the certificate's
         * common name does not match the fully qualified domain name of the host.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        const std::string CertificateStatus::PRINCIPAL_MISMATCH="principalMismatch";

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
        const std::string CertificateStatus::UNTRUSTED_SIGNERS="untrustedSigners";

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
        const std::string CertificateStatus::REVOKED="revoked";

        /**
         * A root or intermediate certificate in this certificate's chain is invalid.
         * 
         *   Indicates that certificate validation processing
         * was attempted, but failed because the certificate's trust chain was
         * invalid.
         * @langversion 3.0
         * @playerversion   AIR 2
         */
        const std::string CertificateStatus::INVALID_CHAIN="invalidChain";

        CertificateStatus::CertificateStatus();
}
}

