

#include "StageCaptureEvent.h"
#include "flash/events/Event.h"

using namespace flash::events;

namespace flash {
namespace automation {


        const std::string StageCaptureEvent::CAPTURE;

        std::string StageCaptureEvent::url()         ;

        unsigned int StageCaptureEvent::checksum()       ;

        Event* StageCaptureEvent::clone()        ;

        StageCaptureEvent::StageCaptureEvent(std::string type, bool bubbles, bool cancelable, std::string url, unsigned int checksum);

        std::string StageCaptureEvent::toString()         ;
}
}

