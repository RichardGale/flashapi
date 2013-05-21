

#include "GameInput.h"
#include "flash/events/EventDispatcher.h"
#include "flash/ui/GameInputDevice.h"

using namespace flash::events;
using namespace flash::ui;

namespace flash {
namespace ui {


        int GameInput::numDevices()      ;

        bool GameInput::isSupported()          ;

        GameInput::GameInput();

        GameInputDevice* GameInput::getDeviceAt(int index)                  ;
}
}

