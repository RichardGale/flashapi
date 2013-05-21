#if !defined(FLEX11_6_FLASH_NET_DRM_DRMPLAYBACKTIMEWINDOW_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMPLAYBACKTIMEWINDOW_AS
#if defined(__cplusplus)


/**
 * The DRMPlaybackTimeWindow class represents the period of time during which a
 * DRM voucher is valid.
 *
 *   <p class="- topic/p ">The <codeph class="+ topic/ph pr-d/codeph ">startDate</codeph> and <codeph class="+ topic/ph pr-d/codeph ">endDate</codeph> properties are
 * <codeph class="+ topic/ph pr-d/codeph ">null</codeph> until the first time that the user views the content.</p>
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
            class DRMPlaybackTimeWindow : public Object
            {
                /**
                 * The period of time during which a DRM voucher is valid
                 * (the playback window), in seconds.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                unsigned int period();

                /**
                 * The start date for the period of time during which a DRM voucher is valid
                 * (the playback window).
                 *
                 *   The startDate is null if the
                 * playback window has not started.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                Date        *startDate();

                /**
                 * The end date for the period of time during which a DRM voucher is valid
                 * (the playback window).
                 *
                 *   The endDate is null if the
                 * playback window has not started.
                 * @langversion 3.0
                 * @playerversion   AIR 1.5
                 * @playerversion   Flash 10.1
                 */
            public:
                Date        *endDate();

            public:
                DRMPlaybackTimeWindow();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMPLAYBACKTIMEWINDOW_AS
#endif // __cplusplus

