

#include "Program3D.h"
#include "flash/utils/ByteArray.h"

using namespace flash::utils;

namespace flash {
namespace display3D {


        Program3D::Program3D();

        void Program3D::upload(ByteArray* vertexProgram, ByteArray* fragmentProgram)       ;

        void Program3D::dispose()       ;
}
}

