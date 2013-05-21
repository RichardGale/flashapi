

#include "IndexBuffer3D.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace display3D {


        IndexBuffer3D::IndexBuffer3D();

        void IndexBuffer3D::uploadFromVector(std::vector<unsigned int> data, int startOffset, int count)       ;

        void IndexBuffer3D::uploadFromByteArray(ByteArray* data, int byteArrayOffset, int startOffset, int count)       ;

        void IndexBuffer3D::dispose()       ;
}
}

