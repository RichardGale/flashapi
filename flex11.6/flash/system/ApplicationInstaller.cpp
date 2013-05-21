

#include "ApplicationInstaller.h"
#include "flash/events/EventDispatcher.h"
#include "flash/utils/ByteArray.h"

using namespace flash::events;
using namespace flash::utils;

namespace flash {
namespace system {


        bool ApplicationInstaller::isInstalled()          ;

        ApplicationInstaller::ApplicationInstaller();

        std::string ApplicationInstaller::stringsDigest(XML* strings)         ;

        std::string ApplicationInstaller::iconDigest(ByteArray* icon)         ;

        void ApplicationInstaller::install(std::string mode)       ;
}
}

