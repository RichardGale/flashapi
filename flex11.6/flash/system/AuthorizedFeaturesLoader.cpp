

#include "AuthorizedFeaturesLoader.h"
#include "flash/events/EventDispatcher.h"
#include "flash/system/AuthorizedFeatures.h"

using namespace flash::events;
using namespace flash::system;

namespace flash {
namespace system {


        AuthorizedFeatures* AuthorizedFeaturesLoader::authorizedFeatures()                     ;

        AuthorizedFeaturesLoader::AuthorizedFeaturesLoader();

        void AuthorizedFeaturesLoader::loadAuthorizedFeatures()       ;void AuthorizedFeaturesLoader::makeGlobal()       ;
}
}

