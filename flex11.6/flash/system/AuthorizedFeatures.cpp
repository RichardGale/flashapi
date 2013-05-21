

#include "AuthorizedFeatures.h"
#include "flash/system/ApplicationInstaller.h"
#include "flash/utils/ByteArray.h"
#include "flash/net/URLStream.h"

using namespace flash::net;
using namespace flash::system;
using namespace flash::utils;

namespace flash {
namespace system {


        AuthorizedFeatures::AuthorizedFeatures();

        ApplicationInstaller* AuthorizedFeatures::createApplicationInstaller(XML* strings, ByteArray* icon)                       ;

        bool AuthorizedFeatures::enableDiskCache(URLStream* stream)          ;bool AuthorizedFeatures::isFeatureEnabled(std::string feature, std::string data)          ;bool AuthorizedFeatures::isNegativeToken()          ;
}
}

