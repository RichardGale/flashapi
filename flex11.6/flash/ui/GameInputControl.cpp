

#include "GameInputControl.h"
#include "flash/events/EventDispatcher.h"
#include "flash/ui/GameInputDevice.h"

using namespace flash::events;
using namespace flash::ui;

namespace flash {
namespace ui {


        int GameInputControl::numValues()      ;

        int GameInputControl::index()      ;

        bool GameInputControl::relative()          ;

        std::string GameInputControl::type()         ;

        std::string GameInputControl::hand()         ;

        std::string GameInputControl::finger()         ;

        GameInputDevice* GameInputControl::device()                  ;

        GameInputControl::GameInputControl();

        float GameInputControl::getValueAt(int index)         ;
}
}

