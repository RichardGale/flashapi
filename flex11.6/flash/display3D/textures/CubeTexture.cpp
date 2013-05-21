

#include "CubeTexture.h"
#include "flash/display/BitmapData.h"
#include "flash/utils/ByteArray.h"

using namespace flash::display;
using namespace flash::utils;

namespace flash {
namespace display3D {
namespace textures {


        CubeTexture::CubeTexture();

        void CubeTexture::uploadFromBitmapData(BitmapData* source, unsigned int side, unsigned int miplevel)       ;

        void CubeTexture::uploadFromByteArray(ByteArray* data, unsigned int byteArrayOffset, unsigned int side, unsigned int miplevel)       ;

        void CubeTexture::uploadCompressedTextureFromByteArray(ByteArray* data, unsigned int byteArrayOffset, bool async)       ;
}
}
}

