

#include "SecurityDomain.h"
#include "flash/system/SecurityDomain.h"

    /**
     * The SecurityDomain class represents the current security "sandbox," also known as a security domain.
     * By passing an instance of this class to <codeph class="+ topic/ph pr-d/codeph ">Loader.load()</codeph>, you can request that loaded media be placed in
     * a particular sandbox.
     * @langversion 3.0
     * @playerversion   Flash 9
     * @playerversion   Lite 4
     */

using namespace flash::system;

namespace flash {
namespace system {


        /**
         * Gets the current security domain.
         * @langversion 3.0
         * @playerversion   Flash 9
         * @playerversion   Lite 4
         */
        flash::system::SecurityDomain* SecurityDomain::currentDomain()                              ;

        std::string SecurityDomain::domainID()         ;

        SecurityDomain::SecurityDomain();
}
}

