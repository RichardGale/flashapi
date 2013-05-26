#if !defined(FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTURE_AS)
#define FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTURE_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace display
    {
        class BitmapData;
    }
}
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}
#include "flash/display3D/TextureBase.h"

using namespace flash::display;
using namespace flash::display3D;
using namespace flash::utils;

namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class Texture : public flash::display3D::TextureBase
            {
            public:
                Texture();

            public:
                void     uploadFromBitmapData(BitmapData *source, unsigned int miplevel=0);

            public:
                void     uploadFromByteArray(ByteArray *data, unsigned int byteArrayOffset, unsigned int miplevel=0);

            public:
                void     uploadCompressedTextureFromByteArray(ByteArray *data, unsigned int byteArrayOffset, bool async=false);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_TEXTURES_TEXTURE_AS
#endif // __cplusplus

