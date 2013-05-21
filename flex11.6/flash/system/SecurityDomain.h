#if !defined(FLEX11_6_FLASH_SYSTEM_SECURITYDOMAIN_AS)
#define FLEX11_6_FLASH_SYSTEM_SECURITYDOMAIN_AS
#if defined(__cplusplus)


#include "flex11.6.h"


/**
 * The SecurityDomain class represents the current security "sandbox," also known as a security domain.
 * By passing an instance of this class to <codeph class="+ topic/ph pr-d/codeph ">Loader.load()</codeph>, you can request that loaded media be placed in
 * a particular sandbox.
 * @langversion 3.0
 * @playerversion   Flash 9
 * @playerversion   Lite 4
 */


namespace flash
{
    namespace system
    {
        class SecurityDomain : public Object
        {
            /**
             * Gets the current security domain.
             * @langversion 3.0
             * @playerversion   Flash 9
             * @playerversion   Lite 4
             */
        public:
            static flash::system::SecurityDomain *currentDomain();

        public:
            std::string  domainID();

        public:
            SecurityDomain();
        };
    }
}

#endif // FLEX11_6_FLASH_SYSTEM_SECURITYDOMAIN_AS
#endif // __cplusplus

