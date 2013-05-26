#if !defined(FLEX11_6_FLASH_DISPLAY3D_TEXTURES_CUBETEXTURE_AS)
#define FLEX11_6_FLASH_DISPLAY3D_TEXTURES_CUBETEXTURE_AS
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

using namespace flash::display;
using namespace flash::utils;

namespace flash
{
    namespace display3D
    {
        namespace textures
        {
            class CubeTexture : public TextureBase
            {
            public:
                CubeTexture();

            public:
                void     uploadFromBitmapData(BitmapData *source, unsigned int side, unsigned int miplevel=0);

            public:
                void     uploadFromByteArray(ByteArray *data, unsigned int byteArrayOffset, unsigned int side, unsigned int miplevel=0);

            public:
                void     uploadCompressedTextureFromByteArray(ByteArray *data, unsigned int byteArrayOffset, bool async=false);
            };
        }
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_TEXTURES_CUBETEXTURE_AS
#endif // __cplusplus

