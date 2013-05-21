

#include "WorkerDomain.h"
#include "flash/system/WorkerDomain.h"
#include "flash/system/Worker.h"
#include "flash/utils/ByteArray.h"

using namespace flash::system;
using namespace flash::utils;

namespace flash {
namespace system {


        bool WorkerDomain::isSupported()          ;

        WorkerDomain* WorkerDomain::current()               ;

        Worker* WorkerDomain::createWorker(ByteArray* swf, bool giveAppPrivileges)         ;

        std::vector<Worker*> WorkerDomain::listWorkers()                  ;

        WorkerDomain::WorkerDomain();
}
}

