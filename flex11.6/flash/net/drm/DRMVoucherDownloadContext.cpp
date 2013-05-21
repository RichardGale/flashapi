

#include "DRMVoucherDownloadContext.h"
#include "flash/net/drm/DRMContentData.h"
#include "flash/net/drm/DRMVoucher.h"

using namespace flash::net::drm;

namespace flash {
namespace net {
namespace drm {


        DRMVoucher* DRMVoucherDownloadContext::voucher()             ;

        void DRMVoucherDownloadContext::download(DRMContentData* inMetadata, bool previewVoucher)       ;

        DRMVoucherDownloadContext::DRMVoucherDownloadContext();

        void DRMVoucherDownloadContext::onSessionComplete()       ;

        void DRMVoucherDownloadContext::onSessionError()       ;
}
}
}

