#if !defined(FLEX11_6_FLASH_DISPLAY3D_PROGRAM3D_AS)
#define FLEX11_6_FLASH_DISPLAY3D_PROGRAM3D_AS
#if defined(__cplusplus)


#include "flex11.6.h"
namespace flash
{
    namespace utils
    {
        class ByteArray;
    }
}

using namespace flash::utils;

namespace flash
{
    namespace display3D
    {
        class Program3D : public Object
        {
        public:
            Program3D();

        public:
            void     upload(ByteArray *vertexProgram, ByteArray *fragmentProgram);

        public:
            void     dispose();
        };
    }
}

#endif // FLEX11_6_FLASH_DISPLAY3D_PROGRAM3D_AS
#endif // __cplusplus

