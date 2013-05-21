

#include "Texture.h"
#include "flash/display/BitmapData.h"
#include "flash/utils/ByteArray.h"
#include "flash/display3D/TextureBase.h"

using namespace flash::display;
using namespace flash::display3D;
using namespace flash::utils;

namespace flash {
namespace display3D {
namespace textures {


        Texture::Texture();

        void Texture::uploadFromBitmapData(BitmapData* source, unsigned int miplevel)       ;

        void Texture::uploadFromByteArray(ByteArray* data, unsigned int byteArrayOffset, unsigned int miplevel)       ;

        void Texture::uploadCompressedTextureFromByteArray(ByteArray* data, unsigned int byteArrayOffset, bool async)       ;
}
}
}

