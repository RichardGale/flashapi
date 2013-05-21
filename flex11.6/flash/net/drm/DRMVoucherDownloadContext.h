#if !defined(FLEX11_6_FLASH_NET_DRM_DRMVOUCHERDOWNLOADCONTEXT_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMVOUCHERDOWNLOADCONTEXT_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMContentData;
        }
    }
}
namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMVoucher;
        }
    }
}

using namespace flash::net::drm;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMVoucherDownloadContext : public DRMManagerSession
            {
            public:
                DRMVoucher  *voucher();

            public:
                void     download(DRMContentData *inMetadata, bool previewVoucher   =false);

            public:
                DRMVoucherDownloadContext();

            public:
                void     onSessionComplete();

            public:
                void     onSessionError();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMVOUCHERDOWNLOADCONTEXT_AS
#endif // __cplusplus

