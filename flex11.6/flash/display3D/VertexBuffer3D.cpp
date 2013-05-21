

#include "VertexBuffer3D.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace display3D {


        void VertexBuffer3D::uploadFromVector(std::vector<float> data, int startVertex, int numVertices)       ;

        void VertexBuffer3D::uploadFromByteArray(ByteArray* data, int byteArrayOffset, int startVertex, int numVertices)       ;

        void VertexBuffer3D::dispose()       ;

        VertexBuffer3D::VertexBuffer3D();
}
}

