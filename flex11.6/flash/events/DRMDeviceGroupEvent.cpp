

#include "DRMDeviceGroupEvent.h"
#include "flash/net/drm/DRMDeviceGroup.h"
#include "flash/events/Event.h"

using namespace flash::events;
using namespace flash::net::drm;

namespace flash {
namespace events {


        const std::string DRMDeviceGroupEvent::ADD_TO_DEVICE_GROUP_COMPLETE  ;
        const std::string DRMDeviceGroupEvent::REMOVE_FROM_DEVICE_GROUP_COMPLETE  ;

        void DRMDeviceGroupEvent::deviceGroup(DRMDeviceGroup* value)       ;
        DRMDeviceGroup* DRMDeviceGroupEvent::deviceGroup()                 ;

        DRMDeviceGroupEvent::DRMDeviceGroupEvent(std::string type, bool bubbles, bool cancelable, DRMDeviceGroup* deviceGroup);

        Event* DRMDeviceGroupEvent::clone()        ;

        std::string DRMDeviceGroupEvent::toString()         ;
}
}

