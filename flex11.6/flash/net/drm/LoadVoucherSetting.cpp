

    /**
     * The LoadVoucherSetting class provides string constants for use
     * with the <codeph class="+ topic/ph pr-d/codeph ">settings</codeph> parameter of the DRMManager <codeph class="+ topic/ph pr-d/codeph ">loadVoucher()</codeph> method.
     * @langversion 3.0
     * @playerversion   AIR 1.5
     * @playerversion   Flash 10.1
     */


namespace flash {
namespace net {
namespace drm {


        /**
         * Downloads the voucher from the media rights server only. Does not load the voucher from the local cache.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string LoadVoucherSetting::FORCE_REFRESH   = "forceRefresh";

        /**
         * Loads the voucher from the local cache only. Does not download the voucher from a media rights server.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string LoadVoucherSetting::LOCAL_ONLY   = "localOnly";

        /**
         * Loads the voucher from the local cache, if possible; downloads the voucher from a media rights server 
         * only if a locally cached copy does not exist.
         * @langversion 3.0
         * @playerversion   AIR 1.5
         * @playerversion   Flash 10.1
         */
        const std::string LoadVoucherSetting::ALLOW_SERVER   = "allowServer";

        LoadVoucherSetting::LoadVoucherSetting();
}
}
}

