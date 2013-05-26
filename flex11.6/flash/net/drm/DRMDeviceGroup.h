#if !defined(FLEX11_6_FLASH_NET_DRM_DRMDEVICEGROUP_AS)
#define FLEX11_6_FLASH_NET_DRM_DRMDEVICEGROUP_AS
#if defined(__cplusplus)



#include "flex11.6.h"



namespace flash
{
    namespace net
    {
        namespace drm
        {
            class DRMDeviceGroup : public Object
            {
            public:
                std::string       serverURL();

            public:
                std::string       authenticationMethod();

            public:
                std::string       domain();

            public:
                DRMDeviceGroup();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_NET_DRM_DRMDEVICEGROUP_AS
#endif // __cplusplus

