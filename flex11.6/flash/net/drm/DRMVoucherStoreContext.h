#if !defined(FLEX11_6_FLASH_NET_DRM_DRMVOUCHERSTORECONTEXT_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMVOUCHERSTORECONTEXT_AS
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
            class DRMVoucherStoreContext : public DRMManagerSession
            {
            public:
                DRMVoucher  *voucher();

            public:
                DRMVoucherStoreContext();

            public:
                void     getVoucherFromStore(DRMContentData *inMetadata);

            public:
                void     onSessionComplete();

            public:
                void     onSessionError();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMVOUCHERSTORECONTEXT_AS
#endif // __cplusplus

