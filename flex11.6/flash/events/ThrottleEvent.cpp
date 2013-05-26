

#include "ThrottleEvent.h"
#include "flash/events/Event.h"

using namespace flash::events;

namespace flash {
namespace events {


        const std::string ThrottleEvent::THROTTLE  ;

        float ThrottleEvent::targetFrameRate()         ;

        std::string ThrottleEvent::state()         ;

        Event* ThrottleEvent::clone()        ;

        ThrottleEvent::ThrottleEvent(std::string type, bool bubbles, bool cancelable, std::string state, float targetFrameRate);

        std::string ThrottleEvent::toString()         ;
}
}

