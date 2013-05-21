

#include "X509Certificate.h"
#include "flash/utils/ByteArray.h"
#include "flash/security/X500DistinguishedName.h"

using namespace flash::security;
using namespace flash::utils;

namespace flash {
namespace security {


        unsigned int X509Certificate::version()       ;

        std::string X509Certificate::serialNumber()         ;

        std::string X509Certificate::signatureAlgorithmOID()         ;

        ByteArray* X509Certificate::signatureAlgorithmParams()            ;

        X500DistinguishedName* X509Certificate::issuer()                        ;

        Date* X509Certificate::validNotBefore()       ;

        Date* X509Certificate::validNotAfter()       ;

        X500DistinguishedName* X509Certificate::subject()                        ;

        std::string X509Certificate::subjectPublicKeyAlgorithmOID()         ;

        std::string X509Certificate::subjectPublicKey()         ;

        std::string X509Certificate::issuerUniqueID()         ;

        std::string X509Certificate::subjectUniqueID()         ;

        ByteArray* X509Certificate::encoded()            ;

        X509Certificate::X509Certificate();
}
}

