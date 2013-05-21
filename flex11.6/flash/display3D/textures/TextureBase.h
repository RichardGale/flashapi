#if !defined(FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTUREBASE_AS)
#define FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTUREBASE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
#include "flash/events/EventDispatcher.h"

using namespace flash::events;

namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class TextureBase : public flash::events::EventDispatcher
            {
            public:
                void     dispose();

            public:
                TextureBase();
            };
        }
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTUREBASE_AS
#endif // __cplusplus

