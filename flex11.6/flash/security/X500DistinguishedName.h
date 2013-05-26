#if !defined(FLEX11_6_FLASH_SECURITY_X500DISTINGUISHEDNAME_AS)
#define FLEX11_6_FLASH_SECURITY_X500DISTINGUISHEDNAME_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace security
    {
        class X500DistinguishedName : public Object
        {
        public:
            std::string       commonName();

        public:
            std::string       organizationName();

        public:
            std::string       organizationalUnitName();

        public:
            std::string       localityName();

        public:
            std::string       stateOrProvinceName();

        public:
            std::string       countryName();

        public:
            std::string   toString();

        public:
            X500DistinguishedName();
        };
    }
}

#endif // FLEX11_6_FLASH_SECURITY_X500DISTINGUISHEDNAME_AS
#endif // __cplusplus

