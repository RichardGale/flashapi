

#include "DRMURLDownloadContext.h"
#include "flash/events/EventDispatcher.h"
#include "flash/utils/ByteArray.h"
#include "flash/net/URLRequest.h"
#include "flash/events/TimerEvent.h"
#include "flash/events/Event.h"
#include "flash/net/URLLoader.h"
#include "flash/utils/Timer.h"

using namespace flash::events;
using namespace flash::net;
using namespace flash::utils;

namespace flash {
namespace net {
namespace drm {


        DRMURLDownloadContext::DRMURLDownloadContext();

        void DRMURLDownloadContext::httpPostAndReceiveASync(std::string url, std::string headerName, std::string headerValue, ByteArray* data)       ;

        void DRMURLDownloadContext::httpGetASync(std::string url)       ;
}
}
}

