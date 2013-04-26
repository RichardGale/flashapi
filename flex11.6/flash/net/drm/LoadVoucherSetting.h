#if !defined(FLEX11_6_FLASH_NET_DRM_LOADVOUCHERSETTING_AS)
#define FLEX11_6_FLASH_NET_DRM_LOADVOUCHERSETTING_AS
#if defined(__cplusplus)


/**
 * The LoadVoucherSetting class provides string constants for use
 * with the <codeph class="+ topic/ph pr-d/codeph ">settings</codeph> parameter of the DRMManager <codeph class="+ topic/ph pr-d/codeph ">loadVoucher()</codeph> method.
 * @langversion 3.0
 * @playerversion   AIR 1.5
 * @playerversion   Flash 10.1
 */

namespace flash
{
    namespace net
    {
        namespace drm
        {
            class LoadVoucherSetting: public Object
            {
                /**
                 * Downloads the voucher from the media rights server only. Does not load the voucher from the local cache.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                static const std::string FORCE_REFRESH;

                /**
                 * Loads the voucher from the local cache only. Does not download the voucher from a media rights server.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                static const std::string LOCAL_ONLY;

                /**
                 * Loads the voucher from the local cache, if possible; downloads the voucher from a media rights server
                 * only if a locally cached copy does not exist.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                static const std::string ALLOW_SERVER;

            public:
                LoadVoucherSetting();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_LOADVOUCHERSETTING_AS
#endif // __cplusplus

