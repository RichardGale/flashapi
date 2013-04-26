#if !defined(FLEX11_6_FLASH_NET_DRM_DRMVOUCHERDOWNLOADCONTEXT_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMVOUCHERDOWNLOADCONTEXT_AS
#if defined(__cplusplus)


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
using namespace flash::net::drm;

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMVoucherDownloadContext: public DRMManagerSession
            {
            public:
                DRMVoucher  *voucher();

            public:
                void     download(DRMContentData *inMetadata, bool previewVoucher);

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

