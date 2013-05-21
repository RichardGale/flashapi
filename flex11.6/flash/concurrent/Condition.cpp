

#include "Condition.h"
#include "flash/concurrent/Mutex.h"

using namespace flash::concurrent;

namespace flash {
namespace concurrent {


        bool Condition::isSupported()          ;

        Mutex* Condition::mutex()        ;

        Condition::Condition(Mutex* mutex);

        bool Condition::wait(float timeout)          ;

        void Condition::notify()       ;

        void Condition::notifyAll()       ;
}
}

