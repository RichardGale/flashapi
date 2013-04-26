#if !defined(FLEX11_6_FLASH_SECURITY_X509CERTIFICATE_AS)
#define FLEX11_6_FLASH_SECURITY_X509CERTIFICATE_AS
#if defined(__cplusplus)


namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
namespace flash
{
    namespace security
    {
        class X500DistinguishedName;
    }
}

using namespace flash::utils;
using namespace flash::security;

namespace flash
{
    namespace security
    {
        class X509Certificate: public Object
        {
        public:
            unsigned int version();

        public:
            std::string  serialNumber();

        public:
            std::string  signatureAlgorithmOID();

        public:
            ByteArray   *signatureAlgorithmParams();

        public:
            X500DistinguishedName *issuer();

        public:
            Date        *validNotBefore();

        public:
            Date        *validNotAfter();

        public:
            X500DistinguishedName *subject();

        public:
            std::string  subjectPublicKeyAlgorithmOID();

        public:
            std::string  subjectPublicKey();

        public:
            std::string  issuerUniqueID();

        public:
            std::string  subjectUniqueID();

        public:
            ByteArray   *encoded();

        public:
            X509Certificate();
        };
    }
}

#endif // FLEX11_6_FLASH_SECURITY_X509CERTIFICATE_AS
#endif // __cplusplus

