

#include "DRMAuthenticationContext.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace net {
namespace drm {


        ByteArray* DRMAuthenticationContext::authenticationToken()            ;

        void DRMAuthenticationContext::authenticate(std::string url, std::string domain, std::string username, std::string password)       ;

        DRMAuthenticationContext::DRMAuthenticationContext();

        void DRMAuthenticationContext::onSessionComplete()       ;

        void DRMAuthenticationContext::onSessionError()       ;
}
}
}

