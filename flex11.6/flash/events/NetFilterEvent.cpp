

#include "NetFilterEvent.h"
#include "flash/utils/ByteArray.h"
#include "flash/events/Event.h"

using namespace flash::events;
using namespace flash::utils;

namespace flash {
namespace events {


                   
                   

        Event* NetFilterEvent::clone()        ;

        NetFilterEvent::NetFilterEvent(std::string type, bool bubbles, bool cancelable, ByteArray* header, ByteArray* data);

        std::string NetFilterEvent::toString()         ;
}
}

