

#include "DRMManagerSession.h"
#include "flash/events/EventDispatcher.h"
#include "flash/net/drm/DRMContentData.h"
#include "flash/events/TimerEvent.h"
#include "flash/utils/Timer.h"
#include "flash/net/drm/DRMVoucher.h"

using namespace flash::events;
using namespace flash::net::drm;
using namespace flash::utils;

namespace flash {
namespace net {
namespace drm {


        const unsigned int DRMManagerSession::STATUS_READY;
        const unsigned int DRMManagerSession::STATUS_NOTREADY;
        const unsigned int DRMManagerSession::STATUS_FAILED;
        const unsigned int DRMManagerSession::STATUS_UNKNOWN;
                   

        DRMContentData* DRMManagerSession::metadata()                 ;
        void DRMManagerSession::metadata(DRMContentData* inData)       ;

        DRMManagerSession::DRMManagerSession();

        void DRMManagerSession::onSessionError()       ;

        void DRMManagerSession::onSessionComplete()       ;

        void DRMManagerSession::setTimerUp()       ;

        unsigned int DRMManagerSession::checkStatus()       ;

        unsigned int DRMManagerSession::getLastError()       ;

        unsigned int DRMManagerSession::getLastSubErrorID()       ;

        void* DRMManagerSession::issueDRMStatusEvent(DRMContentData* inMetadata, DRMVoucher* voucher)    ;

        void DRMManagerSession::issueDRMErrorEvent(DRMContentData* metadata, int errorID, int subErrorID, std::string eventType)       ;

        void DRMManagerSession::errorCodeToThrow(unsigned int errorCode)       ;
}
}
}

