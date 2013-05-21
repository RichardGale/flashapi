

#include "SetIntervalTimer.h"
#include "flash/events/Event.h"

using namespace flash::events;

namespace flash {
namespace utils {


            

        void SetIntervalTimer::clearInterval(unsigned int id_to_clear)       ;

        SetIntervalTimer::SetIntervalTimer(Function* closure, float delay, bool repeats, std::vector<void*> rest);
}
}

