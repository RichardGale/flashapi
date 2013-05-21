

#include "DRMVoucherStoreContext.h"
#include "flash/net/drm/DRMContentData.h"
#include "flash/net/drm/DRMVoucher.h"

using namespace flash::net::drm;

namespace flash {
namespace net {
namespace drm {


        DRMVoucher* DRMVoucherStoreContext::voucher()             ;

        DRMVoucherStoreContext::DRMVoucherStoreContext();

        void DRMVoucherStoreContext::getVoucherFromStore(DRMContentData* inMetadata)       ;

        void DRMVoucherStoreContext::onSessionComplete()       ;

        void DRMVoucherStoreContext::onSessionError()       ;
}
}
}

