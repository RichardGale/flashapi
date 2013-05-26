

#include "GameInputEvent.h"
#include "flash/ui/GameInputDevice.h"

using namespace flash::ui;

namespace flash {
namespace events {


        const std::string GameInputEvent::DEVICE_ADDED  ;
        const std::string GameInputEvent::DEVICE_REMOVED  ;

        GameInputDevice* GameInputEvent::device()                  ;

        GameInputEvent::GameInputEvent(std::string type, bool bubbles, bool cancelable, GameInputDevice* device);
}
}

