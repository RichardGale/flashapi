

#include "DRMDeviceGroupErrorEvent.h"
#include "flash/net/drm/DRMDeviceGroup.h"
#include "flash/events/Event.h"

using namespace flash::events;
using namespace flash::net::drm;

namespace flash {
namespace events {


        const std::string DRMDeviceGroupErrorEvent::ADD_TO_DEVICE_GROUP_ERROR;
        const std::string DRMDeviceGroupErrorEvent::REMOVE_FROM_DEVICE_GROUP_ERROR;

        int DRMDeviceGroupErrorEvent::subErrorID()      ;
        void DRMDeviceGroupErrorEvent::subErrorID(int value)       ;

        void DRMDeviceGroupErrorEvent::deviceGroup(DRMDeviceGroup* value)       ;
        DRMDeviceGroup* DRMDeviceGroupErrorEvent::deviceGroup()                 ;

        bool DRMDeviceGroupErrorEvent::systemUpdateNeeded()          ;

        bool DRMDeviceGroupErrorEvent::drmUpdateNeeded()          ;

        DRMDeviceGroupErrorEvent::DRMDeviceGroupErrorEvent(std::string type, bool bubbles, bool cancelable, std::string errorDetail, int errorCode, int subErrorID, DRMDeviceGroup* deviceGroup, bool systemUpdateNeeded, bool drmUpdateNeeded);

        std::string DRMDeviceGroupErrorEvent::toString()         ;

        Event* DRMDeviceGroupErrorEvent::clone()        ;
}
}

