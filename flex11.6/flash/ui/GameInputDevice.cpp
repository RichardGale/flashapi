

#include "GameInputDevice.h"
#include "flash/events/EventDispatcher.h"
#include "flash/ui/GameInputControl.h"
#include "flash/utils/ByteArray.h"

using namespace flash::events;
using namespace flash::ui;
using namespace flash::utils;

namespace flash {
namespace ui {


        const int GameInputDevice::MAX_BUFFER_SIZE  ;

        int GameInputDevice::numControls()      ;

        int GameInputDevice::sampleInterval()      ;
        void GameInputDevice::sampleInterval(int val)       ;

        bool GameInputDevice::enabled()          ;
        void GameInputDevice::enabled(bool val)       ;

        std::string GameInputDevice::id()         ;

        std::string GameInputDevice::name()         ;

        GameInputDevice::GameInputDevice();

        GameInputControl* GameInputDevice::getControlAt(int i)                   ;

        void GameInputDevice::startCachingSamples(int numSamples, std::vector<int> controls)       ;

        void GameInputDevice::stopCachingSamples()       ;

        int GameInputDevice::getCachedSamples(ByteArray* data, bool append)      ;
}
}

